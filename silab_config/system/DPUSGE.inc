			DPUSGEWorld SGEWorld
			{
				Computer = {VIS};
				Index = 20;
				Alias = {SIGWorld};
				TreeviewGroup = "Visualisierung";
				TreeviewGroup~en = "Visualization";

				G_NObjectsToInsRem = 100000;
			};
			DPUSGEView SGEView
			{
				Computer = {VIS};
				Index = 60;
				Alias = {SIGView};
				TreeviewGroup = "Visualisierung";
				TreeviewGroup~en = "Visualization";

				Threaded = 1;
				VerticalSync = true;
			};

			Connections =
			{
				VDynView.X 			-> SGEView.X,
				VDynView.Y 			-> SGEView.Y,
				VDynView.yaw 		-> SGEView.yaw,
				SCNX.ZOut 		-> SGEView.Z,
				VDynView.pitch 		-> SGEView.pitch,
				VDynView.roll 		-> SGEView.roll,
				SCNX.PitchRoad 	-> SGEView.pitchRoad,
				SCNX.RollRoad 	-> SGEView.rollRoad
			};

			# Nur noch für wenige Low-Level-Parameter
			# Den Rest macht das Environment
			DPUSGELightParams SGELight
			{
				Computer = {VIS};
				Index = 19;
				Alias = {SIGLight};
				TreeviewGroup = "Visualisierung";
				TreeviewGroup~en = "Visualization";
			};


			# Einbindung von Regen, Gewitter
			# Ansteuerung geht über Environment:
			# 	Precipitation (0..1)
			# 	Thunderstorm  (0..1)

			DPUSGEWeather SGEWeather
			{
				Computer = {VIS};
				Index = 55;
				Alias = {SIGWeather};
				TreeviewGroup = "Visualisierung";
				TreeviewGroup~en = "Visualization";

				Rain.ViewAngle = 40;

				Rain.MaxDensity = 20000;
			#	Rain.Color = 0.9;
				Rain.VolMax = 0.3;
				Rain.Speed = 20;
				Rain.Length = 0.7;
			};

			Connections =
			{
				VDyn.v -> SGEWeather.v,
				TRFX.Trafficdata -> SGEWeather.ExternalTimeStamp
			};

			DPUSCNXForesight SGEReflectOffset
			{
			Computer = {VIS};
				Index = 35;
				TreeviewGroup = "Visualisierung";
				TreeviewGroup~en = "Visualization";

				Distance = 60; # geschätzter typischer Vorausschauabstand des Fahrers
			};
			Connections =
			{
				SGEReflectOffset.ZOffset -> SGEView.CamRoadZOffset
			};
			VISM.SGEReflectOffset.Distance = -60; # bei Spiegelansicht schauen wir natürlich nach hinten...
