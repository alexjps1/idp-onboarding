	DPUVehicleSimSCNX ~VSW
	{
		Computer = { VSW };
		Index = 55;
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";
		# select simfile
		SimFile = "simfile.sim";
		# load predefined settings for tirepoints (BikeSim/CarSim/TruckSim) and X,Y,Z,yaw,pitch,roll,XOffset,YOffset,ZOffset
		include VehicleSim\DPUVehicleSimDefs.inc
		# add useful inputs
		In = 
		{
			(IMP_STEER_SW,SteeringWheel,0.0,1.0),
			(IMP_THROTTLE_ENGINE,AcceleratorPedal,0.0,1.0),
			(IMP_PCON_BK,BrakePedal,0.0,5000000.0),
			(IMP_CLUTCH,ClutchPedal,0.0,1.0),
			(IMP_GEAR_TRANS,GearTrans),
			(IMP_MODE_TRANS,GearMode)
		};
		# add useful outputs
		Out = 
		{
			# v in m/s
			(EXP_VXBF_SM,v),
			# internal rad/s RPM = 60.0/2*PI
			(EXP_AV_ENG,RPM,0.0,9.54958),
			(EXP_AX,ax,0.0,+1.0),
			(EXP_AY,ay,0.0,-1.0),
			(EXP_AZ,az,0.0,+1.0)
		};
	};
	DPUAmplifier ~VSWGearMode
	{
		Computer = {VSW};
		Index = 54;
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";
		OutMin = -1.0;
		OutMax = 0.0;
	};
	DPUMixAmplifier ~VSWClutch
	{
		Computer = {VSW};
		Index = 54;
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";
		MinOut = 0.0;
		MaxOut = 1.0;
	};
	DPUMixAmplifier ~VSWClutchControl
	{
		Computer = {VSW};
		Index = 54;
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";
		In2 = 650;
		Multiplicator1 = -0.1;
		Multiplicator2 =  0.1;
		MinOut = 0.0;
		MaxOut = 1.0;
	};
	Connections = 
	{
		 VDyn.SteeringWheel 	-> ~VSW.SteeringWheel
		,VDyn.AcceleratorPedal 	-> ~VSW.AcceleratorPedal
		,VDyn.BrakePedal 		-> ~VSW.BrakePedal
		,~VSW.RPM 				-> ~VSWClutchControl.In1
		,VDyn.ClutchPedal   	-> ~VSWClutch.In1
		,~VSWClutchControl.Out 	-> ~VSWClutch.In2
		,~VSWClutch.Out			-> ~VSW.ClutchPedal
		,VDyn.Gear				-> ~VSW.GearTrans
		,VDyn.Gear 				-> ~VSWGearMode.In
		,~VSWGearMode.Out   	-> ~VSW.GearMode
		,~VSW.X 				-> VDyn.X
		,~VSW.Y 				-> VDyn.Y
		,~VSW.Z 		    	-> VDyn.Z
		,~VSW.yaw   			-> VDyn.yaw
		,~VSW.pitch 	    	-> VDyn.pitch
		,~VSW.roll				-> VDyn.roll
		,VDyn.XOffset 			-> ~VSW.XOffset
		,VDyn.YOffset 			-> ~VSW.YOffset
		,VDyn.ZOffset 			-> ~VSW.ZOffset
	};
			

	/*
	Connections = 
	{
		 SCNX.ZOut 				-> ~VSW.ZRoad
		,SCNX.ve				-> ~VSW.ve
		,VDyn.Ignition 			-> ~VSW.Ignition
		,VDyn.Starter 			-> ~VSW.Starter
		,VDyn.HandBrake 		-> ~VSW.HandBrake
		,VDyn.Gear 				-> ~VSW.Gear
		,VDyn.SteeringWheel 	-> ~VSW.SteeringWheel
		,VDyn.AcceleratorPedal 	-> ~VSW.AcceleratorPedal
		,VDyn.BrakePedal 		-> ~VSW.BrakePedal

		,~VSW.RPM			-> VDyn.RPM
		,~VSW.s				-> VDyn.s
		,~VSW.X 			-> VDyn.X
		,~VSW.Y 			-> VDyn.Y
		,~VSW.Z 		    -> VDyn.Z
		,~VSW.yaw   		-> VDyn.yaw
		,~VSW.pitch 	    -> VDyn.pitch
		,~VSW.roll			-> VDyn.roll
		,~VSW.v 		    -> VDyn.v
		,~VSW.v_kmh 	    -> VDyn.v_kmh
		,~VSW.vx 			-> VDyn.vx
		,~VSW.vy 			-> VDyn.vy
		,~VSW.vz 			-> VDyn.vz
		,~VSW.vyaw 	    	-> VDyn.vyaw
		,~VSW.vpitch 		-> VDyn.vpitch
		,~VSW.vroll 	    -> VDyn.vroll
		,~VSW.ax 			-> VDyn.ax
		,~VSW.ay 			-> VDyn.ay
		,~VSW.az 			-> VDyn.az
		,~VSW.ayaw 	    	-> VDyn.ayaw
		,~VSW.apitch 		-> VDyn.apitch
		,~VSW.aroll 	   	-> VDyn.aroll

		,~VSW.pitch 		-> VDynView.pitch
		,~VSW.roll 			-> VDynView.roll
		,VDyn.PitchRoad 		-> ~VSW.PitchRoad
		,VDyn.RollRoad 			-> ~VSW.RollRoad
		,VDyn.XOffset 			-> ~VSW.XOffset
		,VDyn.YOffset 			-> ~VSW.YOffset
		,VDyn.ZOffset 			-> ~VSW.ZOffset

		,~VSW.X 	     -> VDynMotion.X
		,~VSW.Y 	     -> VDynMotion.Y
		,~VSW.Z 	     -> VDynMotion.Z
		,~VSW.yaw   		 -> VDynMotion.yaw
		,~VSW.pitch    -> VDynMotion.pitch
		,~VSW.roll     -> VDynMotion.roll
		,~VSW.v 	         -> VDynMotion.v
		,~VSW.vx 	     -> VDynMotion.vx
		,~VSW.vy 	     -> VDynMotion.vy
		,~VSW.vz 	     -> VDynMotion.vz
		,~VSW.vyaw 	 -> VDynMotion.vyaw
		,~VSW.vpitch   -> VDynMotion.vpitch
		,~VSW.vroll    -> VDynMotion.vroll
		,~VSW.ax 	     -> VDynMotion.ax
		,~VSW.ay 	     -> VDynMotion.ay
		,~VSW.az 	     -> VDynMotion.az
		,~VSW.ayaw 	 -> VDynMotion.ayaw
		,~VSW.apitch   -> VDynMotion.apitch
		,~VSW.aroll    -> VDynMotion.aroll
	};
	/* */