DPUDYNTruck ~DYNtruck
{
	Index = 42;
	Computer = {VDYN};
	TreeviewGroup = "Fahrdynamik";
	TreeviewGroup~en = "Vehicle Dynamics";
	CfgDYN = "DYNMercedesAtego.cfg";
	Con1_Active=1;
	Con2_Active=0;
	TimeConstant = 0.4;
};

TRFSGE.SimCarName = "Vehicles.V600.MercedesAtego.ego";
TRFSGE.SimCarShow = true;

SGEView.CamS = 0.34;
SGEView.CamA = 1.89;
SGEView.CamB = 1.79;

# Abmessungen Fahrzeugmodell ohne Spiegel
TRF.EGOBBFront = 2.912;
TRF.EGOBBRear = -4.579;
TRF.EGOBBRight = 1.248;
TRF.EGOBBLeft = -1.248;

# Boundingbox der Spiegel inkl. gültigem Höhenbereich
# TODO CPO: Spiegel Boundingbox eintragen
~MirrorBB.Front = 2.342;
~MirrorBB.Rear = 2.251;
~MirrorBB.Left = -1.036;
~MirrorBB.Right = 1.036;
~MirrorBB.Bottom = 1.221;
~MirrorBB.Top = 1.715;

DPUVDSSCNX ~hRoad_Body1
{
	Index = 41;
	Computer = {VDYN};
	TreeviewGroup = "Fahrdynamik";
	TreeviewGroup~en = "Vehicle Dynamics";
	SlopeLimit = 10.0;
};

Connections =
{
##### Road Interface
	~DYNtruck.X1 	     	-> ~hRoad_Body1.Xfl
	,~DYNtruck.Y1 	     	-> ~hRoad_Body1.Yfl
	,~hRoad_Body1.Zfl      		-> ~DYNtruck.Z1
	,~hRoad_Body1.mufl      	-> ~DYNtruck.mu1
	,~DYNtruck.X2 	     	-> ~hRoad_Body1.Xfr
	,~DYNtruck.Y2 	     	-> ~hRoad_Body1.Yfr
	,~hRoad_Body1.Zfr 	     	-> ~DYNtruck.Z2
	,~hRoad_Body1.mufr      	-> ~DYNtruck.mu2	
	,~DYNtruck.X3	     	-> ~hRoad_Body1.Xrl
	,~DYNtruck.Y3 	     	-> ~hRoad_Body1.Yrl
	,~hRoad_Body1.Zrl 	     	-> ~DYNtruck.Z3
	,~hRoad_Body1.murl      	-> ~DYNtruck.mu3	
	,~DYNtruck.X4 	     	-> ~hRoad_Body1.Xrr
	,~DYNtruck.Y4 	     	-> ~hRoad_Body1.Yrr
	,~hRoad_Body1.Zrr 	     	-> ~DYNtruck.Z4
	,~hRoad_Body1.murr      	-> ~DYNtruck.mu4
};

