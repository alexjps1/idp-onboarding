			DPUSCNX SCNX
			{
				Alias = {SCN};
				Computer = {SCN,BEV};
				Index = 40;
				TreeviewGroup~en = "Database";
				TreeviewGroup = "Datenbasis";
			};

			DPUSCNXSGE SCNXSGE
			{
				Alias = {SCNVis};
				Computer = {VIS};
				Index = 50;
				TreeviewGroup = "Visualisierung";
				TreeviewGroup~en = "Visualization";
			};
			DPUSCNXLaunch SCNXLaunch
			{
				Alias = {SCNLaunch};
				Computer = {OPERATOR};
				Index = 120;
				TreeviewGroup~en = "Database";
				TreeviewGroup = "Datenbasis";
			};
			Connections =
			{
				VDyn.X 			-> SCNX.X,
				VDyn.Y 			-> SCNX.Y,
				VDyn.Z 			-> SCNX.Z,
				VDyn.yaw 		-> SCNX.yaw,
				VDyn.pitch 		-> SCNX.pitch,
				VDyn.roll 		-> SCNX.roll,
				SCNX.PitchRoad 	-> VDyn.PitchRoad,
				SCNX.RollRoad 	-> VDyn.RollRoad,
				SCNX.XOffset 	-> VDyn.XOffset,
				SCNX.YOffset 	-> VDyn.YOffset,
				SCNX.ZOffset 	-> VDyn.ZOffset,
				SCNX.SetupX     -> VDyn.SetupX,
				SCNX.SetupY     -> VDyn.SetupY,
				SCNX.SetupZ     -> VDyn.SetupZ,
				SCNX.SetupYaw   -> VDyn.SetupYaw,
				SCNX.SetupPitch -> VDyn.SetupPitch,
				SCNX.SetupRoll  -> VDyn.SetupRoll,
				SCNX.SetupDone  -> VDyn.SetupDone
			};
