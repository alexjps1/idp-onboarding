	DPUCarSimSCNX ~CarSim
	#DPUCarSim ~CarSim
	{
		Index = 120;
		Computer = {VDYN};
		SimFile = "\SILAB_32\LIB\Configurations\CarSim711\WIVW1\Simfile";
		AdditionalOut = 
		{
			(FY_A1)
		};		
		AdditionalIn = 
		{
			(IMP_AUX1)
		};		
	};
	
	Connections = {
		 VDyn.SteeringWheel 	-> ~CarSim.SteeringWheel
		,VDyn.AcceleratorPedal 	-> ~CarSim.AcceleratorPedal
		,VDyn.BrakePedal 		-> ~CarSim.BrakePedal
#		,VDyn.Ignition 			-> ~CarSim.Ignition
		,VDyn.Starter 			-> ~CarSim.StartEngine
		,VDyn.Stopper           -> ~CarSim.StopEngine
		,VDyn.HandBrake 		-> ~CarSim.HandBrake
		,VDyn.Gear 				-> ~CarSim.Gear

		,~CarSim.RPM			-> VDyn.RPM   					 	   
		,~CarSim.X 			-> VDyn.X     				
		,~CarSim.Y 			-> VDyn.Y     				
		,~CarSim.Z 		    -> VDyn.Z     				
		,~CarSim.yaw   		-> VDyn.yaw   				
		,~CarSim.pitch 	    -> VDyn.pitch 			
		,~CarSim.roll			-> VDyn.roll  			
		,~CarSim.v 		    -> VDyn.v     			
		,~CarSim.v_kmh 	    -> VDyn.v_kmh 			
		,~CarSim.vx 			-> VDyn.vx    			   
		,~CarSim.vy 			-> VDyn.vy    			   
		,~CarSim.vz 			-> VDyn.vz    			   
		,~CarSim.vyaw 	    	-> VDyn.vyaw  			
		,~CarSim.vpitch 		-> VDyn.vpitch			
		,~CarSim.vroll 	    -> VDyn.vroll 			
		,~CarSim.ax 			-> VDyn.ax    			   
		,~CarSim.ay 			-> VDyn.ay    			   
		,~CarSim.az 			-> VDyn.az    			   
		,~CarSim.ayaw 	    	-> VDyn.ayaw  			
		,~CarSim.apitch 		-> VDyn.apitch			
		,~CarSim.aroll 	   	-> VDyn.aroll 			
		
		,~CarSim.GearAuto       -> VDyn.GearAuto
		
		,VDyn.XOffset 			-> ~CarSim.XOffset
		,VDyn.YOffset 			-> ~CarSim.YOffset
		,VDyn.ZOffset 			-> ~CarSim.ZOffset

		,~CarSim.XMotion 	     -> VDynMotion.X       	 
		,~CarSim.YMotion 	     -> VDynMotion.Y       	 
		,~CarSim.ZMotion 	     -> VDynMotion.Z       	 
		,~CarSim.yaw   		 -> VDynMotion.yaw     	 
		,~CarSim.pitchMotion    -> VDynMotion.pitch   	 
		,~CarSim.rollMotion     -> VDynMotion.roll    	 
		,~CarSim.v 	         -> VDynMotion.v       	 
		,~CarSim.vxMotion 	     -> VDynMotion.vx      	 
		,~CarSim.vyMotion 	     -> VDynMotion.vy      	 
		,~CarSim.vzMotion 	     -> VDynMotion.vz      	 
		,~CarSim.vyawMotion 	 -> VDynMotion.vyaw    	 
		,~CarSim.vpitchMotion   -> VDynMotion.vpitch   	
		,~CarSim.vrollMotion    -> VDynMotion.vroll   	 
		,~CarSim.axMotion 	     -> VDynMotion.ax      	 
		,~CarSim.ayMotion 	     -> VDynMotion.ay      	 
		,~CarSim.azMotion 	     -> VDynMotion.az      	 
		,~CarSim.ayawMotion 	 -> VDynMotion.ayaw    	 
		,~CarSim.apitchMotion   -> VDynMotion.apitch   	
		,~CarSim.arollMotion    -> VDynMotion.aroll   
	}; 
