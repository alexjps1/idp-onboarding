######### INHALT
# CrossSections

# CrossSection Motorway_7a		Querschnitt  ||v|v||^|^||  Spurbreite 3.75 m  freies Überholen     keine Begrenzung
# CrossSection Motorway_6b       Querschnitt |vv|^^||    |  Spurbreite gemischt -- AUTOBAHNBAUSTELLE --


CrossSection Motorway_7a
{
	ve = 150.0;

	#Shoulder = {1.0, 2.4, -0.7, Shoulder1};
	Shoulder = {2.0, 2.4, -0.7, Shoulder1};		#SH geändert
    Overlay = {TarOld3, 1};


	LaneInfos =
	{
		(0, 2.5, 0.0, Towards, Tar, 1.0, 0.0, { (None, 0.0) } ),
		(1, 3.75, 0.0, Towards, Tar, 1.0, 0.0, { (None, 0.0) } ),
		(2, 3.75, 0.0, Towards, Tar, 1.0, 0.0, { (None, 0.0) } ),
		(3, 3.0, 0.0, Towards, Grass1, 1.0, 0.0, {(None, 0.0)}, 0),
		(4, 3.75, 0.0, Onwards, Tar, 1.0, 0.0, { (None, 0.0) } ),
		(5, 3.75, 0.0, Onwards, Tar, 1.0, 0.0, { (None, 0.0) } ),
		(6, 2.5, 0.0, Onwards, Tar, 1.0, 0.0, { (None, 0.0) } )
	};

	LaneTransitions =
	{
		(0, 0,
			{
				(ReflectionPosts, -0.3, 1.0, Towards, 50.0, 0.0),
				(StoneBorderLeft, -0.68, 1.5, Towards, 8.0, 0)
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
				(Line, -0.3, 0.3, Towards, 1.0, 0.0),
				(Guardrail, 0.4, 1.0, Towards, 0.0, 0.0)
			}
		),
		(3, 4,
			{
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
				(ReflectionPosts, 0.3, 1.0, Onwards, 50.0, 0.0),
				(StoneBorderRight, 0.75, 1.5, Towards, 8.0, 0)
			}
		)
	};
};

CrossSection Motorway_6b
{
	ve = 150.0;

	Shoulder = {2.0, 2.4, -0.7, Shoulder1};
    Overlay = {TarNew1, 1};


	LaneInfos =
	{
		(0, 3.75, 0.0, Towards, Tar,     1.0, 0.0, { (None, 0.0) } ),
		(1, 3.00, 0.0, Towards, Tar,     1.0, 0.0, { (None, 0.0) } ),
		(2, 3.00, 0.0, Onwards, Tar,     1.0, 0.0, { (None, 0.0) } ),
		(3, 3.75, 0.0, Onwards, Tar,     1.0, 0.0, { (None, 0.0) } ),
		(4, 3.00, 0.0, Onwards, Grass1,  1.0, 0.0, { (None, 0.0) }, 0 ),
		(5,10.00, 0.0, Onwards, Gravel2NoOverlay, 1.0, 0.0, { (None, 0.0) } )
	};

	LaneTransitions =
	{
		(0, 0,
			{
				(ReflectionPosts, -0.3, 1.0, Towards, 50.0, 0.0),
				(StoneBorderLeft, -0.68, 1.5, Towards, 8.0, 0),
				(Line, 2.35, 0.3, Towards, 1.0, 0.0),
				(YellowLine, 0.12,  0.15,  Towards, 1.0, 0.0)
			}
		),
		(0, 1,
			{
				(Line, 2.5, 0.15, Towards, 6.0, 12.0),
				(YellowLine, 0,  0.15,  Towards, 6.0, 6.0)
			}
		),
		(1, 2,
			{
				(YellowLine, -0.2,  0.15,  Towards, 1,0),
			#	(ConcreteSeparator, 0, 1.0, Towards, 0, 0),
				(ConcreteSeparator, 0, 1.0, Onwards, 0, 0),
				(YellowLine,  0.2,  0.15,  Towards, 1,0)
			}
		),
		(2, 3,
			{
				(Line, 0, 0.15, Towards, 6.0, 12.0),
				(YellowLine, 0.1,  0.15,  Towards, 6,6)
			}
		),
		(3, 4,
			{
				(Line, -0.3, 0.3, Towards, 1.0, 0.0),
				(Guardrail, 0.4, 1.0, Onwards, 0.0, 0.0),
				(YellowLine, -0.17,  0.15,  Towards, 1,0)
			}
		),
		(5, 5,
			{
				(ReflectionPosts, 0.3, 1.0, Onwards, 50.0, 0.0)
			}
		)
	};
};
