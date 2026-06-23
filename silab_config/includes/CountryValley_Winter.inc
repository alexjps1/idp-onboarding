

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
			CrossSection = CountryRoad;
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

			# dichter Laubwald links
			LandscapeTypeExtra LeafForest
			{
				Left = true;

				MinObjdist = 30;
				MaxObjdist = 400;
				MinObjpos = 30;
				MaxObjpos = 68;
				ObjAngle = 0;
				#Objdist = (12, 0.5);
			};

			LandscapeTypeLeft LeafForest
			{
				Gradient = 0;
				GradientEnd = 0.2;
				Height = 2;
				Roughness = 0.2;

				OverlayDensity = 0.9;

				MinObjpos = 30;
				MinObjdist = 3;
				MaxObjdist = 37;
				MaxHillDist = 500;
			};

			# dichter Nadelwald rechts
			LandscapeTypeRight Forest
			{
				OverlayDensity = 0.9;

				MinObjdist = 10;
				MaxObjdist = 40;
				MaxObjpos = 700;
			};

			LandscapeTypeExtra Forest
			{
				Left = false;

				MinObjdist = 40;
				MaxObjdist = 400;
				MaxObjpos = 30;
				Objangle = 0;
			};

			LandscapeTypeExtra Forest
			{
				Left = false;

				MinObjdist = 40;
				MaxObjdist = 100;
				MinObjpos = 670;
				MaxObjpos = 700;
				Objangle = 0;
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
			CrossSection = CountryRoad;
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

				MinObjdist = 10;
				MaxObjdist = 100;
				MaxObjdistEnd = 200;
				MaxObjpos = 600;

				Objdist = (13, 3);
				ObjAngle = 0;
			};

			# weiter: Dichter Nadelwald links
			LandscapeTypeExtra Forest
			{
				Left = true;

				MinObjdist = 10;
				MaxObjdist = 100;
				MinObjpos = 600;

				Objangle = 0.1;
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

		};

		define Course Croad2
		{
			NodeID = 103013;
			CrossSection = CountryRoad;
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

				MinObjdist = 10;
				MaxObjdist = 50;
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
			CrossSection = CountryRoad;
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

				MinObjdist = 10;
				MaxObjdist = 100;

				Objdist = (13, 3);
				ObjAngle = 0;
			};

			# dichter Nadelwald rechts
			LandscapeTypeRight Forest
			{
				Gradient = -0.4;
				GradientEnd = 0;
				MaxHillDist = 150;

				OverlayDensity = 0.9;

				MinObjdist = 10;
				MaxObjdist = 40;
			};

			LandscapeTypeExtra Forest
			{
				Left = false;

				MinObjdist = 40;
				MaxObjdist = 180;
				MaxObjpos = 30;
				Objangle = 0;
			};

			LandscapeTypeExtra Forest
			{
				Left = false;

				MinObjdist = 40;
				MaxObjdist = 400;
				MinObjpos = 680;
				Objangle = 0;
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

				Objdist = (13, 3);
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

				Objdist = (13, 3);
				ObjAngle = 0.1;
			};

			# Weinberge rechts
			LandscapeTypeExtra Vineyard
			{
				Left = false;

				MinObjdist = 50;
				MaxObjdist = 400;
				MinObjpos = 700;

				Objdist = (10,0.5);
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

			# Laubwald locker zwischen Straße und Fluss
			LandscapeTypeLeft LeafForest
			{
				Gradient = 0.4;
				GradientEnd = 0.4;
				Height = 2;
				Roughness = 0.7;

				OverlayDensity = 0.9;

				MinObjdist = 50;
				MaxObjdist = 150;
				MaxObjdistEnd = 200;
				MaxObjpos = 800;
				MaxHillDist = 300;

				Objdist = (15, 3);
				Objangle = 0.1;
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
				MinObjdist = 150;
				MaxObjdist = 350;
				MaxHillDist = 350;

				Objdist = (16, 3);
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
			TrafficFlow GegenverkehrWechsel
			{
				Source GegenW
				{
				#	Position =(SimCar, -600, 0);
					Position =(SimCar, -600, 0);

					Vehicles =
					{
						(1, CarVan, (HazardFree, 15, 22, 5, 2, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 16, 5, 2, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 20, 5, 4, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 25, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14))
						
					};

					Parameters = (Gauss, 5, 1, 1236, 512);
				};

				Drain GegenW
				{
				#	Position = (SimCar, 610, 1);
					Position = (SimCar, 610, 1);
				};

				Flowpoints=
				{
					(roadentry, 1, 1, SimCar, ActivateSource, (GegenW)),
					(roadentry, 10, 1, SimCar, ActivateDrain, (GegenW)),
					(road2, 700, 1, SimCar, DeactivateSource, (GegenW))
				};
			};
            Vehicle Wildschwein0
			{
				Vehicle = WildBoar_slow;
				Position = (roadexit,520,1);
				# LaneCrossing,<Startabstand>,<Endabstand>,<Geschwindigkeit>
				Behaviour = {(LaneCrossing,10,-3,-1)};
				Flowpoints =
				{
					(roadexit,301,1,SimCar,Activate)
				};
			};
		};

	};
