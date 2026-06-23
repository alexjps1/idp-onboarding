
DPUDataFile ~DebugData
{
	Computer = {DATA};
	Index = 700;

	Separator = "	";	# Tabulator als Trenner
	HeaderType = 1;
	Path = "\Daten\Debug_";
	Extension= "asc";

	#############################
	Record = 
	{
		VDYN.~Clock.Time ("VDYN.Time"),
		VDYN.~Clock.TimeError ("TimeError"),
		VDyn.SteeringWheel ("SteeringWheel"),
		VDyn.AcceleratorPedal ("AcceleratorPedal"),
		VDyn.BrakePedal ("BrakePedal"),
		VDyn.HandBrake ("HandBrake"),
		VDyn.ClutchPedal ("ClutchPedal"),
		VDyn.Gear ("Gear"),
		#VDyn.SimGear ("SimulatedGear"),
		VDyn.RPM ("RPM")
	};
};
