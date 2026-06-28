DPUMMI ~DMSInstrumentcluster
{


	Computer = {MOCKUP};
	Index = 101;
	
	WindowX = 0 ; #-1280, wenn beide Anzeigen (Combi und CID) auf FS-Vehicle aktiv (+1280 funktioniert bei Fasi...)#@Jasmin hier kanns sein, dass 0 drin stehen muss.
	WindowY = 0;
	WindowW = 1366; 		#1280 bei Originaldisplay
	WindowH = 768;			#720 bei Originaldisplay
	W = 1366; 				#1280 bei Originaldisplay
	H = 768;				#720 bei Originaldisplay
	
	ImageDisplay Hintergrund
	{
		X = 0;
		Y = 0;			
		W = 1366;
		H = 768;
		Images = ("DMS\graphics\DMSInstrumentcluster\black.png", "DMS\graphics\DMSInstrumentcluster\Farbverlauf_gruen.png", "DMS\graphics\DMSInstrumentcluster\Farbverlauf_orange.png", "DMS\graphics\DMSInstrumentcluster\Farbverlauf_rot.png");
	};
	NumberDisplay AktuelleGeschw
	{
		X = 0;
		Y = 240;
		W = 400;
		H = 195;
		
		Alignment = "center";
		Font = "arialbd.ttf";
		FontColor = (1, 1, 1);
		Format = "%.0f";
		Show=1;
		
		TextDisplay kmh
		{
			X = 0;
			Y = 0;
			W = 400;
			H = 37.5;
			Font = "arialbd.ttf";
			FontColor = (255, 255, 255);
			Show=1;
			Alignment = "center";
			Texts = {"km/h"};
		};	
	};
	NumberDisplay SollGeschw
	{
		X = 30; 
		Y = 162.5; 
		W = 225;
		H = 50;
		Alignment = "center";
		Font = "arialbd.ttf";
		FontColor = (1, 1, 1);
		Format = "%.0f";
	};
		
	ImageDisplay GeschwBegrenzung
	{
		X = 230;
		Y = 150; 
		W = 75;
		H = 75;
		Images = ("DMS\graphics\DMSInstrumentcluster\274_30.png", "DMS\graphics\DMSInstrumentcluster\274_50.png", "DMS\graphics\DMSInstrumentcluster\274_60.png", "DMS\graphics\DMSInstrumentcluster\274_70.png", "DMS\graphics\DMSInstrumentcluster\274_80.png", "DMS\graphics\DMSInstrumentcluster\274_100.png", "DMS\graphics\DMSInstrumentcluster\274_130.png");
	};
	
	ImageDisplay BlinkerLinks
	{
		X = 398;
		Y = 580;	
		W = 80;
		H = 80;
		#Images = ("DMS\graphics\DMSInstrumentcluster\Icon_Indicator_left_off.png","DMS\graphics\DMSInstrumentcluster\Icon_Indicator_left_on.png");
		Images = ("DMS\graphics\DMSInstrumentcluster\turn_indicator_left_empty.png","DMS\graphics\DMSInstrumentcluster\turn_indicator_left_on.png");
	};
	ImageDisplay BlinkerRechts
	{
		X = 938;
		Y = 580;	
		W = 80;
		H = 80;
		#Images = ("DMS\graphics\DMSInstrumentcluster\Icon_Indicator_off.png","DMS\graphics\DMSInstrumentcluster\Icon_Indicator_on.png");
		Images = ("DMS\graphics\DMSInstrumentcluster\turn_indicator_right_empty.png","DMS\graphics\DMSInstrumentcluster\turn_indicator_right_on.png");
	};
	
#	Light Automationsanzeige #Ein einzelnes großes Piktogramm am rechten Rand des Instrumentencluster, das den Status des Automationssystems (Lateral und Longitudinal) anzeigt			von mir auskommentiert(max)
#	{
#		X = 1100;
#		Y = 250;
#		W = 150;
#		H = 150;
#		OnImage = ("DMS\graphics\DMSInstrumentcluster\Icon_automation_activated.png");
#		OffImage = ("DMS\graphics\DMSInstrumentcluster\Icon_automation.png");
#	};
	
		
	#Vier Piktogramme anstatt der einzelnen Automationsanzeige am rechten Rand des IC, die von oben nach unten den Systemstatus bzw. -werte anzeigen:
	
#	Light LongitudinalAssistenz
#	{
#		X = 1100;
#		Y = 400;
#		W = 120;
#		H = 120;
#		OnImage = ("DMS\graphics\DMSInstrumentcluster\Icon_acc.png");
#		OffImage = ("DMS\graphics\DMSInstrumentcluster\Icon_acc_darklight.png");
#	};
	
ImageDisplay AbstandsanzeigeAus
	{
		X = 1111;
		Y = 120;
		W = 130;
		H = 130;
		Images = ("DMS\graphics\DMSInstrumentcluster\gap1_darklight.png", "DMS\graphics\DMSInstrumentcluster\gap2_darklight.png", "DMS\graphics\DMSInstrumentcluster\gap3_darklight.png", "DMS\graphics\DMSInstrumentcluster\gap4_darklight.png", "DMS\graphics\DMSInstrumentcluster\gap5_darklight.png", "DMS\graphics\DMSInstrumentcluster\gap6_darklight.png", "DMS\graphics\DMSInstrumentcluster\gap7_darklight.png","DMS\graphics\DMSInstrumentcluster\gap8_darklight.png");
	};
	
ImageDisplay AbstandsanzeigeAn
{
		X = 1111;
		Y = 120;
		W = 130;
		H = 130;
		Images = ("DMS\graphics\DMSInstrumentcluster\gap1.png", "DMS\graphics\DMSInstrumentcluster\gap2.png", "DMS\graphics\DMSInstrumentcluster\gap3.png", "DMS\graphics\DMSInstrumentcluster\gap4.png", "DMS\graphics\DMSInstrumentcluster\gap5.png", "DMS\graphics\DMSInstrumentcluster\gap6.png", "DMS\graphics\DMSInstrumentcluster\gap7.png","DMS\graphics\DMSInstrumentcluster\gap8.png");
	};
	
#	Light LateralAssistenz
#	{
#		X = 1100;
#		Y = 200;
#		W = 90;
#		H = 90;
#		OnImage = ("DMS\graphics\DMSInstrumentcluster\Icon_lateral_guidance.png");
#		OffImage = ("DMS\graphics\DMSInstrumentcluster\Icon_lateral_guidance_darklight.png");
#	};
#	
#	ImageDisplay DMSInactive
#	{
#		X = 1100;
#		Y = 100;
#		W = 90;
#		H = 90;
#		Images = ("DMS\graphics\DMSInstrumentcluster\Icon_eye_darklight.png");
#	};
#	
#	ImageDisplay DMSActive
#	{
#		X = 1100;
#		Y = 100;
#		W = 90;
#		H = 90;
#		Images = ("DMS\graphics\DMSInstrumentcluster\Icon_eye_strikethrough.png","DMS\graphics\DMSInstrumentcluster\Icon_eye.png");
#	};
	
	ImageDisplay SpurwechselMeldung
	{
		X = 450; #bei 470 sollte es in der Mitte sein, ist es aber nicht...
		Y = 150;
		W = 500;
		H = 191;
		Images = ("DMS\graphics\DMSInstrumentcluster\txt_spurwechsel.png");
	};
	
	ImageDisplay DMSWarnings
	{
		X = 450; #bei 470 sollte es in der Mitte sein, ist es aber nicht...
		Y = 150;
		W = 500;
		H = 191;
		Images = ("DMS\graphics\DMSInstrumentcluster\Txt_automation_deaktiviert.png","DMS\graphics\DMSInstrumentcluster\Txt_automation_aktiviert.png", "DMS\graphics\DMSInstrumentcluster\Txt_aufmerksam_bleiben.png", "DMS\graphics\DMSInstrumentcluster\Txt_augen_auf_die_Strasse.png", "DMS\graphics\DMSInstrumentcluster\Txt_haende_ans_Lenkrad.png", "DMS\graphics\DMSInstrumentcluster\Txt_uebernehmen.png","DMS\graphics\DMSInstrumentcluster\Txt_abgeworfen.png");
	};
	
		#Meine Ergänzungen (max)
		
		
		ImageDisplay LimitWarnings
		{
			X = 450; #bei 470 sollte es in der Mitte sein, ist es aber nicht...
			Y = 150;
			W = 500;
			H = 191;
			Images = ("DMS\graphics\DMSInstrumentcluster\Txt_System_nicht_verfuegbar_bitte_uebernehmenV2.png");			# zum Testen, später austauschen
		};
	
		ImageDisplay RoteAmpelWarning
		{
			X = 450; #bei 470 sollte es in der Mitte sein, ist es aber nicht...
			Y = 150;
			W = 500;
			H = 191;
			Images = ("DMS\graphics\DMSInstrumentcluster\txt_System_nicht_verfuegbar_bitte_uebernehmenV2.png");			# zum Testen, später austauschen
		};
	
	ImageDisplay DMSWarnIcon
	{
		X = 583; #bei 470 sollte es in der Mitte sein, ist es aber nicht...
		Y = 400;
		W = 250;
		H = 250;
		Images = ("DMS\graphics\DMSInstrumentcluster\Icon_eye.png","DMS\graphics\DMSInstrumentcluster\Icon_hands_on.png","DMS\graphics\DMSInstrumentcluster\Icon_attention.png");
	};
	
		#Meine Ergänzungen (max)
		
		ImageDisplay AutomationAktiviert	
		{
			X = 1100;
			Y = 250;
			W = 150;
			H = 150;
			Images = ("DMS\graphics\DMSInstrumentcluster\Icon_automation_activated.png");
			
		};
		
		
		
		
		ImageDisplay AutomationNichtAktiviert	
		{
			X = 1100;
			Y = 250;
			W = 150;
			H = 150;
			Images = ("DMS\graphics\DMSInstrumentcluster\Icon_automation.png");
			
		};
		
		
		ImageDisplay KeineVerfuegbarkeit	
		{
			X = 1100;
			Y = 250;					
			W = 150;	
			H = 150;
			Images = ("DMS\graphics\DMSInstrumentcluster\Icon_automation_darklight.png");
			
		};
	
			ImageDisplay AmpelLimitUeberdecken	
		{
			X = 450; #bei 470 sollte es in der Mitte sein, ist es aber nicht...
			Y = 150;
			W = 500;
			H = 191;
			Images = ("DMS\graphics\DMSInstrumentcluster\txt_spurwechsel.png");			#war DMSInstrumentcluster\Ampel_Limit_ueberdecken.png
			
		};
};

DPULookUpSequence ~DMSInstrumentclusterGeschwbegrTable
{
	Computer = {MOCKUP};
	Index = 100;
	Sequence = (49,0, 10,1, 10,2, 10,3, 20,4, 30,5, 10,6);
};
	
DPUComparator ~DMSInstrumentclusterGeschwBegrAnzeigen
{
	Computer = {MOCKUP};
	Index = 100;
	Max = 130;
};

DPUOscillator ~DMSBlinkerRechts
{
	Computer = {MOCKUP};
	Index = 100;
	
	Period = 500;
	Amplitude = 1.0;
	Signal = 2;
};

DPUOscillator ~DMSBlinkerLinks
{
	Computer = {MOCKUP};
	Index = 100;
	
	Period = 500;
	Amplitude = 1.0;
	Signal = 2;
};

DPUBooleanGate ~DMSBlinkerLinksHedgehogUndAutomation
{
	Computer = {MOCKUP};
	Index = 100;
	Channels = 2;
	Gate = "AND";
};

DPUBooleanGate ~DMSBlinkerRechtsHedgehogUndAutomation
{
	Computer = {MOCKUP};
	Index = 100;
	Channels = 2;
	Gate = "AND";
};

DPUBooleanGate ~DMSBlinkerLinksHebelOderHedgehog
{
	Computer = {MOCKUP};
	Index = 100;
	Channels = 2;
	Gate = "OR";
};

DPUBooleanGate ~DMSBlinkerRechtsHebelOderHedgehog
{
	Computer = {MOCKUP};
	Index = 100;
	Channels = 2;
	Gate = "OR";
};

DPUBooleanGate ~DMSSpurwechselLinksOderRechts
{
	Computer = {MOCKUP};
	Index = 100;
	Channels = 2;
	Gate = "OR";
};

DPUBooleanGate ~DMSBlinkerLinksOderRechts
{
	Computer = {MOCKUP};
	Index = 100;
	Channels = 2;
	Gate = "OR";
};

DPUBooleanGate ~DMSLongAssistenzStatusInverter
{
	Computer = {MOCKUP};
	Index = 100;
	Channels = 1;
	Gate = "OR";
};

DPUBooleanGate ~DMSLatAssistenzStatusInverter
{
	Computer = {MOCKUP};
	Index = 100;
	Channels = 1;
	Gate = "OR";
};


	DPUBooleanGate ~LimitInverter			#(max)
	{
		Computer = {MOCKUP};
		Index = 100;
		Channels = 2;
		Gate = "AND";
	};
	
	DPUBooleanGate ~VerfuegbarkeitInverter		#(max)
	{
		Computer = {MOCKUP};
		Index = 100;
		Channels = 1;
		Gate = "OR";
	};
	
	DPUBooleanGate ~AutomationAktiviertInverter			#(max)
	{
		Computer = {MOCKUP};
		Index = 100;
		Channels = 1;
		Gate = "OR";
	};
	
	DPUBooleanGate ~AutomationNichtAktiviertInverter			#(max) 
	{
		Computer = {MOCKUP};
		Index = 100;
		Channels = 2;
		Gate = "AND";
	};


	DPUBooleanGate ~RoteAmpelInverter			#(max) 
		{
			Computer = {MOCKUP};
			Index = 100;
			Channels = 2;
			Gate = "AND";
		};
		
	DPUBooleanGate ~RoteAmpelUeberdeckenInverter		#(max) 
		{
			Computer = {MOCKUP};
			Index = 100;
			Channels = 2;
			Gate = "AND";
		};

DPULookUpSequence ~DMSInstrumentclusterAbstandsanzeigeTable
{
	Computer = {MOCKUP};
	Index = 100;
	Sequence = (1.9,0, 0.5,1, 0.5,2, 0.5,3, 0.5,4, 0.5,5, 0.5,6, 0.5,7);
};

DPUSNDXWavPlayer ~DMSAudioWarnings
{
	Computer = {SNDX};#SNDX am FaSi, z.B. OPERATOR an Workstation
	Index = 300;
	SoundPath = "C:\SILAB\Projects\DMStest\DMS\sounds\";			#war auskommentiert, von mir einkommentiert (max)
	SoundPath = "D:\SILAB\Projects\MA_SchneiderV2\DMS\sounds\"; 	#war auskommentiert, von mir einkommentiert (max)
	Sound01 = "DMSWarning.wav"; #EOR1 &EOR2
	Sound02 = "DMSWarning.wav"; #HOR
	Sound03 = "DMSWarning.wav"; #DCR
};
		
DPUSNDXWavPlayer ~DMSBlinkerSound
{
	Computer = {SNDX};#SNDX am FaSi, z.B. OPERATOR an Workstation
	Index = 300;
	#SoundPath = "C:\SILAB\Projects\DMStest\DMS\sounds\";
	#SoundPath = "D:\SILAB\Projects\MA_SchneiderV2\DMS\sounds\";
	Sound01 = "Blinker.wav";
	Loop = 1;
	Volume = 0.3;
};

#DPUMMI Blackcid
#{
#	Computer = {MOCKUP};
#	Index = 520;
#	WindowX = -1600;	#, wenn beide Anzeigen (Combi und CID) auf FS-Vehicle aktiv (0 funktioniert stand 13.04.2024)
#	WindowY = 0;
#	WindowW = 1280;
#	WindowH = 720;
#	W = 1280;
#	H = 720;
#	WindowTopmost = true;

#	ImageDisplay black
#	{
#		X = 0;
#		Y = 0;				#150
#		W = 1280;
#		H = 720;
#		Images = ("Instrumentcluster\black.png", "Instrumentcluster\blue.png");
#		
#		
#	};
#	
#};

# Default-Werte überschreiben, damit Fenster und Piktogramme nicht standardmäßig angezeigt werden
~DMSInstrumentcluster.SollGeschw.Show = false;
~DMSInstrumentcluster.DMSWarnings.Show = false;
~DMSInstrumentcluster.DMSWarnIcon.Show = false;
~DMSInstrumentclusterGeschwBegrAnzeigen.In = 150;
~DMSInstrumentcluster.LimitWarnings.Show = false;						#(max)
~DMSInstrumentcluster.KeineVerfuegbarkeit.Show = false;					#(max)
#hier noch eventuel AutomationAktiviert und AutomationNichtAktiviert defaulten
~DMSInstrumentcluster.AutomationAktiviert.Show = false;
~DMSInstrumentcluster.AutomationNichtAktiviert.Show = false;

~DMSInstrumentcluster.AmpelLimitUeberdecken.Show = false;

Connections =
{	
	#Geschwindigkeiten (aktuelle und Sollgeschwindigkeit)
	VDyn.v_kmh -> ~DMSInstrumentcluster.AktuelleGeschw.In,
	default -> ~DMSInstrumentcluster.SollGeschw.In, 
	default -> ~DMSInstrumentcluster.SollGeschw.Show,
	
	#Geschwindigkeitsbegrenzungen
	default -> ~DMSInstrumentclusterGeschwbegrTable.In,
	default -> ~DMSInstrumentclusterGeschwBegrAnzeigen.In,
	~DMSInstrumentclusterGeschwbegrTable.Out -> ~DMSInstrumentcluster.GeschwBegrenzung.In,
	~DMSInstrumentclusterGeschwBegrAnzeigen.LessEqual -> ~DMSInstrumentcluster.GeschwBegrenzung.Show,
	
	#FAS-Aktivierungsanzeigen (oben auskommentiert)
	#default -> ~DMSInstrumentcluster.LongitudinalAssistenz.In,
	#default -> ~DMSInstrumentcluster.LateralAssistenz.In,
	
	##DMSAktivierungsanzeige (oben auskommentiert)
	#default -> ~DMSLatAssistenzStatusInverter.In1,
	#~DMSLatAssistenzStatusInverter.Out -> ~DMSInstrumentcluster.DMSActive.Show,
	#~DMSLatAssistenzStatusInverter.Out_Not -> ~DMSInstrumentcluster.DMSInactive.Show,
	#DMS.eyes_on_road_state -> ~DMSInstrumentcluster.DMSActive.In,
	
	#Abstandsanzeige (oben auskommentiert)
	default -> ~DMSLongAssistenzStatusInverter.In1, #LongitudinalAssistenz_Status_in
	~DMSLongAssistenzStatusInverter.Out -> ~DMSInstrumentcluster.AbstandsanzeigeAn.Show,
	~DMSLongAssistenzStatusInverter.Out_Not -> ~DMSInstrumentcluster.AbstandsanzeigeAus.Show,
	default -> ~DMSInstrumentclusterAbstandsanzeigeTable.In, #Aktueller Sollabstand in
	~DMSInstrumentclusterAbstandsanzeigeTable.Out -> ~DMSInstrumentcluster.AbstandsanzeigeAn.In,
	~DMSInstrumentclusterAbstandsanzeigeTable.Out -> ~DMSInstrumentcluster.AbstandsanzeigeAus.In,

	#Blinker Links
	#Blinker dürfen von Hedgehogs nur im Automationsmodus aktiviert werden
	default -> ~DMSBlinkerLinksHedgehogUndAutomation.In1, #Automationsstatus in
	default -> ~DMSBlinkerLinksHedgehogUndAutomation.In2, #Hedgehog in
	default <-> ~DMSBlinkerLinksHebelOderHedgehog.In1, # Schalter für Blinker in
	~DMSBlinkerLinksHedgehogUndAutomation.Out -> ~DMSBlinkerLinksHebelOderHedgehog.In2,
	~DMSBlinkerLinksHebelOderHedgehog.Out <-> ~DMSBlinkerLinks.Start, #Blinker können durch den Blinkerhebel oder im Automationsmodus durch Hedgehogs aktviert werden
	~DMSBlinkerLinksHebelOderHedgehog.Out <-> ~DMSBlinkerLinks.On,
	~DMSBlinkerLinks.Out <-> ~DMSInstrumentcluster.BlinkerLinks.In,
	
	#Blinker Rechts (gleich wie links)
	default -> ~DMSBlinkerRechtsHedgehogUndAutomation.In1, #Automation Satus in 
	default <-> ~DMSBlinkerRechtsHebelOderHedgehog.In1, # Schalter für Blinker in
	~DMSBlinkerRechtsHedgehogUndAutomation.Out -> ~DMSBlinkerRechtsHebelOderHedgehog.In2,
	~DMSBlinkerRechtsHebelOderHedgehog.Out <-> ~DMSBlinkerRechts.Start,
	~DMSBlinkerRechtsHebelOderHedgehog.Out <-> ~DMSBlinkerRechts.On,
	~DMSBlinkerRechts.Out <-> ~DMSInstrumentcluster.BlinkerRechts.In, 
	
	#Blinker Sounds
	~DMSBlinkerRechtsHebelOderHedgehog.Out <-> ~DMSBlinkerLinksOderRechts.In1,
	~DMSBlinkerLinksHebelOderHedgehog.Out <-> ~DMSBlinkerLinksOderRechts.In2,
	~DMSBlinkerLinksOderRechts.Out <-> ~DMSBlinkerSound.Play,
	
	#Ab hier würds glaube ich wo anders hingehören
	#DMSTextfenster 
	default -> ~DMSInstrumentcluster.Hintergrund.In,
	default -> ~DMSInstrumentcluster.DMSWarnings.In,
	default -> ~DMSInstrumentcluster.DMSWarnings.Show,
	
			#meine Ergänzungen zu Limits (max)
			
				default <-> ~LimitInverter.In1,
				#default -> ~DMSInstrumentcluster.LimitWarnings.In,
				default -> ~DMSInstrumentcluster.LimitWarnings.Show,
				~LimitInverter.Out -> ~DMSInstrumentcluster.LimitWarnings.Show,
				
				default <-> ~AutomationNichtAktiviertInverter.In1,
			
			
			#meine Ergänzungen zu Verfügbarkeit (max)
			
				default <-> ~VerfuegbarkeitInverter.In1, 
				default <-> ~AutomationAktiviertInverter.In1,
				default <-> ~AutomationNichtAktiviertInverter.In1,
				
				default -> ~DMSInstrumentcluster.KeineVerfuegbarkeit.Show,
				default -> ~DMSInstrumentcluster.AutomationAktiviert.Show,
				default -> ~DMSInstrumentcluster.AutomationNichtAktiviert.Show,
				default -> ~DMSInstrumentcluster.AmpelLimitUeberdecken.Show,
				
				~VerfuegbarkeitInverter.Out_Not -> ~DMSInstrumentcluster.KeineVerfuegbarkeit.Show,
				
				
				~AutomationAktiviertInverter.Out ->  ~DMSInstrumentcluster.AutomationAktiviert.Show,
				
				
				
				~AutomationNichtAktiviertInverter.Out -> ~DMSInstrumentcluster.AutomationNichtAktiviert.Show,
				
				
				
				#~VerfuegbarkeitInverter.Out -> ~DMSInstrumentcluster.AutomationNichtAktiviert.Show,		#das geht so nicht, weil sonst nach erneuter verfügbarkeit nicht AutomationNichtAktiviert und AutomationAktiviert beides showed -> überdeckung 
				
				#~AutomationAktiviertInverter.Out_Not ->  ~DMSInstrumentcluster.AutomationNichtAktiviert.Show, #das geht so auch nicht weil sich sonst AutomationNichtAktiviert und KeineVerfuegbarkeit überdecken
			
			#meine ergänzungen für rote Ampeln
				
			~RoteAmpelUeberdeckenInverter.Out -> ~DMSInstrumentcluster.AmpelLimitUeberdecken.Show,					#AmpelLimitUeberdecken
			
			~RoteAmpelInverter.Out -> ~DMSInstrumentcluster.RoteAmpelWarning.Show,
			
			
			
			
			
			
	
	#DMSPiktogramme
	default -> ~DMSInstrumentcluster.DMSWarnIcon.In,
	default -> ~DMSInstrumentcluster.DMSWarnIcon.Show,
	
	#Spurwechselbenachrichtigung
	default -> ~DMSSpurwechselLinksOderRechts.In1,
	default -> ~DMSSpurwechselLinksOderRechts.In2,
	~DMSSpurwechselLinksOderRechts.Out -> ~DMSInstrumentcluster.SpurwechselMeldung.Show
	
	#Automationsanzeige
	#~Automation_Framework_LfE.active_lat_and_long -> ~DMSInstrumentcluster.Automationsanzeige.In
	
};
