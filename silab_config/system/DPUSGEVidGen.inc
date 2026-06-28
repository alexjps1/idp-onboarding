	DPUSGEVidGen SGEVidGen
	{
		Alias = {SIGVidGen};
		Computer = {RECORD};
		Index = 100;

		VideoCodec = "DivX 6";
		CompressionOptions = "lib\configurations\VidCap\DivX6HiRes.vcc";

		Overwrite = true;
		SaveFile = "SGEVidGen.avi";

		Subsample = 2;
	};

	# Zusätzliche systemabhängige Optionen für die VIDEO-Option
	includeif system/SYSVideoOptions.inc	
	# Zusätzliche systemabhängige Optionen, für's
	# Überschreiben von Einstellungen, falls ein existierender
	# Sim-Rechner als RECORDER oder VIDEO-Generator benutzt werden soll.
	includeif system/SYSRecordOptions.inc
