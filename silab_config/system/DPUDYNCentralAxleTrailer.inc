DPUDYNTruck ~DYNtruck
{
	Index = 42;
	Computer = {VDYN};
	TreeviewGroup = "Fahrdynamik";
	TreeviewGroup~en = "Vehicle Dynamics";
	CfgDYN = "DYNCentralAxleTrailer.cfg";
	Con1_Active=1;
	Con2_Active=0;
	TimeConstant = 0.4;
};

TRFSGE.SimCarName = "Vehicles.V600.MAN_TGL.main";
TRFSGE.SimCarShow = true;
TRFSGE.SimCarTName = "Vehicles.V600.TrailerCE.main";
TRFSGE.SimCarTShow = true;

SGEView.CamS = 0.34;
SGEView.CamA = 2.80;
SGEView.CamB = 0.7;

# Abmessungen Fahrzeugmodell ohne Spiegel
TRF.EGOBBFront = 4.197;
TRF.EGOBBRear = -4.274;
TRF.EGOBBRight = 1.248;
TRF.EGOBBLeft = -1.248;

# Egofahrzeug Kollisionsbox mit Anhänger (bei TGL gleich mit Fahrzeugabmessungen)
#~TrailerCollisionBB.Front = 4.197;
#~TrailerCollisionBB.Rear = -4.274;

# Boundingbox der Spiegel inkl. gültigem Höhenbereich
~MirrorBB.Front = 4.303;
~MirrorBB.Rear = 3.234;
~MirrorBB.Left = -1.531;
~MirrorBB.Right = 1.531;
~MirrorBB.Bottom = 1.652;
~MirrorBB.Top = 2.546;

# Abmessungen Trailer
TRF.EGOTBBFront = -1.250; # Ohne Toleranzbereich 0.026
TRF.EGOTBBRear = -9.214;
TRF.EGOTBBRight = 1.275;
TRF.EGOTBBLeft = -1.275;

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
	
	,VDyn.Z -> ~cabin_z.In
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
