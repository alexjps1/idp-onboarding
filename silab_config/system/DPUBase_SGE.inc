		Pool Base_SGE
		{
			Executeable = true;
			###############################################
			### Grundkonfiguration Clock
			include System/DPUClock.inc			#Überwachung der Rechenzeit, meldet sich bei Zeitverzug von einem Rechner

			###############################################
			### Grundkonfiguration
			###   Mockup mit BMW-Fahrdynamik
			#include System/DPUVeda_ohneCarSim.inc			# Bindet die Fahrdynamik in die Simulation ein
			include System/DPUVeda.inc			# CarSim-Fahrdynamik
			include System/DPUMockup.inc		# Verknüpfung zum MockUp
			#include System/DPUPPM.inc			# Messung physiologischer Größen, ungenutzt bei uns

			###############################################
			### Grundkonfiguration Motion
			#include System/DPUMotion.inc		# Verknüpfung zur Bewegungssimulation hier nicht vorhanden

			###############################################
			### Grundkonfiguration Sound
			include System/DPUSNDX.inc			# Soudnsimulation, bislang nicht verfügbar
			# include System/DPUTTS.inc			# Sprachsynthese, bislang bei uns nicht verwendet?

			###############################################
			### Grundkonfiguration SCNX TRFX incl. VIS
			include System/DPUSCNX_SGE.inc		# Szenerieberechnung
			include System/DPUEnvironment.inc	# Wetter, Tageszeit und Steuerung der Scheinwerfer
			include System/DPUTRFX_SGE.inc		# Verkehrsberechnung

			###############################################
			### Grundkonfiguration MOV incl. VIS
			include System/DPUMOV_SGE.inc		# Fußgängersimulation

			###############################################
			### Grundkonfiguration Projektionen
			include System/DPUSGE.inc			# Erstellung der Visualisierung
			include System/SYSSGEParams.inc		# Kameraeinstellungen für die Sichten
			

			###############################################
			### Verbindung der Fahrdynamik mit dem Rest
			include System/CONVeda.inc			# Verknüpfung Fahrdynamik mit MockUp
			
			###############################################
			### Birdseye auf Operator
			include system/DPUBirdseye.inc		# Birdseyeview
			
			###############################################
			### Instrumentencluster
			include system/Instrumentcluster.inc	#Instrumentcluster
			
			###############################################
			### Simulatorspezifische Anpassungen
			includeif system/SYSOptions.inc
		};
		
	#	Pool FS_SK_Vernetzung : Base_SGE
	#	{
	#		Executeable = true;
	#		include Pulk_FS_SK/DPUBase_SGE.inc;
	#	};
		
		Pool Full : Base_SGE
		{
			Executeable = true;
			DPUMessage ~msg {
				Computer = { OPERATOR };
				Index = 10;
				
				ErrorFlag = false;
				Text = "DPU-Pool 'Full' ist veraltet. Bitte verwenden Sie stattdessen 'Base_SGE'.";
				Text~en = "DPU-Pool 'Full' is deprecated. Please use 'Base_SGE' instead.";
			};
		};

		###################################################
		### Simulatorspezifische zusätzliche Pools
		includeif system/SYSPools.inc
		
