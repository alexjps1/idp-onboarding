#		Pool Einzelplatz
#		{
#			Executeable = true;
#
#			Computer LOCALHOST
#			{
#				IP = "127.0.0.1";
#				Frequency = 60;
#				Alias = {ALL,ASS,TRF,MOV,VDYN,OBS,MOTION,SCN,ODB,DATA,BEV,OPERATOR,VIS,DSP,RECORD,PPM,EINZELPLATZ};		#Ohne MockUp
#				Operator = true;
#			};
#		};

#########################################
#########################################
# Änderung am 10.08.2018:
# Wegen Problemen mit dem RAID und den Festplatten am FS-SCENERY, wird ab sofort auf dem Operator unter E:\ gespeichert
#########################################
#########################################




	
		Pool LFE_Front
		{
			Executeable = true; 			#In der Auswahlliste für DPU-Pools erscheinen dabei nur solche, bei denen in der Konfigurationsdatei „Executeable = true;“ steht. Damit ist es möglich, raffinierte Vererbungshierarchien aufzubauen, in denen auch Pools vorkommen, die nicht direkt ausgeführt werden können. Von solchen Pools muss also ein ausführbarer abgeleitet werden. Sie heißen daher „abstrakte Pools“ 
			
			
			Computer FS-OPERATOR
			{
				IP = "10.152.238.1";
				Frequency = 60;
				Alias = {ALL,OPERATOR,SCN,KEY,DATA};						### 10.08.2018: kein DATA
				Operator = true;
				

			};	
			
			Computer FS-SCENERY
			{
				IP = "10.152.238.2";
				Frequency = 120;
				Alias = {ALL,SCN,ASS,TRF,MOV,VDYN,KAHUD,VDYN2,PPM};			### 10.08.2018: DATA

			};
			
			Computer FS-VEHICLE
			{
				IP = "10.152.238.3";
				Frequency = 60;
				Alias = {ALL,SCN,MOCKUP,MOTION,SND,SNDX};
				
				Thread CAN		#Wago, langsamere Frequenz (50Hz)!
				{
					Frequency = 300;
					Alias = {CAN};
				};
				
				/*Thread STEERINGWHEEL
				{
					Frequency = 300;
					Alias = {WHEEL};
				};
				*/
				
			};
			
			Computer FS-OBSERVER
			{
				IP = "10.152.238.4";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,OBS,BEV};
			};

			
			Computer FS-VISFL
			{
				IP = "10.152.238.11";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF03};
			};
			Computer FS-VISFC
			{
				IP = "10.152.238.12";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF01};
			};
			Computer FS-VISFR
			{
				IP = "10.152.238.13";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF02};
			};
			
		};
		
		Pool LfE
		{
			Executeable = true; 			#In der Auswahlliste für DPU-Pools erscheinen dabei nur solche, bei denen in der Konfigurationsdatei „Executeable = true;“ steht. Damit ist es möglich, raffinierte Vererbungshierarchien aufzubauen, in denen auch Pools vorkommen, die nicht direkt ausgeführt werden können. Von solchen Pools muss also ein ausführbarer abgeleitet werden. Sie heißen daher „abstrakte Pools“ 
			
			
			Computer FS-OPERATOR
			{
				IP = "10.152.238.1";
				Frequency = 60;
				Alias = {ALL,OPERATOR,SCN,KEY,DATA};						### 10.08.2018: kein DATA
				Operator = true;
				
				Thread AutomationStadt
				{
					Frequency = 240;
					Alias = {AS};
				};
				
			};	
			
			Computer FS-SCENERY
			{
				IP = "10.152.238.2";
				Frequency = 120;
				#PeriodMS = 10;
				Alias = {ALL,SCN,ASS,TRF,MOV,KAHUD,PPM,VDYN2,VDYN};			### 10.08.2018: DATA
				
				#Thread VDYN
				#{
				#	Frequency = 300;
				#	Alias = {};
				#};
			};
			
			
			Computer FS-VEHICLE
			{
				IP = "10.152.238.3";
				Frequency = 60;
				Alias = {ALL,SCN,MOCKUP,MOTION,SND,SNDX};
				
				Thread CAN		#Wago, langsamere Frequenz (50Hz)!
				{
					Frequency = 300;
					Alias = {CAN};
				};
				
				/*Thread STEERINGWHEEL
				{
					Frequency = 300;
					Alias = {WHEEL};
				};
				*/
			};
			
			Computer FS-OBSERVER
			{
				IP = "10.152.238.4";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,OBS,BEV};
			};

			
			Computer FS-VISFL
			{
				IP = "10.152.238.11";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF03};
			};
			Computer FS-VISFC
			{
				IP = "10.152.238.12";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF01};
			};
			Computer FS-VISFR
			{
				IP = "10.152.238.13";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF02};
			};
			Computer FS-VISRL
			{
				IP = "10.152.238.14";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF06};
			};
			Computer FS-VISRC
			{
				IP = "10.152.238.15";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF04};
			};
			Computer FS-VISRR
			{
				IP = "10.152.238.16";
				Frequency = 60;
				Alias = {ALL,SCN,VIS,VISF05};
			};
			
		};	
		



