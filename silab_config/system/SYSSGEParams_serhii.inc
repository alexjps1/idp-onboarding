	#
	# Werte vom 18.01.2024 ermittelt mit dem CAD Modell
	#
	#SIGView.WindowTopmost = true;
	
	# Front Links
	VISF03.SIGView.WindowX = 0;
	VISF03.SIGView.WindowY = 0;
	VISF03.SIGView.WindowW = 4096; 
	VISF03.SIGView.WindowH = 2160; 
#	VISF03.SIGView.WindowShift = 130;
	VISF03.SIGView.CamGamma = -64.726; #
	VISF03.SIGView.CamDelta = 0;
	VISF03.SIGView.CamBeta = 180; #
    VISF03.SIGView.CamA = 0.8;
    VISF03.SIGView.CamB = 0.4;
	VISF03.SIGView.CamFOVY = 46.31; #
    VISF03.SIGView.Visibility.SimCar = 0;	#Anzeige des EgoCars
    VISF03.SIGView.WindowTopmost = true;
	VISF03.SGEWorld.AlwaysUpdateShadow = true;
	VISF03.SGEView.ViewportW  = 3200;
	VISF03.SGEView.ViewportH = 2160;
	VISF03.SGEView.ViewportX = 445;
	VISF03.SGEView.ViewportY  = 0;

	# Front Mitte
	VISF01.SIGView.WindowX = 0;
	VISF01.SIGView.WindowY = 0;
	VISF01.SIGView.WindowW = 4096; 
	VISF01.SIGView.WindowH = 2160; 
#	VISF01.SIGView.WindowShift = 130;
	VISF01.SIGView.CamGamma = 0; #
	VISF01.SIGView.CamDelta = 0;
	VISF01.SIGView.CamBeta = 180; #
    VISF01.SIGView.CamA = 0.8;
    VISF01.SIGView.CamB = 0;
	VISF01.SIGView.CamFOVY = 46.31; #
    VISF01.SIGView.Visibility.SimCar = 0;	#Anzeige des EgoCars
	VISF01.SIGView.Mask = {(900,2400, 1100,2100, 1500,1950, 2100,1900, 2700,1900, 3200,1900, 3200,2400), (0,2400, 0,2000, 600,2000, 600,2400)}; #First brackets mask the BMW mock up in the middle and the VISRC cables (would cast a shadow in the bottom right corner), second brackets mask the VISRL projector
	VISF01.SIGView.WindowTopmost = true;
	VISF01.SGEWorld.AlwaysUpdateShadow = true;
	VISF01.SGEView.ViewportW  = 3200;
	VISF01.SGEView.ViewportH = 2160;
	VISF01.SGEView.ViewportX = 445;
	VISF01.SGEView.ViewportY  = 0;


	# Front Rechts
	VISF02.SIGView.WindowX = 0;
	VISF02.SIGView.WindowY = 0;
	VISF02.SIGView.WindowW = 4096; #neue Projektoren
	VISF02.SIGView.WindowH = 2160; #neue Projektoren
#	VISF02.SIGView.WindowShift = 130;  
	VISF02.SIGView.CamGamma = 64.726; #
	VISF02.SIGView.CamDelta = 0;
	VISF02.SIGView.CamBeta = 180; #
    VISF02.SIGView.CamA = 0.8;
    VISF02.SIGView.CamB = 0.4;
	VISF02.SIGView.CamFOVY = 46.31; #
    VISF02.SIGView.Visibility.SimCar = 0;	#Anzeige des EgoCars
	VISF02.SIGView.WindowTopmost = true;
	VISF02.SGEWorld.AlwaysUpdateShadow = true;
	VISF02.SGEView.ViewportW  = 3200;
	VISF02.SGEView.ViewportH = 2160;
	VISF02.SGEView.ViewportX = 448;
	VISF02.SGEView.ViewportY  = 0;
	VISF02.SGEView.Mask = {(0,2400, 0,2100, 1400,2100, 1300,1950, 1400,1950, 1400,2100, 1500,2100, 2000,1900, 3200,2000, 3200,2400)}; #neue Projektoren
	

    
	#  Mitte Rückansicht
	VISF04.SIGView.WindowX = 0;
	VISF04.SIGView.WindowY = 0;
    VISF04.SIGView.WindowW = 1920;
    VISF04.SIGView.WindowH = 1200;
	VISF04.SIGView.WindowShift = 0;
    VISF04.SIGView.CamGamma = 180;
    VISF04.SIGView.CamFOVY = 18.0;
    VISF04.SIGView.CamA = 0.876;
    VISF04.SIGView.CamBeta = 0;
	VISF05.SIGView.CamS = 0.34;
	VISF04.SIGView.CamDelta = 2;													#Nickwinkel funktioniert gut mit NEC M333XS
	VISF04.SIGView.Visibility.SimCar = 0;	#Anzeige des EgoCars
    #VISF04.SIGView.Mask = {(0,980, 1280,980, 1280,830, 840,790, 440,790, 0,830)};	#Funktioniert gut 21.12.2015
	VISF04.SIGView.WindowTopmost = true;
    
	
	#  Rechts Rückansicht
	#Links für Beamer
	VISF05.SIGView.WindowX = 0;
	VISF05.SIGView.WindowY = 0;
    VISF05.SIGView.WindowW = 1600;
    VISF05.SIGView.WindowH = 1200;
    VISF05.SIGView.CamGamma = 172;	## Changed on April 12th 2018 from 160 to 178
    VISF05.SIGView.CamFOVY = 27.0;
    VISF05.SIGView.CamA = 0.66;
    VISF05.SIGView.CamB = -0.84;
    VISF05.SIGView.CamBeta = -90;
	VISF05.SIGView.CamS = 0.34;							# added on April 12th 2018, did not exist before	
	VISF05.SIGView.CamDelta = -4.0;							# added on April 12th 2018, did not exist before
    VISF05.SIGView.Visibility.SimCar = 0;	#Anzeige des EgoCars
	VISF05.SIGView.WindowTopmost = true;
    VISF05.SIGView.Mask = {(1600,300, 1480,500, 1380,700, 1350,900, 1350,1000, 1300,1050, 1300,1100, 1300,1200, 1600,1200)};

    
	#  Links Rückansicht
	#BackUp für Beamer
	VISF06.SIGView.WindowX = 0;
	VISF06.SIGView.WindowY = 0;
    VISF06.SIGView.WindowW = 1600;
    VISF06.SIGView.WindowH = 1200;
 #   VISF06.SIGView.WindowShift = 56;
    VISF06.SIGView.CamGamma = 194;
    VISF06.SIGView.CamFOVY = 27.0;
    VISF06.SIGView.CamA = 0.66;
	VISF06.SIGView.CamB = 0.83;
	VISF06.SIGView.CamS = 0.34;
	VISF06.SIGView.CamDelta = -8.0; 
    VISF06.SIGView.CamBeta = -90;
    VISF06.SIGView.Visibility.SimCar = 0;	#Anzeige des EgoCars
    VISF06.SIGView.Mask = {(0,260, 55,390, 140,550, 230,710, 290,900, 290,1000, 300,1200, 0,1200)};
	VISF06.SIGView.WindowTopmost = true;


	# Verschaltung zur Ermittlung von CamGamma und CamFOVY

	/*
	DPUAmplifier CamFOVY
	{
		Computer = {OPERATOR};
		Index = 0;
		In = 54.3;
	};
	
	Connections = 
	{
		CamFOVY.Out -> VISF01.SIGView.CamFOVY,
		CamFOVY.Out -> VISF02.SIGView.CamFOVY,
		CamFOVY.Out -> VISF03.SIGView.CamFOVY
	};

	DPUAmplifier GamGammaPlus
	{
		Computer = {OPERATOR};
		Index = 0;
		In = 74.51;
	};
	DPUAmplifier GamGammaMinus
	{
		Computer = {OPERATOR};
		Index = 0;
		Multiplicator = -1.0;
	};

	Connections = 
	{
		GamGammaPlus.Out -> GamGammaMinus.In,
		GamGammaPlus.Out -> VISF02.SIGView.CamGamma,
		GamGammaMinus.Out -> VISF03.SIGView.CamGamma
	};
	
	/**/

	
	VISF01.SGEView.ProjectionOffsetY = -0.17;
	VISF02.SGEView.ProjectionOffsetY = -0.17;	
	VISF03.SGEView.ProjectionOffsetY = -0.167;	# Links etwas höher
	
		
	# Observer
	OBS.SIGView.WindowX = -960; #-960;<-- wieder auf -960, falls auf FS-OBSERVER der Bildschirm rechts unten als Hauptanzeige ausgewählt wird, 960 falls Bildschirm oben in der Mitte die Hauptanzeige ist!
	OBS.SIGView.WindowY = 0;
	OBS.SIGView.WindowW = 960;
	OBS.SIGView.WindowH = 1200;
	OBS.SIGView.WindowShift = 130;
	OBS.SIGView.CamGamma = 0;
	OBS.SIGView.CamDelta = 0;
	OBS.SIGView.CamBeta = 180;
    OBS.SIGView.CamA = 3.0;
    OBS.SIGView.CamB = 10.0;
    OBS.SIGView.Visibility.SimCar = 1;	#Anzeige des EgoCars
	
	
    
    #Einzelplatz
    EINZELPLATZ.SIGView.WindowX = 960;
	EINZELPLATZ.SIGView.WindowY = 0;
	EINZELPLATZ.SIGView.WindowW = 960;
	EINZELPLATZ.SIGView.WindowH = 1200;
#	VISF01.SIGView.WindowAspectRatio = 0.9215686;
	EINZELPLATZ.SIGView.WindowShift = 130;
	EINZELPLATZ.SIGView.CamGamma = 0;
	EINZELPLATZ.SIGView.CamDelta = 0;
    EINZELPLATZ.SIGView.CamA = 0.8;
    EINZELPLATZ.SIGView.CamB = 0.4;
    EINZELPLATZ.SIGView.Visibility.SimCar = 0;	#Anzeige des EgoCars
    
    
   	RECORD.SIGView.WindowX = 0;
	RECORD.SIGView.WindowY = 0;
	RECORD.SIGView.WindowW = 1400;
	RECORD.SIGView.WindowH = 1050;
	RECORD.SIGView.WindowShift = 130;
	RECORD.SIGView.CamGamma = 0;
	RECORD.SIGView.CamDelta = 0;
    RECORD.SIGView.CamA = 0.8;
    RECORD.SIGView.CamB = 0.4;
    RECORD.SIGView.Visibility.SimCar = 0;	#Anzeige des EgoCars
    