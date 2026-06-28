	DPUSGERecorder SGERecorder
	{
		Alias = {SIGRecorder};
		Computer = {RECORD};
		Index = 90;

		Threaded = true;

		CamName = "Kamera-Ansicht";
		CamName1 = "Verfolger-Sicht";
	};
	
	#Verknüpfungen primaere Kamerasicht
	Connections = 
	{
		VDyn.X -> SGERecorder.X,
		VDyn.Y -> SGERecorder.Y,
		VDyn.yaw -> SGERecorder.yaw,
		SCNX.ZOut -> SGERecorder.Z,
		VDyn.pitch -> SGERecorder.pitch,
		VDyn.roll -> SGERecorder.roll,
		SCNX.PitchRoad -> SGERecorder.pitchRoad,
		SCNX.RollRoad -> SGERecorder.rollRoad
	};

	#Verfolger-Ansicht
	DPURubyScript ReplayVerfolger01
	{
		Computer = {RECORD};
    	Index = 110; 
    	Script = "RPUReplayCamera.rb"; 
    	Height = 2;
    	Back = 6;
    	IgnorePitchRoll = 1.0;
    	PitchOffset = 0.25;
	}; 
	
	Connections = 
	{
		VDynView.X -> ReplayVerfolger01.XIn,
		VDynView.Y -> ReplayVerfolger01.YIn,
		SCN.ZOut -> ReplayVerfolger01.ZIn,
		VDynView.yaw -> ReplayVerfolger01.YawIn,
		VDynView.pitch -> ReplayVerfolger01.PitchIn,
		VDynView.roll -> ReplayVerfolger01.RollIn,

		
		ReplayVerfolger01.XOut -> SIGRecorder.X1,
		ReplayVerfolger01.YOut -> SIGRecorder.Y1,
		ReplayVerfolger01.ZOut -> SIGRecorder.Z1,
		ReplayVerfolger01.YawOut -> SIGRecorder.yaw1,
		ReplayVerfolger01.PitchOut -> SIGRecorder.pitch1,
		ReplayVerfolger01.RollOut -> SIGRecorder.roll1
	};
	
	# Zusätzliche systemabhängige Optionen für die Replay-Option
	includeif system/SYSReplayOptions.inc	
	# Zusätzliche systemabhängige Optionen, für's
	# Überschreiben von Einstellungen, falls ein existierender
	# Sim-Rechner als RECORDER oder VIDEO-Generator benutzt werden soll.
	includeif system/SYSRecordOptions.inc
