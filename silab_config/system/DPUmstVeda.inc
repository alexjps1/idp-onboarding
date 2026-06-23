	DPUmstVeda ~MSTVeda
	{
		Index = 20;
		Computer = {VDYN};
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";

		FilterWindowLength = 15;

		# ACHTUNG:
		# Parameter ConfigPath nicht ohne Rücksprache
		# mit Sonja/Armin/Martin verstellen!!!

		# richtige Parameter
		ConfigPath = "MSTVedaAutoPar.BMW/";
		ABS = 1.0;
	};

	Connections = {
		 VDyn.Ignition 			-> ~MSTVeda.Ignition
		,VDyn.Starter 			-> ~MSTVeda.Starter
		,VDyn.HandBrake 		-> ~MSTVeda.HandBrake
		,VDyn.Gear 				-> ~MSTVeda.Gear
		,VDyn.SteeringWheel 	-> ~MSTVeda.SteeringWheel
		,VDyn.AcceleratorPedal 	-> ~MSTVeda.AcceleratorPedal
		,VDyn.BrakePedal 		-> ~MSTVeda.BrakePedal

		,~MSTVeda.RPM			-> VDyn.RPM
		,~MSTVeda.s				-> VDyn.s
		,~MSTVeda.X 			-> VDyn.X
		,~MSTVeda.Y 			-> VDyn.Y
		,~MSTVeda.Z 		    -> VDyn.Z
		,~MSTVeda.yaw   		-> VDyn.yaw
		,~MSTVeda.pitch 	    -> VDyn.pitch
		,~MSTVeda.roll			-> VDyn.roll
		,~MSTVeda.v 		    -> VDyn.v
		,~MSTVeda.v_kmh 	    -> VDyn.v_kmh
		,~MSTVeda.vx 			-> VDyn.vx
		,~MSTVeda.vy 			-> VDyn.vy
		,~MSTVeda.vz 			-> VDyn.vz
		,~MSTVeda.v_X 			-> VDyn.v_X
		,~MSTVeda.v_Y 			-> VDyn.v_Y
		,~MSTVeda.v_Z 			-> VDyn.v_Z
		,~MSTVeda.vyaw 	    	-> VDyn.vyaw
		,~MSTVeda.vpitch 		-> VDyn.vpitch
		,~MSTVeda.vroll 	    -> VDyn.vroll
		,~MSTVeda.ax 			-> VDyn.ax
		,~MSTVeda.ay 			-> VDyn.ay
		,~MSTVeda.az 			-> VDyn.az
		,~MSTVeda.ayaw 	    	-> VDyn.ayaw
		,~MSTVeda.apitch 		-> VDyn.apitch
		,~MSTVeda.aroll 	   	-> VDyn.aroll

		,VDyn.PitchRoad 		-> ~MSTVeda.PitchRoad
		,VDyn.RollRoad 			-> ~MSTVeda.RollRoad
		,VDyn.XOffset 			-> ~MSTVeda.XOffset
		,VDyn.YOffset 			-> ~MSTVeda.YOffset
		,VDyn.ZOffset 			-> ~MSTVeda.ZOffset
		,VDyn.SetupX	 		-> ~MSTVeda.SetupX
		,VDyn.SetupY	 		-> ~MSTVeda.SetupY
		,VDyn.SetupZ	 		-> ~MSTVeda.SetupZ
		,VDyn.SetupYaw			-> ~MSTVeda.SetupYaw
		,VDyn.SetupPitch		-> ~MSTVeda.SetupPitch
		,VDyn.SetupRoll			-> ~MSTVeda.SetupRoll
		,VDyn.SetupDone			-> ~MSTVeda.SetupDone

		,~MSTVeda.XMotion 	     -> VDynMotion.X
		,~MSTVeda.YMotion 	     -> VDynMotion.Y
		,~MSTVeda.ZMotion 	     -> VDynMotion.Z
		,~MSTVeda.yaw   		 -> VDynMotion.yaw
		,~MSTVeda.pitchMotion    -> VDynMotion.pitch
		,~MSTVeda.rollMotion     -> VDynMotion.roll
		,~MSTVeda.v 	         -> VDynMotion.v
		,~MSTVeda.vxMotion 	     -> VDynMotion.vx
		,~MSTVeda.vyMotion 	     -> VDynMotion.vy
		,~MSTVeda.vzMotion 	     -> VDynMotion.vz
		,~MSTVeda.vyawMotion 	 -> VDynMotion.vyaw
		,~MSTVeda.vpitchMotion   -> VDynMotion.vpitch
		,~MSTVeda.vrollMotion    -> VDynMotion.vroll
		,~MSTVeda.axMotion 	     -> VDynMotion.ax
		,~MSTVeda.ayMotion 	     -> VDynMotion.ay
		,~MSTVeda.azMotion 	     -> VDynMotion.az
		,~MSTVeda.ayawMotion 	 -> VDynMotion.ayaw
		,~MSTVeda.apitchMotion   -> VDynMotion.apitch
		,~MSTVeda.arollMotion    -> VDynMotion.aroll
	};
	//Correction of wheel angle range of mstVeda
	DPUAmplifier ~VedaWheelAmp
	{
		Index = 25;
		Computer = {VDYN};
		Multiplicator = -0.1;
		Offset = 0;
	};
	Connections = {
		~MSTVeda.FrontWheelAngle -> ~VedaWheelAmp.In,
		~VedaWheelAmp.Out -> VDyn.delta
	};
	
	includeif System/SYSMstVeda.inc
