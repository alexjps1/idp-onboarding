# Einbindung von Nacht
		DPUSCNXHedgehogKiller Nacht
		{
			Computer = { SCN };
			Index = 90;

			Family = "Night";
			Name1 = "Night";
			Default1 = 0.0;
		};

		DPULimiter NachtBlende
		{
			Computer = { VDYN };
			Index = 91;
			In = 0;									#Zielwert
			SlopeLimitPos = 1.0e-2;					#Einblenden;
			SlopeLimitNeg = -2.0e-2;				#Ausblenden;
		};

		Connections =
		{
			Nacht.Out1 <-> NachtBlende.In,
#			NachtBlende.Out <-> HeadlightsF.ColA,
#			NachtBlende.Out <-> HeadlightsL.ColA,
#			NachtBlende.Out <-> HeadlightsR.ColA,
#			NachtBlende.Out <-> HeadlightsR1.ColA,
#			NachtBlende.Out <-> HeadlightsR2.ColA,
#			NachtBlende.Out <-> HeadlightsR3.ColA,
			NachtBlende.Out <-> TRF.Fog
		};

