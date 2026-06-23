#		MOCKUP.Mockup.Gear = 0;
		DPUMixAmplifier ~AutoHandbrake #Was machst du?
		{
			Computer = {MOCKUP};
			Index = 19;
			MinOut = 0;
			MaxOut = 1;
			Multiplicator2 = -1;
			Offset2 = 3.6;
			Gain = 20;
			Multiplicator1 = -10;
		};
		Connections = 
		{
			Mockup.AcceleratorPedal <-> ~AutoHandbrake.In1
#			Display.v <-> ~AutoHandbrake.In2,
#			~AutoHandbrake.Out <-> Mockup.HandBrake
		};
		
		DPULfEAutoHold ~AutoHold			#Fahrzeug bleibt stehen und rollt nicht von sich aus los, wenn Geschwindigkeit = 0 und kein Gaspedal betätigt wird
		{
			Computer = {VDYN};
			Index = 2;
			
		};
		
		Connections =
		{
			VDyn.v_kmh 					<-> ~AutoHold.Speed,
			~AutoHold.AutoHold			<-> Mockup.BrakePedal,
			Mockup.AcceleratorPedal 	<-> ~AutoHold.Accelerator
			
		};
		


        # Die DPUCANBUS stellt die Verbindung zu einem CAN-Kanal her und teilt diesen
        #  dann mit allen CAN-DPUs, welche diesen Kanal benutzen möchten
        DPUCANBUS ~CANBUS1		#Für Wago und FFP
        {
              Computer = {CAN};
              Index = 1;

              # CANMode = Kartennummer:
              # CAN_SIMULATOR,             // 00
              # CAN_PEAK_PCI_CHANNEL1,     // 01
              # CAN_PEAK_PCI_CHANNEL2,     // 02
              # CAN_PEAK_USB_CHANNEL1,     // 03
              # CAN_ETAS_CardXL1,          // 04
              # CAN_ETAS_CardXL2,          // 05
              # CAN_VECTOR_BoardXL1,        // 06
              # CAN_VECTOR_BoardXL2,        // 07
              # CAN_VECTOR_CardXL1,        // 08
              # CAN_VECTOR_CardXL2,        // 09
              # CAN_VECTOR_CardY,          // 10 
              # CAN_VECTOR_CardX1,         // 11 
              # CAN_VECTOR_CardX2,         // 12 
              # CAN_VECTOR_Card2,          // 13 
              # CAN_VECTOR_CANpari,        // 14 
              # CAN_VECTOR_CANAc2_1,        // 15 
              # CAN_VECTOR_CANAc2_2,        // 16 
              # CAN_VECTOR_CANAc2PCI_1,    // 17 
              # CAN_VECTOR_CANAc2PCI_2,    // 18 
              # CAN_VECTOR_CaseXL1,        // 19 
              # CAN_VECTOR_CaseXL2,        // 20
              # CAN_PEAK_PCIE_CHANNEL1		//33
              # CAN_PEAK_PCIE_CHANNEL2		//34
              # CAN_PEAK_PCIE_CHANNEL3		//35
              # CAN_PEAK_PCIE_CHANNEL4		//36
              
              CANMode = 33; # Für 4-Kanal PCIe Karte von Peak; Fuer PEAK PCI Kanal 1 CANMode =1, wenn es nicht funktioniert dann CANMode = 2 benutzen; 
        };
        
        
        
        DPUWAGOIO750 ~WAGO
       {           
              Computer ={CAN};
              Index = 2;
             
              ModuleID = 2; # ModulID des Kopplers
              CANMode = 33;  # gleichen CANMode wie DPUCANBus nutzen
              NodeGuardTime = 0; # Bei Fehler 8110 (Empfangspufferüberlauf) wird das Gerät NICHT gestoppt
              
              Config = 
              {     
                   337, # Buskoppler 750-337
                   612, # eventuell Einspeissung 750-612
                   457, # 4-Kanal Eingangsklemme 750-457
                   600  # Busendklemme 750-600
             };
       };
        ####################################
        ### DPUFFP Für das aktive Gaspedal
        ###  in diesem Beispiel auf dem gleichen CAN-Kanal
        ###  wie die WAGO-Anlage
        DPUFFP ~FFP
       {
             Computer ={CAN};
             Index = 2;
             CANMode = 33; # gleichen CANMode wie DPUCANBus nutzen
        };
        
       Connections = 
		{
			~FFP.AcceleratorPedal <-> Mockup.AcceleratorPedal,
			~WAGO.AnalogIn1 <-> ~Brake.In
		};
		

		DPULookUpTable ~Brake
		{
			Computer = {MOCKUP};
			Index = 1;
			NSamplingPoints = 7;
	
			SamplingPoint1 = 0.00;  Sample1 = 0.00;
			SamplingPoint2 = 0.20;	Sample2 = 0.00;
			SamplingPoint3 = 0.30;  Sample3 = 0.90;
			SamplingPoint4 = 0.60;  Sample4 = 2.50;
			SamplingPoint5 = 1.50;  Sample5 = 3.50;
			SamplingPoint6 = 2.50;  Sample6 = 3.70;
			SamplingPoint7 = 3.00;  Sample7 = 4.00;
		};
		
		
		DPUCANBUS ~CANBUS2			#Für Lenkrad
        {
              Computer = {CAN};
              Index = 1;

              # CANMode = Kartennummer:
              # CAN_SIMULATOR,             // 00
              # CAN_PEAK_PCI_CHANNEL1,     // 01
              # CAN_PEAK_PCI_CHANNEL2,     // 02
              # CAN_PEAK_USB_CHANNEL1,     // 03
              # CAN_ETAS_CardXL1,          // 04
              # CAN_ETAS_CardXL2,          // 05
              # CAN_VECTOR_BoardXL1,        // 06
              # CAN_VECTOR_BoardXL2,        // 07
              # CAN_VECTOR_CardXL1,        // 08
              # CAN_VECTOR_CardXL2,        // 09
              # CAN_VECTOR_CardY,          // 10 
              # CAN_VECTOR_CardX1,         // 11 
              # CAN_VECTOR_CardX2,         // 12 
              # CAN_VECTOR_Card2,          // 13 
              # CAN_VECTOR_CANpari,        // 14 
              # CAN_VECTOR_CANAc2_1,        // 15 
              # CAN_VECTOR_CANAc2_2,        // 16 
              # CAN_VECTOR_CANAc2PCI_1,    // 17 
              # CAN_VECTOR_CANAc2PCI_2,    // 18 
              # CAN_VECTOR_CaseXL1,        // 19 
              # CAN_VECTOR_CaseXL2,        // 20
              # CAN_PEAK_PCIE_CHANNEL1		//33
              # CAN_PEAK_PCIE_CHANNEL2		//34
              # CAN_PEAK_PCIE_CHANNEL3		//35
              # CAN_PEAK_PCIE_CHANNEL4		//36
              
              CANMode = 34; # Fuer PEAK PCIe Kanal 2
              Baud = 0; # Baud = 0 entspricht 1000 kBaud
        };
        
        DPUCANSensoWheel ~Steeringwheel
       {
	        Computer = {CAN};
	        Index = 5;
		     CANMode = 34; #gleichen CANMode wie DPUCANBus nutzen
		     #Referencing = 0;
		     
			 # Für Referenzfahrt gegen den Anschlag:
			 Referencing = 2;
			 Ref2Torque = -2000;
			 Ref2Damping = 100;
			 Ref2Steps = 50;
			 Ref2Pos = 825;
			 
			 
		     Gain = 1.7;
		     
		     Mode = 2;				# Mode = 2: Lenksimulation von Sensodrive
		     SendOptMode = 1;		# Effektparameter übermitteln
		     EnableFriction2 = true;	#Protokollversion 2 für reibungsparameter
		     OptDampingKT1 = 1000;		#Effektparameter für Geschwindigkeitszeitkonstante
		     WheelPositionOffset = -0.044310;
		     WheelPositionMax = 800;
		     
		     #Parameter vom 01.03.13 
		     DampingGain = 0.4;
		     FrictionGain = 0.3;
		     StiffnessGain = 0.4;
		     OptFri2Factor = 100;
		     OptFri2Damping = 200;
		     OptFriGain = 1000;
		     
		     # Dämpfung
		     vDLUT = (# v km/h    ,    mNm 
		                 0.0 ,      0.0,
		                 2.0 ,    30.0,
		               20.0 ,    30.0,
		               40.0 ,    50.0,
		               60.0 ,    60.0,
		               80.0 ,    80.0,
		               100.0 ,    100.0,
		               120.0 ,    140.0,
		               140.0 ,    140.0
		                );
		     # Reibung (Friction)
		     vFLUT = (# v km/h    ,    mNm 
		                  0.0    ,    1800.0,
		                 10.0    ,    1300.0,
		                 20.0    ,    700.0,
		                 30.0    ,    600.0,
		                 40.0    ,    50.0,
		                 50.0    ,    50.0
		                );
		     # Federkraft (Stiffness)
		     vSLUT = (# v km/h    ,    mNm 
		                 0.0 ,      00,
		                 1.0 ,    3.000,    
		               10.0 ,    4.000,
		               20.0 ,    7.000,
		               65.0 ,   16.000,
		               80.0 ,   16.050 
		                );
       };
		
        Connections =
        {
	        VDyn.v_kmh <-> ~Steeringwheel.v,
	       ~Steeringwheel.WheelPositionRad <-> Mockup.SteeringWheel,
	       ~Steeringwheel.WheelPositionP <-> Mockup.SteeringWheelv
        };
        
        
		DPUCounter ~Zaehler
		{	
			Computer = {MOCKUP};
			Index = 1;
			Start = 1;
			Delta = 1;
		};
		
	
		Connections = 
		{
				
			~Brake.Out <-> ~AutoHold.Brakepedal
		};
		
#		DPULfEMockUp ~LfEMockUp
#		{
#			Computer = {MOCKUP};
#			Index = 20;	
#		};
		
#		Connections = 
#		{		
#			VDyn.v_kmh <-> ~LfEMockUp.EgoV,
#			VDyn.RPM   <-> ~LfEMockUp.EgoRPM
#		};
		
		DPUAmplifier ~Gear
		{
			Computer = {VDYN};
			In = 1;
			Index = 0;
		};
		Connections = 
		{
			~Gear.Out <-> Mockup.Gear
		};
		
		DPULfEKCAN ~KCAN  			#Blinker, Lenkstockhebel
		{
			Computer = {MOCKUP};
			Index = 5;
		};
		
		Connections = 
		{
			~KCAN.IndicatorRight	<-> Mockup.IndicatorRight,
			~KCAN.IndicatorLeft		<-> Mockup.IndicatorLeft
		};
		
		DPULfEZBECAN ~ZBECAN			#iDrive, HandsOnDetection und Lenkradknöpfe
		{
			Computer = {MOCKUP};
			Index = 6;
			
		};
		
		Connections =
		{
			~ZBECAN.wheelHORN <-> Mockup.Horn
		};
		
