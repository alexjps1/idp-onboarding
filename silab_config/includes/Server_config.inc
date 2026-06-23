## The SilabServer jpu starts a socket server on the specified port, which can be used to load Silab trf, scn and odb data from any application.
## This server is required by the RoboTaxi Go server to load traffic information.
## Make sure the SilabServer.java file is placed in the <project>/java directory.

SCN.ODB = true;
TRF.ODB = true;
MOV.ODB = true;

DPUJava SilabServer
{
    Computer = {ASS};
    Index = 999;

    Class = SilabServer;
};

Connections =
{
	VDyn.X -> SilabServer.X,
	VDyn.Y -> SilabServer.Y,
	VDyn.yaw -> SilabServer.Yaw,

    ~Automation_Framework_LfE.active_lat_and_long -> SilabServer.AutomationActive,
	~Automation_Framework_LfE.standstill -> SilabServer.AutomationStandstill,
	~Automation_Framework_LfE.hh_available -> SilabServer.AutomationAvailable

    # --- Actuation disabled: read-only server (option B) ---
    # The two impulse outputs below DRIVE the automation framework. While they are
    # connected, tickFlanks() in SilabServer.java continuously forces the framework
    # to match ShouldAutomationActive (default 0), which switches off any manual
    # activation in the simulator. They are commented out so the server only
    # OBSERVES automation state (the reads above) and no longer fights manual use.
    #
    # To re-enable TCP start/stop actuation later, uncomment both lines below (the
    # leading commas keep the connection list valid). Note: to allow manual AND TCP
    # control at the same time (option C), SilabServer.java also needs to stop
    # enforcing ShouldAutomationActive when no TCP command is pending.
    # , SilabServer.AutomationActiveImpulse -> ~Automation_Framework_LfE.sim_long_lat_io
    # , SilabServer.AutomationStandstillImpulse -> ~Automation_Framework_LfE.sim_standstill
};
