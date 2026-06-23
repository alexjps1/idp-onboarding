#########################################################
##### DYNCar Vehicle Dynamics ###########################
#########################################################

DPUDYNCar ~DYNcar
         {
         	Index = 10;
         	Computer = {VDYN};
			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";
			CfgDYN = "Limousine.cfg";
			#CfgDYN = "CompactVan.cfg";
			#CfgDYN = "TransportVan.cfg";
			#CfgDYN = "Roadster.cfg";
			#CfgDYN = "Electric_SUV.cfg";
			#CfgDYN = "Hatchback.cfg";
         };

#########################################################
##### Road contact simulation ###########################
#########################################################
		 
DPUVDSSCNX ~hRoad
		 {
         	Index = 41;	# Index must be greater than SCNX
         	Computer = {VDYN};
			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";
			SlopeLimit = 10.0;
			EnableRefinement = 1;
         };

#########################################################
##### Added interface variables #########################
#########################################################
	 	 
VDyn.VARSet 	+= {SteeringMoment,
					Wheelspeed_fl,Wheelspeed_fr,Wheelspeed_rl,Wheelspeed_rr};
					
Mockup.VARSet 	+= {GearUp ,GearDown, 
					FFB_Spring, FFB_Spring_Fmax, FFB_Damping, FFB_Friction};

#########################################################
##### Sequential Gearbox Shift Logic ####################
#########################################################		 

DPUMixAmplifier ~Gbx_Dir
		{
			Index = 12;
			Computer = {VDYN};
			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";
			Multiplicator1 = 1;
			Multiplicator2 = -1;
		};
DPUCounter ~Gbx_Manual
		{
			Index = 12;
			Computer = {VDYN};
			TreeviewGroup = "Fahrdynamik";
			TreeviewGroup~en = "Vehicle Dynamics";
		};
DPUBooleanGate ~ShifterPressed
		{
			Index = 12;
			Computer = {VDYN};
			Channels = 2;
			Gate = OR;
		};
Connections = {
		 Mockup.GearUp 			-> ~Gbx_Dir.In1
		,Mockup.GearDown 		-> ~Gbx_Dir.In2
		,Mockup.GearUp 			-> ~ShifterPressed.In1
		,Mockup.GearDown		-> ~ShifterPressed.In2
		,~ShifterPressed.Out	-> ~Gbx_Manual.Start
		,~ShifterPressed.Out	-> ~Gbx_Manual.Stop
		,~Gbx_Dir.Out			-> ~Gbx_Manual.Delta
		,~Gbx_Manual.Out 		-> ~DYNcar.GearManual
		};

#########################################################
##### Vehicle state connections #########################
#########################################################

 	Connections = {
	
		## Road contact
		 ~DYNcar.Xfl 	     	-> ~hRoad.Xfl
		,~DYNcar.Yfl 	     	-> ~hRoad.Yfl
		,~hRoad.Zfl      		-> ~DYNcar.Zfl
		,~hRoad.mufl      		-> ~DYNcar.mufl		
		,~DYNcar.Xfr 	     	-> ~hRoad.Xfr
		,~DYNcar.Yfr 	     	-> ~hRoad.Yfr
		,~hRoad.Zfr 	     	-> ~DYNcar.Zfr
		,~hRoad.mufr 	     	-> ~DYNcar.mufr		
		,~DYNcar.Xrl 	     	-> ~hRoad.Xrl
		,~DYNcar.Yrl 	     	-> ~hRoad.Yrl
		,~hRoad.Zrl 	     	-> ~DYNcar.Zrl
		,~hRoad.murl 	     	-> ~DYNcar.murl		
		,~DYNcar.Xrr 	     	-> ~hRoad.Xrr
		,~DYNcar.Yrr 	     	-> ~hRoad.Yrr
		,~hRoad.Zrr 	     	-> ~DYNcar.Zrr
		,~hRoad.murr 	     	-> ~DYNcar.murr
		
		,VDyn.XOffset 			-> ~DYNcar.XOffset
		,VDyn.YOffset 			-> ~DYNcar.YOffset
		,VDyn.ZOffset 			-> ~DYNcar.ZOffset
		,VDyn.SetupX	 		-> ~DYNcar.SetupX
		,VDyn.SetupY	 		-> ~DYNcar.SetupY
		,VDyn.SetupZ	 		-> ~DYNcar.SetupZ
		,VDyn.SetupYaw			-> ~DYNcar.SetupYaw
		,VDyn.SetupPitch		-> ~DYNcar.SetupPitch
		,VDyn.SetupRoll			-> ~DYNcar.SetupRoll
		,VDyn.SetupDone			-> ~DYNcar.SetupDone
		,VDyn.SetupDone			-> ~hRoad.SetupDone
		
		## Controls
		,VDyn.Ignition 			-> ~DYNcar.Ignition
		,VDyn.Starter 			-> ~DYNcar.Starter
		,VDyn.HandBrake 		-> ~DYNcar.HandBrake
		,VDyn.AcceleratorPedal 	-> ~DYNcar.AcceleratorPedal
		,VDyn.BrakePedal 		-> ~DYNcar.BrakePedal
		,VDyn.ClutchPedal 		-> ~DYNcar.ClutchPedal
		
		## Steering
		,VDyn.SteeringWheel 	-> ~DYNcar.SteeringWheel
		,Mockup.FFB_Spring		-> ~DYNcar.FFB_Spring
		,Mockup.FFB_Spring_Fmax	-> ~DYNcar.FFB_Spring_Fmax
		,Mockup.FFB_Damping		-> ~DYNcar.FFB_Damping 
		,Mockup.FFB_Friction	-> ~DYNcar.FFB_Friction
		,~DYNcar.SteeringMoment ->  VDyn.SteeringMoment
		
		## Drivetrain
		,VDyn.Gear 				-> ~DYNcar.GearAutomatic
		#,VDyn.Gear 			-> ~DYNcar.GearManual
		,~DYNcar.Consumption	-> VDyn.Consumption
		,~DYNcar.SelGear		-> VDyn.GearAuto
		,~DYNcar.RPM			-> VDyn.RPM
					
		## Vehicle States
		,~DYNcar.s				-> VDyn.s
		,~DYNcar.X 				-> VDyn.X
		,~DYNcar.Y 				-> VDyn.Y
		,~DYNcar.Z 		    	-> VDyn.Z
		,~DYNcar.yaw   			-> VDyn.yaw
		,~DYNcar.pitch 	    	-> VDyn.pitch
		,~DYNcar.roll			-> VDyn.roll
		,~DYNcar.v 		    	-> VDyn.v
		,~DYNcar.v_kmh 	    	-> VDyn.v_kmh
		,~DYNcar.vx 			-> VDyn.vx
		,~DYNcar.vy 			-> VDyn.vy
		,~DYNcar.vz 			-> VDyn.vz
		,~DYNcar.vyaw 	    	-> VDyn.vyaw
		,~DYNcar.vpitch 		-> VDyn.vpitch
		,~DYNcar.vroll 	    	-> VDyn.vroll
		,~DYNcar.ax 			-> VDyn.ax
		,~DYNcar.ay 			-> VDyn.ay
		,~DYNcar.az 			-> VDyn.az
		,~DYNcar.ayaw 	    	-> VDyn.ayaw
		,~DYNcar.apitch 		-> VDyn.apitch
		,~DYNcar.aroll 	   		-> VDyn.aroll
		,~DYNcar.delta_fl		-> VDyn.delta		
		,~DYNcar.omega_fl 	 	-> VDyn.Wheelspeed_fl
		,~DYNcar.omega_fr 	 	-> VDyn.Wheelspeed_fr
		,~DYNcar.omega_rl	 	-> VDyn.Wheelspeed_rl
		,~DYNcar.omega_rr  	 	-> VDyn.Wheelspeed_rr

		## Motion States
		,~DYNcar.X 	     		-> VDynMotion.X
		,~DYNcar.Y 	     		-> VDynMotion.Y
		,~DYNcar.Z 	     		-> VDynMotion.Z
		,~DYNcar.yaw   		 	-> VDynMotion.yaw
		,~DYNcar.pitch    		-> VDynMotion.pitch
		,~DYNcar.roll     		-> VDynMotion.roll
		,~DYNcar.v 	         	-> VDynMotion.v
		,~DYNcar.vx 	     	-> VDynMotion.vx
		,~DYNcar.vy 	     	-> VDynMotion.vy
		,~DYNcar.vz 	     	-> VDynMotion.vz
		,~DYNcar.vyaw 	 		-> VDynMotion.vyaw
		,~DYNcar.vpitch   		-> VDynMotion.vpitch
		,~DYNcar.vroll    		-> VDynMotion.vroll
		,~DYNcar.ax 	     	-> VDynMotion.ax
		,~DYNcar.ay 	     	-> VDynMotion.ay
		,~DYNcar.az 	     	-> VDynMotion.az
		,~DYNcar.ayaw 	 		-> VDynMotion.ayaw
		,~DYNcar.apitch   		-> VDynMotion.apitch
		,~DYNcar.aroll    		-> VDynMotion.aroll
			
	};
