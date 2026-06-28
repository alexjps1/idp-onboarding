			DPUAmplifier ~EGODistLeft
			{
				Computer = {DATA};
				Index = 41;
				Offset = 0.755;
				Divisor = -2;
			};
			DPUAmplifier ~EGODistRight
			{
				Computer = {DATA};
				Index = 42;
				Offset = -0.755;
				Divisor = 2;
			};
			##############################################################
			###
			###  Der eigentliche Ausgang ist dann EGOOnLane.NotEqual
			###
			DPUComparator EGOOnLane
			{
				Computer = {DATA};
				Index = 43;
			};
			Connections = 
			{
				 SCN.LaneWidth -> ~EGODistLeft.In			
				,SCN.LaneWidth -> ~EGODistRight.In
				,~EGODistLeft.Out -> EGOOnLane.Min
				,~EGODistRight.Out -> EGOOnLane.Max
				,SCN.LateralDistance -> EGOOnLane.In
			};
			includeif system\SYSEgoOnLaneParams.inc
