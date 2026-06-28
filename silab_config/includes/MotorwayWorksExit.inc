		define Course C4aA
		{
			NodeID = 1;
			CrossSection = Motorway_6b;

			Bend (180, 1500);
			Bend (120,-1800);
			Bend (300, 1200);

			HeightProfile = {
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				( 0, 100,1500),
				( 4, 200,1500),
				(-4, 200,1500),
				( 0, 100,1500)
			};

			LandscapeTypeLeft Farmed {
				Gradient = 0;
				GradientEnd = 0.15;
				OverlayDensity = 8;
				Offset = 5;
				Height = 2;
				Ripple = 0.5;
				#MinObjdist = 10;
				MaxObjdist = 200;
			};
			# Deko links
			Object Meadow
			{
				Orientation = Towards;
				YOffset = -14.5;
				Distance = 4.5;
			};
			Strip Guardrail
			{
				Orientation = Towards;
				YOffset = -14.7;
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				Objangle = 0;
				Objdist = (15, 3);
				MinObjdist = 60;
				MaxObjdist = 75;
				MinObjpos = 50;
				MaxObjpos = 400;
			};

			# Deko mitte
			Object GrasslandHighway
			{
				Orientation = Onwards;
				YOffset = 1.75;
				Distance = 4.5;
			};
			LandscapeTypeExtra RoadsideBush {
				Left = false;
				MinObjdist = -13;
				MaxObjdist = -10;
				ObjDensity = 0.5;
			};

			LandscapeTypeRight Wooded {
				Gradient = 0.1;
				TreeDensity = 3;
				OverlayDensity = 1;
				Offset = 5;
				MinObjdist = 10;
				MaxObjdist = 200;
			};
			# Deko rechts
			Object Grassland
			{
				Orientation = Onwards;
				YOffset = 14.5;
				Distance = 4.5;
			};
			LandscapeTypeExtra Grassland
			{
				Left = false;

				MinObjdist = 3.5;
				MaxObjdist = 25;

				Override = { Tree, User };
			};

			Objects = {
				# Beschränkung auf 80 km/h
			#	(sign.Sign250_274_080, 50, 1.5),

				# rüber in 600 m
				(sign.Sign250_H_505_22, 150, 2.5),
				(sign.Sign250_U_1004_wide_34, 150, 2.5),

				# Überholverbot
				(sign.Sign250_H_276, 240, 1.9),
				(sign.Sign250_U_1049_13, 240, 1.9),

				# rüber in 400 m
				(sign.Sign250_H_505_22, 350, 2.5),
				(sign.Sign250_U_1004_wide_33, 350, 2.5),

				# rüber in 200 m
				(sign.Sign250_H_505_22, 549, 2.5),
				(sign.Sign250_U_1004_wide_32, 549, 2.5),

				# Überholverbot
				(sign.Sign250_H_276, 549, -14, 180),
				(sign.Sign250_U_1049_13, 549, -14, 180),

			#	(area2.Road.tarrepair3a, 550, -2),

				(environment.road.overpass_motorway, 250, 1)
			};
		};

		define Course C4aC
		{
			NodeID = 1;
			CrossSection = Motorway_7a;
        	Overlay = {TarNew3, 1};

			Bend (180, 1500);
			Bend (120,-1800);
			Bend (300, 1200);

			HeightProfile = {
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				( 0, 100,1500),
				( 4, 200,1500),
				(-4, 200,1500),
				( 0, 100,1500)
			};

			LandscapeTypeLeft Wooded {
				Gradient = 0;
				GradientEnd = 0.15;
				Height = 2;
				Ripple = 0.5;
				MinObjdist = 30;
				MaxObjdist = 50;
				TreeDensity = 4;
			};
			# Deko links
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
			LandscapeTypeExtra Grassland
			{
				Left = true;

				MinObjdist = 3.5;
				MaxObjdist = 25;

				Override = { Tree, User };
			};
			LandscapeTypeExtra Hedge {
				Objdist = (15, 3);
				Left = true;
				MinObjdist = 50;
				MaxObjdist = 70;
			};

			LandscapeTypeExtra Forest {
				Left = true;
				MinObjdist = 70;
				MaxObjdist = 100;
				Objangle = 0;
			};

			LandscapeTypeExtra Forest {
				Left = true;
				MinObjdist = 100;
				MaxObjdist = 250;
				MinObjpos = 5;
				MaxObjpos = 35;
				Objangle = 0;
			};

			LandscapeTypeExtra Forest {
				Left = true;
				MinObjdist = 100;
				MaxObjdist = 250;
				MinObjpos = 565;
				MaxObjpos = 595;
				Objangle = 0;
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
			LandscapeTypeRight Farmed {
				Gradient = 0.1;
				#FieldDensity = 3;
				OverlayDensity = 1;
				#MinObjdist = 10;
				MaxObjdist = 200;
				WaySetback = (7, 2);
			};
			# Deko rechts
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

			Sign sa	{	Sign = ("274_100"); s = 85; d = 12;	};
			Sign sa	{	Sign = ("274_100"); s = 85; d = 0.5; };


			Objects = {
				# Baustelle in 800 m
				(sign.Sign250_H_123, 595, -12, 180),
				(sign.Sign250_U_1004_34_800, 595, -12, 180),
				(sign.Sign250_H_123, 595, -0.5, 180),
				(sign.Sign250_U_1004_34_800, 595, -0.5, 180),

				# Beschränkung auf 100 km/h
				(sign.Sign250_274_100, 500, -12, 180),
				(sign.Sign250_274_100, 500, -0.5, 180),

				# rüber in 600 m
				(sign.Sign250_H_515_22, 400, -13, 180),
				(sign.Sign250_U_1004_wide_34, 400, -13, 180),

				# Beschränkung auf 80 km/h
				(sign.Sign250_274_080, 300, -12, 180),
				(sign.Sign250_274_080, 300, -0.5, 180),

				# rüber in 400 m
				(sign.Sign250_H_515_22, 200, -13, 180),
				(sign.Sign250_U_1004_wide_33, 200, -13, 180),
			#	(sign.Sign250_H_515_22, 400, 0),
			#	(sign.Sign250_U_1004_wide_33, 400, 0),

				# Überholverbot
				(sign.Sign250_H_276, 100, -12, 180),
				(sign.Sign250_U_1049_13, 100, -12, 180),
				(sign.Sign250_H_276, 100, -0.5, 180),
				(sign.Sign250_U_1049_13, 100, -0.5, 180)

				#(sign.Sign250_274_100,  85, 12),
				#(sign.Sign250_274_100,  85, 0.5)
			};
		};

		C4aA 				c1_4a;
		MotorwayWorksExit 	c2_4a;
		C4aC 				c3_4a;

		Connections =
		{
			c2_4a.Port1 <-> c1_4a.End,
			c2_4a.Port2 <-> c3_4a.Begin
		};
