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

~MSTVeda.Computer = {};

DPUAmplifier ~VScale
{
	Computer = {VDYN};
	Index = 2;
	Divisor = 3.6; 
};

Connections =
{
	VDat.SampleOff -> Stop.Stop

	,default -> VDyn.RPM
	,default -> VDyn.s
	,default -> VDyn.X
	,default -> VDyn.Y
	,default -> VDyn.Z
	,default -> VDyn.yaw
	,default -> VDyn.pitch
	,default -> VDyn.roll
	,default -> VDyn.v
	,default -> VDyn.v_kmh
	,default -> VDyn.vx
	,default -> VDyn.vy
	,default -> VDyn.vz
	,default -> VDyn.v_X
	,default -> VDyn.v_Y
	,default -> VDyn.v_Z
	,default -> VDyn.vyaw
	,default -> VDyn.vpitch
	,default -> VDyn.vroll
	,default -> VDyn.ax
	,default -> VDyn.ay
	,default -> VDyn.az
	,default -> VDyn.ayaw
	,default -> VDyn.apitch
	,default -> VDyn.aroll

	,default -> VDynMotion.X
	,default -> VDynMotion.Y
	,default -> VDynMotion.Z
	,default -> VDynMotion.yaw
	,default -> VDynMotion.pitch
	,default -> VDynMotion.roll
	,default -> VDynMotion.v
	,default -> VDynMotion.vx
	,default -> VDynMotion.vy
	,default -> VDynMotion.vz
	,default -> VDynMotion.vyaw
	,default -> VDynMotion.vpitch
	,default -> VDynMotion.vroll
	,default -> VDynMotion.ax
	,default -> VDynMotion.ay
	,default -> VDynMotion.az
	,default -> VDynMotion.ayaw
	,default -> VDynMotion.apitch
	,default -> VDynMotion.aroll


	,VDat.Out2 		-> VDyn.X
	,VDat.Out3 		-> VDyn.Y
	,VDat.Out4 		-> VDyn.Z
	,VDat.Out5  	-> VDyn.yaw
	,VDat.Out6	  -> VDyn.pitch
	,VDat.Out7		-> VDyn.roll
	,VDat.Out8 		-> VDyn.v_kmh
	,VDat.Out8	 	-> ~VScale.In
	,~VScale.Out	-> VDyn.v

};
