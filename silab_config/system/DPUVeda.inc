	DPUInterface VDyn
	{
		Computer = {VDYN};
		Index = 0;
		Interface_Postfix = "_VDyn";
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";

		VARSet = {
			Ignition,
			Starter,
			Stopper,
			HandBrake,
			Gear,
			SteeringWheel,
			AcceleratorPedal,
			BrakePedal,
			ClutchPedal,
			RPM,
			Consumption,

			s,
			X,
			Y,
			Z,
			yaw,
			pitch,
			roll,
			v,
			v_kmh,
			vx,
			vy,
			vz,
			v_X,
			v_Y,
			v_Z,
			vyaw,
			vpitch,
			vroll,
			ax,
			ay,
			az,
			ayaw,
			apitch,
			aroll,
			delta, 		//wheel angle of front wheel

			PitchRoad,
			RollRoad,
			XOffset,
			YOffset,
			ZOffset,

			SetupX,
			SetupY,
			SetupZ,
			SetupYaw,
			SetupPitch,
			SetupRoll,
			SetupDone,

			GearAuto,		# chosen gear of automatic gear shifting

			TrackWidthF,
			TrackWidthR
		};
		Ignition = 1;
		Starter = 1;
		TrackWidthF = 1.5118;
		TrackWidthR = 1.524;
	};

	DPUInterface VDynMotion
	{
		Computer = {MOTION};
		Index = 0;
		Interface_Postfix = "_VDynMotion";
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";


		VARSet = {
			X,
			Y,
			Z,
			yaw,
			pitch,
			roll,
			v,
			v_kmh,
			vx,
			vy,
			vz,
			vyaw,
			vpitch,
			vroll,
			ax,
			ay,
			az,
			ayaw,
			apitch,
			aroll
		};
	};

DPUAmplifier ~viewpitch
{
	Computer = {VDYN};
	Index = 1;
	TreeviewGroup = "Fahrdynamik";
	TreeviewGroup~en = "Vehicle Dynamics";
};
	

	Connections = {
		VDyn.X -> VDynView.X,
		VDyn.Y -> VDynView.Y,
		VDyn.Z -> VDynView.Z,
		VDyn.yaw   -> VDynView.yaw,
		VDyn.pitch -> ~viewpitch.In,
		~viewpitch.Out -> VDynView.pitch,
		VDyn.roll  -> VDynView.roll
	};

	DPUInterface VDynView
	{
		Computer = {VDYN};
		Index = 0;
		Interface_Postfix = "_VDynView";
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";

		VARSet = {
			X,
			Y,
			Z,
			yaw,
			pitch,
			roll
		};
	};



include system/SYSVeda.inc
