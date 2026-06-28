import java.net.*;
import java.io.*;
import java.util.ArrayList;
import de.wivw.silab.sys.*;
import de.wivw.silab.mth.Vec2;
import de.wivw.silab.mth.Vec3;
import de.wivw.silab.scn.*;
import de.wivw.silab.trf.*;
import de.wivw.silab.odb.*;

/** Java class 'SilabServer'.<br>
  * <br>
  * Created: 14.11.2024 (SILABDPUWizard).<br>
  * @author Christian Schmidt
  * <p>
  * A class that can be loaded as a DPU (using the DPUJava) into SILAB.
  * The {@link #trigger} method will be called
  * periodically while the simulation is running.<br>
  * More callbacks ({@link #prepare}, {@link #start}, {@link #stop} and {@link #release}) are available
  * that are called at respective times during the simulation's lifetime.<p>
  * Communication with other SILAB DPUs is most easily implemented by annotating
  * the fields using the "VarIn", "VarOut" and "VarIO" annotations.
  */
class SilabServer extends JPU
{
    private Server server;
    private ManagedCursor cursor;
    private TRFInterface trf;
    private ODBQuery odbQuery;
	private ODBQuery standstillQuery;


    @VarIn(def=4200) int Port;
    @VarIn(def=1000) int CacheInterval;
    @VarIn(def=0) int AutomationActive;
	@VarIn(def=0) int AutomationStandstill;
	// Availability of the automation (whether the framework will let it engage).
	// Wired from ~Automation_Framework_LfE.hh_available in Server_config.inc.
	// 0 = not available => a "start" will be silently ignored by the framework.
	@VarIn(def=0) int AutomationAvailable;

	@VarIn(def=0) double X;
	@VarIn(def=0) double Y;
	@VarIn(def=0) double Yaw;

    @VarOut(def=0) int AutomationActiveImpulse;
    @VarOut(def=0) int AutomationStandstillImpulse;
	@VarOut(def=0) int ShouldAutomationActive;
	@VarOut(def=0) int ShouldStandstill;
	@VarOut(def=0) int ShouldHold;

    private double timeSinceCache = 1000;
	private double timeSinceFlank = 0;
    private String trfCache;
    private String scnCache;
    private String odbCache;

    // We can't reliably write a log file on the simulation PC (its filesystem
    // is unknown/inaccessible), so we keep the most recent log lines in memory
    // here and let clients retrieve them over the socket via the "log" command.
    private static final int MAX_LOG_LINES = 500;
    private static final java.util.ArrayDeque<String> logLines = new java.util.ArrayDeque<String>();

    // Records a timestamped line. Used to confirm the JPU is actually
    // loaded/running and to trace which commands are received.
    static synchronized void appendLog(String msg) {
        String line = java.time.LocalDateTime.now() + " " + msg;
        SILAB.logSys(line); // also surface in SILAB's own (cross-machine) log
        logLines.addLast(line);
        while (logLines.size() > MAX_LOG_LINES) {
            logLines.removeFirst();
        }
    }

    // Returns the accumulated log as a single newline-separated string.
    static synchronized String getLog() {
        return String.join("\n", logLines);
    }

	public SilabServer(long peer) {
		super(peer);
        timeSinceCache = CacheInterval;
	}

	public boolean prepare() {
		SILAB.logSys("prepare silab server");
        init();
        return true;
	}

	public int start(int step) {
        startServer(Port);
        init();
        return step;
	}

	public void trigger(double time, double timeError) {
        timeSinceCache += time;
        if (timeSinceCache >= CacheInterval) {
            timeSinceCache = 0;
            scnCache = makePositionMessage();
            trfCache = makeTrafficMessage();
            odbCache = makeODBMessage();
			SILAB.logErr(odbCache);
        }

		timeSinceFlank += time;
		if (timeSinceFlank >= 100000) {
			timeSinceFlank = 0;
			tickFlanks();
		}

		// TODO: Might not need this every trigger
		checkForStandStill();
	}

	public void release() {
        if (server != null) {
            server.close();
        }

        cursor = null;
        trf = null;
	}

    private void init() {
        if (cursor == null) {
            try {
                cursor = new ManagedCursor(0);
                SILAB.logSys("initialized cursor");
            } catch (Exception e) {
                SILAB.logErr("failed to initialize cursor");
            }
        }

        if (trf == null) {
            try {
                trf = TRFInterface.get(this);
                SILAB.logSys("initialized trf interface");
            } catch (Exception e) {
                SILAB.logErr("failed to initialize trf interface");
            }
        }

        if (odbQuery == null) {
            try {
                odbQuery = new ODBQuery();
                odbQuery.setShape(ODBQuery.POLYGON);
				Vec2[] coords = { new Vec2(-100, -100), new Vec2(100, -100), new Vec2(100, 100), new Vec2(-100, 100)};
				odbQuery.setCoords(coords);
				odbQuery.setFilterMode(ODBQuery.WHITELIST_FILTER);
				odbQuery.addFilter(1);
                SILAB.logSys("initialized odb query");
            } catch (Exception e) {
                SILAB.logErr("failed to initialize odb query");
            }
        }

		if (standstillQuery == null) {
			try {
                standstillQuery = new ODBQuery();
                standstillQuery.setShape(ODBQuery.POLYGON);
				Vec2[] coords = { new Vec2(-5, -5), new Vec2(5, -5), new Vec2(5, 0), new Vec2(-5, 0)};
				standstillQuery.setCoords(coords);
				standstillQuery.setFilterMode(ODBQuery.WHITELIST_FILTER);
				standstillQuery.addFilter(1);
            } catch (Exception e) {
                SILAB.logErr("failed to initialize standstill query");
            }
		}
    }

	private void tickFlanks() {
		// Sorry to whoever has to read the following code, but it works and I can't be bothered to refactor right now
		boolean shouldTriggerAutomation = AutomationActive != ShouldAutomationActive;
		if (shouldTriggerAutomation) {
			if (AutomationActiveImpulse == 0) {
				AutomationActiveImpulse = 1;
			} else {
				AutomationActiveImpulse = 0;
			}
		} else {
			AutomationActiveImpulse = 0;
		}

		int hold = 0;
		if ((ShouldStandstill + ShouldHold) > 0) {
			hold = 1;
		}

		boolean shouldTriggerStandstill = AutomationStandstill != hold;
		if (shouldTriggerStandstill) {
			if (AutomationStandstillImpulse == 0) {
				AutomationStandstillImpulse = 1;
			} else {
				AutomationStandstillImpulse = 0;
			}
		} else {
			AutomationStandstillImpulse = 0;
		}
	}

    private void startServer(int port) {
        SILAB.logSys("starting silab server");

        if (server != null) {
            SILAB.logSys("server already running on port " + port);
            return;
        }

        try {
            server = new Server(port, this);
            server.start();
            appendLog("silab server started on port " + port);
        } catch (IOException e) {
            SILAB.logErr("failed to start server on port " + port);
            appendLog("FAILED to start silab server on port " + port + ": " + e.getMessage());
            return;
        }
    }

   private static class Server extends Thread {

        private ServerSocket serverSocket;
        private int port;
        private boolean running = true;
        private SilabServer s;

        public Server(int port, SilabServer s) throws IOException {
            this.port = port;
            this.s = s;
            serverSocket = new ServerSocket(port);
        }

        public void run() {
            SILAB.logSys("server running on port " + port);

            while (running) {
                try {
                    new ClientHandler(serverSocket.accept(), s).start();
                } catch (IOException e) {
                    SILAB.logErr("failed to start server on port " + port);
                    return;
                }
            }
        }

        public void close() {
            running = false;
            try {
                serverSocket.close();
            } catch (IOException e) {
                SILAB.logErr("failed to close server");
            }
        }
    }

    private static class ClientHandler extends Thread {
        private Socket clientSocket;
        private PrintWriter out;
        private BufferedReader in;
        private SilabServer s;

        public ClientHandler(Socket socket, SilabServer s) {
            this.clientSocket = socket;
            this.s = s;
        }

        public void run() {

            try {
                out = new PrintWriter(clientSocket.getOutputStream(), true);
                in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

                String inputLine;
                while ((inputLine = in.readLine()) != null) {
                    if ("close".equals(inputLine)) {
                        break;
                    }

                    if ("scn".equals(inputLine)) {
                        appendLog("received scn command");
                        sendMessage(s.scnCache);
						continue;
                    }

                    if ("trf".equals(inputLine)) {
                        appendLog("received trf command");
                        sendMessage(s.trfCache);
						continue;
                    }

					if ("odb".equals(inputLine)) {
                        appendLog("received odb command");
                        sendMessage(s.odbCache);
						continue;
                    }

                    if ("start".equals(inputLine)) {
                        appendLog("received start command");
                        sendMessage(s.startAutomation());
						continue;
                    }

                    if ("stop".equals(inputLine)) {
                        appendLog("received stop command");
                        sendMessage(s.stopAutomation());
						continue;
                    }

					if ("automation".equals(inputLine)) {
                        appendLog("received automation command");
						sendMessage(s.makeAutomationMessage());
						continue;
					}

					if ("log".equals(inputLine)) {
                        sendMessage(getLog());
						continue;
					}

					appendLog("received unknown command: " + inputLine);
					sendMessage("{ 'error': { 'code': 401, 'message': 'unknown command' } }");
                }

                in.close();
                out.close();
                clientSocket.close();
            } catch (Exception e) {
                SILAB.logErr("failure in client handler");
                return;
            }
        }

        private void sendMessage(String msg) {
            out.write(msg + '\u0003');
            out.flush();
        }
    }

    private String makeTrafficMessage() {
        if (trf == null) {
            return makeError(1, "trf interface not initialized");
        }

        try {
            JsonArray objects = new JsonArray();

            for (int i = 0; i < trf.getCount(); i++) {
                TRFObject obj = trf.get(i);
                if (obj == null) {
                    continue;
                }

                JsonObject o = new JsonObject();
                o.putInt("id", obj.getTRFID())
                    .putDouble("acceleration", obj.getAcceleration())
                    .putDouble("speed", obj.getSpeed())
                    .putDouble("dFront", obj.getDFront())
                    .putDouble("dLeft", obj.getDLeft())
                    .putDouble("dRear", obj.getDRear())
                    .putDouble("dRight", obj.getDRight())
                    .putVec3("lFront", obj.getLFront())
                    .putVec3("mFront", obj.getMFront())
                    .putVec3("rFront", obj.getRFront())
                    .putVec3("lRear", obj.getLRear())
                    .putVec3("mRear", obj.getMRear())
                    .putVec3("rRear", obj.getRRear())
                    .putDouble("pitch", obj.getPitch())
                    .putDouble("pitchRoad", obj.getPitchRoad())
                    .putVec3("refPoint", obj.getRefPoint())
                    .putDouble("scnd", obj.getSCND())
                    .putInt("scnLaneId", obj.getSCNLaneID())
                    .putInt("scnNodeId", obj.getSCNNodeID())
                    .putInt("scnNodeInstanceId", obj.getSCNNodeInstanceID())
                    .putDouble("scns", obj.getSCNS())
                    .putDouble("scnsLane", obj.getSCNSLane())
                    .putInt("userId", obj.getUserID())
                    .putDouble("roll", obj.getRoll())
                    .putDouble("yaw", obj.getYaw())
                    .putObject("lightState", makeLightState(obj))
                    .putBoolean("isActive", obj.isActive());

                TRFObjectType type = obj.getType();
                o.putString("objectType", mapObjectType(type));

                objects.add(o);
            }

            JsonObject data = new JsonObject();
            data.putArray("trfObjects", objects);

            JsonObject msg = new JsonObject();
            msg.putString("type", "trf")
                .putString("version", "0.0")
                .putObject("data", data);

            return msg.toString();
        } catch (Exception e) {
            SILAB.logErr("trf query failed: " + e.getMessage());
            return "{ 'error': { 'code': 501, 'message': 'failed to query trf: " + e.getMessage() + "' } }";
        }
    }

    private String makePositionMessage() {
        if (cursor == null) {
            return makeError(1, "scn cursor not initialized");
        }

        try {
            cursor.update();


            JsonObject scn = new JsonObject();
            scn.putVec3("eyePosition", cursor.getEyePos())
                .putGpsPos("gps", cursor.getGPSPos())
                .putDouble("psi", cursor.getPsi())
                .putVec3("position", cursor.getPos())
                .putVec2("aEditPosition", cursor.getAEditPos())
                .putDouble("tangentXY", cursor.getTangentAngleXY())
                .putDouble("curvatureXY", cursor.getCurvatureXY())
                .putInt("numLanes", cursor.getNumLanes())
                .putInt("laneIndex", cursor.getLaneIndex())
                .putInt("laneDir", cursor.getLaneDir())
                .putDouble("laneWidth", cursor.getLaneWidth())
                .putDouble("laneLength", cursor.getLaneLength())
                .putString("nodeTypeName", cursor.getNodeTypeName())
                .putString("nodeInstanceName", cursor.getNodeInstanceName())
                .putLong("nodeId", cursor.getNodeID())
                .putDouble("s", cursor.getS())
                .putDouble("sLane", cursor.getSLane())
                .putDouble("sPropagated", cursor.getSPropagated())
                .putDouble("lateralDistance", cursor.getLateralDistance())
                .putDouble("ve", cursor.getVe())
                .putLong("moduleId", cursor.getModuleID())
                .putString("moduleTypeName", cursor.getModuleTypeName())
                .putString("moduleInstanceName", cursor.getModuleInstanceName())
                .putInt("moduleInstanceCounter", cursor.getModuleInstanceCounter());

            if (cursor.isLaneHeadingLeft()) {
                scn.putString("heading", "left");
            } else if (cursor.isLaneHeadingRight()) {
                scn.putString("heading", "right");
            } else {
                scn.putString("heading", "straight");
            }

            int nodeType = cursor.getNodeType();
            if (nodeType == SCN.COURSE) {
                scn.putString("nodeType", "course");
            } else if (nodeType == SCN.AREA2) {
                scn.putString("nodeType", "area2");
            } else {
                scn.putString("nodeType", "unknown");
            }

            JsonObject data = new JsonObject();
            data.putObject("scn", scn);

            JsonObject msg = new JsonObject();
            msg.putString("type", "scn")
                .putString("version", "0.0")
                .putObject("data", data);

            return msg.toString();
        } catch (Exception e) {
            SILAB.logErr("scn query failed: " + e.getMessage());
            return "{ 'error': { 'code': 501, 'message': 'failed to query scn: " + e.getMessage() + "' } }";
        }
    }

    private String makeODBMessage() {
        try {
            odbQuery.transform(X, Y, Yaw);
            odbQuery.update();

            JsonArray objects = new JsonArray();

            for (ODBObject obj : odbQuery) {
                JsonObject entry = new JsonObject();

                JsonArray bbox = new JsonArray();
                for (Vec2 point : obj.bbox) {
                    bbox.addVec2(point);
                }

                JsonArray type = new JsonArray();
                for (int t : obj.type) {
                    type.addInt(t);
                }

                entry.putArray("bbox", bbox)
                    .putBoolean("bboxValid", obj.bboxValid)
                    .putBoolean("coordValid", obj.coordValid)
                    .putDouble("d", obj.d)
                    .putInt("laneCellID", obj.laneCellID)
                    .putInt("laneID", obj.laneID)
                    .putInt("moduleID", obj.moduleID)
                    .putString("name", obj.name)
                    .putInt("nodeID", obj.nodeID)
                    .putVec3("position", obj.position)
                    .putBoolean("rnIDsValid", obj.rnIDsValid)
                    .putBoolean("roadCoordValid", obj.roadCoordValid)
                    .putVec3("rotation", obj.rotation)
                    .putDouble("s", obj.s)
                    .putArray("type", type)
                    .putDouble("v", obj.v)
                    .putDouble("xMax", obj.xMax)
                    .putDouble("yMax", obj.yMax)
                    .putDouble("zMax", obj.zMax)
                    .putDouble("xMin", obj.xMin)
                    .putDouble("yMin", obj.yMin)
                    .putDouble("zMin", obj.zMin);

                objects.add(entry);
            }

            JsonObject data = new JsonObject();
            data.putArray("odbObjects", objects);

            JsonObject msg = new JsonObject();
            msg.putString("type", "odb")
                .putString("version", "0.0")
                .putObject("data", data);

            return msg.toString();
        } catch (Exception e) {
            SILAB.logErr("odb query failed: " + e.getMessage());
            return "{ 'error': { 'code': 501, 'message': 'failed to query odb: " + e.getMessage() + "' } }";
        }
    }

    private String startAutomation() {
        SILAB.logSys("should start automation");

		ShouldAutomationActive = 1;
		ShouldStandstill = 0;

        // We can record the intent, but the automation framework only actually
        // engages if it is "available" at the car's current position. If it is
        // not available, the start is silently ignored by the framework, so we
        // report success=false and explain why instead of a misleading true.
        boolean available = AutomationAvailable != 0;

        JsonObject data = new JsonObject();
        data.putBoolean("success", available)
            .putBoolean("available", available)
            .putInt("availability", AutomationAvailable)
            .putBoolean("active", AutomationActive != 0);
        if (!available) {
            data.putString("reason", "automation not available at current position "
                + "(check cfg_available / cfg_hh_available_ignore and availability hedgehogs)");
        }

        JsonObject msg = new JsonObject();
        msg.putString("type", "start")
            .putString("version", "0.0")
            .putObject("data", data);

        return msg.toString();
    }


    private String stopAutomation() {
        SILAB.logSys("should stop automation");

		ShouldStandstill = 1;

        JsonObject data = new JsonObject();
        data.putBoolean("success", true);

        JsonObject msg = new JsonObject();
        msg.putString("type", "stop")
            .putString("version", "0.0")
            .putObject("data", data);

        return msg.toString();
    }

    private String makeAutomationMessage() {
        // AutomationActive is a VarIn connected to
        // ~Automation_Framework_LfE.active_lat_and_long (see Server_config.inc),
        // so it reflects whether the driving automation (ADAS) is currently on.
        JsonObject data = new JsonObject();
        data.putBoolean("active", AutomationActive != 0)
            .putInt("automationActive", AutomationActive)
            .putInt("automationStandstill", AutomationStandstill)
            .putBoolean("available", AutomationAvailable != 0)
            .putInt("availability", AutomationAvailable);

        JsonObject msg = new JsonObject();
        msg.putString("type", "automation")
            .putString("version", "0.0")
            .putObject("data", data);

        return msg.toString();
    }

	private void checkForStandStill() {
        try {
            standstillQuery.transform(X, Y, Yaw);
            standstillQuery.update();
			ShouldHold = getShouldHold();
        } catch (Exception e) {
            SILAB.logErr("standstill query failed: " + e.getMessage());
        }
    }

	private int getShouldHold() {
		for (ODBObject obj : standstillQuery) {
			if (isRedTrafficLight(obj.type)) {
				return 1;
			}
		}

		return 0;
	}

	private boolean isRedTrafficLight(int[] type) {
		boolean isTrafficLight = type[0] == 1 && type[1] == 6 && type[4] == 1;
		if (!isTrafficLight) {
			return false;
		}

		boolean isRed = type[3] == 3 || type[3] == 6;
		return isRed;
	}

	private boolean isPedestrian(int[] type)  {
		return type[0] == 1 || type[1] == 7;
	}

    private String makeError(int code, String message) {
        JsonObject error = new JsonObject();
        error.putInt("code", code)
            .putString("message", message);

        JsonObject data = new JsonObject();
        data.putObject("error", error);

        JsonObject msg = new JsonObject();
        msg.putString("type", "error")
            .putString("version", "0.0")
            .putObject("data", data);

        return msg.toString();
    }

    private JsonObject makeLightState(TRFObject obj) {
        JsonObject out = new JsonObject();
        out.putBoolean("backLight", obj.getLightState(TRFLightState.BackLight))
            .putBoolean("brakeLight", obj.getLightState(TRFLightState.BrakeLight))
            .putBoolean("frontLight", obj.getLightState(TRFLightState.FrontLight))
            .putBoolean("greenLight", obj.getLightState(TRFLightState.GreenLight))
            .putBoolean("leftBackLight", obj.getLightState(TRFLightState.LeftBackLight))
            .putBoolean("leftBrakeLight", obj.getLightState(TRFLightState.LeftBrakeLight))
            .putBoolean("leftFrontLight", obj.getLightState(TRFLightState.LeftFrontLight))
            .putBoolean("leftIndicator", obj.getLightState(TRFLightState.LeftIndicator))
            .putBoolean("redLight", obj.getLightState(TRFLightState.RedLight))
            .putBoolean("rightBackLight", obj.getLightState(TRFLightState.RightBackLight))
            .putBoolean("rightBrakeLight", obj.getLightState(TRFLightState.RightBrakeLight))
            .putBoolean("rightFrontLight", obj.getLightState(TRFLightState.RightFrontLight))
            .putBoolean("rightIndicator", obj.getLightState(TRFLightState.RightIndicator))
            .putBoolean("yellowIndicatorLight", obj.getLightState(TRFLightState.YellowIndicatorLight))
            .putBoolean("yellowLight", obj.getLightState(TRFLightState.YellowLight));

        return out;
    }

    private String mapObjectType(TRFObjectType type) {
        switch (type) {
            case OBSTACLE:
                return "obstacle";
            case OTHER:
                return "other";
            case ROADUSER:
                return "roaduser";
            case SIMCAR:
                return "simcar";
            case TRAFFICLIGHT:
                return "trafficlight";
            case VEHICLE:
                return "vehicle";
            default:
                return "unknown";
        }
    }

	public int getDebugLevel() {
		return JPU.DEBUG_ALL;
	}
}

class JsonArray {
    private ArrayList<String> entries = new ArrayList<String>();

    public JsonArray add(JsonObject obj) {
        entries.add(obj.toString());
        return this;
    }

    public JsonArray addVec2(Vec2 vec) {
        JsonObject o = new JsonObject();
        o.putDouble("x", vec.x).putDouble("y", vec.y);
        return add(o);
    }

    public JsonArray addInt(int i) {
        entries.add("" + i);
        return this;
    }

    public String toString() {
        String buf = "[";
        buf += String.join(",", entries);
        buf += "]";
        return buf;
    }
}

class JsonObject {
    private ArrayList<String> entries = new ArrayList<String>();

    public JsonObject putString(String key, String value) {
        String entry = "\"" + value + "\"";
        return addEntry(key, entry);
    }

    public JsonObject putDouble(String key, double value) {
        return addEntry(key, "" + value);
    }

    public JsonObject putInt(String key, int value) {
        return addEntry(key, "" + value);
    }

	public JsonObject putLong(String key, long value) {
        return addEntry(key, "" + value);
    }

    public JsonObject putBoolean(String key, boolean value) {
        return addEntry(key, value ? "true" : "false");
    }

    public JsonObject putVec(String key, double x, double y, double z) {
        JsonObject vec3 = new JsonObject();
        vec3.putDouble("x", x)
            .putDouble("y", y)
            .putDouble("z", z);
        return putObject(key, vec3);
    }

    public JsonObject putObject(String key, JsonObject obj) {
        return addEntry(key, obj.toString());
    }

    public JsonObject putArray(String key, JsonArray arr) {
        return addEntry(key, arr.toString());
    }

    public JsonObject putVec2(String key, Vec2 vec) {
        JsonObject o = new JsonObject();
        o.putDouble("x", vec.x).putDouble("y", vec.y);
        return putObject(key, o);
    }

    public JsonObject putVec3(String key, Vec3 vec) {
        return putVec(key, vec.x, vec.y, vec.z);
    }

    public JsonObject putGpsPos(String key, GPSPos gps) {
        JsonObject obj = new JsonObject();
        obj.putDouble("latitude", gps.getLatitude());
        obj.putDouble("longitude", gps.getLongitude());
        obj.putDouble("north", gps.getNorth());
        obj.putDouble("east", gps.getEast());
        obj.putDouble("heading", gps.getHeading());
        return putObject(key, obj);
    }

    public String toString() {
        String buf = "{";
        buf += String.join(",", entries);
        buf += "}";
        return buf;
    }

    private JsonObject addEntry(String key, String value) {
        String entry = "\"" + key + "\":" + value;
        entries.add(entry);
        return this;
    }
}
