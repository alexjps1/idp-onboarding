			DPUVarioPort ~VarioPort
			{
				Computer = {VP};
				Index = 1;
				Port = 1;
				Baudrate = 115200;
				
				DefData = "2284-10106.def"; # in lib/varioport
				useDeffileChannels = 1; # EKG,EMG1,EMG2,EDA,ATEM,TEMP,EDA1,EDA2,EDA3,HR,X,Y,Z,Marker
/*
				# Alternativ: manuelle Kanalauswahl
				AktiviereKanal01 = 1; #EKG
				AktiviereKanal02 = 1; #EMG1
				AktiviereKanal03 = 1; #EMG2
				AktiviereKanal04 = 1; #EDA
				AktiviereKanal05 = 1; #ATEM
				AktiviereKanal06 = 1; #TEMP
				AktiviereKanal07 = 1; #EDA1
				AktiviereKanal08 = 1; #EDA2
				AktiviereKanal09 = 1; #EDA3
				AktiviereKanal10 = 0; #AUX4
				AktiviereKanal11 = 0; #AUX5
				AktiviereKanal12 = 0; #AUX6
				AktiviereKanal13 = 0; #ungenutzter Kanal
				AktiviereKanal14 = 1; #X
				AktiviereKanal15 = 1; #Y
				AktiviereKanal16 = 1; #Z
				AktiviereKanal17 = 1; #HR
				# viele ungenutzte Kanäle
				AktiviereKanal65 = 1; #Marker
				AktiviereKanal66 = 1; #BatV
				AktiviereKanal67 = 1; #BatI
				# Rest: ungenutzte Kanäle
*/
								
				QuickStart = 0; # =1 vermeidet "Lag" von ca. 500ms beim Start in SIM1
				QuickStop = 0;  # =1 vermeidet "Lag" von ca. 10s beim Beenden in SIM1
			};

includeif system/SYSVarioPort.inc
