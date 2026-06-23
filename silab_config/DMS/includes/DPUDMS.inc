		#include system\DPUEyetrackingLFE.inc #@Jasmin eventuell hier auskommentieren
		
		DPUDMS DMS
		{
			Computer = {OPERATOR};
			Index = 300;
			cfg_autom_lock_after_interrupt = false;
			cfg_signal_smoothing_window = 10;
			cfg_warn_casc_v_act = 0; # Klassifizierung als abgelenkt und Warnsignalausgabe nur bei Geschwindigkeiten über 10 km/h nach ADAS 27-02 Proposal
			cfg_distr_sgl_enable = true;	#war true, von mir geändert (max)
			cfg_distr_sgl_duration = 5000; # Mindestdauer [ms] einer langen visuellen Ablenkung (Kontinuierlicher, 5000 ms oder länger anhaltender Blick weg von der Frontszenerie)
			cfg_distr_sgl_rst_duration = 200; # Mindestdauer [ms] eines Blicks zur Verkehrsszenerie zur Wiederherstellung der visuellen Aufmerksamkeit (200 ms nach ADAS)
			cfg_distr_pat_enable = true;	#war true, von mir geändert (max)
			cfg_distr_pat_duration = 10000;
			cfg_distr_pat_window = 30000;
			cfg_distr_pat_rst_duration = 1000;
			cfg_eor1_enable = true;	#war true, von mir geändert (max)
			cfg_eor1_duration = 3000;
			cfg_eor2_enable = true;	#war true, von mir geändert (max)
			cfg_eor2_duration = 3000;
			cfg_hor_enable = true;
			cfg_hor_duration = 5000;
			cfg_dcr_enable = true;		#war true, von mir geändert (max)
			cfg_dcr_duration = 3000;
			cfg_eject_enable = true; 	#war true, von mir geändert (max)
			cfg_aoi1 = 2; #Windshield left
			cfg_aoi2 = 3; #Windshield Right 
			cfg_aoi3 = 1; #left Mirror
			cfg_aoi4 = 6; #right Mirror
			cfg_aoi5 = 5; #rear Mirror
			#cfg_aoi6;#alle anderen als default -1 übergeben
			#cfg_aoi7;
			#cfg_aoi8;
			#cfg_aoi9;
			#cfg_aoi10;
		};
		
		Connections = 
			{
				#DMSInputs
				VDyn.v_kmh -> DMS.v_kmh, 
				
				#DMSOutputs
				DMS.audio_signal_index -> ~DMSAudioWarnings.Play,
				DMS.audio_signal_loop -> ~DMSAudioWarnings.Loop, #wird nicht gehen weil das im normalen DMS auf SNDX läuft		
				
				#DMSTextfenster
				DMS.ic_bg_color -> ~DMSInstrumentcluster.Hintergrund.In,
				DMS.ic_text_box_index -> ~DMSInstrumentcluster.DMSWarnings.In,
				DMS.ic_text_box_show -> ~DMSInstrumentcluster.DMSWarnings.Show,
				
				#DMSTextfensterLimits			(max)
				
				#DMS.ic_text_box_index -> ~DMSInstrumentcluster.LimitWarnings.In,
				#DMS.ic_text_box_show -> ~DMSInstrumentcluster.LimitWarnings.Show,
				
				
				#DMSPiktogramme
				DMS.ic_pictogram_index -> ~DMSInstrumentcluster.DMSWarnIcon.In,
				DMS.ic_pictogram_show -> ~DMSInstrumentcluster.DMSWarnIcon.Show
			};