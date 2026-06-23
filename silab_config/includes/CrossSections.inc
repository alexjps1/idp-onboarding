	# zunächst eine zusätzliche Superstructure definieren
	# ein Flussbett
	SCN Params
	{
		# Parameter für die Landschaftsgenerierung
		SCN CrossSection
		{
			SCN Superstructures
			{
				# Flussbett
				# Breite 7.5 m
				Strip Riverbed {
					Element Left {
						TextureName = "ROAD.PAVINGS.gravel2";

						Vy1 = -3.5;
						Vz1 = 0;
						Vy2 = -2.5;
						Vz2 = -.4;

						Texturey1 = 0;
						Texturey2 = 0.2;
						TextureWidth = 8;
						FixTextureSize = true;
					};
					Element Bottom {
						TextureName = "ROAD.PAVINGS.gravel2";

						Vy1 = -2.5;
						Vz1 = -.4;
						Vy2 = 2.5;
						Vz2 = -.4;

						Texturey1 = 0.2;
						Texturey2 = 0.8;
						TextureWidth = 8;
						FixTextureSize = true;
					};
					Element Right {
						TextureName = "ROAD.PAVINGS.gravel2";

						Vy1 = 2.5;
						Vz1 = -.4;
						Vy2 = 3.5;
						Vz2 = 0;

						Texturey1 = 0.8;
						Texturey2 = 1.0;
						TextureWidth = 8;
						FixTextureSize = true;
					};
				};
			};
		};
	};

   CrossSection NarrowRoad
   {
      # distgerade, distanz, höhe, textur, transparenz
      Shoulder = {1.0, 1.4, -0.7, Shoulder1, 1};
	  Overlay = {TarOld1, 1};

      ve = 100;
      LaneInfos =
      {
         (0, 3.0, 0, Towards, Tar, 1.0, 0.0, {(None, 0.0)}),
         (1, 3.0, 0, Onwards, Tar, 1.0, 0.0, {(None, 0.0)})
      };
      LaneTransitions =
      {
         (0, 0,
         {
			(StoneBorderLeft, -0.68, 1.5, Towards, 8.0, 0),
            (Reflectionposts_Night, -0.5, 1.0, Towards, 50.0, 0.0),
            (Line, 0.12, 0.15, Towards, 1.0, 0.0)
         }
         ),
         (1, 1,
         {
			(StoneBorderRight, 0.75, 1.5, Towards, 8.0, 0),
            (Reflectionposts_Night, 0.5, 1.0, Onwards, 50.0, 0.0),
            (Line, -0.12, 0.15, Towards, 1.0, 0.0)
         }
         )
      };
   };

   CrossSection NarrowRoad_smooth
   {
      # distgerade, distanz, höhe, textur, transparenz
      Shoulder = {1.0, 4.4, -0.7, Shoulder1, 1};
	  Overlay = {TarOld2, 1};

      ve = 100;
      LaneInfos =
      {
         (0, 3.0, 0, Towards, Tar, 1.0, 0.0, {(None, 0.0)}),
         (1, 3.0, 0, Onwards, Tar, 1.0, 0.0, {(None, 0.0)})
      };
      LaneTransitions =
      {
         (0, 0,
         {
			(StoneBorderLeft, -0.68, 1.5, Towards, 8.0, 0),
            (Reflectionposts_Night, -0.5, 1.0, Towards, 50.0, 0.0),
            (Line, 0.12, 0.15, Towards, 1.0, 0.0)
         }
         ),
         (1, 1,
         {
			(StoneBorderRight, 0.75, 1.5, Towards, 8.0, 0),
            (Reflectionposts_Night, 0.5, 1.0, Onwards, 50.0, 0.0),
            (Line, -0.12, 0.15, Towards, 1.0, 0.0)
         }
         )
      };
   };

   CrossSection CountryRoad
   {
      # distgerade, distanz, höhe, textur, transparenz
      Shoulder = {1.0, 1.4, -0.7, Shoulder1, 1};
      Overlay = {TarNew2, 1};

      ve = 100;
      LaneInfos =
      {
         (0, 3.5, 0, Towards, Tar, 1.0, 0.0, {(None, 0.0)}),
         (1, 3.5, 0, Onwards, Tar, 1.0, 0.0, {(None, 0.0)})
      };
      LaneTransitions =
      {
         (0, 0,
         {
			(StoneBorderLeft, -0.68, 1.5, Towards, 8.0, 0),
            (ReflectionPosts, -0.2, 1.0, Towards, 50.0, 0.0),
            (Line, 0.12, 0.15, Towards, 1.0, 0.0)
         }
         ),
         (0, 1, {(Line, 0.0, 0.15, Towards, 2.0, 6.0)}),
         (1, 1,
         {
			(StoneBorderRight, 0.75, 1.5, Towards, 8.0, 0),
            (ReflectionPosts, 0.2, 1.0, Onwards, 50.0, 0.0),
            (Line, -0.12, 0.15, Towards, 1.0, 0.0)
         }
         )
      };
   };

   CrossSection Bridge
   {
      # distgerade, distanz, höhe, textur, transparenz
      Shoulder = {1.0, 0.01, -1.0, Concrete1, 0};
      Overlay = {TarNew1, 1};

      ve = 100;
      LaneInfos =
      {
         (0, 3.5, 0.0, Towards, Tar, 1.0, 0.0, {(None, 0.0)}),
         (1, 3.5, 0.0, Onwards, Tar, 1.0, 0.0, {(None, 0.0)})
      };
      LaneTransitions =
      {
         (0, 0,
         {
			 (BridgeRailing, -0.95, 1.0, Towards, 0,0),
            (Line, 0.12, 0.15, Towards, 1.0, 0.0)
         }
         ),
         (0, 1,
         {
			 (Line, 0.0, 0.15, Towards, 2.0, 6.0),
             (BridgeBottom, 0.0, 1.0, Towards, 0.0, 0.0)
         }
         ),
         (1, 1,
         {
            (Line, -0.12, 0.15, Towards, 1.0, 0.0),
			 (BridgeRailing, 0.95, 1.0, Onwards, 0,0)
		 }
		 )
      };
   };

   CrossSection CountryRoad_Tunnel
   {
      # distgerade, distanz, höhe, textur
      Shoulder = {1.0, 1.0, -0.7, Concrete1};
      Overlay = {TarNew1, 1};

	  GraphicOptions = {NormallyDark, ObjectsCourseRelative};

      ve = 100;
      LaneInfos =
      {
         (0, 3.5, 0, Towards, Tar, 1.0, 0.0, {(None, 0.0)}),
         (1, 3.5, 0, Onwards, Tar, 1.0, 0.0, {(None, 0.0)})
      };
      LaneTransitions =
      {
         (0, 0, {
            (Line, 0.12, 0.15, Towards, 1.0, 0.0)
         }),
         (0, 1, {
			 (Line, 0.0, 0.15, Towards, 2.0, 0.0),
			# (TunnelInside_2, 0, 1, Onwards, 0, 0),
			# (TunnelLight, 0, 1, Onwards, 30, 0),
			 (TunnelVentilation, 0, 1, Onwards, 60, 18)
		 }),
         (1, 1, {
            (Line, -0.12, 0.15, Towards, 1.0, 0.0)
         })
      };
   };

   CrossSection River
   {
      # distgerade, distanz, höhe, textur
      Shoulder = {1.0, 5, 0, Shoulder1};

      ve = 70;
      LaneInfos =
      {
         (0, 3.5, 0, Towards, Transparent, 1.0, 0.0, {(None, 0.0)}, 0.0),
         (1, 3.5, 0, Onwards, Transparent, 1.0, 0.0, {(None, 0.0)}, 0.0)
      };
      LaneTransitions =
      {
		  (0, 0, {(StoneBorderLeft, -0.68, 1.5, Towards, 8.0, 0)}),
		  (0, 1, {(RiverUp, 0, 8.0, Towards, 0.0, 0.0),
		          (Riverbed, 0, 1.0, Towards, 0.0, 0.0)}),
		  (1, 1, {(StoneBorderRight, 0.75, 1.5, Towards, 8.0, 0)})
      };
   };

   CrossSection Transparent
   {
      # distgerade, distanz, höhe, textur
      Shoulder = {1.0, 5, 0, Transparent};

      ve = 70;
      LaneInfos =
      {
         (0, 3.5, 0, Towards, Transparent, 1.0, 0.0, {(None, 0.0)}),
         (1, 3.5, 0, Onwards, Transparent, 1.0, 0.0, {(None, 0.0)})
      };
      LaneTransitions =
      {
         (0, 0, {})
      };
   };

	CrossSection Motorway
	{
		ve = 150.0;

        Shoulder = {2.0, 2.4, -0.7, Shoulder1};
        Overlay = {TarNew3, 1};

		LaneInfos =
		{
			(0, 2.5, 0.0, Towards, Concrete1NoOverlay, 1.0, 0.0, { (None, 0.0) } ),
			(1, 3.75, 0.0, Towards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(2, 3.75, 0.0, Towards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(3, 3.0, 0.0, Towards, Grass1, 1.0, 0.0, {(None, 0.0)}, 0.0	),
			(4, 3.75, 0.0, Onwards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(5, 3.75, 0.0, Onwards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(6, 2.5, 0.0, Onwards, Concrete1NoOverlay, 1.0, 0.0, { (None, 0.0) } )
		};

		LaneTransitions =
		{
			(0, 0,
				{
					(StoneBorderLeft, -0.68, 1.5, Towards, 8.0, 0),
					(Reflectionposts, -0.3, 1.0, Towards, 50.0, 0.0)
				}
			),
			(0, 1,
				{
					(Line, 0.0, 0.3, Towards, 1.0, 0.0)
				}
			),
			(1, 2,
				{
					(Line, 0.0, 0.15, Towards, 6.0, 12.0)
				}
			),
			(2, 3,
				{
					(StoneBorderRight, 0.75, 1.5, Towards, 8.0, 0),
					(Line, -0.3, 0.3, Towards, 1.0, 0.0),
					(Guardrail, 0.4, 1.0, Towards, 0.0, 0.0)
				}
			),
			(3, 4,
				{
					(StoneBorderLeft, -0.68, 1.5, Towards, 8.0, 0),
					(Line, 0.3, 0.3, Onwards, 1.0, 0.0),
					(Guardrail, -0.4, 1.0, Towards, 0.0, 0.0)
				}
			),
			(4, 5,
				{
					(Line, 0.0, 0.15, Onwards, 6.0, 12.0)
				}
			),
			(5, 6,
				{
					(Line, 0.0, 0.3, Onwards, 1.0, 0.0)
				}
			),
			(6, 6,
				{
					(StoneBorderRight, 0.75, 1.5, Towards, 8.0, 0),
					(Reflectionposts, 0.3, 1.0, Onwards, 50.0, 0.0)#
				}
			)
		};
	};

	include includes\CrossSections_MotorwayWorks.inc
