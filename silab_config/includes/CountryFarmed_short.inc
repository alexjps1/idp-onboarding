	define Module CountryFarmed
	{
		ModuleID = 10102;

		define Course CF1_1
		{
			NodeID = 101021;
			CrossSection = NarrowRoad_Meadow;

			Straight(350);
			Bend    (220, 580);
			Bend    (205, -550);
			Straight(200);
			Bend    (170, 490);
			Straight(310);

			# bis hierhin 1455 m

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 100.0, 3000),
				(2.0, 240.0,  3000),
				(4.0, 320.0,  3000),
				(-3 , 190.0,  3000),
				(-4 , 280.0,  3000),
				(0.0, 325.0,  3000)
			};

			LandscapeTypeLeft Farmed
			{
				Height = (1, 3);
				Ripple = 0.1;
				Offset = 0;
				OverlayDensity = (0.7, 0.9);
				TreeDensity = (1, 2);
				#GadgetDensity = (1, 3);
				FieldDensity = 5;
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
				GadgetDensity = (0, 2);
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
			NodeID = 101022;
			CrossSection = NarrowRoad_Meadow_smooth;


			# scharfe Kurve bei 1455 m
			Bend    (170, 90);


			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
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
				GadgetDensity = (0, 2);
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
				(sign.Middle625_20, 90, -4.5, 0),

				(models.lake_farmed, 160, -80, 0)
			};
		};


		define Course CF1_3
		{
			NodeID = 101023;
			CrossSection = NarrowRoad_Meadow;

			# 1625m
			Straight(50);
			# Gegenkurve bei 1675 m
			Bend    (180, -95);
			Straight(320);
			Bend    (125, -700);
			# bis hierhin 2300 m

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 75.0,  1600),
				(3.0, 500.0,  1400),
				(0.0, 100.0, 1000)
			};

			LandscapeTypeLeft Farmed
			{
				Height = (1, 3);
				Ripple = 0.1;
				Offset = 1;
				OverlayDensity = (0.7, 0.9);
				TreeDensity = (1, 2);
				GadgetDensity = (1, 3);
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
				TreeDensity = (0.7, 2);
				GadgetDensity = (0, 2);
				MinObjdist = 10;
				MaxObjdist = 500;
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
				(sign.sign150_274_080, 600, -4, 180)
			};
		};


		CF1_1 uf1;
		CF1_2 uf12;
		CF1_3 uf13;

		# Es werde Nacht!
		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)
			(uf1, 1000, DontCare, 0, Night, Night, 1.0), #Nacht
			(uf1, 1000, DontCare, 1, Night, Night, 1.0), #Nacht

			(uf1, 1000, DontCare, 0, Env, CRTimeOfDay, 0.1, TimeOfDay, 0.0),
			(uf1, 1000, DontCare, 1, Env, CRTimeOfDay, 0.1, TimeOfDay, 0.0),
			(uf1,1,Normal,1, Scenario, Name, "SILABDemo Überland",
				Number, 1010100, State, 0, ActivateLateral,0, ActivateSpeed,0, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(uf1,1,Reverse,0, Scenario, Name, "SILABDemo Überland",
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
				Vehicle = PorscheBoxter_mint;
				Position = (uf1, 180, 1);
				Behaviour = {(SimCarLocked), (EXSTDDVR, 40, 45)};

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
				Vehicle = MiniCooper_yellow;
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
				Behaviour = {(HazardFree, 45, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(uf1,1 , 1, SimCar, Activate)
				};
			};
			Vehicle gegen2
			{
				Vehicle = CarVan;
				Position = (uf1, 650, 0);
				Behaviour = {(HazardFree, 35, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(uf1,1 , 1, SimCar, Activate)
				};
			};
			Vehicle gegen3
			{
				Vehicle = Car;
				Position = (uf1, 680, 0);
				Behaviour = {(HazardFree,25, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(uf1,1 , 1, SimCar, Activate)
				};
			};
			Vehicle gegen4
			{
				Vehicle = BUSPolizei;
				Position = (uf1, 880, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(uf1,1 , 1, SimCar, Activate)
				};
			};
	};
};
