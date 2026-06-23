			DPUEnvSCNX Environment
			{
				Computer = {SCN};
				Index = 42;
				TreeviewGroup~en = "Database";
				TreeviewGroup = "Datenbasis";
				InTimeOfDay = 15;
			};

			DPUMixAmplifier ~HLMux
			{
				Computer = {MOCKUP};
				Index = 20;
				TreeviewGroup = "Mockup";

				Multiplicator2 = 2;
				MaxOut = 2;
			};
			Connections = {
				Mockup.LowerBeam -> ~HLMux.In1,
				Mockup.UpperBeam -> ~HLMux.In2,
				~HLMux.Out -> Environment.InHeadLight
			};

			DPUDemultiplexer ~HLDem
			{
				Computer = {MOCKUP};
				Index = 20;
				TreeviewGroup = "Mockup";

				In = 1;
				OutMax1 = 1;
				OutMax2 = 1;
			};
			Connections = {
				Environment.OutHeadLight -> ~HLDem.Switch,
				~HLDem.Out1 -> Display.LowerBeam,
				~HLDem.Out2 -> Display.UpperBeam
			};
