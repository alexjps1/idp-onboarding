	define Module MotorwayRoadWorks
	{
		ModuleID = 40201;

		define Course FreeDriving
		{
			NodeID = 402011;
			CrossSection = Motorway_7a;

			Bend (500, -4000);

			#Objects =
			#{
			#	(sign.sign200_274_130, 120, 12),
			#	(sign.sign200_274_130, 120, 0.5)
			#};
			TrafficRules T {
				Sign sa	{	Sign = ("274_130"); s = 120; d = 12;	};
				Sign sa	{	Sign = ("274_130"); s = 120; d = 0.5;	};
			};


			# Landschaft links
			LandscapeTypeLeft Farmed
			{
				Height = (0, 0);
				Ripple = (0, 0);
				Offset = (0, 0);
				Gradient = 0.04;
				OverlayDensity = (0.7, 0.9);
				MaxObjdist = 250;
				WaySetback = (7, 2);
			};
			# Deko links
			Object Meadow
			{
				Orientation = Towards;
				YOffset = -12.5;
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

			# Landschaft rechts
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

		};

		define Course FreeDriving_New  # identisch, aber neu geteert (nach der Baustelle)
		{
			NodeID = 402016;
			CrossSection = Motorway_7a;
        	Overlay = {TarNew3, 1};

			Bend (500, -4000);

			#Objects =
			#{
			#	(sign.sign200_274_130, 120, 12),
			#	(sign.sign200_274_130, 120, 0.5)
			#};
			TrafficRules T {
				Sign sa	{	Sign = ("274_130"); s = 120; d = 12;	};
				Sign sa	{	Sign = ("274_130"); s = 120; d = 0.5;	};
			};


			# Landschaft links
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

			# Landschaft rechts
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
		};

		include includes\MotorwayWorksEntry.inc
		include includes\MotorwayWorksExit.inc
		include parts\MotorwayWorksEntry_76_Area2.cfg
		include parts\MotorwayWorksExit_67_Area2.cfg
		include parts\Overpass_7722_Area2.cfg

		FreeDriving			cfree0;					#500m
		FreeDriving			cfree1;					#500m
		FreeDriving_New		cfree2;					#500m
													#c1_3a = 600m
		Overpass apass0;

		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)
			(cfree1,1,Normal,4, Scenario, Name, "Autobahn-Baustelle",
				Number, 4020100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cfree1,1,Normal,5, Scenario, Name, "Autobahn-Baustelle",
				Number, 4020100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cfree1,1,Normal,6, Scenario, Name, "Autobahn-Baustelle",
				Number, 4020100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),

			(cfree2,250,Normal,4, Scenario, State, 2),
			(cfree2,250,Normal,5, Scenario, State, 2),
			(cfree2,250,Normal,6, Scenario, State, 2)
		};

		Connections =
		{
			Port1 <-> cfree0.Begin,
			cfree0.End <-> cfree1.Begin,
			cfree1.End <-> c1_3a.Begin,
			c2_3a.Port2 <-> c1_4a.Begin,
			c3_4a.End <-> cfree2.Begin,
			cfree2.End <-> apass0.Port1,
			apass0.Port2 <-> Port2
		};

		Traffic	Verkehr
		{
			GlobalVehicle Global1
			{
				Vehicle = Car;
				Position = (c1_3a, 590,	5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 10, 18, 5, 2, 10, -14)
				};
				RoleNumber = 101;
				Type = 0;
				Flowpoints =
				{
					(cfree1, 1, 5, SimCar, ActivateVehicle,1.5),
					#(c3_4a, 530, 1, Traffic, TargetSpeed, 29),	#Course wird von hinten nach vorne durchfahren!
					#(c3_4a, 530, 2, Traffic, TargetSpeed, 29),
					#(c3_4a, 530, 3, Traffic, TargetSpeed, 29),

					(c3_4a, 5, 4, Traffic, TargetSpeed, 29),

					(cfree2, 1, 5,  Traffic, TargetSpeed, 40)
				};
			};

			GlobalVehicle Global2
			{
				Vehicle = Car;
				Position = (c1_3a, 400,	5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 8, 18, 5, 1, 10, -14)
				};
				RoleNumber = 102;
				Type = 0;
				Flowpoints =
				{
					(cfree1, 5, 5, SimCar, ActivateVehicle,1.5),
					#(c3_4a, 530, 1, Traffic, TargetSpeed, 29),	#Course wird von hinten nach vorne durchfahren!
					#(c3_4a, 530, 2, Traffic, TargetSpeed, 29),
					#(c3_4a, 530, 3, Traffic, TargetSpeed, 29),

					(c3_4a, 5, 4, Traffic, TargetSpeed, 29),

					(cfree2, 1, 5,  Traffic, TargetSpeed, 35),
					(cfree2, 300, 5,  Traffic, TargetSpeed, 45),
					(cfree2, 400, 5,  Traffic, TargetSpeed, 50),
					(cfree2, 490, 5, Traffic, ChangeLane, 4, 100)
				};
			};
			
			GlobalVehicle Global3
			{
				Vehicle = Car;
				Position = (c1_3a, 50,	4);
				Behaviour =
				{
					(DSM),
					(HazardFree, 3, 25, 5, 1, 10, -14)
				};
				RoleNumber = 104;
				Type = 0;
				Flowpoints =
				{
					(cfree0, 460, 5,SimCar, ActivateVehicle,1.5),
					(cfree2, 300, 4,  Traffic, ChangeLane, 5, 45),
					(cfree2, 400, 5,  Traffic, TargetSpeed, 50),
					(cfree2, 490, 5, Traffic, ChangeLane, 4, 100)
				};
			};
			
			GlobalVehicle Global4
			{
				Vehicle = Car;
				Position = (c1_3a, 55,	4);
				Behaviour =
				{
					(DSM),
					(HazardFree, 3, 25, 5, 1, 10, -14)
				};
				RoleNumber = 104;
				Type = 0;
				Flowpoints =
				{
					(cfree0, 460, 5,SimCar, ActivateVehicle,1.5),
					(cfree2, 300, 4,  Traffic, ChangeLane, 5, 45),
					(cfree2, 400, 5,  Traffic, TargetSpeed, 50),
					(cfree2, 490, 5, Traffic, ChangeLane, 4, 100)
				};
			};
			
			GlobalVehicle Global5
			{
				Vehicle = Car;
				Position = (c1_3a, 200,	5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 3, 25, 5, 2, 10, -14)
				};
				RoleNumber = 103;
				Type = 0;
				Flowpoints =
				{
					(cfree0, 460, 5, SimCar, ActivateVehicle,1.5),
					(cfree2, 300, 5,  Traffic, TargetSpeed, 45),
					(cfree2, 400, 5,  Traffic, TargetSpeed, 50),
					(cfree2, 490, 5, Traffic, ChangeLane, 4, 100)
				};
			};

			GlobalVehicle Global6
			{
				Vehicle = Car;
				Position = (cfree1,499,	5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 3, 25, 5, 1, 10, -14)
				};
				RoleNumber = 104;
				Type = 0;
				Flowpoints =
				{
					(cfree0, 460, 5,SimCar, ActivateVehicle,1.5),
					(cfree2, 300, 5,  Traffic, TargetSpeed, 45),
					(cfree2, 400, 5,  Traffic, TargetSpeed, 45),
					(cfree2, 490, 5, Traffic, ChangeLane, 4, 100)
				};
			};

			GlobalVehicle Global7
			{
				Vehicle = Car;
				Position = (c1_3a, 2,	4);
				Behaviour =
				{
					(DSM),
					(HazardFree, 3, 25, 5, 1, 10, -14)
				};
				RoleNumber = 104;
				Type = 0;
				Flowpoints =
				{
					(cfree0, 460, 5,SimCar, ActivateVehicle,1.5),
					(cfree2, 100, 4,  Traffic, ChangeLane, 5, 45),
					(cfree2, 400, 5,  Traffic, TargetSpeed, 50),
					(cfree2, 490, 5, Traffic, ChangeLane, 4, 100)
				};
			};


			GlobalVehicle Global8_linkshinten1
			{
				Vehicle = Car;
				Position = (cfree1,1,	4);
				Behaviour =
				{
					(DSM),
					(HazardFree, 50, 40, 5, 1, 10, -14)
				};
				RoleNumber = 105;
				Type = 0;
				Flowpoints =
				{
					(cfree1, 400, 5,SimCar, ActivateVehicle,1.5),
					(c1_3a, 300, 4, Traffic, TargetSpeed, 28),
					(c1_3a, 450, 4,  Traffic, TargetSpeed, 27),
				#	(c3_4a, 590, 1, Traffic, TargetSpeed, 32),	#Course wird von hinten nach vorne durchfahren!
				#	(c3_4a, 590, 2, Traffic, TargetSpeed, 32),
				#	(c3_4a, 590, 3, Traffic, TargetSpeed, 32),

					(c3_4a, 5, 4, Traffic, TargetSpeed, 32),

					(cfree2, 20, 4, Traffic, TargetSpeed, 45),
					(cfree2, 420, 4, Traffic, TargetSpeed, 50)
				};
			};

			GlobalVehicle Global9_linkshinten2
			{
				Vehicle = Car;
				Position = (cfree0,200,4);
				Behaviour =
				{
					(DSM),
					(HazardFree, 50, 40, 5, 1, 10, -14)
				};
				RoleNumber = 109;
				Type = 0;
				Flowpoints =
				{
					(cfree1, 11, 5,SimCar, ActivateVehicle,1.5),
					(c1_3a, 300, 4, Traffic, TargetSpeed, 28),
					(c1_3a, 450, 4,  Traffic, TargetSpeed, 26),
					#(c3_4a, 590, 1, Traffic, TargetSpeed, 30),	#Course wird von hinten nach vorne durchfahren!
					#(c3_4a, 590, 2, Traffic, TargetSpeed, 30),
					#(c3_4a, 590, 3, Traffic, TargetSpeed, 30),

					(c3_4a, 5, 4, Traffic, TargetSpeed, 32),

					(cfree2, 2, 4, Traffic, TargetSpeed, 50)
				};
			};

			GlobalVehicle Global10_linkshinten3
			{
				Vehicle = Car;
				Position = (cfree0,200,4);
				Behaviour =
				{
					(DSM),
					(HazardFree, 50, 40, 5, 1, 10, -14)
				};
				RoleNumber = 110;
				Type = 0;
				Flowpoints =
				{
					(cfree1, 430, 5,SimCar, ActivateVehicle,1.5),
				#	(c1_3a, 300, 4, Traffic, TargetSpeed, 28),
					(c1_3a, 450, 4,  Traffic, TargetSpeed, 28),
				#	(c3_4a, 530, 1, Traffic, TargetSpeed, 30),	#Course wird von hinten nach vorne durchfahren!
				#	(c3_4a, 530, 2, Traffic, TargetSpeed, 30),
				#	(c3_4a, 530, 3, Traffic, TargetSpeed, 30),

					(c3_4a, 5, 4, Traffic, TargetSpeed, 32),

					(cfree2, 200, 4, Traffic, TargetSpeed, 50)
				};
			};

			Vehicle PKWhinterSIMCAR
			{
				Vehicle = Car;
				Position = (cfree0,200,	5);
				Behaviour = {(HazardFree, 45, 35, 5, 2.5, 10, -14)};

				Flowpoints =
				{
					(cfree1, 40, 5, SimCar, Activate),
					(cfree1, 490, 5, Traffic, TargetSpeed, 20),
					(c3_4a, 5, 5, Traffic, TargetSpeed, 29),
					(cfree2, 1, 5,  Traffic, TargetSpeed, 40)
				};
			};

			Vehicle LKWhinterSIMCAR
			{
				Vehicle = Car;
				Position = (cfree0,100,	5);
				Behaviour = {(HazardFree, 33, 33, 5, 2.5, 10, -14)};

				Flowpoints =
				{
					(cfree1, 40, 5,SimCar,Activate)
				};
			};

			
#######################				Panne					######################

			Vehicle Panne1
			{
				Position = (cfree1, 460, 6);
				Vehicle = Car;

				Behaviour = {(HazardFree, 0, 0, 5, 0.8, 10, -14)};
				Flowpoints =
				{
					(cfree0, 300, 0, SimCar, Activate),
					(cfree1, 11, 1, Traffic, AutoIndicatorLightControl, 0),
					(cfree1, 12, 0, SimCar, IndicatorLeft,1),
					(cfree1, 13, 0, SimCar, IndicatorRight,1)
				};
			};
			
			Vehicle Panne2
			{
				Position = (cfree1, 470, 6);
				Vehicle = IvecoDaily_TowTruck;

				Behaviour = {(HazardFree, 0, 0, 5, 0.8, 10, -14)};
				Flowpoints =
				{
					(cfree0, 300, 0, SimCar, Activate),
					(cfree1, 11, 1, Traffic, AutoIndicatorLightControl, 0),
					(cfree1, 12, 0, SimCar, IndicatorLeft,1),
					(cfree1, 13, 0, SimCar, IndicatorRight,1)
				};
			};

			TrafficFlow Gegenverkehr
			{
				Source GegenSpur1
				{
					Position =(SimCar, -800, 1);

					Vehicles =
					{
						(2, TruckMotorway, (HazardFree, 20, 25, 5, 1, 10, -14))
					};

					Parameters = (Gauss, 3,1, 451,512);
				};

				Drain GegenSpur11
				{
					Position = (SimCar, 720, 1);
				};

				Flowpoints=
				{
					(cfree1, 2, 5, SimCar, ActivateSource, (GegenSpur1)),
					(cfree1, 1, 5, SimCar, ActivateDrain, (GegenSpur11)),
					(cfree1, 250, 5, SimCar, DeactivateSource, (GegenSpur1)),
					(cfree1, 250, 5, SimCar, DeactivateSource, (GegenSpur11))
				};
			};

			TrafficFlow Gegenverkehr2
			{
				Source GegenSpur2
				{
					Position =(SimCar, -700, 2);

					Vehicles =
					{

						(1, Car, (HazardFree, 30, 35, 5, 1, 10, -14)),
						(1, Motorbike, (HazardFree, 35, 40, 5, 1, 10, -14)),
						(1, Car, (HazardFree, 30, 35, 5, 1, 10, -14))
					};

					Parameters = (Gauss, 3,1, 451,512);
				};

				Drain GegenSpur22
				{
					Position = (SimCar, 720, 2);
				};

				Flowpoints=
				{
					(cfree1, 2, 5, SimCar, ActivateSource, (GegenSpur2)),
					(cfree1, 1, 5, SimCar, ActivateDrain, (GegenSpur22)),
					(cfree1, 250, 5, SimCar, DeactivateSource, (GegenSpur2)),
					(cfree1, 250, 5, SimCar, DeactivateSource, (GegenSpur22))
				};
			};			
		};
	};
