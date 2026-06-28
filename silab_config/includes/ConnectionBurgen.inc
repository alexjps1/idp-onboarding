	define Module ConnectionBurgen
	{
		ModuleID = 10702;

		define Course U1
		{
			NodeID = 107021;
			CrossSection = CountryRoad;
      	  	Overlay = {TarOld3, 1};

			Bend(120, -880);
			Bend(80, 790);

			HeightProfile =
			{
				# Steigung/Gef‰lle, L‰nge, Ausrundungshalbmesser
				(0.0,  30.0, 700),
				(7.0, 140.0, 700),
				(0.0,  30.0, 700)
			};

			LandscapeTypeLeft Inhabited
			{
				Height = (1, 2);
				Ripple = (0.3, 0.5);
				Offset = (-3, -1);
				Gradient = -0.1;
				OverlayDensity = (0.3, 0.5);

				SmallTreeDensity = (2, 3);
				HouseDensity = (0.5, 0.8);
				MinObjdist = 10;
				MaxObjdist = 400;
			};
			# Dekoration des Straﬂenrands links
			Object Grassland
			{
				Orientation = Towards;
				YOffset = -3.8;
				Distance = 4.5;
			};
			LandscapeTypeExtra Alley1 {
				Left = true;
				MinObjdist = 5;
				MaxObjdist = 22;
				MinObjpos = 30;
				MaxObjpos = 180;
			};
			LandscapeTypeExtra Grassland
			{
				Left = true;
				MinObjdist = 2.5;
				MaxObjdist = 25;
				Override = { Tree, User, Road };
			};

			LandscapeTypeRight Inhabited
			{
				Height = (2, 3);
				Ripple = (0.3, 0.5);
				Offset = (0, 1);
				Gradient = 0.06;
				OverlayDensity = (0.3, 0.5);

				SmallTreeDensity = (1, 3);
				HouseDensity = (0.3, 0.8);
				MinObjdist = 10;
				MaxObjdist = 400;
			};
			# Dekoration des Straﬂenrands rechts
			Object Grassland
			{
				Orientation = Onwards;
				YOffset = 3.8;
				Distance = 4.5;
			};
			LandscapeTypeExtra Alley2 {
				Left = false;
				MinObjdist = 56;
				MaxObjdist = 73;
				MinObjpos = 30;
				MaxObjpos = 180;
			};
			LandscapeTypeExtra Grassland
			{
				Left = false;
				MinObjdist = 2.5;
				MaxObjdist = 25;
				Override = { Tree, User, Road };
			};

			TrafficRules T
			{
				Sign sa	{	Sign = ("274_070"); s = 30; d = 4;	};
				Sign sa	{	Sign = ("274_070"); s = 30; d = -4;	};
			};
		};

		include parts\TownBurgen_22_Area2.cfg
		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)
			(u1,190,Normal,1, Scenario, Name, "Ortschaft",
				Number, 1070200, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(u1,190,Reverse,0, Scenario, Name, "Ortschaft",
				Number, 1070200, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1)
		};

		include parts\TownBurgen_22_TRF.cfg

		U1 				u1;
		TownBurgen	 	TownBurgen;

		Connections =
		{
			u1.Begin <-> Port1,
			u1.End <-> TownBurgen.Port1,
			TownBurgen.Port2 <-> Port2
		};
	};
