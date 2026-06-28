	DPUInterface Mockup
	{
		Computer = {VDYN};
		Index = 0; # bei DPUInterface ist der Index egal
		Interface_Postfix = "_Mockup";
		TreeviewGroup = "Mockup";

		VARSet = {
			Ignition,
			Starter,
			Stopper,
			Gear,
			AcceleratorPedal,
			AcceleratorKickdown,
			BrakePedal,
			ClutchPedal,
			BrakeReadiness,
			SteeringWheel,
			SteeringWheelv,
			SteeringWheelTouch,
			OffsetSteeringMoment,
			SteeringMoment,
			SteeringMomentModel,
			Indicator,
			IndicatorLeft,
			IndicatorRight,
			IndicatorLeftFirstLevel,
			IndicatorRightFirstLevel,
			IndicatorLeftSecondLevel,
			IndicatorRightSecondLevel,
			IndicatorOverwrite,
			IndicatorReset,
			ActivateIndicatorLeft,
			ActivateIndicatorRight,
			HandBrake,
			Horn,
			UpperBeam,
			LowerBeam,
			FogLight
		};

		Ignition = 1;
		Starter = 1;
	};

	DPUBooleanGate ~Indicator
	{
		Computer = {MOCKUP};
		TreeviewGroup = "Mockup";
		Index = 1;
		Gate = OR;
		Channels = 2;
	};
	Connections =
	{
		Mockup.IndicatorLeft -> ~Indicator.In1,
		Mockup.IndicatorRight -> ~Indicator.In2,
		~Indicator.Out -> Mockup.Indicator
	};
	
	DPUInterface Display
	{
		Computer = {VDYN};
		Index = 1; # bei DPUInterface ist der Index egal
		Interface_Postfix = "_Display";
		TreeviewGroup = "Mockup";

		VARSet = {
			v,
			RPM,
			IndicatorLeft,
			IndicatorRight,
			LowerBeam,
			UpperBeam,
			FogLight,
			OilPressure,
			BatteryWarning,
			Temperature,
			FuelGauge,
			FuelWarning,
			SteeringWarning,
			ABSWarning,
			DashboardLight
		};
		DashboardLight = 3;
	};

	DPUInterface Buttons
	{
		Computer = {VDYN};
		Index = 0; # bei DPUInterface ist der Index egal
		Interface_Postfix = "_Buttons";
		TreeviewGroup = "Mockup";

		VARSet = {
			Privilege,
			Button1Left,
			Button2Left,
			Button1Right,
			Button2Right,

			MFSButton1Left,
			MFSButton2Left,
			MFSButton3Left,
			MFSButton4Left,
			MFSButton5Left,
			MFSButton6Left,
			MFSButton7Left,
			MFSButton1Right,
			MFSButton2Right,
			MFSButton3Right,
			MFSButton4Right,
			MFSButton5Right,
			MFSButton6Right,
			MFSButton7Right
		};
	};

include system/SYSMockup.inc
