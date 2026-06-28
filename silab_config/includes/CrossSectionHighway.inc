
	CrossSection Highway
	{
		ve = 150.0;

        Shoulder = {2.0, 1.4, -0.7, Shoulder1};
        Overlay = {TarNew2, 1};

		LaneInfos =
		{
			(0, 3.75, 0.0, Towards, Tar1NoOverlay, 1.0, 0.0, { (None, 0.0) } ),
			(1, 3.75, 0.0, Towards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(2, 3.75, 0.0, Towards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(3, 3.75, 0.0, Towards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(4, 3.0, 0.0, Towards, Grass1, 1.0, 0.0, {(None, 0.0)} ),
			(5, 3.75, 0.0, Onwards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(6, 3.75, 0.0, Onwards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(7, 3.75, 0.0, Onwards, Tar, 1.0, 0.0, { (None, 0.0) } ),
			(8, 3.75, 0.0, Onwards, Tar1NoOverlay, 1.0, 0.0, { (None, 0.0) } )
		};

		LaneTransitions =
		{
			(0, 0,
				{
					(Reflectionposts, -0.2, 1.0, Towards, 50.0, 0.0),
					(Line, 0.175, 0.15, Towards, 1.0, 0.0),
					(Guardrail, -0.3, 1.0, Towards, 0.0, 0.0)
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
					(Line, 0.0, 0.15, Towards, 6.0, 12.0)
				}
			),
			(3, 4,
				{
					(Line, -0.3, 0.3, Towards, 1.0, 0.0),
					(Guardrail, 0.4, 1.0, Towards, 0.0, 0.0)
				}
			),
			(4, 5,
				{
					(Line, 0.3, 0.3, Onwards, 1.0, 0.0),
					(Guardrail, -0.4, 1.0, Onwards, 0.0, 0.0)
				}
			),
			(5, 6,
				{
					(Line, 0.0, 0.15, Onwards, 6.0, 12.0)
				}
			),
			(6, 7,
				{
					(Line, 0.0, 0.15, Onwards, 6.0, 12.0)
				}
			),
			(7, 8,
				{
					(Line, 0.0, 0.3, Onwards, 1.0, 0.0)
				}
			),
			(8, 8,
				{
					(Reflectionposts, 0.2, 1.0, Onwards, 50.0, 0.0),
					(Line, -0.175, 0.15, Onwards, 1.0, 0.0),
					(Guardrail, 0.3, 1.0, Onwards, 0.0, 0.0)
				}
			)
		};
	};

	
	
