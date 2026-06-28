		DPUMOV MOV
		{
		    Computer = {MOV};
			NumPersons = 100;
			TreeviewGroup = "Verkehr";
			TreeviewGroup~en = "Traffic";

			PathPlanner = 1;
			Index = 55;
		};
		DPUMOVClient MOVClient
		{
			Computer = {VIS,TRF,BEV,SNDX};
			Index = 56;
			TreeviewGroup = "Verkehr";
			TreeviewGroup~en = "Traffic";

			NumPersons = 100;
			InformTRF = false;
		};
		TRF.MOVClient.InformTRF = true;
		Connections ={
		   MOV.SimTime -> MOVClient.SimTime
		};

		DPUMOPSGE MOPSGE
		{
			Alias = {MOPVis};
			Computer = {VIS};
			Index = 57;  # nach MOV, nach SCNXSGE!
			TreeviewGroup = "Visualisierung";
			TreeviewGroup~en = "Visualization";
		};

		includeif system\SYSMOVParams.inc
