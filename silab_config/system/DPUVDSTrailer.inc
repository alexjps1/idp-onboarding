		DPUVDSST4WTR2W ~VDS
         {
         	Index = 10;
         	Computer = {VDYN};
			Trailer = true;
         	CfgDriveTrain = "DriveTrain_MAN_TGA.cfg";
         	CfgSingleTrack = "SingleTrack_MAN_TGA.cfg";
         	CfgSingleTrackTrailer = "SingleTrack_MAN_TGA.cfg";
         };
 		DPUVDSSCNX ~VDSSCNX
		{
			Index = 50;
			Computer = {VDYN};
		};

		 Connections =
		 {
			~VDS.Xfl -> ~VDSSCNX.Xfl,
			~VDS.Yfl -> ~VDSSCNX.Yfl,
			~VDS.Xfr -> ~VDSSCNX.Xfr,
			~VDS.Yfr -> ~VDSSCNX.Yfr,
			~VDSSCNX.Zfl -> ~VDS.Zfl,
			~VDSSCNX.Zfr -> ~VDS.Zfr,

			~VDS.Xrl -> ~VDSSCNX.Xrl,
			~VDS.Yrl -> ~VDSSCNX.Yrl,
			~VDS.Xrr -> ~VDSSCNX.Xrr,
			~VDS.Yrr -> ~VDSSCNX.Yrr,
			~VDSSCNX.Zrl -> ~VDS.Zrl,
			~VDSSCNX.Zrr -> ~VDS.Zrr,

			~VDS.XhlTrailer -> ~VDSSCNX.Xtl,
			~VDS.YhlTrailer -> ~VDSSCNX.Ytl,
			~VDSSCNX.Ztl -> ~VDS.ZhlTrailer,
			~VDS.XhrTrailer -> ~VDSSCNX.Xtr,
			~VDS.YhrTrailer -> ~VDSSCNX.Ytr,
			~VDSSCNX.Ztr -> ~VDS.ZhrTrailer
		 };
	Connections = {
		 SCNX.ZOut 				-> ~VDS.ZRoad
		,SCNX.ve				-> ~VDS.ve
		,VDyn.Ignition 			-> ~VDS.Ignition
		,VDyn.Starter 			-> ~VDS.Starter
		,VDyn.HandBrake 		-> ~VDS.HandBrake
		,VDyn.Gear 				-> ~VDS.Gear
		,VDyn.SteeringWheel 	-> ~VDS.SteeringWheel
		,VDyn.AcceleratorPedal 	-> ~VDS.AcceleratorPedal
		,VDyn.BrakePedal 		-> ~VDS.BrakePedal
		,VDyn.ClutchPedal		-> ~VDS.ClutchPedal
		,VDyn.SetupX	 		-> ~VDS.SetupX
		,VDyn.SetupY	 		-> ~VDS.SetupY
		,VDyn.SetupZ	 		-> ~VDS.SetupZ
		,VDyn.SetupYaw			-> ~VDS.SetupYaw
		,VDyn.SetupPitch		-> ~VDS.SetupPitch
		,VDyn.SetupRoll			-> ~VDS.SetupRoll
		,VDyn.SetupDone			-> ~VDS.SetupDone
		,~VDS.RPM			-> VDyn.RPM
		,~VDS.s				-> VDyn.s
		,~VDS.X				-> VDyn.X
		,~VDS.Y				-> VDyn.Y
		,~VDS.Z				-> VDyn.Z
		,~VDS.yaw			-> VDyn.yaw
		,~VDS.pitch		-> VDyn.pitch
		,~VDS.roll		-> VDyn.roll
		,~VDS.v				-> VDyn.v
		,~VDS.v_kmh		-> VDyn.v_kmh
		,~VDS.vx			-> VDyn.vx
		,~VDS.vy			-> VDyn.vy
		,~VDS.vz			-> VDyn.vz
	#	,~VDS.v_X			-> VDyn.v_X
	#	,~VDS.v_Y			-> VDyn.v_Y
	#	,~VDS.v_Z			-> VDyn.v_Z
		,~VDS.vyaw		-> VDyn.vyaw
		,~VDS.vpitch	-> VDyn.vpitch
		,~VDS.vroll		-> VDyn.vroll
		,~VDS.ax			-> VDyn.ax
		,~VDS.ay			-> VDyn.ay
		,~VDS.az			-> VDyn.az
		,~VDS.ayaw		-> VDyn.ayaw
		,~VDS.apitch	-> VDyn.apitch
		,~VDS.aroll		-> VDyn.aroll
		,~VDS.TrackWidthF	-> VDyn.TrackWidthF
		,~VDS.TrackWidthR	-> VDyn.TrackWidthR
		,~VDS.pitchView		-> VDynView.pitch
		,~VDS.rollView		-> VDynView.roll
		,VDyn.PitchRoad		-> ~VDS.PitchRoad
		,VDyn.RollRoad		-> ~VDS.RollRoad
		,VDyn.XOffset			-> ~VDS.XOffset
		,VDyn.YOffset			-> ~VDS.YOffset
		,VDyn.ZOffset			-> ~VDS.ZOffset

		,~VDS.X 	     -> VDynMotion.X
		,~VDS.Y 	     -> VDynMotion.Y
		,~VDS.Z 	     -> VDynMotion.Z
		,~VDS.yaw   	 -> VDynMotion.yaw
		,~VDS.pitch    -> VDynMotion.pitch
		,~VDS.roll     -> VDynMotion.roll
		,~VDS.v 	     -> VDynMotion.v
		,~VDS.vx 	     -> VDynMotion.vx
		,~VDS.vy 	     -> VDynMotion.vy
		,~VDS.vz 	     -> VDynMotion.vz
		,~VDS.vyaw 	 	 -> VDynMotion.vyaw
		,~VDS.vpitch   -> VDynMotion.vpitch
		,~VDS.vroll    -> VDynMotion.vroll
		,~VDS.ax 	     -> VDynMotion.ax
		,~VDS.ay 	     -> VDynMotion.ay
		,~VDS.az 	     -> VDynMotion.az
		,~VDS.ayaw 	 	 -> VDynMotion.ayaw
		,~VDS.apitch   -> VDynMotion.apitch
		,~VDS.aroll    -> VDynMotion.aroll
	};

	Connections = 
	{
		~VDS.XTrailer 		-> TRF.EGOTX,
		~VDS.YTrailer 		-> TRF.EGOTY,
		~VDS.ZTrailer		-> TRF.EGOTZ,
		~VDS.yawTrailer		-> TRF.EGOTyaw,
		~VDS.pitchTrailer 	-> TRF.EGOTpitch,
		~VDS.rollTrailer	-> TRF.EGOTroll,
		~VDS.alphaTrailer	-> TRF.EGOTalpha
	};
	Connections = 
	{
		~VDS.XTrailer 		-> TRFClient.EGOTX,
		~VDS.YTrailer 		-> TRFClient.EGOTY,
		~VDS.ZTrailer		-> TRFClient.EGOTZ,
		~VDS.yawTrailer		-> TRFClient.EGOTyaw,
		~VDS.pitchTrailer 	-> TRFClient.EGOTpitch,
		~VDS.rollTrailer	-> TRFClient.EGOTroll,
		~VDS.alphaTrailer	-> TRFClient.EGOTalpha
	};
