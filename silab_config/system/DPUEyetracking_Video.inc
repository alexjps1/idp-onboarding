 
## Videogenerierung
DPUSGEVidGen SGEVidGen
{
	Computer = {EYEVIS};
	Index = 10000;
	ViewID = 0;
	Subsample = 2;
	VideoCodec = "DivX";
	CompressionOptions = "D:\Silab_Dev\lib\configurations\VidCap\DivX6HiRes.vcc";
	SaveFile = "__ReplayVideo.avi";
	Overwrite = 1.0;
	#ExternalX = 800;
	#ExternalY = 600;
};

DPUSGEObject EyeTrack
{
	Computer = {EYEVIS};
	#Computer = {FRONT};
	Index = 25;
	Object = "ODB.eye";
	SysDebug = 2; 
	Show = 1;
};
Connections =
{
	SEPAReceiver.ClosestWorldIntersectionX -> EyeTrack.X,
	SEPAReceiver.ClosestWorldIntersectionY -> EyeTrack.Y
	#SEPACompute.ScreenEyeAzi -> AmpX.In,
	#AmpX.Out -> EyeTrack.X,
	#SEPACompute.ScreenEyeEle -> AmpY.In,
	#AmpY.Out -> EyeTrack.Y
	#SEPAFixation.Fixation -> EyeTrack.Show
};

			
## Visualisierung Fixation
/*
DPUODBVIS ODBAnim
{
	Computer = {EYEVIS};
	Index = 23;
	SysDebug = 2; 
};
DPUSGEObject EyeTrack
{
	Computer = {EYEVIS};
	Index = 25;
	Object = "ODB.eye";
	SysDebug = 2; 
	Show = 1;
};
Connections =
{
	SEPACompute.ScreenEyeAzi -> AmpX.In,
	AmpX.Out -> EyeTrack.X,
	SEPACompute.ScreenEyeEle -> AmpY.In,
	AmpY.Out -> EyeTrack.Y
	#SEPAFixation.Fixation -> EyeTrack.Show
};
DPUAmplifier AmpX
{
	Computer = {EYEVIS};
	Index = 24;
	SysDebug = 2; 
	Multiplicator = 1.0;

	##### Bei 1024 * 768 ; X-Winkel = +/- 30 Grad
	Divisor = 0.05859375; # auf Bogenmass zurückgerechnet
	##### # Divisor =  0.001022653858590427486478725; # spaeter wieder wie alle Parameter in RAD
	Offset = 512;

	######## Bei 1280 * 1024 ; X-Winkel = +/- 30 Grad
	###Divisor = 0.046875; # auf Bogenmass zurückgerechnet
	##### # Divisor =  0.00081812308687234198918298; # spaeter wieder wie alle Parameter in RAD
	###Offset = 640;

	######## Bei 1152 * 864 ; X-Winkel = +/- 30 Grad
	###Divisor = 0.0520833333333333333333333333333; # auf Bogenmass zurückgerechnet
	##### # Divisor =  0.000909025652080379987981; # spaeter wieder wie alle Parameter in RAD
	###Offset = 576;

	# Gleichung Divisor = maxgrad/screensize [* 360/(2*pi) ]
};
DPUAmplifier AmpY
{
	Computer = {EYEVIS};
	Index = 24;
	SysDebug = 2; 
	Multiplicator = -1.0;

	#### Bei 1024 * 768 ; Y-Winkel = +/- 23.5 Grad
	Divisor = 0.0611979166666666666666666666; # auf Bogenmaß zurückgerechnet
	##### # Divisor =  0.0010681051411944464858777795067574; # spaeter wieder wie alle Parameter in RAD
	Offset = 384;

	#### Bei 1280 * 1024 ; Y-Winke = +/- 23.5 Grad
	###Divisor = 0.0458984375; # auf Bogenmaß zurückgerechnet
	##### # Divisor =  0.0008010788558958348644; # spaeter wieder wie alle Parameter in RAD
	###Offset = 512;

	#### Bei 1152 * 864 ; Y-Winke = +/- 23.5 Grad
	###Divisor = 0.054398148148148148148148148148148148148148; # auf Bogenmaß zurückgerechnet
	##### # Divisor =  0.00094942679217284132; # spaeter wieder wie alle Parameter in RAD
	###Offset = 432;

	# Gleichung Divisor = maxgrad/screensize [* 360/(2*pi) ]
};
*/
