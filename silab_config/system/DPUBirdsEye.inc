
	DPUBirdsEye bev
	{
		Computer = { BEV };
		Index = 100;  # nach allem

		# Breite, Höhe, und Position des Fensters
		WindowW = 960;
		WindowH = 1080;
		#WindowX = -1920;
		#WindowY = -1200;
		WindowX = 0; #-1920; <-- wieder auf -1920, falls auf FS-OBSERVER der Bildschirm rechts unten als Hauptanzeige ausgewählt wird, 0 falls Bildschirm oben in der Mitte die Hauptanzeige ist!
		WindowY = 0;
		# Größe des dargestellten Ausschnitts aus der Datenbasis
		SizeY = 500;
		
		NoParamWarnings = true;
		
		RenderOffscreen = true;
		
		DrawTRFBB = false;
		DrawTRFBBCollision = false;
		DrawHedgehogs = true;
		DrawHedgehogText = true;
		DrawTRFScanBox = false;
		DrawTRFScanBoxCollision = false;
		DrawTRFLights = true;
		DrawPCCurrentNodesText = true;
		DrawPCPositionText = true;
		DrawPCTACurvText = false;
		DrawPCSText = true;
		DrawPCHeadingText = false;
		DrawPCPsiText = false;
		DrawPCOrientationText = true;
		DrawRefCurveInfoText = true;
		DrawTRFScanBox = true;
		DrawTRFScanBoxCollision = true;
		DrawCourseLanes = true;
		DrawArea = true;
		DrawAreaLanes = true;
		DrawArea2Lanes = true;
		DrawVisObjects = true;
		DrawLGVisObjects = true;
		DrawRoad = true;
		DrawRoadBorder = true;
		
	};
	Connections =
	{
		VDyn.X <-> bev.X,
		VDyn.Y <-> bev.Y,
		VDyn.yaw <-> bev.yaw
	};



