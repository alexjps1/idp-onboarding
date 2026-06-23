# Einbindung von Regen
# Ansteuerung geht über Hedgehogs:
# Family = Weather
#   StartRain -> 0 oder 1 (Regen aus/an)
#   RainDensity -> (0...20000) (Dichte des Regens)
#   FlashTime -> (0..100) (Blitzzeit)

		DPUSCNXHedgehogKiller Weather
		{
			Computer = {SCN};
			Index = 76;

			Family = "Weather";
			Name1 = "StartRain";
			Name2 = "RainDensity";
			Name3 = "FlashTime";

			Default1 = 0;
			Default2 = 20000;
			Default3 = 20;
		};

		DPULimiter FogBlender
		{
			Computer = {VDYN};
			Index = 77;
			In = 0;									#Zielwert
			SlopeLimitPos = 1.0e-3;					#Einblenden;
			SlopeLimitNeg = -1.0e-3;				#Ausblenden;
		};

		DPULimiter RainBlender
		{
			Computer = {VDYN};
			Index = 77;
			In = 0;									#Zielwert
			SlopeLimitPos = 1000;					#Einblenden;
			SlopeLimitNeg = -1000;					#Ausblenden;
		};

        Connections =
        {
			Weather.Out1 <-> SIGWeather.StartRain,			#war auskommentiert, von mir geändert (max)
			Weather.Out2 <-> RainBlender.In #,
	#		RainBlender.Out <-> SIGWeather.RainDensity,
	#		Weather.Out3 <-> SIGWeather.FlashTime,

	#		SIGWeather.Fog <-> FogBlender.In,
	#		FogBlender.Out <-> SIGView.Fog,
	#		SIGWeather.FogR <-> SIGView.FogR,
	#		SIGWeather.FogG <-> SIGView.FogG,
	#		SIGWeather.FogB <-> SIGView.FogB,
	#		SIGWeather.FogA <-> SIGView.FogA
		};


