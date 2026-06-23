			DPUExtClock ~ExtClock
			{
				Computer = {ALL};
				Index = 1;
			};

			DPUExtClockSGE ~ExtClockSGE
			{
				Computer = {VIS};
				Index = 1;
			};

			DPUExtClockLog ~ExtClockLog
			{
				Computer = {OPERATOR};
				Index = 1000;
				DPUExtClockName = "~ExtClock";
				DPUExtClockAlias = "ALL";
				ExtClockSGEName = "~ExtClockSGE";
				ExtClockSGEAlias = "VIS";
			};
