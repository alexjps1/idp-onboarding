	define Module Motorway
	{
		ModuleID = 827;

		define Course Motorway_Empty
		{
			NodeID = 1001;
			CrossSection = Motorway;
			Straight (1000);
			Straight (1000);
					

			Objects =
			{
				#(sign.sign200_330, 50, 12.5),
				#(sign.sign200_330, 50, 0.5),
				#(sign.Sign200_274_130, 250, 12.5),
				#(sign.Sign200_274_130, 250, 0.5)
			};

			TrafficRules T {
				Sign sa	{	Sign = ("274_130"); s = 250; d = 12;	};
				Sign sa	{	Sign = ("274_130"); s = 250; d = 0.5;	};
			};

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 100.0, 3000),
				(-1.0, 200.0, 2000),
				(-4.0, 400.0, 2000), 
				(0.0, 200.0, 2000),
				(4.0, 350.0, 3000),
				(1.0, 650.0, 3000),
				(0.0, 100.0, 7000)
			};


			LandscapeTypeLeft Meadows
			{
				Height = (2, 4);
				Ripple = (1, 3);
				Offset = (-1.5, -0.5);
				Gradient = 0.1;
				GradientEnd = 0.05;
				GadgetDensity = (5, 10);
				OverlayDensity = 1;
				#FieldDensity = (0, 0);
				TreeDensity = (1, 3);
				MinObjdist = 0;
				MaxObjdist = 200;
				MaxObjpos = 1850;
				WaySetback = (7, 2);
			};
			# Deko links
			LandscapeTypeExtra CountryVillage {
				Left = true;
				MinObjdist = 50;
				MaxObjdist = 140;
				MinObjpos = 1800;
				MaxObjpos = 2000;
				CountryHouseDensity = 20;
				SmallTreeDensity = 30;
			};
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
			# Bodennebel
			LandscapeTypeExtra GroundFog
			{
				Left = false;

				MinObjpos = 640;
				MaxObjpos = 720; 
				MinObjdist = -50;
				MaxObjdist = 15;
				MinScaleZ = 1.2;
				MaxScaleZ = 1.5;
				Objdist = (6.0, 0.8);
				Objangle = 0.05;
				Override = { FieldPlant, Meadow, Fence, Way, Grassland };
			};
			LandscapeTypeExtra GroundFog
			{
				Left = false;

				MinObjpos = 720;
				MaxObjpos = 880; 
				MinObjdist = -50;
				MaxObjdist = 15;
				MinScaleZ = 1.2;
				MaxScaleZ = 1.5;
				Objangle = 0.05;
				Override = { FieldPlant, Meadow, Fence, Way, Grassland };
			};
			LandscapeTypeExtra GroundFog
			{
				Left = false;

				MinObjpos = 880;
				MaxObjpos = 950; 
				MinObjdist = -50;
				MaxObjdist = 15;
				MinScaleZ = 1.2;
				MaxScaleZ = 1.5;
				Objdist = (5.0, 0.8);
				Objangle = 0.05;
				Override = { FieldPlant, Meadow, Fence, Way, Grassland };
			};
						
			# Landschaft rechts
			LandscapeTypeRight Forest
			{
				Height = (0, 10);
				Ripple = (0, 4);
				Offset = (0, 10);
				Gradient = 0;
				GradientEnd = 0.5;
				#GadgetDensity = (0, 0);
				#FieldDensity = (0, 2);
				//TreeDensity = (2, 100);
				//FieldSetback = (12, 2);
				//WaySetback = (9, 2);
				MinObjdist = 0;
				MaxObjdist = 200;
				MinObjpos = 200;
			};
			# Deko rechts
			LandscapeTypeExtra AncientVillage {
				Left = false;
				MinObjdist = 30;
				MaxObjdist = 130;
				MinObjpos = 0;
				MaxObjpos = 200;
				AncientHouseDensity = 1;
				SmallTreeDensity = 100;
			};
			LandscapeTypeExtra Meadow {
				Left = false;
				MinObjdist = 2.5;
				MaxObjdist = 20;
				MaxObjpos = 200;
			};
			LandscapeTypeExtra Alley2 {
				Left = false;
				MinObjdist = 216;
				MaxObjdist = 223;
				MaxObjpos = 700;
			};
			LandscapeTypeExtra Alley2 {
				Left = false;
				MinObjdist = 6;
				MaxObjdist = 13;
				MinObjpos = 700;
				MaxObjpos = 1300;
			};
			LandscapeTypeExtra Alley2 {
				Left = false;
				MinObjdist = 216;
				MaxObjdist = 233;
				MinObjpos = 1250;
			};
			Object Meadow
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
			# Wetter (eintrüben; wieder aufklaren)
			Hedgehogs = {
				(1, Normal, 4, Env, CRHumidity, 0.02, Humidity, 0.4),
				(1, Normal, 5, Env, CRHumidity, 0.02, Humidity, 0.4),
				(1, Normal, 6, Env, CRHumidity, 0.02, Humidity, 0.4),
				(1299, Normal, 4, Env, CRHumidity, 0.005, Humidity, 0.15),
				(1299, Normal, 5, Env, CRHumidity, 0.005, Humidity, 0.15),
				(1299, Normal, 6, Env, CRHumidity, 0.005, Humidity, 0.15)
			};			
		};

		define Course Motorway_FreeDriving
		{
			NodeID = 1002;
			CrossSection = Motorway;
			Bend (1000, 2000);
			Bend (1000, -2000);
			Bend (1000, 2000);
			Bend (1000, -2000);


			TrafficRules T {
				Sign sa	{	Sign = ("274_130"); s = 150; d = 12;	};
				Sign sa	{	Sign = ("274_130"); s = 150; d = 0.5;	};
			};

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 500, 7000),
				(1.0, 500.0, 7000),
				(0.0, 500.0, 7000),
				(1.0, 500.0, 7000),
				(0.0, 500.0, 7000),
				(-1.5, 1000.0, 7000),
				(0.0, 500, 7000)
			};

			LandscapeTypeLeft Wooded
			{
				Height = (0, 0);
				Ripple = (0, 0);
				Offset = (-0.5, 0.5);
				Gradient = 0;
				GradientEnd = -0.15;
				TreeDensity = (10, 15);
				MinObjdist = 30;
				MaxObjdist = 300;
			};
			# Deko links
			LandscapeTypeExtra Grassland {
				Left = true;
				MinObjdist = 2.5;
				MaxObjdist = 20;
			};
			Object Grassland
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
			LandscapeTypeExtra Suburb {
				Left = true;
				MinObjdist = 40;
				MaxObjdist = 180;
				MinObjpos = 1340;
				MaxObjpos = 1630;
				SuburbHouseDensity = 25;
			};
			LandscapeTypeExtra Suburb {
				Left = true;
				MinObjdist = 20;
				MaxObjdist = 150;
				MinObjpos = 2900;
				MaxObjpos = 3230;
				SuburbHouseDensity = 25;
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

			LandscapeTypeRight Vineyard
			{
				Height = (0, 2);
				Ripple = (2, 3);
				Offset = (-4, -2);
				Gradient = 0.3;
				GradientEnd = 0.4;
				MinObjdist = 20;
				MaxObjdist = 200;
				MaxObjpos = 2000;
			};
			# Deko rechts
			Object Meadow
			{
				Orientation = Onwards;
				YOffset = 12.8;
				Distance = 4.5;
				End = 2000;
			};
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 13;
			};
			LandscapeTypeExtra Meadow {
				Left = false;
				MinObjdist = 2.5;
				MaxObjdist = 20;
				MaxObjpos = 2000;
			};
			# Deko zweite Hälfte rechts
			Object Grassland
			{
				Orientation = Onwards;
				YOffset = 12.8;
				Distance = 4.5;
				Start = 2000;
			};
			LandscapeTypeExtra Grassland {
				Left = false;
				MinObjdist = 2.5;
				MaxObjdist = 20;
				MinObjpos = 2000;
			};
			# Baumgruppen:
			LandscapeTypeExtra Wooded {
				Left = false;
				MinObjdist = 10;
				MaxObjdist = 130;
				MinObjpos = 2000;
				MaxObjpos = 2200;
				TreeDensity = 30;
			};
			LandscapeTypeExtra Wooded {
				Left = false;
				MinObjdist = 40;
				MaxObjdist = 110;
				MinObjpos = 2300;
				MaxObjpos = 2550;
				TreeDensity = 30;
			};
			LandscapeTypeExtra Wooded {
				Left = false;
				MinObjdist = 20;
				MaxObjdist = 150;
				MinObjpos = 2600;
				MaxObjpos = 2800;
				TreeDensity = 30;
			};
			LandscapeTypeExtra Wooded {
				Left = false;
				MinObjdist = 50;
				MaxObjdist = 120;
				MinObjpos = 2900;
				MaxObjpos = 3200;
				TreeDensity = 30;
			};
			LandscapeTypeExtra Wooded {
				Left = false;
				MinObjdist = 10;
				MaxObjdist = 90;
				MinObjpos = 3230;
				MaxObjpos = 3470;
				TreeDensity = 30;
			};
			LandscapeTypeExtra Wooded {
				Left = false;
				MinObjdist = 28;
				MaxObjdist = 134;
				MinObjpos = 3500;
				MaxObjpos = 3780;
				TreeDensity = 30;
			};
			LandscapeTypeExtra Wooded {
				Left = false;
				MinObjdist = 12;
				MaxObjdist = 80;
				MinObjpos = 3810;
				MaxObjpos = 3940;
				TreeDensity = 30;
			};
			LandscapeTypeExtra Bushes {
				Left = false;
				MinObjdist = 8;
				MaxObjdist = 70;
				MinObjpos = 2000;
				HedgeDensity = 6;
			};

		};

		define Course Motorway_Jam
		{
			NodeID = 1002;
			CrossSection = Motorway;
			Bend (1000, 5000);
			Bend (1000, -5000);
			Bend (1000, 2000);

			Objects =
			{
				("sign.Sign200_448~Knoblach", 2060, 15),
				("sign.Sign200_449~Würzburg~Knoblach", 2560, 15),
				(sign.Sign200_450_300, 2760, 13),
				(sign.Sign200_450_200, 2860, 13),
				(sign.Sign200_450_100, 2960, 13),
				(models.lake_farmed, 2250, 0),
				(models.lake_farmed, 2600, 0)
			};

			TrafficRules T {
				Sign sa	{	Sign = ("274_100"); s = 150; d = 13;	};
				Sign sa	{	Sign = ("274_100"); s = 150; d = 0.5;	};
			};

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 500, 7000),
				(0.5, 600.0, 7000),
				(0.0, 900.0, 7000),
				(-2.0, 300.0, 2000),
				(0.0, 200.0, 7000),
				(1.5, 200.0, 7000),
				(0.0, 300, 7000)
			};

			LandscapeTypeLeft Farmed
			{
				Height = (0, 2);
				Ripple = (1, 3);
				Offset = (0.5, 2.5);
				Gradient = -0.1;
				GradientEnd = 0.1;
				FieldSetback = (13, 3);
				WaySetback = (15, 5);
				MinObjdist = 0;
				MaxObjdist = 200;
			};
			# Deko links
			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 8;
				MaxObjdist = 17;
				MaxObjpos = 600;
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 8;
				MaxObjdist = 17;
				MaxObjpos = 600;
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 108;
				MaxObjdist = 117;
				MinObjpos = 450;
				MaxObjpos = 950;
				Override = {Field};
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 8;
				MaxObjdist = 17;
				MinObjpos = 900;
				MaxObjpos = 1300;
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 168;
				MaxObjdist = 179;
				MinObjpos = 1200;
				MaxObjpos = 1750;
				Override = {Field};
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 8;
				MaxObjdist = 17;
				MinObjpos = 1700;
				MaxObjpos = 2300;
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 208;
				MaxObjdist = 129;
				MinObjpos = 2200;
				MaxObjpos = 2650;
				Override = {Field};
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				MinObjdist = 78;
				MaxObjdist = 89;
				MinObjpos = 2600;
				Override = {Field};
			};
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

			# Landschaft rechts
			LandscapeTypeRight Meadows
			{
				Height = (0, 9);
				Ripple = (0, 9);
				Offset = (0, 0.9);
				Gradient = 0.3;
				GradientEnd = -0.08;
				// TreeDensity = 0;
				 MinObjdist = 1;
				MaxObjdist = 250;
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
			LandscapeTypeExtra AncientVillage {
				Left = false;
				MinObjdist = 1;
				MaxObjdist = 100;
				#MaxObjpos = 3000;
			};
		};

		include parts\MotorwayExit_7722_Area2.cfg
		include parts\MotorwayExit_7722_TRF.cfg
		

		Traffic	Einzelfahrzeuge_Spur5
		{
			Vehicle SW1
			{
				Vehicle = Car;
				Position = (cempty, 450, 5);
				Behaviour = {(HazardFree, 15, 57, 5, 2, 10, -14)};
				ID = 101;
				UserID = 1001;
				Flowpoints =
				{
					(cempty, 1, 5, SimCar,Activate),
					(cempty, 640, 5, SimCar, ChangeLane, 4, 100)
				};
			};
			
			
			Vehicle Dahinter
			{
				Vehicle = Car;
				Position = (cempty, 1, 5);
				UserID = 1002;
				Behaviour = {(HazardFree, 5, 50, 5, 2, 10, -14)};

				Flowpoints =
				{
					(cempty, 200, 5, SimCar,Activate)
				};
			};

			Vehicle re0
			{
				Vehicle = Car;
				UserID = 1003;
				Position = (cempty, 500, 5);
				Behaviour = {(HazardFree, 15, 27, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1, 5, SimCar,Activate)
				};
			};

			Vehicle re1
			{
				Vehicle = Car;
				Position = (cempty, 800, 5);
				UserID = 1004;
				Behaviour = {(HazardFree, 15, 27, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1, 5, SimCar,Activate)
				};
			};

			Vehicle re2
			{
				Vehicle = BMWR1200;
				UserID = 1005;
				Position = (cempty, 1160, 5);
				Behaviour = {(HazardFree, 30, 27, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 560, 5, SimCar,Activate)
				};
			};

			Vehicle re3
			{
				Vehicle = MercedesActros;
				Position = (cempty, 1505, 5);
				Behaviour = {(HazardFree, 20, 20, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 700, 5, SimCar,Activate)
				};
			};
			
			Vehicle re4
			{
				Vehicle = MercedesActros;
				Position = (cempty, 1500, 5);
				Behaviour = {(HazardFree, 20, 20, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 700, 5, SimCar,Activate)
				};
			};

			Vehicle re5
			{
				Vehicle = Car;
				Position = (cempty, 1498, 5);
				Behaviour = {(HazardFree, 30, 30, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 700, 5, SimCar,Activate)
				};
			};

			Vehicle re6
			{
				Vehicle = Car;
				Position = (cempty, 1490, 5);
				Behaviour = {(HazardFree, 30, 30, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 750, 5, SimCar,Activate)
				};
			};

			Vehicle re7
			{
				Vehicle = Car;
				Position = (cempty, 1800, 5);
				Behaviour = {(HazardFree, 32, 32, 5, 1, 10, -14)};
				ID = 103;

				Flowpoints =
				{
					(cempty, 800, 5, SimCar,Activate)
				};
			};

			Vehicle re8
			{
				Vehicle = Car;
				Position = (cempty, 1800, 5);
				Behaviour = {(CommandAction, 1, TRFC_ONOFF, 0),(HazardFree, 33, 33, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 900, 5, SimCar,Activate)
				};
			};
			
			Vehicle re9
			{
				Vehicle = MercedesActros;
				Position = (cfreedriving, 120, 5);
				Behaviour = {(HazardFree, 20, 20, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};

			Vehicle re10
			{
				Vehicle = IvecoDaily_TowTruck;
				Colour = orange;
				Position = (cfreedriving, 100, 5);
				UserID = 2009;
				Behaviour = {(HazardFree, 33, 33, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};

			Vehicle re11
			{
				Vehicle = Car;
				Position = (cfreedriving, 200, 5);
				UserID = 2008;
				Behaviour = {(CommandAction, 1, TRFC_ONOFF, 0),(HazardFree, 33, 33, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};

			Vehicle re12
			{
				Vehicle = MercedesActros;
				Colour = blue;
				Position = (cfreedriving, 400, 5);
				Behaviour = {(CommandAction, 1, TRFC_ONOFF, 0),(HazardFree, 33, 33, 5, 1, 10, -14)};
				ID = 104;
				UserID = 2007;

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};

			Vehicle re13
			{
				Vehicle = Car;
				Position = (cfreedriving, 700, 5);
				UserID = 2006;
				Behaviour = {(CommandAction, 1, TRFC_ONOFF, 0),(HazardFree, 33, 33, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};

			Vehicle re14
			{
				Vehicle = Car;
				Position = (cfreedriving, 1000, 5);
				Behaviour = {(HazardFree, 33, 33, 5, 1, 10, -14)};
				UserID = 2005;

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};

			#Stau_rechts:

			Vehicle reLKW
			{
				Vehicle = MercedesActros;
				Colour = black;
				Position = (cjam, 280, 5);
				UserID = 2004;
				Behaviour = {(HazardFree, 15, 15, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cfreedriving, 3200, 5, SimCar,Activate),
					(cjam, 200, 5, SimCar, TargetSpeed,  5),
					(cjam, 600, 5, SimCar, TargetSpeed,  0.4),
					(cjam, 630, 5, SimCar, TargetSpeed, 20),
					(cjam, 950, 5, SimCar, TargetSpeed, 25)
				};
			};

			Vehicle re15
			{
				Vehicle = Car;
				Position = (cjam, 200, 5);
				Behaviour = {(HazardFree, 15, 15, 5, 1, 10, -14)};
				UserID = 2003;

				Flowpoints =
				{
					(cfreedriving, 3200, 5, SimCar,Activate),
					(cjam, 200, 5, SimCar, TargetSpeed,  5),
					(cjam, 600, 5, SimCar, TargetSpeed,  0.4),
					(cjam, 630, 5, SimCar, TargetSpeed, 20),
					(cjam, 910, 5, SimCar, TargetSpeed, 25)
				};
			};

			Vehicle re16
			{
				Vehicle = BMWR1200;
				Position = (cjam, 150, 5);
				Behaviour = {(HazardFree, 15, 15, 5, 1, 10, -14)};
				UserID = 2001;

				Flowpoints =
				{
					(cfreedriving, 3200, 5, SimCar,Activate),
					(cjam, 200, 5, SimCar, TargetSpeed,  5),
					(cjam, 600, 5, SimCar, TargetSpeed,  0.4),
					(cjam, 630, 5, SimCar, TargetSpeed, 20),
					(cjam, 920, 5, SimCar, TargetSpeed, 25)
				};
			};

			Vehicle re17
			{
				Vehicle = Car;
				Position = (cjam, 100, 5);
				Behaviour = {(HazardFree, 15, 15, 5, 1, 10, -14)};
				UserID = 2002;

				Flowpoints =
				{
					(cfreedriving, 3200, 5, SimCar,Activate),
					(cjam, 200, 5, SimCar, TargetSpeed,  5),
					(cjam, 600, 5, SimCar, TargetSpeed,  0.4),
					(cjam, 630, 5, SimCar, TargetSpeed, 20),
					(cjam, 930, 5, SimCar, TargetSpeed, 25)
				};
			};
		};

		Traffic	Einzelfahrzeuge_Spur4
		{
			Vehicle li0f
			{
				Vehicle = Car;
				Dirt = 0.15;
				Position = (cempty, 1, 4);
				Behaviour = {(CommandAction, 2, TRFC_BRAKELIGHT, 0),(HazardAvoidance2, 5, 1.5),(SimCarLocked),(HazardFree, 55, 54, 5, 1.5, 10, -14)};

				ID = 100;

				Flowpoints =
				{
					(cempty, 200, 5, SimCar,Activate),
					(cempty, 300, 5, SimCar,ActivateCommandAction,2),
					(cempty, 301, 5, SimCar,DistanceLess, 2000),
					(cempty, 302, 5, SimCar, AutoBrakeLightControl,0),
					(cempty, 710, 5, SimCarOnLane,TargetSpeed, 45),
					(cempty, 720, 5, SimCarOnLane, SetLockDistance, 15),
					(cempty, 805, 5, SimCarOnLane, Unlock),
					(cempty, 780, 5, SimCar, ChangeLane, 5, 50)
				};
			};

			Vehicle li00
			{
				Vehicle = Car;
				Position = (cempty, 1, 4);
				Behaviour = {(HazardFree, 55, 55, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 250, 5, SimCar,Activate)
				};
			};

			#Aktivierung bei 500m

			Vehicle li1
			{
				Vehicle = Car;
				Position = (cempty, 20, 4);
				Behaviour = {(HazardFree, 50, 45, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 300, 5, SimCar,Activate)
				};
			};

			Vehicle li2
			{
				Vehicle = Car;
				Position = (cempty, 10, 4);
				Behaviour = {(HazardFree, 50, 45, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 300, 5, SimCar,Activate)
				};
			};

			Vehicle li3
			{
				Vehicle = Car;
				Position = (cempty, 10, 4);
				Behaviour = {(HazardFree, 50, 45, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 400, 5, SimCar,Activate)
				};
			};

			Vehicle li4
			{
				Vehicle = Car;
				Position = (cempty, 20, 4);
				Behaviour = {(HazardFree, 50, 45, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 400, 5, SimCar,Activate)
				};
			};

			#Aktivierung bei 1000m

			Vehicle li4
			{
				Vehicle = Car;
				Position = (cempty, 400, 4);
				Behaviour = {(HazardFree, 50, 44, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};

			Vehicle li5
			{
				Vehicle = Car;
				Position = (cempty, 100, 4);
				Behaviour = {(HazardFree, 40, 44, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};

			Vehicle li6
			{
				Vehicle = Car;
				Position = (cempty, 10, 4);
				Behaviour = {(HazardFree, 40, 44, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cempty, 1000, 5, SimCar,Activate)
				};
			};
			#Stau_links:

			Vehicle li11
			{
				Vehicle = Car;
				Position = (cjam, 200, 4);
				Behaviour = {(HazardFree, 15, 16, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cfreedriving, 3200, 5, SimCar,Activate),
					(cjam, 200, 5, SimCar, TargetSpeed, 5),
					(cjam, 600, 5, SimCar, TargetSpeed,  0.5),
					(cjam, 615, 5, SimCar, TargetSpeed, 20),
					(cjam, 800, 5, SimCar, TargetSpeed, 35),
					(cjam, 1800, 5, SimCar, TargetSpeed, 45)
				};
			};

			Vehicle li12
			{
				Vehicle = Car;
				Position = (cjam, 150, 4);
				Behaviour = {(HazardFree, 15, 16, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cfreedriving, 3200, 5, SimCar,Activate),
					(cjam, 200, 5, SimCar, TargetSpeed, 5),
					(cjam, 600, 5, SimCar, TargetSpeed,  0.5),
					(cjam, 615, 5, SimCar, TargetSpeed, 20),
					(cjam, 800, 5, SimCar, TargetSpeed, 34),
					(cjam, 1800, 5, SimCar, TargetSpeed, 45)
				};
			};

			Vehicle li13
			{
				Vehicle = Car;
				Position = (cjam, 100, 4);
				Behaviour = {(HazardFree, 15, 16, 5, 1, 10, -14)};

				Flowpoints =
				{
					(cfreedriving, 3200, 5, SimCar,Activate),
					(cjam, 200, 5, SimCar, TargetSpeed, 5),
					(cjam, 600, 5, SimCar, TargetSpeed,  0.5),
					(cjam, 615, 5, SimCar, TargetSpeed, 20),
					(cjam, 800, 5, SimCar, TargetSpeed, 33),
					(cjam, 1800, 5, SimCar, TargetSpeed, 45)
				};
			};
		};

		Traffic Gegenverkehr
		{
			SourceX GegenverkehrSpur1
			{
				Position = (SimCar, -900, 1);
				Group = Car;
				Sequence = (2, 2.5, 1.8, 2.3, 1,9, 2.6);
				Behaviour = {(HazardFree, 20, 20, 5, 2, 10, -14)};
				DeactivationRadius = 400;
				NumberOfVehicles = 5;
				Flowpoints = {
					(cempty, 1, 5, SimCar, Activate),
					(cjam, 1, 2000, SimCar, Deactivate)
				};
			};
			
			SourceX GegenverkehrSpur2
			{
				Position = (SimCar, -900, 2);
				Group = Car;
				Sequence = (2.2, 2.1, 1.7, 2.4, 2,1, 1.9);
				Behaviour = {(HazardFree, 30, 30, 5, 3, 10, -14)};
				DeactivationRadius = 400;
				NumberOfVehicles = 5;
				Flowpoints = {
					(cempty, 2, 5, SimCar, Activate),
					(cjam, 2, 2000, SimCar, Deactivate)
				};
			};
			
			/*
			TrafficFlow Gegenverkehr1
			{
				Source GegenSpur1
				{
					Position =(SimCar, -900, 1);

					Vehicles =
					{
						(5, Car, (HazardFree, 20, 20, 5, 2, 10, -14))
					};

					Parameters = (Gauss, 2,1, 451,512);
				};

				Drain GegenSpur11
				{
					Position = (SimCar, 920, 1);
				};

				Flowpoints=
				{
					(cempty, 2, 5, SimCar, ActivateSource, (GegenSpur1)),
					(cempty, 1, 5, SimCar, ActivateDrain, (GegenSpur11))
				};
			};

			TrafficFlow Gegenverkehr2
			{
				Source GegenSpur2
				{
					Position =(SimCar, -900, 2);

					Vehicles =
					{
						(3, Car, (HazardFree, 30, 30, 5, 3, 10, -14))
					};

					Parameters = (Gauss, 2,1, 451,512);
				};

				Drain GegenSpur22
				{
					Position = (SimCar, 920, 2);
				};

				Flowpoints=
				{
					(cempty, 2, 5, SimCar, ActivateSource, (GegenSpur2)),
					(cempty, 1, 5, SimCar, ActivateDrain, (GegenSpur22))
				};
			};
			*/
		};

		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value,Name DPULimiter)
			# Initialisierung Regen
			(cfreedriving, 100, DontCare,  0, Weather, RainDensity, 0),
			(cfreedriving, 100, DontCare,  1, Weather, RainDensity, 0),
			(cfreedriving, 100, DontCare,  2, Weather, RainDensity, 0),
			(cfreedriving, 100, DontCare,  3, Weather, RainDensity, 0),
			(cfreedriving, 100, DontCare,  4, Weather, RainDensity, 0),
			(cfreedriving, 100, DontCare,  5, Weather, RainDensity, 0),
			(cfreedriving, 100, DontCare,  6, Weather, RainDensity, 0),
			(cfreedriving, 100, DontCare,  0, Env, CRHumidity, 0.02, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  1, Env, CRHumidity, 0.02, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  2, Env, CRHumidity, 0.02, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  3, Env, CRHumidity, 0.02, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  4, Env, CRHumidity, 0.02, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  5, Env, CRHumidity, 0.02, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  6, Env, CRHumidity, 0.02, Humidity, 0.15),

			# Es fange zu regnen an!
			(cfreedriving, 1900, DontCare,  0, Weather, StartRain, 1.0, RainDensity, 4000),
			(cfreedriving, 1900, DontCare,  1, Weather, StartRain, 1.0, RainDensity, 4000),
			(cfreedriving, 1900, DontCare,  2, Weather, StartRain, 1.0, RainDensity, 4000),
			(cfreedriving, 1900, DontCare,  3, Weather, StartRain, 1.0, RainDensity, 4000),
			(cfreedriving, 1900, DontCare,  4, Weather, StartRain, 1.0, RainDensity, 4000),
			(cfreedriving, 1900, DontCare,  5, Weather, StartRain, 1.0, RainDensity, 4000),
			(cfreedriving, 1900, DontCare,  6, Weather, StartRain, 1.0, RainDensity, 4000),
			(cfreedriving, 100, DontCare,  0, Env, Humidity, 0.6),
			(cfreedriving, 100, DontCare,  1, Env, Humidity, 0.6),
			(cfreedriving, 100, DontCare,  2, Env, Humidity, 0.6),
			(cfreedriving, 100, DontCare,  3, Env, Humidity, 0.6),
			(cfreedriving, 100, DontCare,  4, Env, Humidity, 0.6),
			(cfreedriving, 100, DontCare,  5, Env, Humidity, 0.6),
			(cfreedriving, 100, DontCare,  6, Env, Humidity, 0.6),

			# Es regne stärker!
			(cfreedriving, 3900, DontCare,  0, Weather, StartRain, 1.0, RainDensity, 20000),
			(cfreedriving, 3900, DontCare,  1, Weather, StartRain, 1.0, RainDensity, 20000),
			(cfreedriving, 3900, DontCare,  2, Weather, StartRain, 1.0, RainDensity, 20000),
			(cfreedriving, 3900, DontCare,  3, Weather, StartRain, 1.0, RainDensity, 20000),
			(cfreedriving, 3900, DontCare,  4, Weather, StartRain, 1.0, RainDensity, 20000),
			(cfreedriving, 3900, DontCare,  5, Weather, StartRain, 1.0, RainDensity, 20000),
			(cfreedriving, 3900, DontCare,  6, Weather, StartRain, 1.0, RainDensity, 20000),
			(cfreedriving, 100, DontCare,  0, Env, Humidity, 1.0),
			(cfreedriving, 100, DontCare,  1, Env, Humidity, 1.0),
			(cfreedriving, 100, DontCare,  2, Env, Humidity, 1.0),
			(cfreedriving, 100, DontCare,  3, Env, Humidity, 1.0),
			(cfreedriving, 100, DontCare,  4, Env, Humidity, 1.0),
			(cfreedriving, 100, DontCare,  5, Env, Humidity, 1.0),
			(cfreedriving, 100, DontCare,  6, Env, Humidity, 1.0),

			# Es höre wieder auf!
			(cjam, 900, DontCare,  0, Weather, StartRain, 1.0, RainDensity, 0),
			(cjam, 900, DontCare,  1, Weather, StartRain, 1.0, RainDensity, 0),
			(cjam, 900, DontCare,  2, Weather, StartRain, 1.0, RainDensity, 0),
			(cjam, 900, DontCare,  3, Weather, StartRain, 1.0, RainDensity, 0),
			(cjam, 900, DontCare,  4, Weather, StartRain, 1.0, RainDensity, 0),
			(cjam, 900, DontCare,  5, Weather, StartRain, 1.0, RainDensity, 0),
			(cjam, 900, DontCare,  6, Weather, StartRain, 1.0, RainDensity, 0),
			(cfreedriving, 100, DontCare,  0, Env, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  1, Env, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  2, Env, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  3, Env, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  4, Env, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  5, Env, Humidity, 0.15),
			(cfreedriving, 100, DontCare,  6, Env, Humidity, 0.15),

			# Es werde wieder sonnig!
			(cjam, 2000, DontCare,  0, Weather, StartRain, 0.0),
			(cjam, 2000, DontCare,  1, Weather, StartRain, 0.0),
			(cjam, 2000, DontCare,  2, Weather, StartRain, 0.0),
			(cjam, 2000, DontCare,  3, Weather, StartRain, 0.0),
			(cjam, 2000, DontCare,  4, Weather, StartRain, 0.0),
			(cjam, 2000, DontCare,  5, Weather, StartRain, 0.0),
			(cjam, 2000, DontCare,  6, Weather, StartRain, 0.0),

			# DFA / SAFE
			(cempty,1,Normal,4, Scenario, Name, "Autobahn: Freie Fahrt",
				Number, 4040100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cempty,1,Normal,5, Scenario, Name, "Autobahn: Freie Fahrt",
				Number, 4040100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cempty,1,Normal,6, Scenario, Name, "Autobahn: Freie Fahrt",
				Number, 4040100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),

			(cfreedriving,3750,Normal,4, Scenario, State, 2),
			(cfreedriving,3750,Normal,5, Scenario, State, 2),
			(cfreedriving,3750,Normal,6, Scenario, State, 2),

			(cjam,1,Normal,4, Scenario, Name, "Autobahn: Stau",
				Number, 4050100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cjam,1,Normal,5, Scenario, Name, "Autobahn: Stau",
				Number, 4050100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cjam,1,Normal,6, Scenario, Name, "Autobahn: Stau",
				Number, 4050100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),

			(cjam,2750,Normal,4, Scenario, State, 2),
			(cjam,2750,Normal,5, Scenario, State, 2),
			(cjam,2750,Normal,6, Scenario, State, 2)
		};


		Motorway_Empty			cempty;
		Motorway_FreeDriving	cfreedriving;
		Motorway_Jam			cjam;
		MotorwayExit 			cexit;

		Connections =
		{
			Port1 <-> cempty.Begin,
			cempty.End <-> cfreedriving.Begin,
			cfreedriving.End <-> cjam.Begin,
			cjam.End <-> cexit.Port1,
			cexit.Port2 <-> cempty.Begin, # Motorway endlos
			cexit.Port3 <-> Port2, # Ausfahrten
			cexit.Port4 <-> Port3
		};
	};
