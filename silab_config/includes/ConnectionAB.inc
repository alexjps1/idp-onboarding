	define Module ConnectionAB
	{
		ModuleID = 10701;

		define Course U1
		{
			NodeID = 107011;
			CrossSection = CountryRoad;

			Bend(120, -880);
			Bend(80, 790);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
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

			Objects =
			{
				# Tunnel signs for the reverse direction
				# They don't fit if we're coming from the motorway track
				# so we'll rather omit them
				#(sign.sign150_327, 10, 4, 180),
				#(sign.sign150_327, 10, -4, 180)
			};

			TrafficRules T {
				Sign sa	{	Sign = ("274_070"); s = 30; d = 4;	};
				Sign sa	{	Sign = ("274_070"); s = 30; d = -4;	};
			};

		};

		include parts\TownA_22_Area2.cfg

		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)
			(u1,190,Normal,1, Scenario, Name, "Ortschaft",
				Number, 1070100, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(u1,190,Reverse,0, Scenario, Name, "Ortschaft",
				Number, 1070100, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1)
		};

		include parts\TownA_22_TRF.cfg

		U1 u1;
		TownA TownA;

		Connections =
		{
			u1.Begin <-> Port1,
			u1.End <-> TownA.Port1,
			TownA.Port2 <-> Port2
		};
	};
