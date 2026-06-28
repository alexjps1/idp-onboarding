		DPUVDSST2W ~VDS
         {
         	Index = 10;
         	Computer = {VDYN};
 			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";
        	CfgDriveTrain = "DriveTrain_BMWK1200R.cfg";
         	CfgSingleTrack = "SingleTrack_BMWK1200R.cfg";
         	#CfgDriveTrain = "DriveTrain_Transit.cfg";
         	#CfgSingleTrack = "SingleTrack_Transit.cfg";
         	#CfgDriveTrain = "DriveTrain_Actros.cfg";
         	#CfgSingleTrack = "SingleTrack_Actros.cfg";
         	CounterSteeringMode = 0;
			SteeringAngleMode = 1;
         };
 	Connections = {
	#	 VDyn.Ignition 			<-> ~VDS.Ignition
	#	,VDyn.Starter 			<-> ~VDS.Starter
		VDyn.Brake_Hand 		<-> ~VDS.Brake_Hand
		,VDyn.Gear 				<-> ~VDS.Gear
		,VDyn.HandlebarTorque 	<-> ~VDS.HandlebarTorque
		,VDyn.HandlebarAngle 	<-> ~VDS.HandlebarAngle
		,VDyn.AcceleratorPedal 	<-> ~VDS.AcceleratorPedal
		,VDyn.Brake_Foot 		<-> ~VDS.Brake_Foot
		,VDyn.HipAngle			<-> ~VDS.HipAngle
		,VDyn.Clutch 			<-> ~VDS.Clutch
		#,VDyn.HipAngle			<-> ~VDS.HipAngle
		,VDyn.RollIn			<-> ~VDS.RollIn
		,~VDS.RPM			<-> VDyn.RPM
	#	,~VDS.s				<-> VDyn.s
		,~VDS.X 			<-> VDyn.X
		,~VDS.Y 			<-> VDyn.Y
		,~VDS.Z 		    <-> VDyn.Z
		,~VDS.yaw   		<-> VDyn.yaw
		,~VDS.pitch 	    <-> VDyn.pitch
		,~VDS.roll			<-> VDyn.roll
		,~VDS.v 		    <-> VDyn.v
		,~VDS.v_kmh 	    <-> VDyn.v_kmh
	#	,~VDS.vx 			<-> VDyn.vx
	#	,~VDS.vy 			<-> VDyn.vy
	#	,~VDS.vz 			<-> VDyn.vz
	#	,~VDS.v_X 			<-> VDyn.v_X
	#	,~VDS.v_Y 			<-> VDyn.v_Y
	#	,~VDS.v_Z 			<-> VDyn.v_Z
	#	,~VDS.vyaw 	    	<-> VDyn.vyaw
	#	,~VDS.vpitch 		<-> VDyn.vpitch
	#	,~VDS.vroll 	    <-> VDyn.vroll
		,~VDS.ax 			<-> VDyn.ax
		,~VDS.ay 			<-> VDyn.ay
	#	,~VDS.az 			<-> VDyn.az
	#	,~VDS.ayaw 	    	<-> VDyn.ayaw
	#	,~VDS.apitch 		<-> VDyn.apitch
	#	,~VDS.aroll 	   	<-> VDyn.aroll

		,VDyn.PitchRoad 		<-> ~VDS.PitchRoad
	#	,VDyn.RollRoad 			<-> ~VDS.RollRoad
		,VDyn.SetupX 			<-> ~VDS.XOffset
		,VDyn.SetupY 			<-> ~VDS.YOffset
		,VDyn.ZOffset 			<-> ~VDS.ZOffset
		,VDyn.SetupX	 		-> ~VDS.SetupX
		,VDyn.SetupY	 		-> ~VDS.SetupY
		,VDyn.SetupZ	 		-> ~VDS.SetupZ
		,VDyn.SetupYaw			-> ~VDS.SetupYaw
		,VDyn.SetupPitch		-> ~VDS.SetupPitch
		,VDyn.SetupRoll			-> ~VDS.SetupRoll
		,VDyn.SetupDone			-> ~VDS.SetupDone

		,~VDS.X 	     <-> VDynMotion.X
		,~VDS.Y 	     <-> VDynMotion.Y
		,~VDS.Z 	     <-> VDynMotion.Z
		,~VDS.yaw   		 <-> VDynMotion.yaw
		,~VDS.pitch    <-> VDynMotion.pitch
		,~VDS.roll     <-> VDynMotion.roll
		,~VDS.v 	         <-> VDynMotion.v
	#	,~VDS.vx 	     <-> VDynMotion.vx
	#	,~VDS.vy 	     <-> VDynMotion.vy
	#	,~VDS.vz 	     <-> VDynMotion.vz
	#	,~VDS.vyaw 	 <-> VDynMotion.vyaw
	#	,~VDS.vpitch   <-> VDynMotion.vpitch
	#	,~VDS.vroll    <-> VDynMotion.vroll
		,~VDS.ax 	     <-> VDynMotion.ax
		,~VDS.ay 	     <-> VDynMotion.ay
	#	,~VDS.az 	     <-> VDynMotion.az
	#	,~VDS.ayaw 	 <-> VDynMotion.ayaw
	#	,~VDS.apitch   <-> VDynMotion.apitch
	#	,~VDS.aroll    <-> VDynMotion.aroll
	};
	DPUComparator ~VDSNegAX
	{
		Computer = {VDYN};
		Index = 0;
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";
		Min = 0;
		Max = 20;
	};
	DPUAmplifier ~VDSPitchGain
	{
		Computer = {VDYN};
		Index = 0;
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";
		#In = 0.063;
		#Offset = 0.06;
		In = 0.02;
		Offset = 0.03;
	};
	Connections = 
	{
		~VDSNegAX.Less -> ~VDSPitchGain.Multiplicator,
		~VDS.ax -> ~VDSNegAX.In,
		~VDSPitchGain.Out -> ~VDS.DriveTrain.pitch_gain
	};

