			DPUHUDSGE Nav
			{
				Computer = {FRONT};
				Index = 20;
				x = 20;
				y = 20;

				Object1 = nav.n04;
				Object2 = nav.n08;
				Object3 = nav.n09;
				Object4 = nav.n10;

				Scale = 2;
			};

			DPUSCNXHedgehogKiller NavHedgehogKiller
			{
				Computer = {SCN};
				Index = 1000;

				Family = "Nav";
				Name1 = "Image";
				Default1 = 0.0;
			};

			DPUDemultiplexer NavMux
			{
				Computer = {VDYN};
				Index = 1001;

				In = 1;
			};

			Connections =
			{
				NavHedgehogKiller.Out1 <-> NavMux.Switch,

				NavMux.Out1 <-> Nav.Show1,
				NavMux.Out2 <-> Nav.Show2,
				NavMux.Out3 <-> Nav.Show3,
				NavMux.Out4 <-> Nav.Show4,
				NavMux.Out5 <-> Nav.Show5
			};
