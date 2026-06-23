DPUDYNTruck ~DYNtruck
{
	Index = 42;
	Computer = {VDYN};
	TreeviewGroup = "Fahrdynamik";
	TreeviewGroup~en = "Vehicle Dynamics";
	CfgDYN = "DYNC1E.cfg";
	Con1_Active=1;
	Con2_Active=0;
	TimeConstant = 0.4;
};

TRFSGE.SimCarName = "Vehicles.V600.FusoCanter.pickup_ego";
TRFSGE.SimCarShow = true;
TRFSGE.SimCarTName = "Vehicles.V600.TrailerC1E.small";
TRFSGE.SimCarTShow = true;

SGEView.CamS = 0.34;
SGEView.CamA = 2.80;
SGEView.CamB = 0.7;	

# Abmessungen Fahrzeugmodell ohne Spiegel
TRF.EGOBBFront = 2.632;
TRF.EGOBBRear = -2.157;
TRF.EGOBBRight = 0.841;
TRF.EGOBBLeft = -0.841;

# Egofahrzeug Kollisionsbox mit Anhänger (identisch zu Fahrzeugabmessungen)
#~TrailerCollisionBB.Front = 2.632;
#~TrailerCollisionBB.Rear = -2.157;

# Boundingbox der Spiegel inkl. gültigem Höhenbereich
~MirrorBB.Front = 2.342;
~MirrorBB.Rear = 2.251;
~MirrorBB.Left = -1.036;
~MirrorBB.Right = 1.036;
~MirrorBB.Bottom = 1.221;
~MirrorBB.Top = 1.715;

# Abmessungen Trailer (Ohne Königszapfen)
TRF.EGOTBBFront = -0.600;
TRF.EGOTBBRear = -4.845;
TRF.EGOTBBRight = 1.085;
TRF.EGOTBBLeft = -1.085;

DPUVDSSCNX ~hRoad_Body1
{
	Index = 41;
	Computer = {VDYN};
	TreeviewGroup = "Fahrdynamik";
	TreeviewGroup~en = "Vehicle Dynamics";
	SlopeLimit = 10.0;
};
DPUVDSSCNX ~hRoad_Body2
{
	Index = 41;
	Computer = {VDYN};
	TreeviewGroup = "Fahrdynamik";
	TreeviewGroup~en = "Vehicle Dynamics";
	SlopeLimit = 10.0;
};


Connections = 
{
	 VDyn.Body2_X -> TRFX.EGOTX
	,VDyn.Body2_Y -> TRFX.EGOTY
	,VDyn.Body2_Z -> TRFX.EGOTZ
	,VDyn.Body2_roll -> TRFX.EGOTroll
	,VDyn.Body2_pitch -> TRFX.EGOTpitch
	,VDyn.Body2_yaw -> TRFX.EGOTyaw

	,VDyn.Body2_X -> TRFClient.EGOTX
	,VDyn.Body2_Y -> TRFClient.EGOTY
	,VDyn.Body2_Z -> TRFClient.EGOTZ
	,VDyn.Body2_roll -> TRFClient.EGOTroll
	,VDyn.Body2_pitch -> TRFClient.EGOTpitch
	,VDyn.Body2_yaw -> TRFClient.EGOTyaw
	
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
	
	,~DYNtruck.X5 	     	-> ~hRoad_Body2.Xfl
	,~DYNtruck.Y5 	     	-> ~hRoad_Body2.Yfl
	,~hRoad_Body2.Zfl      	-> ~DYNtruck.Z5	
	,~hRoad_Body2.mufl      	-> ~DYNtruck.mu5
	,~DYNtruck.X6	     	-> ~hRoad_Body2.Xfr
	,~DYNtruck.Y6 	     	-> ~hRoad_Body2.Yfr
	,~hRoad_Body2.Zfr 	     -> ~DYNtruck.Z6
	,~hRoad_Body2.mufr      	-> ~DYNtruck.mu6	
	,~DYNtruck.X7	     	-> ~hRoad_Body2.Xrl
	,~DYNtruck.Y7	     	-> ~hRoad_Body2.Yrl
	,~hRoad_Body2.Zrl 	     -> ~DYNtruck.Z7
	,~hRoad_Body2.murl      	-> ~DYNtruck.mu7	
	,~DYNtruck.X8	     	-> ~hRoad_Body2.Xrr
	,~DYNtruck.Y8 	     	-> ~hRoad_Body2.Yrr
	,~hRoad_Body2.Zrr 	     -> ~DYNtruck.Z8
	,~hRoad_Body2.murr      	-> ~DYNtruck.mu8
	
	
};	 
