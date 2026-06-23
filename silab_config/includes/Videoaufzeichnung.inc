	# MPEG4 ist leider noch langsamer
	DPUSGECapture Video
	{
		Computer = {RECORD};
		Index = 100;

		Subsample = 2;
		Threads = 4;

		Path = "/Daten/SILABDemo/";
		FileName = VAR_DATAFILENAME;
		Extension = "mp4"; 
		Overwrite = true; 

		CaptureAudio = false;  //true bringt einen Fehler baim Öffnen des Audio-Aufnahmegeräts

		#HighVideoQuality = true;
		VideoCodec = "mpeg4"; 
		VideoOptions = "g=150 bf=0";
		VideoKbps = 9000;

		SysDebug = 0;
		GenerateAudio = true;
		ListFormats = true;
	}; 
	
	# Konfiguration der SGE Ansicht auf QUAD
	RECORD.TRFSGE.SimCarShow = false;
	RECORD.TRFSGE.SimCarName = Cars.OpelZafira.Blue;
	RECORD.SGEView.WindowW = 1280;
	RECORD.SGEView.WindowH = 720;
	 
	RECORD.SGEView.ViewportX = 0;
	RECORD.SGEView.ViewportY = 0;
	RECORD.SGEView.ViewportW = 1280;
	RECORD.SGEView.ViewportH = 720;
	
	RECORD.SGEView.HeadY = 0.5;
	RECORD.SGEView.HeadX = 0.1;
	RECORD.SGEView.HeadZ = 0.5;

	# Parameter für die Darstellung setzen
    RECORD.SGEView.VerticalSync = false; 

	DPUSGEObject EgoCarHighlight
	{
		Computer = {RECORD};
		Index = 400;
		X = 496;	
		Y = 650;
		Z = 5;
		sX = 0.8;
		sY = 1.8;
		Show = 1.0;
		Object = cars.Octavia.blau;
	};
