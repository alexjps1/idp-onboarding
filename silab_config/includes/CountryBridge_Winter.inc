	define Module CountryBridge
	{
		ModuleID = 10501;
		
		define Course Ccenter
		{
			NodeID = 105031;
			CrossSection = CountryRoad;
			Bend(45, 27);
			
			# Guardrail rechte Straßenseite
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = -4.6;

				Entry = 0;
				Start= 5;
				End = 40;
				Exit = 45;
			};
						
			Objects = {
				(sign.Middle625_10, 5,  -4.5, 180),
				(sign.Middle625_10, 15,  -4.5, 180),
				(sign.Middle625_10, 25,  -4.5, 180),
				(sign.Middle625_10, 35,  -4.5, 180)
			};
		}; 

		define Course Capproach
		{
			NodeID = 105012;
			CrossSection = CountryRoad;
			Bend (200, 600);
			Bend (200, -610);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 100.0, 1000),
				(-10.0, 100.0, 1000),
				(-7.0, 150.0, 1000),
				(0.0, 50.0, 1000)
			};

			LandscapeTypeLeft Farmed
			{
				Height = 3;
				Ripple = 0.1;
				Offset = 1;
			#	GadgetDensity = (0, 0.1);
				#FieldDensity = (3, 4.5);
				OverlayDensity = 0.2;
				TreeDensity = (1, 2);
				MinObjdist = 0;
				MaxObjdist = 400;
			};

			LandscapeTypeRight Wooded
			{
				Height = 5;
				Ripple = (0, 1);
				Offset = -2;
				OverlayDensity = 0.8;
				#GadgetDensity = (0, 0);
				#FieldDensity = (1, 2);
				TreeDensity = (2, 4);
				MinObjdist = 10;
				MaxObjdist = 400;
			};

			# Guardrail vor Brücke rechte Straßenseite
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 4.2;

				Entry = 245;
				Start= 250;
				End = 400;
				Exit = 400;
			};

			# Guardrail vor Brücke, linke Straßenseite
			Strip Guardrail
			{
				Orientation = Towards;
				YOffset = -4.2;

				Entry = 245;
				Start= 250;
				End = 400;
				Exit = 400;
			};

			Objects =
			{
				(sign.sign150_278_060, 50, 4)				
			};
		};

		define Course Cbridge
		{
			NodeID = 105013;
			CrossSection = Bridge;
			Straight (220);
			Hedgehogs = {
				# Gummiband an der Brücke zunächst deaktivieren, dann aktivieren und am
				#   Ende wieder aktivieren und deaktivieren
				(  1,  DontCare,  0, SCNX, OffRoad , 1, OffRoadThreshold, 0.0),
				(  1,  DontCare,  1, SCNX, OffRoad , 1, OffRoadThreshold, 0.0),
				(  3,  DontCare,  0, SCNX, OffRoad , 0, OffRoadThreshold, 0.0),
				(  3,  DontCare,  1, SCNX, OffRoad , 0, OffRoadThreshold, 0.0),
				(216,  DontCare,  0, SCNX, OffRoad , 0, OffRoadThreshold, 0.0),
				(216,  DontCare,  1, SCNX, OffRoad , 0, OffRoadThreshold, 0.0),
				(219,  DontCare,  0, SCNX, OffRoad , 1, OffRoadThreshold, 0.0),
				(219,  DontCare,  1, SCNX, OffRoad , 1, OffRoadThreshold, 0.0)
			};

			# Landschaftsbeeinflussung (Beeinflussung des Höhenmodells)
			# 0 = Keine
			# 1 = Nur HCoarse
			# 2 = Nur HFine
			# 3 = HCoarse + HFine (default)
			LandscapeInfluence = 1;

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 220.0, 1000)
			};

			LandscapeTypeLeft Farmed
			{
				Height = 2.0;
				Ripple = 0.1;
				Offset = -15;
				OverlayDensity = 0;
				#FieldDensity = (3, 4.5);
				TreeDensity = (1, 2);
				MinObjdist = 0;
				MaxObjdist = 400;
			};

			LandscapeTypeRight Farmed
			{
				Height = (0, 1);
				Ripple = (0, 1);
				Offset = -17;
				OverlayDensity = 0.8;
				GadgetDensity = (0, 0);
				#FieldDensity = 1;
				#TreeDensity = (2, 4);
				MinObjdist = 10;
				MaxObjdist = 400;
			};

			Objects =
			{
				(environment.road.parts.bridgepillar, 30, 3.5),
				(environment.road.parts.bridgepillar, 30, -3.5),
				(environment.road.parts.bridgepillar, 80, 3.5),
				(environment.road.parts.bridgepillar, 80, -3.5),
				(environment.road.parts.bridgepillar,130, 3.5),
				(environment.road.parts.bridgepillar,130, -3.5),
				(environment.road.parts.bridgepillar,180, 3.5),
				(environment.road.parts.bridgepillar,180, -3.5)
			};
		};

		define Course Cafter
		{
			NodeID = 105014;
			CrossSection = CountryRoad;
			Bend (150, 200);

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 80.0, 1000),
				(-3.0, 50.0, 1000),
				(0.0, 20.0, 1000)
			};

			LandscapeTypeLeft Wooded
			{
				Height = 7;
				Ripple = (0, 1);
				Offset = -4;
				OverlayDensity = 0.7;
				#GadgetDensity = (0, 0);
				#FieldDensity = (1, 2);
				TreeDensity = (2, 4);
				MinObjdist = 0;
				MaxObjdist = 400;
			};

			LandscapeTypeRight Wooded
			{
				Height = 2;
				Ripple = 0.1;
				Offset = 0;
				OverlayDensity = 0.8;
			#	GadgetDensity = (0, 0.1);
				#FieldDensity = (3, 4.5);
				TreeDensity = (5, 7);
				MinObjdist = 10;
				MaxObjdist = 100;
			};

			# Guardrail nach Brücke rechte Straßenseite
			Strip Guardrail
			{
				Orientation = Onwards;
				YOffset = 4.2;

				Entry = 0;
				Start= 0;
				End = 50;
				Exit = 55;
			};

			# Guardrail nach Brücke, linke Straßenseite
			Strip Guardrail
			{
				Orientation = Towards;
				YOffset = -4.2;

				Entry = 0;
				Start= 0;
				End = 50;
				Exit = 55;
			};

			Objects =
			{
				# Tunnelschilder
				(sign.sign150_327, 140, 4, 0),
				(sign.sign150_327, 140, -4, 0)
			};
		};

		define Course Ctunnel
		{
			NodeID = 106011;
			CrossSection = CountryRoad_Tunnel;

			# l = 400 m
			Bend(200, -400);
			Bend(200, 370);
			Hedgehogs = {
				# Gummiband an der Brücke zunächst deaktivieren, dann aktivieren und am
				#   Ende wieder aktivieren und deaktivieren
				(  1,  DontCare,  0, SCNX, OffRoad , 1, OffRoadThreshold, 0.0),
				(  1,  DontCare,  1, SCNX, OffRoad , 1, OffRoadThreshold, 0.0),
				(  3,  DontCare,  0, SCNX, OffRoad , 0, OffRoadThreshold, 0.0),
				(  3,  DontCare,  1, SCNX, OffRoad , 0, OffRoadThreshold, 0.0),
				(396,  DontCare,  0, SCNX, OffRoad , 0, OffRoadThreshold, 0.0),
				(396,  DontCare,  1, SCNX, OffRoad , 0, OffRoadThreshold, 0.0),
				(399,  DontCare,  0, SCNX, OffRoad , 1, OffRoadThreshold, 0.0),
				(399,  DontCare,  1, SCNX, OffRoad , 1, OffRoadThreshold, 0.0)
			};

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 30.0, 1000),
				(3.0, 170.0, 1000),
				(-3.0, 170.0, 1000),
				(0.0, 30.0, 1000)
			};

			LandscapeTypeLeft Wooded
			{
				Offset = 10;
				OverlayDensity = 0.9;
		#		MinObjdist = 0;
		#		MaxObjdist = 200;
			};

			LandscapeTypeRight Wooded
			{
				Offset = 10;
				OverlayDensity = 0.9;
		#		MinObjdist = 0;
		#		MaxObjdist = 200;
			};

			LandscapeTypeExtra Tunnel
			{
				Left = false;
				MinObjdist = -7.0;
				MaxObjdist = 0.0;
				MinObjpos = 6;
				MaxObjpos = 390;
				# optional parameter:
				# Obj1Occurrence = n # result: each n'th object is the first object in the tunnel group (tunnel_parking)
				# Obj2Occurrence = m # result: each m'th object is the second object in the tunnel group (tunnel_exit)
				# etc... until Obj4Occurrence
			};

			Strip TunnelTop_8
			{
				Orientation = Onwards;
				YOffset = 0;

				Start = 5;
				End = 395;
			};


			Objects = {
				(environment.road.tunnel_entrance, 0, 0),
				(environment.road.tunnel_entry_hill_left, 0, 0),			#optional
				(environment.road.tunnel_entry_hill_right, 0, 0),			#optional

				(SCNX.ROAD.SUPERSTRUCTURES.OBJECTS.tunnel_lamp, 0, 0),	# extra light at entrance
				(SCNX.ROAD.SUPERSTRUCTURES.OBJECTS.tunnel_lamp, 396, 0), # extra light at exit

				(environment.road.tunnel_entrance, 396, 0, 180),
				(environment.road.tunnel_entry_hill_left, 396, 0, 180),	#optional
				(environment.road.tunnel_entry_hill_right, 396, 0, 180)	# "
			};
		};

		define Course Cbelow
		{
			NodeID = 105019;
			CrossSection = CountryRoad;
			Overlay = {TarOld5, 1};

			Straight (100);
			Bend (300, 180);
			Straight (150);
			Bend (300, 180);
			Straight(400);

			# Landschaftsbeeinflussung (Beeinflussung des Höhenmodells)
			# 0 = Keine
			# 1 = Nur HCoarse
			# 2 = Nur HFine
			# 3 = HCoarse + HFine (default)
			# LandscapeInfluence = 2;

			HeightProfile =
			{
				# Steigung/Gefälle, Länge, Ausrundungshalbmesser
				(0.0, 150.0, 500),
				(-10.0, 400.0, 500),
				(0.0, 700.0, 500)
			};

			LandscapeTypeLeft Farmed
			{
				Height = 2;
				Ripple = 0.1;
				Offset = -3;
				OverlayDensity = 0.2;
			#	GadgetDensity = (0, 0.1);
				#FieldDensity = (3, 4.5);
				TreeDensity = (5, 7);
				MinObjdist = 0;
				MaxObjdist = 60;
				MaxObjpos = 1000;
				MaxHillDist = 50;
				Gradient = -0.1;
			};

			LandscapeTypeRight Wooded
			{
				Height = 1;
				Ripple = (0, 1);
				Offset = -2;
				OverlayDensity = 0.6;
				#GadgetDensity = (0, 0);
				#FieldDensity = (1, 2);
				TreeDensity = (2, 4);
				MinObjdist = 10;
				MaxObjdist = 400;
				MaxObjpos = 1000;
			};

			LandscapeTypeExtra Farmed
			{
				Left = true;
				TreeDensity = (5, 7);
				MinObjdist = 0;
				MaxObjdist = 60;
				MinObjpos = 1050;
			};

			LandscapeTypeExtra Wooded
			{
				Left = false;
				TreeDensity = (2, 4);
				MinObjdist = 10;
				MaxObjdist = 400;
				MinObjpos = 1050;
			};

			# Vorwarnung
			Objects =
			{
				# Schilder Ende
				(sign.sign150_H_103_10, 200, -4, 180),
				(sign.sign150_U_1004_32, 200, -4, 180),
				(sign.sign150_274_060, 100, -4, 180)
			};

		};


		Hedgehogs =
		{	# (Course, TrackPos, Direction, LaneID, Family, Name1, Value)
			(c1,1,Normal,1, Scenario, Name, "Straßenbrücke",
				Number, 1050100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(c1,1,Reverse,0, Scenario, Name, Scenario, Name, "Straßenbrücke",
				Number, 1050100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(c3,1,Normal,1, Scenario, State, 2),
			(c3,1,Reverse,0, Scenario, State, 2),
			/*(c1b,1,Normal,1, Scenario, Name, "Seebrücke",
				Number, 1050200, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(c1b,1,Reverse,0, Scenario, Name, Scenario, Name, "Seebrücke",
				Number, 1050200, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(c3b,1,Normal,1, Scenario, State, 2),
			(c3b,1,Reverse,0, Scenario, State, 2),*/
			(cta,1,Normal,1, Scenario, Name, "Tunnel",
				Number, 1060100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cta,1,Reverse,0, Scenario, Name, Scenario, Name, "Tunnel",
				Number, 1060100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(cta,399,Normal,1, Scenario, State, 2),
			(cta,399,Reverse,0, Scenario, State, 2) /*,
			(ctb,1,Normal,1, Scenario, Name, "Tunnel",
				Number, 1060100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(ctb,1,Reverse,0, Scenario, Name, Scenario, Name, "Tunnel",
				Number, 1060100, State, 1, ActivateLateral,1, ActivateSpeed,1, ActivateTimeHeadway,0, ActivateVigilanz,0, ActivateGapSize, 0, ActivateLaneID, -1),
			(ctb,399,Normal,1, Scenario, State, 2),
			(ctb,399,Reverse,0, Scenario, State, 2)*/
		};


		Ccenter tk;
		Capproach c1;
		Cbridge c2;
		Cafter c3;
		Ctunnel  cta;
		#Capproach2 c1b;
		#Cbridge2 c2b;
		#Cafter c3b;
		#Ctunnel ctb;
		Cbelow cabfahrt;


		Connections =
		{
			# Geradeaus
			c1.Begin <-> tk.Begin,
			c1.End <-> c2.Begin,
			c2.End <-> c3.Begin,
			c3.End <-> cta.Begin,
			cta.End <-> Port2,
			# Abfahrt
			tk.End <-> cabfahrt.Begin,
			cabfahrt.End <-> Port1
			# Rückwärts
			#c1b.Begin <-> tk.Begin,
			#c1b.End <-> c2b.Begin,
			#c2b.End <-> c3b.Begin,
			#c3b.End <-> ctb.Begin,
			#ctb.End <-> Port3
		};

		Traffic ub1
		{
			TrafficFlow GegenverkehrWechsel
			{
				Source GegenW
				{
					Position =(SimCar, -600, 0);

					Vehicles =
					{
						(1, CarVan, (HazardFree, 15, 22, 5, 2, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 20, 5, 2, 10, -14)),
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
					Position = (SimCar, 610, 0);
				};

				Flowpoints=
				{
					(cta, 399, 0, Traffic, Light, 1),
					(cta, 299, 0, Traffic, Light, 1),
					(cta, 199, 0, Traffic, Light, 1),
					(cta,  99, 0, Traffic, Light, 1),
					(cta, 5, 0, Traffic, Light, 0),
					/*(ctb, 399, 0, Traffic, Light, 1),
					(ctb, 299, 0, Traffic, Light, 1),
					(ctb, 199, 0, Traffic, Light, 1),
					(ctb,  99, 0, Traffic, Light, 1),
					(ctb, 5, 0, Traffic, Light, 0),*/

					#(cabfahrt, 1249, 1, SimCar, ActivateSource, (GegenW)),
					#(cabfahrt, 1239, 1, SimCar, ActivateDrain, (GegenW)),
					#(cabfahrt, 600, 1, SimCar, DeactivateSource, (GegenW)),
					(c1, 1, 1, SimCar, ActivateSource, (GegenW)),
					#(c1, 10, 1, SimCar, ActivateDrain, (GegenW)),
 					(c3, 1, 1, SimCar, DeactivateSource, (GegenW)) /*,
					(c1b, 1, 1, SimCar, ActivateSource, (GegenW)),
					#(c1b, 10, 2, SimCar, ActivateDrain, (GegenW)),
					(c3b, 1, 1, SimCar, DeactivateSource, (GegenW))*/
				};
			};

			TrafficFlow GegenverkehrWechsel
			{
				Source GegenW
				{
					Position =(SimCar, -600, 1);

					Vehicles =
					{
						(1, CarVan, (HazardFree, 15, 22, 5, 2, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 20, 5, 2, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 20, 5, 4, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 25, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14)),
						(1, CarVan, (HazardFree, 15, 22, 5, 1, 10, -14))
					};

					Parameters = (Gauss, 7, 2, 1236, 512);
				};

				Drain GegenW
				{
					Position = (SimCar, 610, 1);
				};

				Flowpoints=
				{
					(cta, 399, 0, Traffic, Light, 1),
					(cta, 299, 0, Traffic, Light, 1),
					(cta, 199, 0, Traffic, Light, 1),
					(cta,  99, 0, Traffic, Light, 1),
					(cta, 5, 0, Traffic, Light, 0),
					/*(ctb, 399, 0, Traffic, Light, 1),
					(ctb, 299, 0, Traffic, Light, 1),
					(ctb, 199, 0, Traffic, Light, 1),
					(ctb,  99, 0, Traffic, Light, 1),
					(ctb, 5, 0, Traffic, Light, 0),*/

					(cabfahrt, 1249, 0, SimCar, ActivateSource, (GegenW)),
					(cabfahrt, 1239, 0, SimCar, ActivateDrain, (GegenW)),
					(cabfahrt, 600, 0, SimCar, DeactivateSource, (GegenW))
					#(c1, 1, 2, SimCar, ActivateSource, (GegenW)),
					#(c1, 10, 2, SimCar, ActivateDrain, (GegenW)),
 					#(c3, 1, 2, SimCar, DeactivateSource, (GegenW)),
					#(c1b, 1, 2, SimCar, ActivateSource, (GegenW)),
					#(c1b, 10, 2, SimCar, ActivateDrain, (GegenW)),
					#(c3b, 1, 2, SimCar, DeactivateSource, (GegenW))
				};
			};

            Vehicle vorne1
			{
				Vehicle = Car;
				Position = (c1,200,1);
				Behaviour = {(EXSTD1, 5, 25, 2, 20)}; 
				Flowpoints =
				{
					(c1, 1, 1, SimCar, Activate),
					(c1, 201, 1, Traffic, AutoIndicatorLightControl, 0),
					(c3, 1, 1, Traffic, IndicatorRight,1),
					(c3, 30, 1, Traffic, TargetSpeed,15),
					(c3, 80, 1, Traffic, TargetSpeed,5),
					(c3, 90, 1, Traffic, StopAt, 40, 1.5)
				};

			};

            /*Vehicle vorne2
			{
				Vehicle = Car;
				Position = (c1b,200,1);
				Behaviour = {(EXSTD1, 5, 25, 2, 20)}; 

				Flowpoints =
				{
					(c1b, 1, 1, SimCar, Activate),
					(c1b, 201, 1, Traffic, AutoIndicatorLightControl, 0),
					(c3b, 1, 1, Traffic, IndicatorRight,1),
					(c3b, 30, 1, Traffic, TargetSpeed,15),
					(c3b, 80, 1, Traffic, TargetSpeed,5),
					(c3b, 90, 1, Traffic, StopAt, 40, 1.5)
				};

			};*/
		};

	};
