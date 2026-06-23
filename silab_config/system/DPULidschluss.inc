
	/* Umrechnung Spulen (Volt) in Meter */
	DPUAmplifier Lid_V_m
	{
		Computer = {PPM};
		Index = 1;
		Multiplicator = 4;
		Divisor = 1000;
		Offset = -0.0084;
	};
	Connections = {
		PPM.FahrerLid -> Lid_V_m.In,
		Lid_V_m.Out -> Lidschluss.In
	};
	/**/
		
	DPULidschluss Lidschluss
	{
		Computer = {PPM};
		Index = 10;
	};

	/* für SmartEye */
	#Connections = {
		#SEPAReceiver.EyelidOpening -> Lidschluss.In
	#};
	
	/**/

	includeif System/SYSLidschluss.inc

