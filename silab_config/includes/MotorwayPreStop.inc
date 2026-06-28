	define Module MotorwayPreStop
	{
		ModuleID = 40101;

		define Course FreeDriving
		{
			NodeID = 401011;
			CrossSection = Motorway_7a;

			Bend (1200, 2000);

			TrafficRules T {
				Sign sa	{	Sign = ("274_130"); s = 120; d = 12;	};
				Sign sa	{	Sign = ("274_130"); s = 120; d = 0.5;	};
			};


			LandscapeTypeLeft Wooded
			{
				Height = (0, 0);
				Ripple = (0, 0);
				Offset = (0, 0);
				TreeDensity = (5, 8);
				MaxObjdist = 300;
				MinObjdist = 15;
			};
			# Deko links
			Object Meadow
			{
				Orientation = Towards;
				YOffset = -12.8;
				Distance = 4.5;
			};
			Strip Guardrail
			{
				Orientation = Towards;
				YOffset = -13;
			};
			LandscapeTypeExtra Wooded {
				Left = true;
				MinObjdist = 50;
				MaxObjdist = 120;
				MinObjpos = 80;
				MaxObjpos = 360;
				TreeDensity = 15;
			};

			# Deko mitte
			Object GrasslandHighway
			{
				Orientation = Onwards;
				YOffset = 0;
				Distance = 4.5;
			};
			LandscapeTypeExtra RoadsideBush {
				Left = true;
				MinObjdist = -13;
				MaxObjdist = -10;
				ObjDensity = 0.5;
			};

			LandscapeTypeRight Wooded
			{
				Height = (0, 0);
				Ripple = (0, 0);
				Offset = (0, 0);
				TreeDensity = (6, 6);
				MaxObjdist = 260;
				MinObjdist = 20;
			};
			# Deko rechts
			Object Grassland
			{
				Orientation = Onwards;
				YOffset = 12.8;
				Distance = 4.5;
			};
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 13;
			};
			LandscapeTypeExtra Grassland
			{
				Left = false;

				MinObjdist = 3.5;
				MaxObjdist = 25;

				Override = { Tree, User };
			};

			Objects = {
				(sign.Sign200_448_11~Wiesental_, 310, 15),
				(sign.Sign200_448_11_500~Wiesental_, 810, 15)
			};
		};

		FreeDriving			cfree1;					#1200m

		Hedgehogs =

		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)

			(cfree1,1,Normal,4, Scenario, Name, "Autobahn-Parkplatz",
				Number, 4010100, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cfree1,1,Normal,5, Scenario, Name, "Autobahn-Parkplatz",
				Number, 4010100, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cfree1,1,Normal,5, Scenario, Name, "Autobahn-Parkplatz",
				Number, 4010100, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1)
		};

		Connections =
		{
			Port1 <-> cfree1.Begin,
			cfree1.End <-> Port2
		};
	};
