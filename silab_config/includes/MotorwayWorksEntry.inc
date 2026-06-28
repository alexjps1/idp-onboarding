		define Course C3aA
		{
			NodeID = 1;
			CrossSection = Motorway_7a;

			Bend (180, 1500);
			Bend (120,-1800);
			Bend (300, 1200);

			HeightProfile = {
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				( 0, 100,1500),
				#( 4, 200,1500),
				( 1, 200,1500),
				(-4, 200,1500),
				( 0, 100,1500)
			};

			LandscapeTypeLeft Farmed {
				Gradient = 0;
				GradientEnd = 0.1;
				Height = 2;
				Ripple = 0.5;
				#MinObjdist = 10;
				MaxObjdist = 200;
				OverlayDensity = 0.8;
				#GadgetDensity = 2;
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
			LandscapeTypeExtra Alley2 {
				Left = true;
				Objdist = (15, 2);
				Objangle = 0;
				MinObjdist = 95;
				MaxObjdist = 120;
				MinObjpos = 50;
				MaxObjpos = 300;
			};
			LandscapeTypeExtra Hedge {
				Left = true;
				Objangle = 0;
				MinObjdist = 10;
				MaxObjdist = 100;
				MinObjpos = 280;
				MaxObjpos = 295;
			};
			LandscapeTypeExtra Alley2 {
				Left = true;
				Objdist = (15, 2);
				Objangle = 0;
				MinObjdist = 130;
				MaxObjdist = 155;
				MinObjpos = 300;
				MaxObjpos = 550;
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
			LandscapeTypeRight Wooded {
				Gradient = 0.15;
				TreeDensity = 3;
				OverlayDensity = 1;
				MinObjdist = 10;
				MaxObjdist = 200;
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
				End = 10;
				Exit = 15;
			};
			LandscapeTypeExtra Grassland
			{
				Left = false;

				MinObjdist = 3.5;
				MaxObjdist = 25;

				Override = { Tree, User };
			};

			TrafficRules T {
				Sign sa	{	Sign = ("274_100"); s = 300; d = 13;	};
				Sign sa	{	Sign = ("274_100"); s = 300; d = -1.5;	};
				Sign sa	{	Sign = ("274_080"); s = 450; d = 13;	};
				Sign sa	{	Sign = ("274_080"); s = 450; d = -1.5;	};
			};

			Objects =
			{
				# Baustelle in 600 m
				(sign.Sign250_H_123, 5, 12),
				(sign.Sign250_U_1004_34, 5, 12),
				(sign.Sign250_H_123, 5, 0.5),
				(sign.Sign250_U_1004_34, 5, 0.5),

				#(sign.Sign250_274_100, 300, 13),
				#(sign.Sign250_274_100, 300, -1.5),

				# Überholverbot
				(sign.Sign250_H_276, 550.5, 13),
				(sign.Sign250_U_1049_13, 550, 13),
			#	(sign.Sign250_H_276, 500, 0.5),
			#	(sign.Sign250_U_1049_13, 500, 0.5),

				#(sign.Sign250_274_080, 450, 13),
				#(sign.Sign250_274_080, 450, -1.5),

				# rüber in 200 m
				(sign.Sign250_H_505_11, 599, 13.5),
				(sign.Sign250_U_1004_wide_32, 599, 13.5),
			#	(sign.Sign250_H_505_11, 599, 0),
			#	(sign.Sign250_U_1004_wide_32, 599, 0),


				# VERZIERUNG RECHTS
				# WINDKRAFTWERKE
				(house.Windmill, 250, 100),
				(house.Windmill, 350, 210),
				(house.Windmill, 450, 320)
			};
		};

		C3aA 				c1_3a;
		MotorwayWorksEntry 	c2_3a;

		Connections =
		{
			c1_3a.End  <-> c2_3a.Port1
		};


