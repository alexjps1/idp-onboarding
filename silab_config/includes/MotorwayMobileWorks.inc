	define Module MotorwayMobileWorks
	{
		ModuleID = 40301;

		define Course MobileWorks
		{
			NodeID = 403011;
			CrossSection = Motorway;
			Bend (500, 500);
			Bend (500, -700);
			Bend (500, -700);
			Bend (500, 1500);

			Objects =
			{
			#	(sign.Big274_120, 25, 14.5),
			#	(sign.Big274_120, 25, -1.5),

				(sign.Big277, 250, -1.5),
				(sign.Big277, 250, 14.5),

				(sign.big625_10, 570, 14.5),
				(sign.Big625_10, 620, 14.5),
				(sign.big625_10, 670, 14.5),
				(sign.Big625_10, 720, 14.5),

				(area2.road.tarrepair1, 100, 7),
				(area2.road.tarrepair1, 115, 7.5),
				(area2.road.tarrepair1, 200, 8),

				("sign.sign200_453_2~3~Würzburg~108 km~Knoblach~11 km", 1770, 15.5)
			};

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 100.0, 5000),
				(3.0, 300.0, 5000),
				(-3.0, 700.0, 5000),
				(1.0, 600.0, 4000),
				(0.0, 300.0, 4000)
			};

			LandscapeTypeLeft Meadows
			{
				Height = (2, 4);
				Ripple = (1, 3);
				Offset = (-2.5, 0.5);
				Gradient = 0.1;
				GadgetDensity = (5, 10);
				OverlayDensity = 1;
				#FieldDensity = (0, 0);
				TreeDensity = (1, 3);
				MinObjdist = 0;
				MaxObjdist = 200;
				WaySetback = (7, 2);
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


			LandscapeTypeRight Grassland
			{
				Height = (4, 8);
				Ripple = (1, 3);
				Offset = (-3, -2);
				Gradient = -0.12;
				OverlayDensity = 1;
				MinObjdist = 0;
				MaxObjdist = 25;
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
			LandscapeTypeExtra LeafForest
			{
				Left = false;
				OverlayDensity = 1;
				MinObjdist = 50;
				MaxObjdist = 137;
			};
		};

		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)
			(cworks,1,Normal,4, Scenario, Name, "Autobahn-Wanderbaustelle",
				Number, 4030100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cworks,1,Normal,5, Scenario, Name, "Autobahn-Wanderbaustelle",
				Number, 4030100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cworks,1,Normal,6, Scenario, Name, "Autobahn-Wanderbaustelle",
				Number, 4030100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),

			(cworks,1750,Normal,4, Scenario, State, 2),
			(cworks,1750,Normal,5, Scenario, State, 2),
			(cworks,1750,Normal,6, Scenario, State, 2)
		};
		# Wetter (eintrüben)
		Hedgehogs = {
			(cworks, 300, Normal, 4, Env, CRHumidity, 0.005, Humidity, 0.4),
			(cworks, 300, Normal, 5, Env, CRHumidity, 0.005, Humidity, 0.4),
			(cworks, 300, Normal, 6, Env, CRHumidity, 0.005, Humidity, 0.4)
		};
		

		MobileWorks		cworks;

		Connections =
		{
			Port1 <-> cworks.Begin,
			cworks.End <-> Port2
		};

		Traffic	WanderBS
		{
			Vehicle Hinterher1
			{
				Vehicle = HyundaiVeloster;
				Dirt = 0.3;
				Position = (cworks, 1, 5);
				Behaviour = {(HazardFree, 50, 48, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cworks, 200, 5, SimCar, Activate)
				};
			};

			Vehicle Hinterher2
			{
				Vehicle = Car;
				Dirt = 0.2;
				Position = (cworks, 1, 5);
				Behaviour = {(HazardFree, 50, 45, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cworks, 210, 5, SimCar, Activate)
				};
			};

			Vehicle Hinterher3
			{
				Vehicle = Car;
				Position = (cworks, 1, 5);
				Behaviour = {(HazardFree, 50, 30, 5, 1.5, 10, -14)};

				Flowpoints =
				{
					(cworks, 220, 5, SimCar, Activate)
				};
			};

			GlobalVehicle Global7
			{
				Position = (cworks, 1, 5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 50, 55, 5, 1, 10, -14)
				};
				RoleNumber = 107;
				Type = 0;
				Flowpoints =
				{
				#	(cworks,250,5,SimCar,ActivateVehicle,1.5),
					(cworks, 1500, 4, Traffic, TargetSpeed, 65),
					(cworks, 1700, 4, Traffic, ChangeLane, 5, 100),
					(cworks, 1900, 5, Traffic, TargetSpeed, 45)
				};
			};

			GlobalVehicle Global8		#LKW nach cworks 
			{
				Position = (cworks, 1501, 5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 1, 15, 5, 1, 10, -14)
				};
				RoleNumber = 108;
				Type = 2;
				Flowpoints =
				{
					(cworks,801,4,SimCar,ActivateVehicle,1.5)
					#(cworks, 1611, 5, Traffic, IndicatorLeft,1),
					#(cworks, 1611, 5, Traffic, IndicatorRight,1),
					#(cworks, 1620, 5, Traffic, TargetSpeed, 5),
					#(cworks, 1700, 5, Traffic, ChangeLane, 6, 100),
					#(cworks, 1820, 6, Traffic, TargetSpeed, 0)
				};
			};

			GlobalVehicle nachWB
			{
				
				Position = (cworks, 1500, 5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 1, 15, 5, 1, 10, -14)
				};
				RoleNumber = 109;
				Type = 2;

				Flowpoints =
				{
					(cworks, 850, 4, SimCar,Activate),
					(cworks, 1501, 5, Traffic, TargetSpeed,  5),
					(cworks, 1520, 5, Traffic, TargetSpeed,  15),
					(cworks, 1530, 5, Traffic, TargetSpeed, 25),
					(cworks, 1700, 5, Traffic, TargetSpeed, 15)
				};
			};
			
			GlobalVehicle hinter_nachWB
			{
				Position = (cworks, 1499, 5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 1, 15, 5, 1, 10, -14)
				};
				RoleNumber = 110;
				Type = 2;

				Flowpoints =
				{
					(cworks, 900, 4, SimCar,Activate)
				};
			};
			
			GlobalVehicle hinter2_nachWB
			{
				Position = (cworks, 1495, 5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 1, 15, 5, 1, 10, -14)
				};
				RoleNumber = 111;
				Type = 1;

				Flowpoints =
				{
					(cworks, 950, 4, SimCar,Activate)
				};
			};
			
			GlobalVehicle hinter3_nachWB
			{
				Position = (cworks, 1480, 5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 1, 15, 5, 1, 10, -14)
				};
				RoleNumber = 112;
				Type = 2;

				Flowpoints =
				{
					(cworks, 1000, 4, SimCar,Activate),
					(cworks, 1501, 5, Traffic, TargetSpeed,  5),
					(cworks, 1520, 5, Traffic, TargetSpeed,  15),
					(cworks, 1530, 5, Traffic, TargetSpeed, 25),
					(cworks, 1700, 5, Traffic, TargetSpeed, 20)
				};
			};

			GlobalVehicle hinter4_nachWB
			{
				Position = (cworks, 1500, 5);
				Behaviour =
				{
					(DSM),
					(HazardFree, 1, 15, 5, 1, 10, -14)
				};
				RoleNumber = 113;
				Type = 1;

				Flowpoints =
				{
					(cworks, 1050, 4, SimCar,Activate),
					(cworks, 1501, 5, Traffic, TargetSpeed,  5),
					(cworks, 1520, 5, Traffic, TargetSpeed,  15),
					(cworks, 1530, 5, Traffic, TargetSpeed, 25),
					(cworks, 1700, 5, Traffic, TargetSpeed, 20)
				};
			};

			
			
			
					
			
			
			
			
			Vehicle WanderBS
			{
				Vehicle = IvecoDaily_TrafficSafety_222_20;
				Position = (cworks, 950, 5);
				Behaviour = {(HazardFree, 1, 5, 5, 1.5, 10, -14)};

				Flowpoints =
				{
					(cworks,  200, 5, SimCar, Activate),
					(cworks,  210, 5, SimCar, AutoIndicatorLightControl, 0),
					(cworks,  215, 5, SimCar, IndicatorLeft, 1),
					(cworks,  215, 5, SimCar, IndicatorRight, 1),
					(cworks, 1900, 5, Traffic, TargetSpeed, 0)
				};
			};

			Vehicle WanderBS2
			{
				Vehicle = MercedesSprinter_construction;
				Colour = orange; 
				Position = (cworks, 970, 5);
				Behaviour = {(HazardFree, 1, 5, 5, 0.5, 10, -14)};

				Flowpoints =
				{
					(cworks, 200, 5, SimCar, Activate),
					(cworks, 210,   5, SimCar, AutoIndicatorLightControl, 0),
					(cworks, 215,   5, SimCar, IndicatorLeft, 1),
					(cworks, 210,   4, SimCar, AutoIndicatorLightControl, 0),
					(cworks, 215,   4, SimCar, IndicatorRight, 1),
					(cworks, 1900, 5, Traffic, TargetSpeed, 0)
				};
			};
			
			Vehicle Bus
			{
				Vehicle = IvecoDaily_Pickup;
				Dirt = 0.2;
				Position = (cworks, 500, 5);
				Behaviour = {(HazardFree, 10, 18, 5, 2.5, 10, -14)};

				Flowpoints =
				{
					(cworks, 200, 5, SimCar, Activate)
				};
			};

			TrafficFlow Gegenverkehr_Spur1
			{
				Source GegenSpur1
				{
					Position =(SimCar, -700, 1);

					Vehicles =
					{
						(1, TruckMotorway, (HazardFree, 29, 29, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 29, 29, 5, 1, 10, -14)),
						(1, VanTruck, (HazardFree, 29, 29, 5, 1, 10, -14)),						#blauer Golf!?
						(1, Car, (HazardFree, 29, 29, 5, 1, 10, -14)),
						(1, TruckMotorway, (HazardFree, 29, 29, 5, 1, 10, -14))
					};

					Parameters = (Gauss, 4,2, 451,512);
				};

				Drain GegenSpur11
				{
					Position = (SimCar, 720, 1);
				};

				Flowpoints=
				{
					(cworks, 2, 5, SimCar, ActivateSource, (GegenSpur1)),
					(cworks, 1, 5, SimCar, ActivateDrain, (GegenSpur11)),
					(cworks, 1250, 5, SimCar, DeactivateSource, (GegenSpur1)),
					(cworks, 1250, 5, SimCar, DeactivateSource, (GegenSpur11))
				};
			};

			TrafficFlow Gegenverkehr_Spur2
			{
				Source GegenSpur2
				{
					Position =(SimCar, -700, 2);

					Vehicles =
					{

						(1, CarVan, (HazardFree, 29, 29, 5, 1, 10, -14)),
						(4, Car, (HazardFree, 29, 29, 5, 1, 10, -14))
					};

					Parameters = (Gauss, 4,2, 451,512);
				};

				Drain GegenSpur11
				{
					Position = (SimCar, 720, 2);
				};

				Flowpoints=
				{
					(cworks, 2, 5, SimCar, ActivateSource, (GegenSpur1)),
					(cworks, 1, 5, SimCar, ActivateDrain, (GegenSpur11)),
					(cworks, 1250, 5, SimCar, DeactivateSource, (GegenSpur1)),
					(cworks, 1250, 5, SimCar, DeactivateSource, (GegenSpur11))
				};
			};
		};
	};

