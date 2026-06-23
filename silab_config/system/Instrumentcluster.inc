DPUMMI ~Instrumentcluster
{
	Computer = {MOCKUP};
	Index = 100;
	
	WindowX = 1280; #-1280, wenn beide Anzeigen (Combi und CID) auf FS-Vehicle aktiv
	WindowY = 0;
	WindowW = 1366; 		#1280 bei Originaldisplay
	WindowH = 768;			#720 bei Originaldisplay
	W = 1366; 				#1280 bei Originaldisplay
	H = 768;				#720 bei Originaldisplay
	
	ImageDisplay Tacho
	{
		X = 64;
		Y = 80;				#150
		W = 512;
		H = 512;
		Images = "Instrumentcluster\tacho.tga";
		
		Needle Tachonadel
		{
			X = 0;
			Y = -10.5;
			W = 512;
			H = 512;
			XMount = 256;  
			YMount = 256;
			XNeedleMount = 256;
			YNeedleMount = 256;
			AngleMin = 85;
			AngleMax = 352;
			ValueMin = 0;
			ValueMax = 260;
			NeedleImage = "Instrumentcluster\needle2.tga";
		};
		
	};
	ImageDisplay RPMMeter
	{
		X = 704;
		Y = 80;				#150
		W = 512;
		H = 512;
		Images = "Instrumentcluster\RPM2.tga";
		
		Needle RPMnadel
		{
			X = 0;
			Y = -10.5;
			W = 512;
			H = 512;
			XMount = 256;  
			YMount = 256;
			XNeedleMount = 256;
			YNeedleMount = 256;
			AngleMin = 85;
			AngleMax = 329.5;
			ValueMin = 0;
			ValueMax = 5000;
			NeedleImage = "Instrumentcluster\needle2.tga";
		};
	};
	ImageDisplay BlinkerLinks
	{
		X = 545;
		Y = 540;			#610
		W = 50;
		H = 50;
		Images = ("AS\blinker_l_off.png","AS\blinker_l_on.png");
	};
	ImageDisplay BlinkerRechts
	{
		X = 685;
		Y = 540;			#610
		W = 50;
		H = 50;
		Images = ("AS\blinker_r_off.png","AS\blinker_r_on.png");
	};
};


DPUOscillator ~BlinkerRechts
{
	Computer = {MOCKUP};
	Index = 100;
	
	Period = 500;
	Amplitude = 1.0;
	Signal = 2;
};

DPUOscillator ~BlinkerLinks
{
	Computer = {MOCKUP};
	Index = 100;
	
	Period = 500;
	Amplitude = 1.0;
	Signal = 2;
};

DPUMMI Blackcid
{
	Computer = {MOCKUP};
	Index = 520;
	WindowX = 0;	#, wenn beide Anzeigen (Combi und CID) auf FS-Vehicle aktiv 
	WindowY = 0;
	WindowW = 1280;
	WindowH = 720;
	W = 1280;
	H = 720;
	WindowTopmost = true;
	
	ImageDisplay black
	{
		X = 0;
		Y = 0;				#150
		W = 1280;
		H = 720;
		Images = "Instrumentcluster\black.png";
		
		
	};
	
};

Connections =
{	
	VDyn.v_kmh <-> ~Instrumentcluster.Tacho.Tachonadel.In,
	VDyn.RPM <-> ~Instrumentcluster.RPMMeter.RPMnadel.In,
	Mockup.IndicatorRight <-> ~BlinkerRechts.Start,
	Mockup.IndicatorRight <-> ~BlinkerRechts.On,
	~BlinkerRechts.Out <-> ~Instrumentcluster.BlinkerRechts.In, 
	Mockup.IndicatorLeft <-> ~BlinkerLinks.Start,
	Mockup.IndicatorLeft <-> ~BlinkerLinks.On,
	~BlinkerLinks.Out <-> ~Instrumentcluster.BlinkerLinks.In
	
};
