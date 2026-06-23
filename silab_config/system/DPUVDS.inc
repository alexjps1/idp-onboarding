		DPUVDSST4W ~VDS
         {
         	Index = 10;
         	Computer = {VDYN};
			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";

         	CfgDriveTrain = "DriveTrain.cfg";
         	CfgSingleTrack = "SingleTrack.cfg";
         	#CfgDriveTrain = "DriveTrain_Transit.cfg";
         	#CfgSingleTrack = "SingleTrack_Transit.cfg";
         	#CfgDriveTrain = "DriveTrain_Actros.cfg";
         	#CfgSingleTrack = "SingleTrack_Actros.cfg";
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
		,VDyn.ClutchPedal 		-> ~VDS.ClutchPedal
		,~VDS.RPM			-> VDyn.RPM
		,~VDS.s				-> VDyn.s
		,~VDS.X 			-> VDyn.X
		,~VDS.Y 			-> VDyn.Y
		,~VDS.Z 		    -> VDyn.Z
		,~VDS.yaw   		-> VDyn.yaw
		,~VDS.pitch 	    -> VDyn.pitch
		,~VDS.roll			-> VDyn.roll
		,~VDS.v 		    -> VDyn.v
		,~VDS.v_kmh 	    -> VDyn.v_kmh
		,~VDS.vx 			-> VDyn.vx
		,~VDS.vy 			-> VDyn.vy
		,~VDS.vz 			-> VDyn.vz
		,~VDS.vyaw 	    	-> VDyn.vyaw
		,~VDS.vpitch 		-> VDyn.vpitch
		,~VDS.vroll 	    -> VDyn.vroll
		,~VDS.ax 			-> VDyn.ax
		,~VDS.ay 			-> VDyn.ay
		,~VDS.az 			-> VDyn.az
		,~VDS.ayaw 	    	-> VDyn.ayaw
		,~VDS.apitch 		-> VDyn.apitch
		,~VDS.aroll 	   	-> VDyn.aroll
		,~VDS.delta    		-> VDyn.delta	


		,~VDS.pitch 		-> VDynView.pitch
		,~VDS.roll 			-> VDynView.roll
		,VDyn.PitchRoad 		-> ~VDS.PitchRoad
		,VDyn.RollRoad 			-> ~VDS.RollRoad
		,VDyn.XOffset 			-> ~VDS.XOffset
		,VDyn.YOffset 			-> ~VDS.YOffset
		,VDyn.ZOffset 			-> ~VDS.ZOffset
		,VDyn.SetupX	 		-> ~VDS.SetupX
		,VDyn.SetupY	 		-> ~VDS.SetupY
		,VDyn.SetupZ	 		-> ~VDS.SetupZ
		,VDyn.SetupYaw			-> ~VDS.SetupYaw
		,VDyn.SetupPitch		-> ~VDS.SetupPitch
		,VDyn.SetupRoll			-> ~VDS.SetupRoll
		,VDyn.SetupDone			-> ~VDS.SetupDone

		,~VDS.X 	     -> VDynMotion.X
		,~VDS.Y 	     -> VDynMotion.Y
		,~VDS.Z 	     -> VDynMotion.Z
		,~VDS.yaw   		 -> VDynMotion.yaw
		,~VDS.pitch    -> VDynMotion.pitch
		,~VDS.roll     -> VDynMotion.roll
		,~VDS.SelGear	-> VDyn.GearAuto
		,~VDS.v 	         -> VDynMotion.v
		,~VDS.vx 	     -> VDynMotion.vx
		,~VDS.vy 	     -> VDynMotion.vy
		,~VDS.vz 	     -> VDynMotion.vz
		,~VDS.vyaw 	 -> VDynMotion.vyaw
		,~VDS.vpitch   -> VDynMotion.vpitch
		,~VDS.vroll    -> VDynMotion.vroll
		,~VDS.ax 	     -> VDynMotion.ax
		,~VDS.ay 	     -> VDynMotion.ay
		,~VDS.az 	     -> VDynMotion.az
		,~VDS.ayaw 	 -> VDynMotion.ayaw
		,~VDS.apitch   -> VDynMotion.apitch
		,~VDS.aroll    -> VDynMotion.aroll
	};

	# 3.1.18 MH: Anpassung ay
	# Querbeschleunigung fühlt sich zu hoch an, ist deutlich höher als mstVEDA
	DPUAmplifier ~AmpAy {
		Computer = {VDYN};
		Index = 20;
		Divisor = 2.5;
	};
	Connections = {
		~VDS.ay -> ~AmpAy.In,
		~AmpAy.Out -> VDyn.ay,
		~AmpAy.Out -> VDynMotion.ay
	};
	
	# 2.11.20 MH: Anpassung RPM
	# Drehzahl weniger sprunghaft
	DPULimiter ~LimRpm {
		Computer = {VDYN};
		Index = 20;
		SlopeLimitPos = 3000;
		SlopeLimitNeg = -3000;
	};
	Connections = {
		~VDS.RPM -> ~LimRpm.In,
		~LimRpm.Out -> VDyn.RPM
	};
