SIGView.WindowW = 640;
SIGView.WindowH = 480;
SIGWorld.EnableTextureCompression = false;
SIGView.AVI = true;
SIGView.AVICompression = true;
SIGView.AVIFileName = "Data\MakeAVI.avi";
SIGView.AVIFPS = 25;
SIGView.Threaded = false;
SIGView.VerticalSync = false;
SIGView.LowTextureAnisotropy = 16;
SIGView.MedTextureAnisotropy = 16;
SIGView.MaxTextureAnisotropy = 16;

DPUSampleFilePlayer VDat {
	Computer = {DATA};
	Index = 0;

	Start = 1; # Sofort starten

	SampleID1 = 1;   # SimTime
	SampleID2 = 3;   # x
	SampleID3 = 4;	 # y
	SampleID4 = 5;	 # z
	SampleID5 = 6;	 # yaw
	SampleID6 = 7;	 # pitch
	SampleID7 = 8;	 # roll
	SampleID8 = 9;	 # v
	SampleID9 = 10;	 # trg
	FileName = "data\DriveData.dat";
};

DPUStopper Stop {
	Computer = {OPERATOR};
	Index = 1;
};

Connections =
{
	VDat.SampleOff -> Stop.Stop,

	VDat.Out1 -> TRF.ExternTrafficTime,
	VDat.Out1 -> MOV.ExternalSimTime,
	VDat.Out1 -> SIGView.AVITime,
	VDat.Out2 -> SCN.X,
	VDat.Out3 -> SCN.Y,
	VDat.Out4 -> SCN.Z,
	VDat.Out5 -> SCN.yaw,
	default -> SCN.pitch,
	default -> SCN.roll,
	#VDat.Out6 -> SCN.pitch,
	#VDat.Out7 -> SCN.roll,

	VDat.Out2 -> SIGView.X,
	VDat.Out3 -> SIGView.Y,
	VDat.Out5 -> SIGView.yaw,
	default -> SIGView.pitch,
	default -> SIGView.roll,
	#VDat.Out6 -> SIGView.pitch,
	#VDat.Out7 -> SIGView.roll,

	VDat.Out9 -> SIGView.AVIWrite
};
