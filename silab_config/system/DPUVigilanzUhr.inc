			DPUVigilanzUhr VigilanzUhr
			{
				Computer =	{ VIGILANZ };
				Index = 14;
				TreeviewGroup = "Nebenaufgabe";
				TreeviewGroup~en = "Secondary task";

				TonW = 90;
				TonZeit = 2000;
				Volume = 110;
				Instrument = 4;
				Ton = 66;
			};

			Connections =
			{
				Buttons.Button1Left -> VigilanzTasteL.In,
				VigilanzTasteL.Out -> VigilanzUhr.Taste1,
				Buttons.Button1Right -> VigilanzTasteR.In,
				VigilanzTasteR.Out -> VigilanzUhr.Taste2
			};
			DPUVigilanzUhrDecoder VigilanzUhrDecoder
			{
				Computer = { DATA,OPERATOR	};
				Index = 15;
				TreeviewGroup = "Nebenaufgabe";
				TreeviewGroup~en = "Secondary task";
			};
			Connections =
			{
				VigilanzUhr.Data -> VigilanzUhrDecoder.Data
			};
