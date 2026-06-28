# Actual DPU include is inside
# include system/SYSDYNTruck.inc
# at the end of file
	#include DYN/AutomationDYN.inc
	include DYN/TempomatDYN.inc
	#include DYN/DPUDYNTruckAufzeichnung.inc
	# System specific selection of truck model
	#include system/DPUDYNRoadTrain.inc
	#include system/DPUDYNSemiTrailer.inc
	#include system/DPUDYNCentralAxleTrailer.inc
	#include system/DPUDYNC1E.inc
	#include system/DPUDYNCsolo.inc
	#include DYN/ShowTireRuler.inc
	#include DYN/ShowSingleTireDirection.inc

VDyn.VARSet += {Retarder_Level, Load_Select, Load_Plus, Load_Minus, Load_Menu, Load_HMI_value};
VDyn.VARSet += {SteeringMoment,omega1,omega2,omega3,omega4};	
VDyn.VARSet += {Body2_X,Body2_Y,Body2_Z,Body2_roll,Body2_pitch,Body2_yaw,omega5,omega6,omega7,omega8};
VDyn.VARSet += {Body3_X,Body3_Y,Body3_Z,Body3_roll,Body3_pitch,Body3_yaw,Body3_alpha,omega9,omega10,omega11,omega12};
VDyn.VARSet += {ABS};
# Body-enabled flag
VDyn.VARSet += {Body1_active, Body2_active, Body3_active};
VDyn.VARSet += {Connector_Active, TrailerConnected, TrailerPort, TrailerReady};
# Tire coordinates 1-12
VDyn.VARSet += {Tires.NTires,
				Tires.Tire1X,Tires.Tire1Y,Tires.Tire1Z,Tires.Tire1Active,
				Tires.Tire2X,Tires.Tire2Y,Tires.Tire2Z,Tires.Tire2Active,
				Tires.Tire3X,Tires.Tire3Y,Tires.Tire3Z,Tires.Tire3Active,
				Tires.Tire4X,Tires.Tire4Y,Tires.Tire4Z,Tires.Tire4Active,
				Tires.Tire5X,Tires.Tire5Y,Tires.Tire5Z,Tires.Tire5Active,
				Tires.Tire6X,Tires.Tire6Y,Tires.Tire6Z,Tires.Tire6Active,
				Tires.Tire7X,Tires.Tire7Y,Tires.Tire7Z,Tires.Tire7Active,
				Tires.Tire8X,Tires.Tire8Y,Tires.Tire8Z,Tires.Tire8Active,
				Tires.Tire9X,Tires.Tire9Y,Tires.Tire9Z,Tires.Tire9Active,
				Tires.Tire10X,Tires.Tire10Y,Tires.Tire10Z,Tires.Tire10Active,
				Tires.Tire11X,Tires.Tire11Y,Tires.Tire11Z,Tires.Tire11Active,
				Tires.Tire12X,Tires.Tire12Y,Tires.Tire12Z,Tires.Tire12Active};
				
DPUInterface ~MirrorBB
{
	Index = 11;
	Computer = {TRF};
	
	VARSet = {
		Front
		,Rear
		,Left
		,Right
		,Bottom
		,Top
	};
};

DPUInterface ~TrailerCollisionBB
{
	Index = 11;
	Computer = {TRF};
	
	VARSet = {
		Front
		,Rear
	};
};

# Standard: Gesamter Fahrzeugbody kann mit Trailer kollidieren
Connections = 
{
	TRF.EGOBBFront -> ~TrailerCollisionBB.Front,
	TRF.EGOBBRear -> ~TrailerCollisionBB.Rear
};

Connections = {
	Mockup.Connector_Active -> ~DYNtruck.Con1_Active
	
	##### SCNX Communication to DYN
	,SCNX.ZOut 				-> ~DYNtruck.ZRoad
	,SCNX.ve				-> ~DYNtruck.v_lim
	
	##### Setup to DYN
	,VDyn.PitchRoad 		-> ~DYNtruck.PitchRoad
	,VDyn.RollRoad 			-> ~DYNtruck.RollRoad
	,VDyn.XOffset 			-> ~DYNtruck.XOffset
	,VDyn.YOffset 			-> ~DYNtruck.YOffset
	,VDyn.ZOffset 			-> ~DYNtruck.ZOffset
	,VDyn.SetupX	 		-> ~DYNtruck.SetupX
	,VDyn.SetupY	 		-> ~DYNtruck.SetupY
	,VDyn.SetupZ	 		-> ~DYNtruck.SetupZ
	,VDyn.SetupYaw			-> ~DYNtruck.SetupYaw
	,VDyn.SetupPitch		-> ~DYNtruck.SetupPitch
	,VDyn.SetupRoll			-> ~DYNtruck.SetupRoll
	,VDyn.SetupDone			-> ~DYNtruck.SetupDone
	,VDyn.SetupDone			-> ~hRoad.SetupDone
	
	
	##### HMI Outputs
	,~DYNtruck.Load_Menu	  -> VDyn.Load_Menu
	,~DYNtruck.Load_HMI_value -> VDyn.Load_HMI_value
	
	##### Driver Controls to DYN
	,VDyn.Ignition 			-> ~DYNtruck.Ignition
	,VDyn.Starter 			-> ~DYNtruck.Starter
	,VDyn.HandBrake 		-> ~DYNtruck.HandBrake
	,VDyn.Gear 				-> ~DYNtruck.GearAutomatic
	,VDyn.SteeringWheel 	-> ~DYNtruck.SteeringWheel
	,VDyn.AcceleratorPedal 	-> ~DYNtruck.AcceleratorPedal
	,VDyn.BrakePedal 		-> ~DYNtruck.BrakePedal
	,VDyn.ClutchPedal 		-> ~DYNtruck.ClutchPedal
	,VDyn.Retarder_Level	-> ~DYNtruck.Retarder_Level
	
	##### DYN Outputs
	,~DYNtruck.SteeringMoment 	-> VDyn.SteeringMoment
	,~DYNtruck.Consumption		-> VDyn.Consumption
	,~DYNtruck.RPM				-> VDyn.RPM
	,~DYNtruck.s				-> VDyn.s
	,~DYNtruck.v 		    	-> VDyn.v
	,~DYNtruck.v_kmh 	    	-> VDyn.v_kmh
	,~DYNtruck.SelGear			-> VDyn.GearAuto
	,~DYNtruck.TrailerConnected -> VDyn.TrailerConnected
	,~DYNtruck.TrailerPort 		-> VDyn.TrailerPort
	,~DYNtruck.Con1Ready		-> VDyn.TrailerReady
	,~DYNtruck.delta1			-> VDyn.delta
	
	,~DYNtruck.omega1 	 	-> VDyn.omega1
	,~DYNtruck.omega2 	 	-> VDyn.omega2
	,~DYNtruck.omega3	 	-> VDyn.omega3
	,~DYNtruck.omega4  	 	-> VDyn.omega4
	,~DYNtruck.omega5 	 	-> VDyn.omega5
	,~DYNtruck.omega6 	 	-> VDyn.omega6
	,~DYNtruck.omega7	 	-> VDyn.omega7
	,~DYNtruck.omega8  	 	-> VDyn.omega8
	,~DYNtruck.omega9 	 	-> VDyn.omega9
	,~DYNtruck.omega10 	 	-> VDyn.omega10
	,~DYNtruck.omega11	 	-> VDyn.omega11
	,~DYNtruck.omega12  	-> VDyn.omega12


	,~DYNtruck.X_body1 				-> VDyn.X
	,~DYNtruck.Y_body1 				-> VDyn.Y
	,~DYNtruck.Z_body1 		    	-> VDyn.Z
	,~DYNtruck.yaw_body1   			-> VDyn.yaw
	,~DYNtruck.pitch_body1	    	-> VDyn.pitch
	,~DYNtruck.roll_body1			-> VDyn.roll
	
	,~DYNtruck.vx_body1 			-> VDyn.vx
	,~DYNtruck.vy_body1 			-> VDyn.vy
	,~DYNtruck.vz_body1 			-> VDyn.vz
	,~DYNtruck.vyaw_body1 	    	-> VDyn.vyaw
	,~DYNtruck.vpitch_body1 		-> VDyn.vpitch
	,~DYNtruck.vroll_body1 	    	-> VDyn.vroll
	
	,~DYNtruck.ax_body1 			-> VDyn.ax
	,~DYNtruck.ay_body1 			-> VDyn.ay
	,~DYNtruck.az_body1 			-> VDyn.az
	,~DYNtruck.ayaw_body1 	    	-> VDyn.ayaw
	,~DYNtruck.apitch_body1 		-> VDyn.apitch
	,~DYNtruck.aroll_body1 	   		-> VDyn.aroll
	,~DYNtruck.BodyActive1			-> VDyn.Body1_active
	

	,~DYNtruck.X_body2 				-> VDyn.Body2_X
	,~DYNtruck.Y_body2 				-> VDyn.Body2_Y
	,~DYNtruck.Z_body2 		    	-> VDyn.Body2_Z
	,~DYNtruck.yaw_body2   			-> VDyn.Body2_yaw
	,~DYNtruck.pitch_body2	    	-> VDyn.Body2_pitch
	,~DYNtruck.roll_body2			-> VDyn.Body2_roll
	,~DYNtruck.BodyActive2			-> VDyn.Body2_active
	#,~DYNtruck.alpha_body2			-> VDyn.Body2_alpha
	
	,~DYNtruck.X_body3 				-> VDyn.Body3_X
	,~DYNtruck.Y_body3 				-> VDyn.Body3_Y
	,~DYNtruck.Z_body3 		    	-> VDyn.Body3_Z
	,~DYNtruck.yaw_body3   			-> VDyn.Body3_yaw
	,~DYNtruck.pitch_body3	    	-> VDyn.Body3_pitch
	,~DYNtruck.roll_body3			-> VDyn.Body3_roll
	,~DYNtruck.BodyActive3			-> VDyn.Body3_active
	#,~DYNtruck.alpha_body3			-> VDyn.Body3_alpha
	,~DYNtruck.ABS_active 					->  VDyn.ABS

	##### Trailer connection state -> TRFX / TRFClient
	,VDyn.TrailerConnected -> TRFX.EGOTConnected
	,VDyn.TrailerConnected -> TRFClient.EGOTConnected

	##### Motion System Outputs
	,~DYNtruck.X_body1  	     	-> VDynMotion.X
	,~DYNtruck.Y_body1  	     	-> VDynMotion.Y
	,~DYNtruck.Z_body1  	     	-> VDynMotion.Z
	,~DYNtruck.yaw_body1    		-> VDynMotion.yaw
	,~DYNtruck.pitch_body1     		-> VDynMotion.pitch
	,~DYNtruck.roll_body1      		-> VDynMotion.roll

	,~DYNtruck.v 	         		-> VDynMotion.v
	,~DYNtruck.vx_body1 	     	-> VDynMotion.vx
	,~DYNtruck.vy_body1  	     	-> VDynMotion.vy
	,~DYNtruck.vz_body1  	     	-> VDynMotion.vz
	,~DYNtruck.vyaw_body1  	 		-> VDynMotion.vyaw
	,~DYNtruck.vpitch_body1    		-> VDynMotion.vpitch
	,~DYNtruck.vroll_body1     		-> VDynMotion.vroll
	,~DYNtruck.ax_body1  	     	-> VDynMotion.ax
	,~DYNtruck.ay_body1  	     	-> VDynMotion.ay
	,~DYNtruck.az_body1  	     	-> VDynMotion.az
	,~DYNtruck.ayaw_body1  	 		-> VDynMotion.ayaw
	,~DYNtruck.apitch_body1    		-> VDynMotion.apitch
	,~DYNtruck.aroll_body1     		-> VDynMotion.aroll
	
	# Tire coordinates
	,~DYNtruck.X1					-> VDyn.Tires.Tire1X
	,~DYNtruck.Y1					-> VDyn.Tires.Tire1Y
	,~DYNtruck.Z1					-> VDyn.Tires.Tire1Z
	,~DYNtruck.WheelActive1			-> VDyn.Tires.Tire1Active #
	,~DYNtruck.X2					-> VDyn.Tires.Tire2X
	,~DYNtruck.Y2					-> VDyn.Tires.Tire2Y
	,~DYNtruck.Z2					-> VDyn.Tires.Tire2Z 
	,~DYNtruck.WheelActive2			-> VDyn.Tires.Tire2Active #
	,~DYNtruck.X3					-> VDyn.Tires.Tire3X
	,~DYNtruck.Y3					-> VDyn.Tires.Tire3Y
	,~DYNtruck.Z3					-> VDyn.Tires.Tire3Z
	,~DYNtruck.WheelActive3			-> VDyn.Tires.Tire3Active #
	,~DYNtruck.X4					-> VDyn.Tires.Tire4X
	,~DYNtruck.Y4					-> VDyn.Tires.Tire4Y
	,~DYNtruck.Z4					-> VDyn.Tires.Tire4Z
	,~DYNtruck.WheelActive4			-> VDyn.Tires.Tire4Active #
	,~DYNtruck.X5					-> VDyn.Tires.Tire5X
	,~DYNtruck.Y5					-> VDyn.Tires.Tire5Y
	,~DYNtruck.Z5					-> VDyn.Tires.Tire5Z
	,~DYNtruck.WheelActive5			-> VDyn.Tires.Tire5Active #
	,~DYNtruck.X6					-> VDyn.Tires.Tire6X
	,~DYNtruck.Y6					-> VDyn.Tires.Tire6Y
	,~DYNtruck.Z6					-> VDyn.Tires.Tire6Z
	,~DYNtruck.WheelActive6			-> VDyn.Tires.Tire6Active #
	,~DYNtruck.X7					-> VDyn.Tires.Tire7X
	,~DYNtruck.Y7					-> VDyn.Tires.Tire7Y
	,~DYNtruck.Z7					-> VDyn.Tires.Tire7Z
	,~DYNtruck.WheelActive7			-> VDyn.Tires.Tire7Active #
	,~DYNtruck.X8					-> VDyn.Tires.Tire8X
	,~DYNtruck.Y8					-> VDyn.Tires.Tire8Y
	,~DYNtruck.Z8					-> VDyn.Tires.Tire8Z
	,~DYNtruck.WheelActive8			-> VDyn.Tires.Tire8Active #
	,~DYNtruck.X9					-> VDyn.Tires.Tire9X
	,~DYNtruck.Y9					-> VDyn.Tires.Tire9Y
	,~DYNtruck.Z9					-> VDyn.Tires.Tire9Z
	,~DYNtruck.WheelActive9			-> VDyn.Tires.Tire9Active #
	,~DYNtruck.X10					-> VDyn.Tires.Tire10X
	,~DYNtruck.Y10					-> VDyn.Tires.Tire10Y
	,~DYNtruck.Z10					-> VDyn.Tires.Tire10Z
	,~DYNtruck.WheelActive10		-> VDyn.Tires.Tire10Active #
	,~DYNtruck.X11					-> VDyn.Tires.Tire11X
	,~DYNtruck.Y11					-> VDyn.Tires.Tire11Y
	,~DYNtruck.Z11					-> VDyn.Tires.Tire11Z
	,~DYNtruck.WheelActive11		-> VDyn.Tires.Tire11Active #
	,~DYNtruck.X12					-> VDyn.Tires.Tire12X
	,~DYNtruck.Y12					-> VDyn.Tires.Tire12Y
	,~DYNtruck.Z12					-> VDyn.Tires.Tire12Z
	,~DYNtruck.WheelActive12		-> VDyn.Tires.Tire12Active #
};

