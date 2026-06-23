

	define Module CountryValley
	{
		ModuleID = 10301;

		/* define Course Ctest
		{
			CrossSection = CountryRoad;
			NodeID = 12379;

			Straight(1000);

		}; */

		# ######################## STRASSE ##########################

		define Course Croadentry
		{
			NodeID = 103011;
			CrossSection = NarrowRoad;
			Overlay = {TarOld4, 1};

			# l = 1000 m
			Bend(500, 600);
			Bend(500, -1200);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 150.0, 1000),
				(2.0, 500.0, 1000),
				(-1.5, 300.0, 1000),
				(0.0, 50.0, 1000)
			};

			# Rest Wiese links
			LandscapeTypeExtra Grassland
			{
				Left = true;

				MinObjdist = 2.5;
				MaxObjdist = 25;
				MaxObjpos = 30;

				Override = { Tree, User };
			};

			# dichter Laubwald links

			LandscapeTypeLeft LeafForest
			{
				Gradient = 0;
				GradientEnd = 0.2;
				Height = 2;
				Roughness = 0.2;

				OverlayDensity = 0.9;

				MinObjpos = 30;
				MinObjdist = 2.5;
				MaxObjdist = 300;
				MaxHillDist = 500;
				Override = { ForestEdge, ForestLeafTreeLOD, Road };
			};
			# Dekoration des Straßenrands links
			Object Grassland
			{
				Orientation = Towards;
				YOffset = -3.3;
				Distance = 4.5;
				End = 30;
			};
			Object ForestPlants
			{
				Orientation = Towards;
				YOffset = -3.5;
				Distance = 4.5;
				Start = 30;
			};


			# dichter Nadelwald rechts
			LandscapeTypeRight Forest
			{
				OverlayDensity = 0.9;

				MinObjdist = 2.5;
				MaxObjdist = 300;
				MaxObjpos = 700;
			};

			LandscapeTypeExtra Grassland
			{
				Left = false;

				MinObjpos = 700;
				MinObjdist = 2.7;
				MaxObjdist = 25;
			};
			# Dekoration des Straßenrands rechts
			Object ForestPlants
			{
				Orientation = Onwards;
				YOffset = 3.5;
				Distance = 4.5;
				End = 700;
			};
			Object Grassland
			{
				Orientation = Onwards;
				YOffset = 3.3;
				Distance = 4.5;
				Start = 700;
			};

			# Guardrail rechte Straßenseite
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 4.2;

				Entry = 600;
				Start= 605;
				End = 900;
				Exit = 905;
			};

			Objects = {
				(environment.lgwooded.woodstack, 200, 13),
				(environment.lgwooded.woodstack, 400, -12, 180),
				(environment.lgwooded.woodstack, 500, 14),
				(environment.lgwooded.woodstack, 700, -16, 180)
			};

			TrafficRules T {
				Sign sa	{	Sign = ("274_080"); s = 10; d = 4;	};
			};


		};

		define Course Croad1
		{
			NodeID = 103012;
			CrossSection = NarrowRoad;
			Overlay = {TarOld4, 1};

			# Landschaftsbeeinflussung (Beeinflussung des Höhenmodells)
			# 0 = Keine
			# 1 = Nur HCoarse
			# 2 = Nur HFine
			# 3 = HCoarse + HFine (default)
			LandscapeInfluence = 2;

			# l = 800 m
			Bend(180, 188);
			Bend(110, -800);
			Bend(100, 400);
			Bend(200, -180);
			Bend(70, 730);
			Bend(140, -150);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 50.0, 1000),
				(8.0, 300.0, 1000),
				(9.0, 200.0, 1000),
				(6.5, 200.0, 1000),
				(0.0, 50.0, 1000)
			};

			Hedgehogs = {
				# vorwärts eintrüben
				(300,  Reverse, 0, Env, CRHumidity, 0.05, Humidity, 0.5, ReflectionVisible, 1),
				(300,  Normal,  1, Env, CRHumidity, 0.05, Humidity, 0.5, ReflectionVisible, 1),
				# rückwärts aufklaren
				(799,  Normal,  0, Env, CRHumidity, 0.05, Humidity, 0.15, ReflectionVisible, 0),
				(799,  Reverse, 1, Env, CRHumidity, 0.05, Humidity, 0.15, ReflectionVisible, 0)
			};

			# Aufgelockerter Laubwald links
			LandscapeTypeLeft LeafForest
			{
				OverlayDensity = (0.7, 0.9);

				MinObjdist = 2.5;
				MaxObjdist = 100;
				MaxObjdistEnd = 200;
				MaxObjpos = 600;

				Treedist = (13, 3);
				TreeDepth = 100;
				ObjAngle = 0;

				Override = { ForestEdge };
			};


			# weiter: Dichter Nadelwald links
			LandscapeTypeExtra Forest
			{
				Left = true;

				MinObjdist = 2.5;
				MaxObjdist = 100;
				MinObjpos = 600;

				TreeDepth = 100;

				Objangle = 0.1;
			};
			# Dekoration des Straßenrands links
			Object ForestPlants
			{
				Orientation = Towards;
				YOffset = -3.5;
				Distance = 4.5;
			};

			# Guardrail rechte Straßenseite
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 4.2;

				Entry = 0;
				Start= 5;
				End = 745;
				Exit = 750;
			};

			# Guardrail linke Straßenseite (nur an gefährlicher Kurve)
			Strip Guardrail
			{
				Orientation = Towards;
				YOffset = -4.2;

				Entry = 400;
				Start= 405;
				End = 525;
				Exit = 530;
			};
			# Grasland rechts
			LandscapeTypeExtra Grassland
			{
				Left = false;

				MinObjdist = 2.5;
				MaxObjdist = 25;
			};
			# Dekoration des Straßenrands rechts
			Object Grassland
			{
				Orientation = Onwards;
				YOffset = 3.3;
				Distance = 4.5;
			};
		};

		define Course Croad2
		{
			NodeID = 103013;
			CrossSection = NarrowRoad;
			Overlay = {TarOld4, 1};

			# Landschaftsbeeinflussung (Beeinflussung des Höhenmodells)
			# 0 = Keine
			# 1 = Nur HCoarse
			# 2 = Nur HFine
			# 3 = HCoarse + HFine (default)
			LandscapeInfluence = 2;

			# l = 790 m
			Bend(380, 330);
			Bend(110, -500);
			Bend(100, 800);
			Bend(200, -180);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 50.0, 1000),
				(5.0, 300.0, 1000),
				(7.0, 200.0, 1000),
				(4.5, 190.0, 1000),
				(0.0, 50.0, 1000)
			};

			# dichter Nadelwald links
			LandscapeTypeLeft Forest
			{
				OverlayDensity = 0.9;

				MinObjdist = 2.5;
				MaxObjdist = 50;
				TreeDepth = 50;
			};
			# Dekoration des Straßenrands links
			Object ForestPlants
			{
				Orientation = Towards;
				YOffset = -3.5;
				Distance = 4.5;
			};

			Strip WaterPath
			{
				YOffset = 1.5;
				Width = 3;

				Entry = 0;
				Start= 100;
				End = 690;
				Exit = 790;
			};

			Strip WaterPath
			{
				YOffset = -1.5;
				Width = 3;

				Entry = 0;
				Start= 100;
				End = 690;
				Exit = 790;
			};

			Hedgehogs = {
				# vorwärts Regen Start
				# Hedgehog mehrmals einfügen zur Sicherheit
				# (manchmal wird der Fahrer von der zwj Area "eingefangen"
				# so dass der Hedgehog nicht ausgelöst wird)
				(1,  Reverse, 0, Env, CRPrecipitation, 0.2, Precipitation, 1.0),
				(1,  Normal,  1, Env, CRPrecipitation, 0.2, Precipitation, 1.0),
				(10,  Reverse, 0, Env, CRPrecipitation, 0.2, Precipitation, 1.0),
				(10,  Normal,  1, Env, CRPrecipitation, 0.2, Precipitation, 1.0),
				(20,  Reverse, 0, Env, CRPrecipitation, 0.2, Precipitation, 1.0),
				(20,  Normal,  1, Env, CRPrecipitation, 0.2, Precipitation, 1.0),
				# vorwärts Regen Ende
				(690, Reverse, 0, Env, CRPrecipitation, 0.2, Precipitation, 0),
				(690, Normal,  1, Env, CRPrecipitation, 0.2, Precipitation, 0),
				# rückwärts Regen Start
				(789, Normal, 0, Env, CRPrecipitation, 0.2, Precipitation, 1.0),
				(789, Reverse,1, Env, CRPrecipitation, 0.2, Precipitation, 1.0),
				# rückwärts Regen Ende
				(100, Normal, 0, Env, CRPrecipitation, 0.2, Precipitation, 0),
				(100, Reverse,1, Env, CRPrecipitation, 0.2, Precipitation, 0)
			};

			# Guardrail rechte Straßenseite
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 4.2;

				Entry = 150;
				Start= 155;
				End = 315;
				Exit = 320;
			};

			# Guardrail rechte Straßenseite
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 4.2;

				Entry = 550;
				Start= 555;
				End = 785;
				Exit = 790;
			};

			# Landschaft rechts: lockerer Laubwald mit Gras drunter
			LandscapeTypeRight LeafForest
			{
				MinObjdist = 0;
				MaxObjdist = 100;
				MaxObjdistEnd = 150;
				TreeDepth = 100;
				PlantDepth = 0;
				EdgeDepth = 0;

				Treedist = (15, 3);
				Objangle = 0.1;
			};

			LandscapeTypeExtra Grassland
			{
				Left = false;

				MinObjdist = 2.5;
				MaxObjdist = 20;
				Override = { ForestLeafTree, ForestLeafTreeLOD };
			};
			# Dekoration des Straßenrands rechts
			Object Grassland
			{
				Orientation = Onwards;
				YOffset = 3.3;
				Distance = 4.5;
			};

			TrafficRules T {
				Sign sa	{	Sign = ("274_080"); s = 10; d = 4;	};
			};

			# Schild rückwärts nicht als TrafficRule
			Objects =
			{
				# Schilder Ende
				(sign.sign150_274_080, 10, -4, 180)
			};

		};

		define Course Croadexit
		{
			NodeID = 103014;
			CrossSection = NarrowRoad;
			Overlay = {TarOld4, 1};

			# l = 710 m
			Bend(70, 730);
			Bend(140, -150);
			Bend(500, -900);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 50.0, 1000),
				(2.0, 610.0, 1000),
				(0.0, 50.0, 1000)
			};

			# Aufgelockerter Laubwald links
			LandscapeTypeLeft LeafForest
			{
				Gradient = 0.3;
				GradientEnd = 0;
				Height = 2;
				Roughness = 0.2;

				OverlayDensity = 0.9;

				MinObjdist = 2.5;
				MaxObjdist = 100;

				Treedist = (13, 3);
				ObjAngle = 0;
			};
			# Dekoration des Straßenrands links
			Object ForestPlants
			{
				Orientation = Towards;
				YOffset = -3.5;
				Distance = 4.5;
			};

			# dichter Nadelwald rechts
			LandscapeTypeRight Forest
			{
				Gradient = -0.4;
				GradientEnd = 0;
				MaxHillDist = 150;

				OverlayDensity = 0.9;

				MinObjdist = 2.5;
				MaxObjdist = 180;
			};
			# Dekoration des Straßenrands rechts
			Object ForestPlants
			{
				Orientation = Onwards;
				YOffset = 3.5;
				Distance = 4.5;
			};

			Hedgehogs = {
				# vorwärts aufklaren
				(1,  Reverse, 0, Env, CRHumidity, 0.05, Humidity, 0.15, ReflectionVisible, 0),
				(1,  Normal,  1, Env, CRHumidity, 0.05, Humidity, 0.15, ReflectionVisible, 0),
				# rückwärts eintrüben
				(250,  Normal,  0, Env, CRHumidity, 0.05, Humidity, 0.5, ReflectionVisible, 1),
				(250,  Reverse, 1, Env, CRHumidity, 0.05, Humidity, 0.5, ReflectionVisible, 1)
			};

			TrafficRules T {
				Sign sa	{	Sign = ("278_080"); s = 600; d = 4;	};
			};

			# Schild rückwärts nicht als TrafficRule
			Objects =
			{
				# Schilder Ende
				(sign.sign150_274_080, 600, -4, 180)
			};

		};

		# ######################## FLUSS ##########################

		define Course Criverentry
		{
			NodeID = 103015;
			CrossSection = River;

			# l = 500 m
			Bend(500, 500);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 50.0, 1000),
				(1.0, 300.0, 1000),
				(0.0, 150.0, 1000)
			};

			# aufgelockerter Nadelwald rechts
			LandscapeTypeRight Forest
			{
				Gradient = 0;
				GradientEnd = 0.2;
				Height = 2;
				Roughness = 0.7;

				OverlayDensity = 0.9;

				MinObjdist = 50;
				MaxObjdist = 150;
				MaxHillDist = 500;

				PlantDepth = 0;

				Treedist = (13, 3);
				ObjAngle = 0.1;
			};

			# Flussbepflanzung
			LandscapeTypeExtra Alley2
			{
				Left = false;

				MinObjdist = 5;
				MaxObjdist = 10;
			};

			LandscapeTypeExtra Alley2
			{
				Left = true;

				MinObjdist = 5;
				MaxObjdist = 10;
			};

		};

		define Course Cjoin1
		{
			NodeID = 103016;
			CrossSection = Transparent; # muss unsichtbar sein!

			Straight(7);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 2.0, 10),
				(-20, 3.0, 10),
				(0.0, 2.0, 10)
			};

		};

		define Course Criver1
		{
			NodeID = 103017;
			CrossSection = River;

			# l = 1 km
			Bend(180, 130);
			Bend(210, -300);
			Bend(100, 400);
			Bend(200, -180);
			Bend(170, 730);
			Bend(140, -150);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 50.0, 1000),
				(1.0, 300.0, 1000),
				(0.0, 200.0, 1000),
				(1.5, 400.0, 1000),
				(0.0, 50.0, 1000)
			};

			# Gebüsch zwischen Fluss u. Straße
			LandscapeTypeLeft Hedge
			{
				Gradient = 0.2;
				GradientEnd = 0.4;
				Height = 2;
				Roughness = 0.7;

				OverlayDensity = 0.9;

				MinObjdist = 20;
				MinObjpos = 200;
				MaxObjdist = 50;
				MaxObjdistEnd = 150;
				MaxHillDist = 300;

				Objangle = 0;
				Objdist = (11, 2);
			};

			# Fortsetzung lockerer Nadelwald rechts
			LandscapeTypeRight Forest
			{
				Gradient = 0.2;
				GradientEnd = 0.5;
				Height = 2;
				Roughness = 0.7;

				OverlayDensity = 0.9;

				MinObjdist = 100;
				MaxObjdist = 250;
				MaxObjdistEnd = 400;
				MinObjpos = 130;
				MaxObjpos = 700;
				MaxHillDist = 400;
				PlantDepth = 0;

				Treedist = (13, 3);
				ObjAngle = 0.1;
			};

			# Weinberge rechts
			LandscapeTypeExtra Vineyard
			{
				Left = false;

				MinObjdist = 50;
				MaxObjdist = 400;
				MinObjpos = 700;

				#Objdist = (10,0.5);
			};



			# Flussbepflanzung
			LandscapeTypeExtra Alley2
			{
				Left = false;

				MinObjdist = 5;
				MaxObjdist = 10;
			};

			LandscapeTypeExtra Alley2
			{
				Left = true;

				MinObjdist = 5;
				MaxObjdist = 10;
			};

		};

		define Course Cjoin2
		{
			NodeID = 103018;
			CrossSection = Transparent; # muss unsichtbar sein!

			Straight(150);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 10.0, 10),
				(-36, 130.0, 10),
				(0.0, 10.0, 10)
			};

		};

		define Course Criver2
		{
			NodeID = 103019;
			CrossSection = River;

			# l = 1.3 km
			Bend(180, 130);
			Bend(210, -300);
			Bend(100, 400);
			Bend(200, -280);
			Bend(170, 430);
			Bend(140, -250);
			Bend(300, 900);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 50.0, 1000),
				(1.0, 300.0, 1000),
				(0.0, 200.0, 1000),
				(1.0, 700.0, 1000),
				(0.0, 50.0, 1000)
			};

			# etwas Bäume locker zwischen Straße und Fluss
			LandscapeTypeLeft Wooded
			{
				Gradient = 0.4;
				GradientEnd = 0.4;
				Height = 2;
				Roughness = 0.7;

				OverlayDensity = 0.9;

				TreeDensity = 10;
				MinObjdist = 50;
				MaxObjdist = 100;
			};

			# Weinberge rechts
			LandscapeTypeExtra Vineyard
			{
				Left = false;

				MinObjdist = 50;
				MaxObjdist = 400;
				MaxObjpos = 400;

				Objdist = (10,0.5);
			};

			# Laubwald locker, rechts
			LandscapeTypeRight LeafForest
			{
				Gradient = 0.5;
				Height = 2;
				Roughness = 0.7;

				OverlayDensity = 0.9;

				MinObjpos = 400;
				MinObjdist = 100;
				MaxObjdist = 350;
				MaxHillDist = 350;
				PlantDepth = 0;
				EdgeDepth = 0;
				TreeDepth = 200;

				Treedist = (16, 3);
				Objangle = 0.2;
			};

			# Flussbepflanzung
			LandscapeTypeExtra Alley2
			{
				Left = false;

				MinObjdist = 5;
				MaxObjdist = 10;
			};

			LandscapeTypeExtra Alley2
			{
				Left = true;

				MinObjdist = 5;
				MaxObjdist = 10;
			};

		};

		include parts\zwj_country_Area2.cfg
		include parts\zwj_country_2w300_Area2.cfg

		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)
			(roadentry,1,Normal,1, Scenario, Name, "Kurvige Bergstrecke",
				Number, 1030100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(roadentry,1,Reverse,0, Scenario, Name, "Kurvige Bergstrecke",
				Number, 1030100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(roadexit,500,Normal,1, Scenario, State, 2),
			(roadexit,500,Reverse,0, Scenario, State, 2)
		};


		Croadentry roadentry;
		zwj_country_2w300 roadjoin1;
		Croad1 road1;
		zwj_country_2w300 roadjoin2;
		Croad2 road2;
		Croadexit roadexit;

		Cjoin1 join1;
		zwj_country riverjoin1;
		Criverentry riverentry;
		Criver1 river1;

		Cjoin2 join2;
		zwj_country riverjoin2;
		Criver2 river2;


		Connections =
		{
			Port1 <-> roadentry.Begin,
			roadentry.End <-> roadjoin1.Port1,
			roadjoin1.Port2 <-> road1.Begin,
			road1.End <-> roadjoin2.Port1,
			roadjoin2.Port2 <-> road2.Begin,
			road2.End <-> roadexit.Begin,
			roadexit.End <-> Port2,

			roadjoin1.Port3 <-> join1.Port1,
			join1.Port2 <-> riverjoin1.Port3,
			riverjoin1.Port2 <-> riverentry.End,
			riverjoin1.Port1 <-> river1.Begin,

			roadjoin2.Port3 <-> join2.Port1,
			join2.Port2 <-> riverjoin2.Port3,
			riverjoin2.Port1 <-> river2.Begin
		};


		Traffic uw1
		{
 
 			Vehicle gegen1
			{
				Vehicle = AudiA6;
				Colour = black;
				Position = (road2, 1, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(roadentry,1 , 1, SimCar, Activate)
				};
			};
 
			Vehicle gegen2
			{
				Vehicle = VWPassat;
				Colour = white;
				Position = (roadexit, 1, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(roadentry,900 , 1, SimCar, Activate)
				};
			};
			
			Vehicle gegen3
			{
				Vehicle = MercedesC;
				Colour = silver;
				Position = (road2, 300, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(roadentry,1 , 1, SimCar, Activate)
				};
			};		
			
			Vehicle gegen4
			{
				Vehicle = VWGolf;
				Colour = white;
				Position = (road1, 10, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(roadentry,1 , 1, SimCar, Activate)
				};
			};
			
			Vehicle gegen5
			{
				Vehicle = RenaultTwingo;
				Colour = red;
				Position = (road2, 170, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(road1,1 , 1, SimCar, Activate)
				}; 
			};
			
			Vehicle gegen6
			{
				Vehicle = OpelInsignia;
				Colour = black;
				Position = (roadexit, 1, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(road2,1 , 1, SimCar, Activate)
				};
			};
			
	
			Vehicle gegen8
			{
				Vehicle = MitsubishiASX;
				Colour = black;
				Position = (road2, 200, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(road1,1 , 1, SimCar, Activate)
				};
			};
			
			Vehicle gegen9
			{
				Vehicle = VWPassat;
				Colour = silver;
				Position = (roadexit, 700, 0);
				Behaviour = {(HazardFree, 15, 30, 5, 3, 10, -14)};

				Flowpoints =
				{
					(roadexit,1 , 1, SimCar, Activate)
				};
			};
			
			Vehicle Wildschwein0
			{
				Vehicle = WildBoar_slow;
				Position = (roadexit,517,1);
				# LaneCrossing,<Startabstand>,<Endabstand>,<Geschwindigkeit>
				Behaviour = {(LaneCrossing,8,-15,-1.25)};
				Flowpoints =
				{
					(roadexit,301,1,SimCar,Activate)
				};
			};
			
			Vehicle Wildschwein1
			{
				Vehicle = WildBoar_slow;
				Position = (roadexit,520,1);
				# LaneCrossing,<Startabstand>,<Endabstand>,<Geschwindigkeit>
				Behaviour = {(LaneCrossing,8,-15,-2)};
				Flowpoints =
				{
					(roadexit,301,1,SimCar,Activate)
				};
			};
			
			Vehicle Wildschwein2
			{
				Vehicle = WildBoar_slow;
				Position = (roadexit,523,1);
				# LaneCrossing,<Startabstand>,<Endabstand>,<Geschwindigkeit>
				Behaviour = {(LaneCrossing,8,-15,-1.5)};
				Flowpoints =
				{
					(roadexit,301,1,SimCar,Activate)
				};
			};
		};

	};
