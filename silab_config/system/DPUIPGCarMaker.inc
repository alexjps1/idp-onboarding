			# SILAB-seitige Schnittstelle zu IPG CarMaker. Zur Verwendung ist zusätzlich ein angepasster CarMaker notwendig.
			DPUIPGAPO ~IPGAPO
			{
				Computer = {OPERATOR};
				Index = 1;
				TreeviewGroup = "Fahrdynamik";
				TreeviewGroup~en = "Vehicle Dynamics";
				Config = "Flaeche";
				AppClass = "CarMaker";
				AppHost = "localhost";
				AppUser = "*";
			};
			DPUSocket ~IPG
			{
				Index = 20;
				Computer = {VDYN};          
				TreeviewGroup = "Fahrdynamik";
				TreeviewGroup~en = "Vehicle Dynamics";
				Socket_IP = "127.0.0.1";
				Socket_IsTCPIP = 0;
				Socket_PortSend = 26100;
				Socket_PortReceive = 26110;
				Socket_IsServer = true;
				SendDefinition = (
					(AcceleratorPedal, double),
					(BrakePedal, double),
					(ClutchPedal, double),
					(SteeringWheel, double,0.0,1.0),
					(Gear,double),
					# Wheel 0
					(CP0Z,double),
					(CP0mu,double,1.0),
					(CP0nvecX,double),
					(CP0nvecY,double),
					(CP0nvecZ,double,1.0),
					# Wheel 1
					(CP1Z,double),
					(CP1mu,double,1.0),
					(CP1nvecX,double),
					(CP1nvecY,double),
					(CP1nvecZ,double,1.0),
					# Wheel 2
					(CP2Z,double),
					(CP2mu,double,1.0),
					(CP2nvecX,double),
					(CP2nvecY,double),
					(CP2nvecZ,double,1.0),
					# Wheel 3
					(CP3Z,double),
					(CP3mu,double,1.0),
					(CP3nvecX,double),
					(CP3nvecY,double),
					(CP3nvecZ,double,1.0),
					# Optionale Daten Verkehr
					# Vorderfahrzeug
					(TRFIDAheadNext,double),
					(TRFLengthAheadNext,double),
					(TRFWidthAheadNext,double),
					(TRFXAheadNext,double),
					(TRFYAheadNext,double),
					(TRFZAheadNext,double),
					(TRFyawAheadNext,double),
					(TRFvAheadNext,double),
					(TRFStLongAheadNext,double),
					(TRFStLatAheadNext,double),
					(TRFSpLongAheadNext,double),
					(TRFSpLatAheadNext,double),
				
					# Fahrzeug links
					(TRFIDAheadNextLeft,double),
					(TRFLengthAheadNextLeft,double),
					(TRFWidthAheadNextLeft,double),
					(TRFXAheadNextLeft,double),
					(TRFYAheadNextLeft,double),
					(TRFZAheadNextLeft,double),
					(TRFyawAheadNextLeft,double),
					(TRFvAheadNextLeft,double),
					(TRFStLongAheadNextLeft,double),
					(TRFStLatAheadNextLeft,double),
					(TRFSpLongAheadNextLeft,double),
					(TRFSpLatAheadNextLeft,double),
				
					# Fahrzeug rechts
					(TRFIDAheadNextRight,double),
					(TRFLengthAheadNextRight,double),
					(TRFWidthAheadNextRight,double),
					(TRFXAheadNextRight,double),
					(TRFYAheadNextRight,double),
					(TRFZAheadNextRight,double),
					(TRFyawAheadNextRight,double),
					(TRFvAheadNextRight,double),
					(TRFStLongAheadNextRight,double),
					(TRFStLatAheadNextRight,double),
					(TRFSpLongAheadNextRight,double),
					(TRFSpLatAheadNextRight,double),
				
					# Optionale Daten Datenbasis
					(SCNLaneWidth,double),
					(SCNLeftTraversable,double),
					(SCNRightTraverseable,double)
				);
				ReceiveDefinition = (
					(CycleNo,ulong),
					(X, double),
					(ax, double),
					(Y, double),
					(ay, double),
					(Z, double),
					(az, double),
					(yaw, double),
					(pitch, double),
					(roll, double),
					(RPM, double),
					(BX,double),
					(BY,double),
					(BZ,double),
					(v, double),
					(Debug01, double),
					(CP0X,double),
					(CP0Y,double),
					(CP1X,double),
					(CP1Y,double),
					(CP2X,double),
					(CP2Y,double),
					(CP3X,double),
					(CP3Y,double)
				);
			};

			DPUVDSSCNX ~IPGSCNX
			{
				Index = 41;
				Computer = {VDYN};          
				TreeviewGroup = "Fahrdynamik";
				TreeviewGroup~en = "Vehicle Dynamics";
			};
			DPUAmplifier ~IPGV
			{
				Index = 21;
				Computer = {VDYN};          
				TreeviewGroup = "Fahrdynamik";
				TreeviewGroup~en = "Vehicle Dynamics";
				Multiplicator = 3.6;
			};
			Connections = 
			{
				 VDyn.SteeringWheel 	-> ~IPG.SteeringWheel
				,VDyn.AcceleratorPedal 	-> ~IPG.AcceleratorPedal
				,VDyn.BrakePedal 		-> ~IPG.BrakePedal
				,VDyn.ClutchPedal 		-> ~IPG.ClutchPedal
				,VDyn.Gear 				-> ~IPG.Gear
				,~IPG.X 			-> VDyn.X
				,~IPG.Y 			-> VDyn.Y
				,~IPG.Z 		    -> VDyn.Z
				,~IPG.yaw   		-> VDyn.yaw
				,~IPG.pitch 	    -> VDyn.pitch
				,~IPG.roll			-> VDyn.roll
				,~IPG.v 		    -> VDyn.v
				,~IPG.v 		    -> ~IPGV.In
				,~IPGV.Out 	   		-> VDyn.v_kmh
				,~IPG.RPM			-> VDyn.RPM
				
				# Reifen FR
				,~IPG.CP0X 		-> ~IPGSCNX.Xfr
				,~IPG.CP0Y 		-> ~IPGSCNX.Yfr
				,~IPGSCNX.Zfr 	-> ~IPG.CP0Z
				,~IPGSCNX.FrNevX	-> ~IPG.CP0nvecX
				,~IPGSCNX.FrNevY	-> ~IPG.CP0nvecY
				,~IPGSCNX.FrNevZ	-> ~IPG.CP0nvecZ
				# Reifen FL
				,~IPG.CP1X 		-> ~IPGSCNX.Xfl
				,~IPG.CP1Y 		-> ~IPGSCNX.Yfl
				,~IPGSCNX.Zfl 	-> ~IPG.CP1Z
				,~IPGSCNX.FlNevX	-> ~IPG.CP1nvecX
				,~IPGSCNX.FlNevY	-> ~IPG.CP1nvecY
				,~IPGSCNX.FlNevZ	-> ~IPG.CP1nvecZ
				# Reifen RR
				,~IPG.CP2X 		-> ~IPGSCNX.Xrr
				,~IPG.CP2Y 		-> ~IPGSCNX.Yrr
				,~IPGSCNX.Zrr 	-> ~IPG.CP2Z
				,~IPGSCNX.RrNevX	-> ~IPG.CP2nvecX
				,~IPGSCNX.RrNevY	-> ~IPG.CP2nvecY
				,~IPGSCNX.RrNevZ	-> ~IPG.CP2nvecZ
				# Reifen RL
				,~IPG.CP3X 		-> ~IPGSCNX.Xrl
				,~IPG.CP3Y 		-> ~IPGSCNX.Yrl
				,~IPGSCNX.Zrl 	-> ~IPG.CP3Z
				,~IPGSCNX.RlNevX	-> ~IPG.CP3nvecX
				,~IPGSCNX.RlNevY	-> ~IPG.CP3nvecY
				,~IPGSCNX.RlNevZ	-> ~IPG.CP3nvecZ
			};
