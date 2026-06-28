	DPULimiter ~MSTPitchRoad
	{
		Index = 18;
		Computer = {VDYN};
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";

		SlopeLimitNeg = -0.067;
		SlopeLimitPos = 0.067;
	};
	DPULimiter ~MSTRollRoad
	{
		Index = 18;
		Computer = {VDYN};
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";

		SlopeLimitNeg = -0.067;
		SlopeLimitPos = 0.067;
	};
	Connections =
	{
		 VDyn.PitchRoad 		-> ~MSTPitchRoad.In
		,~MSTPitchRoad.Out 		-> ~MSTVeda.PitchRoad
		,VDyn.RollRoad 			-> ~MSTRollRoad.In
		,~MSTRollRoad.Out 		-> ~MSTVeda.RollRoad
	};