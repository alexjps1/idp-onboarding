	DPUInterface MotionSensor
	{
		Computer = {VDYN};
		Index = 0; # bei DPUInterface ist der Index egal
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";

		Interface_Postfix = "_MotionSensor";
		VARSet = {
			AX,
			AY,
			AZ,
			vyaw,
			vpitch,
			vroll
		};
	};
