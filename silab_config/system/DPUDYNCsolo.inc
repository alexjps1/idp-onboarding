DPUDYNTruck ~DYNtruck
{
	Index = 42;
	Computer = {VDYN};
	TreeviewGroup = "Fahrdynamik";
	TreeviewGroup~en = "Vehicle Dynamics";
	CfgDYN = "DYNCsolo.cfg";
	Con1_Active=0;
	Con2_Active=0;
	TimeConstant = 0.4;
};	

TRFSGE.SimCarName = "Vehicles.V600.MAN_TGL.main";
TRFSGE.SimCarShow = true;

SGEView.CamS = 0.34;
SGEView.CamA = 2.80;
SGEView.CamB = 0.7;

# Abmessungen Fahrzeugmodell ohne Spiegel
TRF.EGOBBFront = 4.197;
TRF.EGOBBRear = -4.274;
TRF.EGOBBRight = 1.248;
TRF.EGOBBLeft = -1.248;

# Boundingbox der Spiegel inkl. gültigem Höhenbereich
~MirrorBB.Front = 4.303;
~MirrorBB.Rear = 3.234;
~MirrorBB.Left = -1.531;
~MirrorBB.Right = 1.531;
~MirrorBB.Bottom = 1.652;
~MirrorBB.Top = 2.546;

DPUVDSSCNX ~hRoad_Body1
		 {
		 	Index = 41;
		 	Computer = {VDYN};
			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";
			SlopeLimit = 10.0;
		 };

DPUAmplifier ~cabin_z
		{
		 	Index = 11;
		 	Computer = {VDYN};
			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";
		 };	
		 
DPUAmplifier ~cabin_theta
		{
		 	Index = 11;
		 	Computer = {VDYN};
			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";
		 };		

Connections =
{

	VDyn.Z -> ~cabin_z.In
	,~DYNtruck.z_cab -> ~cabin_z.Offset
	,~cabin_z.Out -> VDynView.Z
	
	,VDyn.pitch -> ~cabin_theta.In
	,~DYNtruck.theta_cab -> ~cabin_theta.Offset
	,~cabin_theta.Out -> VDynView.pitch
##### Road Interface
	,~DYNtruck.X1 	     	-> ~hRoad_Body1.Xfl
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
