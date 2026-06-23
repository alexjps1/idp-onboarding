	DPUHeli ~Heli
	{
		Index = 20;
		Computer = {VDYN};
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";
	};

	Connections = {
		 VDyn.Gear 				-> ~Heli.Gear
		,VDyn.SteeringWheel 	-> ~Heli.SteeringWheel
		,VDyn.AcceleratorPedal 	-> ~Heli.AcceleratorPedal
		,VDyn.BrakePedal 		-> ~Heli.BrakePedal

		,default			-> VDyn.RPM
		,default		  -> VDyn.s
		,default			-> VDyn.vx
		,default			-> VDyn.vy
		,default			-> VDyn.vz
		,default			-> VDyn.v_X
		,default			-> VDyn.v_Y
		,default			-> VDyn.v_Z
		,default			-> VDyn.az
		,default    		-> VDynMotion.X
		,default    		-> VDynMotion.Y
		,default    		-> VDynMotion.Z
		,default    		-> VDynMotion.yaw
		,default    		-> VDynMotion.pitch
		,default   		 	-> VDynMotion.roll
		,default    		-> VDynMotion.v
		,default    		-> VDynMotion.vx
		,default    		-> VDynMotion.vy
		,default    		-> VDynMotion.vz
		,default	 			-> VDynMotion.vyaw
		,default    		-> VDynMotion.vpitch
		,default    		-> VDynMotion.vroll
		,default    		-> VDynMotion.ax
		,default    		-> VDynMotion.ay
		,default    		-> VDynMotion.az
		,default	 			-> VDynMotion.ayaw
		,default    		-> VDynMotion.apitch
		,default    		-> VDynMotion.aroll

		,~Heli.X 				-> VDyn.X
		,~Heli.Y 				-> VDyn.Y
		,~Heli.Z 				-> VDyn.Z
		#,~Heli.yaw   			-> VDyn.yaw
		,~Heli.ViewYaw 			-> VDyn.yaw
		,~Heli.pitch 			-> VDyn.pitch
		,~Heli.roll 	   		-> VDyn.roll
		,~Heli.v 				-> VDyn.v
		,~Heli.v_kmh 			-> VDyn.v_kmh
		,~Heli.vyaw 	    	-> VDyn.vyaw
		,~Heli.vpitch 			-> VDyn.vpitch
		,~Heli.vroll 			-> VDyn.vroll
		,~Heli.ax 				-> VDyn.ax
		,~Heli.ay 				-> VDyn.ay
		,~Heli.ayaw 	    	-> VDyn.ayaw
		,~Heli.apitch 			-> VDyn.apitch
		,~Heli.aroll 			-> VDyn.aroll

		,VDyn.PitchRoad 		-> ~Heli.PitchRoad
		,VDyn.RollRoad 			-> ~Heli.RollRoad
		,VDyn.XOffset 			-> ~Heli.XOffset
		,VDyn.YOffset 			-> ~Heli.YOffset
		,VDyn.ZOffset 			-> ~Heli.ZOffset
		,VDyn.SetupX	 		-> ~Heli.SetupX
		,VDyn.SetupY	 		-> ~Heli.SetupY
		,VDyn.SetupZ	 		-> ~Heli.SetupZ
		,VDyn.SetupYaw			-> ~Heli.SetupYaw
		,VDyn.SetupPitch		-> ~Heli.SetupPitch
		,VDyn.SetupRoll			-> ~Heli.SetupRoll
		,VDyn.SetupDone			-> ~Heli.SetupDone


	};

    ~MSTVeda.Computer = {};

