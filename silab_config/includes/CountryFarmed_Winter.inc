	define Module CountryFarmed
	{
		ModuleID = 10101;

		define Course CF1_1
		{
			NodeID = 101011;
			CrossSection = CountryRoad;

			Straight(350);
			Bend    (220, 580);
			Bend    (205, -550);
			Straight(200);
			Bend    (170, 490);
			Straight(310);

			# bis hierhin 1455 m

			HeightProfile =
			{
				# Steigung/Gef‰lle, L‰nge, Ausrundungshalbmesser
				(0.0, 100.0, 1000),
				(2.0, 240.0,  700),
				(4.0, 320.0,  800),
				(-3 , 190.0,  500),
				(-4 , 280.0,  700),
				(0.0, 325.0,  600)
			};

			LandscapeTypeLeft Farmed
			{
				Height = (1, 3);
				Ripple = 0.1;
				Offset = 0;
				OverlayDensity = (0.7, 0.9);
				TreeDensity = (1, 2);
				GadgetDensity = 0;
				MinObjdist = 10;
				MaxObjdist = 500;
			};

			LandscapeTypeRight Farmed
			{
				Height = (1, 3);
				Ripple = (0.1, 0.3);
				Offset = (0.5, 1);
				Gradient = 0.04;
				OverlayDensity = (0.7, 0.9);
				TreeDensity = (0.7, 2);
				GadgetDensity = 0;
				FieldDensity = 5;
				MinObjdist = 15;
				MaxObjdist = 500;
			};

			TrafficRules T {
				Sign sa	{	Sign = ("274_080"); s = 10; d = 4;	};
			};


			Objects =
			{
				# Schilder Anfang
				#(sign.sign150_274_080, 10, 4, 0),
				# Schilder Kurve
				(sign.sign150_105_20, 1400, 4, 0),

				# Wege
				(environment.road.gravel_road_50, 300, -29.2),
				(environment.road.gravel_road_50, 300, -79.2),
				(environment.road.gravel_road_50, 300, -129.2),
				(environment.road.gravel_road_50, 300, -90, 90, -127),
				(environment.road.gravel_road_50, 300, -90, 90, -77),
				(environment.road.gravel_road_50, 300, -90, 90, -27),
				(environment.road.gravel_road_50, 300, -80, 90, 27),
				(environment.road.gravel_road_50, 300, -80, 90, 77),
				(environment.road.gravel_road_50, 300, -80, 90, 127),

				(environment.road.gravel_road_50, 530, -29.2),
				(environment.road.gravel_road_50, 530, -79.2),
				(environment.road.gravel_road_50, 530, -129.2),
				(environment.road.gravel_road_50, 530, -91, 90, -77),
				(environment.road.gravel_road_50, 530, -91, 90, -27),
				(environment.road.gravel_road_50, 530, -88, 90, 27),
				(environment.road.gravel_road_50, 530, -88, 90, 77),


				(environment.road.gravel_road_50, 900, -29.2),
				(environment.road.gravel_road_50, 900, -79.2),
				(environment.road.gravel_road_50, 900, -129.2),
				(environment.road.gravel_road_50, 900, -95, 90, -127),
				(environment.road.gravel_road_50, 900, -95, 90, -77),
				(environment.road.gravel_road_50, 900, -95, 90, -27),
				(environment.road.gravel_road_50, 900, -80, 90, 27),
				(environment.road.gravel_road_50, 900, -80, 90, 77),
				(environment.road.gravel_road_50, 900, -80, 90, 127),

				(environment.road.gravel_road_50,1135, -29.2),
				(environment.road.gravel_road_50,1135, -79.2),
				(environment.road.gravel_road_50,1135, -129.2),
				(environment.road.gravel_road_50,1135, -91, 90, -77),
				(environment.road.gravel_road_50,1135, -91, 90, -27),
				(environment.road.gravel_road_50,1135, -91, 90, 27),
				(environment.road.gravel_road_50,1135, -91, 90, 77)
			};

		};

		define Course CF1_2
		{
			NodeID = 101012;
			CrossSection = CountryRoad_smooth;


			# scharfe Kurve bei 1455 m
			Bend    (170, 90);


			HeightProfile =
			{
				# Steigung/Gef‰lle, L‰nge, Ausrundungshalbmesser
				(0.0, 170.0, 1000)

			};

			LandscapeTypeLeft Wooded
			{
				Height = 1;
				Ripple = 1;
				Offset = 0;
				Gradient = 0;
				OverlayDensity = 0.9;
				TreeDensity = 10;
				MinObjdist = 10;
				MaxObjdist = 250;
				MaxHillDist = 200;
			};

			LandscapeTypeRight Farmed
			{
				Height = (1, 3);
				Ripple = (0.1, 0.3);
				Offset = 0;
				Gradient = 0.04;
				OverlayDensity = (0.7, 0.9);
				TreeDensity = (0.7, 2);
				GadgetDensity = 0;
				MinObjdist = 10;
				MaxObjdist = 500;
			};

			Objects =
			{
				(sign.Middle625_20, 15, -4.5, 0),
				(sign.Middle625_20, 30, -4.5, 0),
				(sign.Middle625_20, 45, -4.5, 0),
				(sign.Middle625_20, 60, -4.5, 0),
				(sign.Middle625_20, 75, -4.5, 0),
				(sign.Middle625_20, 90, -4.5, 0)
			};

			# Guardrail linke Straﬂenseite
			Strip Guardrail
			{
				Orientation = Towards;
				YOffset = -4.6;

				Entry = 0;
				Start= 5;
				End = 165;
				Exit = 170;
			};

			# SCHLOSSPARK
			LandscapeTypeExtra Hedge {
				Left = true;
				Objdist = (8, 2);
				MinObjdist = 45;
				MaxObjdist = 130;
				MinObjpos = 140;
				MaxObjpos = 160;
				Objangle = 0;
			};

		};


		define Course CF1_3
		{
			NodeID = 101013;
			CrossSection = CountryRoad;

			# 1625m
			Straight(50);
			# Gegenkurve bei 1675 m
			Bend    (180, -95);
			Straight(320);
			Bend    (125, -700);
			# bis hierhin 2300 m

			HeightProfile =
			{
				# Steigung/Gef‰lle, L‰nge, Ausrundungshalbmesser
				(0.0, 75.0,  600),
				(3.0, 500.0,  400),
				(0.0, 100.0, 1000)
			};

			LandscapeTypeLeft Inhabited
			{
				Height = (1, 3);
				Ripple = 0.1;
				Offset = 1;
				OverlayDensity = (0.7, 0.9);
				HouseDensity = 0;
				MinObjdist = 10;
				MaxObjdist = 500;
			};

			LandscapeTypeRight Farmed
			{
				Height = (1, 3);
				Ripple = (0.1, 0.3);
				Offset = (0, 1);
				Gradient = 0.04;
				OverlayDensity = (0.7, 0.9);
				TreeDensity = 0;
				GadgetDensity = 0;
				MinObjdist = 10;
				MaxObjdist = 500;
			};

			# Guardrail rechte Straﬂenseite
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 4.6;

				Entry = 50;
				Start= 55;
				End = 225;
				Exit = 230;
			};

			Objects =
			{
				(sign.sign150_105_10, 275, -4, 180),
				(sign.Middle625_20, 215,  4.5, 180),
				(sign.Middle625_20, 200,  4.5, 180),
				(sign.Middle625_20, 185,  4.5, 180),
				(sign.Middle625_20, 170,  4.5, 180),
				(sign.Middle625_20, 155,  4.5, 180),
				(sign.Middle625_20, 140,  4.5, 180),
				# Schilder Ende
				(sign.sign150_274_080, 600, -4, 180),

				# SCHLOSS
				(house.Buerohaus4_a, 	10, -70,  0, -22),
				(house.Buerohaus4_a, 	10, -70,  0,  22),
				(house.Buerohaus4_a, 	10, -77, 90,   0),
				(area2.walls.hecke4_25, 10, -40,  0, -23),
				(area2.walls.hecke4_25, 10, -40,  0,  23),
				(area2.walls.hecke4_25, 10, -40,  0, -48),
				(area2.walls.hecke4_25, 10, -40,  0,  48),
				(area2.walls.hecke4_25, 10, -52.5, 90, -60.5),
				(area2.walls.hecke4_25, 10, -52.5, 90,  60.5),
				(area2.walls.hecke4_25, 10, -77.5, 90, -60.5),
				(area2.walls.hecke4_25, 10, -77.5, 90,  60.5),
				(area2.walls.hecke4_25, 10, -102.5, 90, -60.5),
				(area2.walls.hecke4_25, 10, -102.5, 90,  60.5),
				(area2.walls.hecke4_25, 10, -127.5, 90, -60.5),
				(area2.walls.hecke4_25, 10, -127.5, 90,  60.5),
				# ZUFAHRT
				(environment.road.gravel_road_50, 10, -29.2),
				(environment.lgfarmed.tree14a, 10, -10, 0, -7),
				(environment.lgfarmed.tree14b, 10, -21, 0, -7.5),
				(environment.lgfarmed.tree14c, 10, -33, 0, -7),
				(environment.lgfarmed.tree14d, 10, -11, 0,  7),
				(environment.lgfarmed.tree14a, 10, -23, 0,  6.5),
				(environment.lgfarmed.tree14b, 10, -35, 0,  7),

				# DORF
				(environment.road.gravel_road_50, 330, 29.2),
				(environment.road.gravel_road_50, 330, 79),
				(environment.road.gravel_road_50, 356, 100, 90)
			};

			# SCHLOSSPARK
			LandscapeTypeExtra Hedge {
				Left = true;
				Objdist = (12, 2);
				MinObjdist = 45;
				MaxObjdist = 130;
				MinObjpos = 0;
				MaxObjpos = 65;
				Objangle = 0;
			};

			# ALLEEN
			LandscapeTypeExtra Alley2 {
				Left = false;
				MinObjdist = 80;
				MaxObjdist = 105;
				MaxObjpos = 215;
			};

			LandscapeTypeExtra Alley2 {
				Left = false;
				Objangle = 0;
				MinObjdist = 10;
				MaxObjdist = 235;
				MinObjpos = 220;
				MaxObjpos = 245;
			};

			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 210;
				MaxObjdist = 235;
				MinObjpos = 300;
				MaxObjpos = 700;
			};

			LandscapeTypeExtra Alley2 {
				Left = true;
				Objangle = 0;
				MinObjdist = 20;
				MaxObjdist = 210;
				MinObjpos = 620;
				MaxObjpos = 645;
			};

			# Felder links (vor Allee)
			LandscapeTypeExtra Farmed
			{
				Left = true;

				FieldDensity = 10;

				MinObjdist = 60;
				MaxObjdist = 170;
				MinObjpos = 300;
				MaxObjpos = 620;
			};

			# DORF
			LandscapeTypeExtra AncientVillage
			{
				Left = false;

				AncientHouseDensity = 30;
				SmallTreeDensity = 30;

				MinObjdist = 40;
				MaxObjdist = 140;
				MinObjpos = 260;
				MaxObjpos = 420;
			};

			# FELDER rechts (neben Dorf)
			LandscapeTypeExtra Farmed
			{
				Left = false;

				FieldDensity = 10;

				MinObjdist = 60;
				MaxObjdist = 340;
				MinObjpos = 450;
				MaxObjpos = 620;
			};


		};


		CF1_1 uf1;
		CF1_2 uf12;
		CF1_3 uf13;

		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)
			(uf1,1,Normal,1, Scenario, Name, "SILABDemo ‹berland",
				Number, 1010100, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(uf1,1,Reverse,0, Scenario, Name, "SILABDemo ‹berland",
				Number, 1010100, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(uf12,1,Normal,1, Scenario, Name, "Panne in S-Kurve",
				Number, 1020100, State, 1, ActivateLateral,0, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(uf12,1,Reverse,0, Scenario, Name, "Panne in S-Kurve",
				Number, 1020100, State, 1, ActivateLateral,0, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(uf13,450,Normal,1, Scenario, State, 2),
			(uf13,450,Reverse,0, Scenario, State, 2)
		};

		Connections =
		{
			uf1.Begin <-> Port1,
			uf1.End <-> uf12.Begin,
			uf12.End <-> uf13.Begin,
			uf13.End <-> Port2
		};

		Traffic uf1
		{
			Vehicle ueberholt
			{
				Vehicle = PorscheMacan;
				Colour = mint;
				Dirt = 0.2;
				Position = (uf1, 180, 1);
				Behaviour = {(SimCarLocked), (HazardFree, 40, 45, 5, 0.5, 10, -14)};

				Flowpoints =
				{	(uf1, 400, 1, SimCar, Activate),
					(uf1, 800, 1, SimCar, LockDistance, -30),
					(uf1, 900, 1, SimCar, LockDistance, -20),
					(uf1, 1000, 1, SimCar, Light, 1),
					(uf1, 1050, 1, SimCar, Light, 0),
					(uf1, 1050, 1, SimCar, LockDistance, -30),
					(uf1, 1120, 1, SimCar, Unlock, ChangeLane, 0, 50),
					(uf13, 75, 0, SimCar, ChangeLane, 1, 300),
					(uf13, 85, 1, Traffic, TargetSpeed, 80, 7)
				};
			};

			Vehicle Ruckspiegel
			{
				Vehicle = Car;
				Position = (uf1, 150, 1);
				Behaviour = {(HazardFree, 30, 27, 5, 1, 10, -14)};

				Flowpoints =
				{
					(uf1, 400, 1, SimCar, Activate),
					#(uf1, 1540, 2, SimCar, ChangeLane, 1, 50),
					#(uf1, 1650, 1, SimCar, ChangeLane, 2, 50),
					(uf13, 400, 1, Traffic, Targetspeed, 0, 2, -2)
				};
			};


			Vehicle Panne
			{
				Vehicle = FiatPanda;
				Colour = yellow;
				Dirt = 0.7;
				Position = (uf12, 99, 1);
				Behaviour = {(HazardFree, 5, 2, 5, 3, 8, -10)};

				Flowpoints =
				{
					(uf1, 1, 1, SimCar, Activate),
					(uf12, 100, 1, Traffic, AutoIndicatorLightControl, 0),
					(uf12, 100, 1, Traffic, AutoBrakeLightControl, 0),
					(uf12, 101, 1, Traffic, IndicatorLeft,1),
					(uf12, 101, 1, Traffic, IndicatorRight,1),
					(uf12, 101, 1, Traffic, Brakelight, 0),
					(uf12, 115, 1, Traffic, Targetspeed, 0.00001, 3, -3),
					(uf13, 600, 1, SimCar, Deactivate)
				};
			};

			Vehicle gegen1
			{
				Vehicle = CarVan;
				Position = (uf1, 600, 0);
				Behaviour = {(HazardFree, 15,30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(uf1,1 , 1, SimCar, Activate)
				};
			};
			Vehicle gegen2
			{
				Vehicle = CarVan;
				Position = (uf1, 650, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(uf1,1 , 1, SimCar, Activate)
				};
			};
			Vehicle gegen3
			{
				Vehicle = Car;
				Position = (uf1, 680, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(uf1,1 , 1, SimCar, Activate)
				};
			};
	};
};
