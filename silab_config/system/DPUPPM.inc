	DPUInterface PPM
	{
		Computer = {PPM};
		Index = 0;
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";

		TreeviewGroup = "Mockup";
		Interface_Postfix = "_PPM";
		VARSet =
		{
			FahrerLid,
			FahrerPuls,
			FahrerPuls01
		};
	};

	includeif system\SYSPPM.inc
