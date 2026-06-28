      DPUBirdsEye bev
      {
			Computer = { MAIN };
			Index = 100;  # nach allem

			# Weitere Parameter!!!
			# WindowWHXY
			WindowW = 1000;
			WindowH = 1000;
			WindowX = 0;
			WindowY = 0;
			# SizeY
			SizeY = 100;

			# Grid
			DrawGrid = true;

			# MOVParameter
			DrawMovGraph     = true;
			DrawMovStartPos  = true;
			DrawMovSForce    = true;
			DrawMovObstacles = true;
			DrawMovArea      = true;
			DrawMovPersons   = true;

			MovDisplayPotential = 0;
			MovPotentialRange = 10;
			MovPotentialStep = 0.2;

			# SCNX Parameter
			DrawLandscape = false;
			DrawHFine = false;

			DrawHedgehogs = true;
			DrawHedgehogText = true;
			DrawHedgehogFamily = true;
			DrawHedgehogParams = true;
			DrawRefCurve = true;
			DrawRefCurveInfoText = true;
			DrawCourseLanes = true;
			DrawArea = true;
			DrawAreaLanes = true;
			DrawArea2Lanes = true;
			DrawArea2RVis = true;
			DrawPCCurrentNodesText = true;
			DrawPCPositionText = true;
			DrawPCTACurvText = true;
			DrawPCSText = true;
			DrawPCHeadingText = true;
			DrawPCPsiText = true;
			DrawPCOrientationText = true;

			DrawGazeVector = true;
			GazeAngle = 0.0;
			GazeVectorLength = 200.0;
			DrawLGVisObjects = true;
			DrawVisObjects = true;

			LandscapeColHeight = 10;
			LandscapeColClamp = true;

			# TRF Parameter
			DrawBB = true;
			DrawBBCollision = true;
			DrawScanBox = true;
			DrawScanBoxCollision = true;
			DrawSimCar = true;
         };
         Connections =
         {
			 VehicleDynamics.X <-> bev.X,
			 VehicleDynamics.Y <-> bev.Y,
			 VehicleDynamics.yaw <-> bev.yaw
		 };


