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
				Frequency = 120;
				Alias = {ALL,OPERATOR,SCN,KEY,DATA,SCN,ASS,TRF,MOV,VDYN,KAHUD,VDYN2,PPM};						### 10.08.2018: kein DATA
				Operator = true;
				

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
				Frequency = 120;
				Alias = {ALL,OPERATOR,SCN,KEY,DATA,SCN,ASS,TRF,MOV,KAHUD,PPM,VDYN2,VDYN};						### 10.08.2018: kein DATA
				Operator = true;
				
				Thread AutomationStadt
				{
					Frequency = 240;
					Alias = {AS};
				};
				
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
		
		
Pool FS_SK_Vernetzung ## Work in Progress
{
	Executeable = true;
	
	##################################################
	#Computer des Fahrsimulators
	#Automatisiertes Fahrzeug
	#Egofahrzeug
	Computer FS-OPERATOR
			{
				IP = "10.152.238.1";
				Frequency = 120;
				Alias = {ALL,OPERATOR,SCN,KEY,DATA,SCN,ASS,TRF,MOV,KAHUD,PPM,VDYN2,VDYN};						### 10.08.2018: kein DATA
				Operator = true;
				
				Thread AutomationStadt
				{
					Frequency = 240;
					Alias = {AS};
				};
				
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
	
	
	#Computer der Sitzkiste
	#Pulkfahrzeug
	Computer SK-OPERATOR
		{
		
			IP = "10.152.238.40";
			Frequency = 120;
			Alias = {ALL,PUSCN,PUBEV,PPM,PUMOV,PUTRF,PUOPERATOR,PUSND,PUSNDX,PUCAN, PUDSPCAN, PUMOCKUP,OBS,ODB,PUWHEEL,PUVDYN,LA, TC};  
			# PUTTS,PUTTSP,PUOP,PUSCNVis,PUSCNLaunch,PUTRFVISFront,PUMOPVis,PUSIGWorld,PUSIGView,PUSIGLight,PUSIGWeather
			Operator = true;


			Thread OP5		
			{
				Frequency = 30;	
				Alias = {JOYDRIVE}; 
			};	
		};
		
		
		Computer SK-VISRR
		{
			IP = "10.152.238.41";
			Frequency = 120;
			Alias = {ALL, PUSCN, PUVIS, PUMOTION}; 
			

		};
		
		Computer SK-VISFR
		{
			IP = "10.152.238.42";
			Frequency = 120;
			Alias = {ALL, PUSCN, PUVIS}; 
		};
		

		Computer SK-VISFC
		{
			IP = "10.152.238.43";
			
			Frequency = 120;
			Alias = {ALL, PUSCN, PUVIS, MMI, DSP, VISF01, PROJM, HUD_2}; #PUVISM
			

		};
		
		
		Computer SK-VISFL
		{
			IP = "10.152.238.44";
			Frequency = 120;
			Alias = {ALL, PUSCN, PUVIS};
		};
		
		Computer SK-VISRL
		{
			IP = "10.152.238.45";
			Frequency = 120;
			Alias = {ALL, PUSCN, PUVIS}; 
		};
};