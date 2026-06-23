	Pool Allround : Full
	{
		Executable = true;

		################################################################################################
		# Nacht
		include system/SYSNight_SGE.inc

		################################################################################################
		#MiniNav fuer SCNX:
		include system/SYSNav_SGE.inc

		###############################################################################################
		# Regen & Gewitter
		include system/SYSWeather_SGE.inc

		SIGWorld.RenderMode = 8;
		Environment.InHumidity = 0.15;
		Environment.InTimeOfDay = 13;			#war 13, von mir geändert 
		Environment.InReflectionVisible = 0;

		# Fehler in HazardAvoidance umgehen
		# Bremslichter nur aktivieren wenn mit mehr als 1.5 m/s² gebremst wird
		TRF.AutoBrakeLightControl = 3;
		TRF.AutoBrakeLightThreshold = -3;
	};
	
	Pool Videoaufzeichnung : Allround
   	{
			Executable = true;
			include includes\Videoaufzeichnung.inc;
	};

	includeif ext\includes\DFA.inc

	includeif includes/DPUs_Test.inc
