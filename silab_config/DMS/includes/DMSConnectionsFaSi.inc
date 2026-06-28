Connections = 
{
			#DMSInputs
			~Automation_Framework_LfE.active_lat_and_long <-> DMS.automation_active,
			~ZBECAN.wheelQualifier_HOD <-> DMS.lfe_wheel_hands_on_id, 
			DPUEyeTracker.WorldIntersecID <-> DMS.world_intersec_id,
			
			#DMSOutputs
			DMS.automation_interrupt <-> ~Automation_Framework_LfE.dms,
			DMS.led_mode -> ~ZBECAN.wheelOPMode,
			DMS.led_color -> ~ZBECAN.wheelLEDColor,
			
			#Instrumentcluster
			#Sollgeschwindigkeit
			~Automation_Framework_LfE.vset_hmi_kmph -> ~DMSInstrumentcluster.SollGeschw.In, 
			~Automation_Framework_LfE.active_long -> ~DMSInstrumentcluster.SollGeschw.Show,
			
			#Automationsanzeige
			#~Automation_Framework_LfE.active_lat_and_long -> ~DMSInstrumentcluster.Automationsanzeige.In,			Von mir auskommentiert (max)
			
			#Anzeige der Geschwindigkeitsbegrenzungen
			~HedgehogMurderer.Out1 -> ~DMSInstrumentclusterGeschwbegrTable.In,
			~HedgehogMurderer.Out1 -> ~DMSInstrumentclusterGeschwBegrAnzeigen.In,
			
			#FAS-Aktivierungsanzeigen
			#~Automation_Framework_LfE.active_long -> ~DMSInstrumentcluster.LongitudinalAssistenz.In,
			#~Automation_Framework_LfE.active_lat -> ~DMSInstrumentcluster.LateralAssistenz.In,
			
			#DMSAktivierungsanzeige
			#~Automation_Framework_LfE.active_lat -> ~DMSLatAssistenzStatusInverter.In1,
			#DMS.eyes_on_road_state -> ~DMSInstrumentcluster.DMSActive.In,
			
			#Abstandsanzeige
			~Automation_Framework_LfE.active_long -> ~DMSLongAssistenzStatusInverter.In1,
			~Automation_Framework_LfE.gap_set_hmi_s -> ~DMSInstrumentclusterAbstandsanzeigeTable.In,

			#Blinker Links
			~Automation_Framework_LfE.active_lat -> ~DMSBlinkerLinksHedgehogUndAutomation.In1,
			~HedgehogMurderer.Out4 -> ~DMSBlinkerLinksHedgehogUndAutomation.In2,
			Mockup.IndicatorLeft <-> ~DMSBlinkerLinksHebelOderHedgehog.In1,
			
			#Blinker Rechts
			~Automation_Framework_LfE.active_lat -> ~DMSBlinkerRechtsHedgehogUndAutomation.In1,  #Hedgehog noch einbinden
			~HedgehogMurderer.Out3 -> ~DMSBlinkerRechtsHedgehogUndAutomation.In2,
			Mockup.IndicatorRight <-> ~DMSBlinkerRechtsHebelOderHedgehog.In1,
			
			#Spurwechselbenachrichtigung
			#~Automation_Framework_LfE.lc_indicator_right -> ~DMSSpurwechselLinksOderRechts.In1,
			#~Automation_Framework_LfE.lc_indicator_left -> ~DMSSpurwechselLinksOderRechts.In2,
			
			
				#Limits 			(max)
				
					~Automation_Framework_LfE.active_lat_and_long -> ~LimitInverter.In1,
					~HedgehogLimit.Out1 -> ~LimitInverter.In2,
				
				#rote Ampeln Limits
				
					~Automation_Framework_LfE.standstill -> ~RoteAmpelInverter.In1,
					~HedgehogLimit.Out2 ->  ~RoteAmpelInverter.In2,
				
				#rote Ampeln Limit überdecken
				
					~AutomationAktiviertInverter.Out_Not -> ~RoteAmpelUeberdeckenInverter.In1,
					~HedgehogLimit.Out3 -> ~RoteAmpelUeberdeckenInverter.In2,
					
			
			
				#Verfügbarkeit
				
					~Automation_Framework_LfE_HH_1.Out1 -> ~VerfuegbarkeitInverter.In1,				# macht aus available = 3 eine 1 (bool)
					
					~Automation_Framework_LfE.active_lat_and_long -> ~AutomationAktiviertInverter.In1,
					
					~VerfuegbarkeitInverter.Out -> ~AutomationNichtAktiviertInverter.In1, 				#Inverter benutzen sonst ist availablr = 3 der eingan. 1 wird benötigt
					~DMSLongAssistenzStatusInverter.Out_Not -> ~AutomationNichtAktiviertInverter.In2
				 
				
				
				
};
