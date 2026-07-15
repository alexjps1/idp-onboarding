#### Framework und Doku - Bitte einmal komplett lesen vor erster Verwendung!

# Dieses Framewok schaltet die Automation vom WIVW in einer sinnvollen Konfiguration zusammen, die einfach anpassbar ist.
# Bitte überschreiben Sie nur die Dateien in Ihrem Projektordner und nie die im Systems Ordner von SILAB
# Sollten Sie sinnvolle Neuerungen in Ihrem Projekt entwickeln, die für zukünftige Projekte relevant sind, melden Sie sich
# beim Fahrsimverantwortlichen. Ggf. könnnen wir sie gleich im Framework für alle integrieren.
# Erstellt von Lorenz Steckhan 03.03.2024
# Bearbeitet von xxx



#### Konfigurationsprofil

# Nachfolgende DPU verschaltet alles und liegt als SIMULINK Modell vor. Die weiteren relevanten DPUs (zB Regler) sind am Ende über eine ergänzende .inc eingebunden.
# Normalerweise sollten Sie nur Anpasssungen in dieser Datei vornehmen müssen. Stellen Sie dafür einfach nachfolgend alle
# Konfigurationswerte (cfg) auf die für Sie gewünschte Konfiguration der Automation.


DPUAutomation_Framework_LfE ~Automation_Framework_LfE
{
	Computer = {ASS}; # DPU wurde so kompiliert dass der PC auf 120 HZ laufen sollte
	Index = 1;
	TreeviewGroup = "Automation";

	## Verfügbarkeit der Automation steuern und konfigurieren
	# Hedgehogs (available) können dynamisch zur Laufzeit die Verfügbarkeit regeln. Soll dies genutzt werden
	# muss der folgende Konfigwert auf 0 stehen. Soll in der gesamten Strecke dasselbe verfügbar sein kann der Wert auf 1 gestellt
	# werden und dann wird der nachfolgende Konfigwert durchgehend verwendet.
	cfg_hh_available_ignore = 0; # 0: HH bestimmen Verfügbarkeit (HH müssen in Strecke sein sonst ist nichts verfügbar), 1: nachfolgender Wert bestimmt Verfügbarkeit
	cfg_available = 3; # Für die gesamte Strecke: 0:keine Automation, 1: ACC, 2: LKS, 3: ACC+LKS

	## Ein/Ausschaltlogik konfigurieren
	# DMS???
	gas_threshold = 20; # Bei welchem Wert [0...1] der Pedalstellung soll die Automation ausgeschaltet werden. Werte > 1 = wird nie ausgeschaltet
	brake_threshold = 0.05; # Bei welchem Wert [0...1] der Pedalstellung soll die Automation ausgeschaltet werden. Werte > 1 = wird nie ausgeschaltet
	steering_force_threshold = 4000; # Bei welchem Wert [???] der Kraft am Lenkrad soll die Automation ausgeschaltet werden.

	## Geschwindigkeitsregelung konfigurieren
	vlim_standard = 150; # Verwendetes Geschwindigkeitslimit, wenn kein Geschwindigkeitslimit erkannt wurde zB am Start
	cfg_vlim_ignore =0; # Einstellung der Set Geschwindigkeit über dem Geschwindigkeitslimit möglich (1) oder nicht (0)
	cfg_v_from_vlim = 0; # Geschwindigkeitslimits automatisch als neue vset in hmi und controller übernehmen (1) oder nicht (0)

	## Abstandsregelung konfigurieren
	cfg_vehicledetection_on = 1; # Fahrzeuge erkennen an (1) oder aus (1) (schaltet auch immer die Ampelerkennung mit aus)
	cfg_trafficlightdetection_on = 1; #Ampelerkennung an (1) oder aus (1)
	cfg_gap_lim_upper = 5; # maximal möglicher Wert bei der Abstandregelung in s
	cfg_gap_lim_lower = 1.5; # minimal möglicher Wert bei der Abstandregelung in s
	gap_standard = 2.5; # Defaultwert des Abstands in s

	## Spurwechselregelung konfigurieren
	cfg_lc_function_active = 1; # Aktivierung der automatischen Spurwechseltriggerungsfunktion (1) oder Deaktivierung (0)
	cfg_lc_sensor_active =1; # Aktivierung (1) oder Deaktivierung (0) des seitlichen Sensors, der prüft ob eine Spur frei ist bevor ein Wechsel gestartet wird
	cfg_lc_trigger_delay_s = 1; # Einstellung der Dauer die ein Spurwechsel nach Trigger durch ein Vorblinken verzügert wird


};


#### Hedgehogs

# Folgende Hedgehogs stehen zur Verfügung (ggf. sind oben cfg korrekt zu setzen, damit diese erkannt werden
# Alle HH sind mit der Family automation und den nachfolgenden Namen und Werten zu definieren

# Family: AutomationTest			#von mir geändert (max)
# HHs für die Verfügbarkeit der Automation
# Name: available, schaltet Automation verfügbar/nicht verfügbar. Wenn nicht mehr verfügbar und aktiv wird es auch direkt ausgeschaltet, Wert: 0:keine Automation, 1: ACC, 2: LKS, 3: ACC+LKS, Defaultwert: 0

# HHs für das Aus/Einschalten der Automation
# Name: long_io, Schaltet ACC an/aus. DPU schaut auf Flanken/Veränderung des HH-Wertes: 0->1: Einschalten, 1->0: Ausschalten, Defaultwert: 0
# Name: lat_io, Schaltet LKS an/aus. DPU schaut auf Flanken/Veränderung des HH-Wertes: 0->1: Einschalten, 1->0: Ausschalten, Defaultwert: 0
# Name: long_lat_io, Schaltet ACC+LKS an/aus. DPU schaut auf Flanken/Veränderung des HH-Wertes: 0->1: Einschalten, 1->0: Ausschalten, Defaultwert: 0

# HHs die einen  stillen Fehler simulieren
# Name: corrupt_long, Schaltet ACC an/aus. DPU schaut auf Flanken/Veränderung des HH-Wertes: 0->1: Kein Fehler, 1->0: Fehler, Defaultwert: 1
# Name: corrupt_lat, Schaltet LKS an/aus. DPU schaut auf Flanken/Veränderung des HH-Wertes: 0->1: Kein Fehler, 1->0: Fehler, Defaultwert: 1
# Name: corrupt_long_lat, Kappt Verbindung zur Fahrdynamik von ACC+LKS. DPU schaut auf Flanken/Veränderung des HH-Wertes: 0->1: kein Fehler, 1->0: Fehler, Defaultwert: 1

# HHs die eine Veränderung der Geschwindigkeit oder des Geschwindigkeitslimits bewirken
# Bei der Geschwindigkeit kann die Anzeige im HMI und der Wert im Regler/Controller separat manipuliert werden um zB in Kurven still v anzupassen oder Fehler zu simulieren
# Einheit kmh
# Name: vset_contr_hmi, setzt bei einem Sprung im Wert die Set Geschwindigkeit für den Controller und im HMI auf den neuen Wert [>=0, Controller kann nicht auf 0 stehen und setzt bei 0 daher auf 0.1], Default 0
# Name: vset_contr, setzt bei einem Sprung im Wert die Set Geschwindigkeit für den Controller und NICHT im HMI auf den neuen Wert [>=0, Controller kann nicht auf 0 stehen und setzt bei 0 daher auf 0.1], Default 0
# Name: vset_hmi, setzt bei einem Sprung im Wert die Set Geschwindigkeit für den Controller NICHT und im HMI doch auf den neuen Wert [>=0, Controller kann nicht auf 0 stehen und setzt bei 0 daher auf 0.1], Default 0
# Name: set_vlim, setzt bei einem Sprung im Wert die Set Geschwindigkeit für den Controller NICHT und im HMI doch auf den neuen Wert [>=10], Default 0

# HHs die eine Veränderung der Abstandsregelung
# Beim Abstand kann die Anzeige im HMI und der Wert im Regler/Controller separat manipuliert werden um zB Fehler zu simulieren
# Einheit s
# Name: set_gap_contr_hmi, setzt bei einem Sprung im Wert den Set Abstand für den Controller und im HMI auf den neuen Wert [>=0, Controller kann nicht auf 0 stehen und setzt bei 0 daher auf 0.1], Default 0
# Name: set_gap_contr, setzt bei einem Sprung im Wert den Set Abstand für den Controller und NICHT im HMI auf den neuen Wert [>=0, Controller kann nicht auf 0 stehen und setzt bei 0 daher auf 0.1], Default 0
# Name: set_gap_hmi, setzt bei einem Sprung im Wert den Set Abstand für den Controller NICHT und im HMI doch auf den neuen Wert [>=0, Controller kann nicht auf 0 stehen und setzt bei 0 daher auf 0.1], Default 0

# HHs die die Spurwechsellogik triggern
# Name: lc_time, Verändert beim Sprung im Wert die Spurwechseldauer in s (wird durch einen Wert im Regler auf mind. Xm nach unten begrenzt
# Name: lc_left, triggert beim Sprung von 0 auf 1 einen Spurwechsel nach links
# Name: lc_right, triggert beim Sprung von 0 auf 1 einen Spurwechsel nach rechts
# Name: lc_abort, triggert beim Sprung von 0 auf 1 einen Spurwechselabbruch

#HHs die eine Bremsung ins Stehen verursachen
# Name: standstill, Jeder Sprung von 0 auf 1 in diesem Wert ändert den Zustand der Funktion (an bzw. aus), Defaultwert 0

#### Operator Interface
# Das folgende Interface bietet die wichtigsten Werte zur Manipulation und Anzeige. Sie können für Ihre Studie unbenötigete Werte hier auskommentieren, da dies lediglich eine Anzeige ist und die Werte in der Automation weiter existieren
# Nachfolend ist das Operator Interface erklärt, welches Sie nutzen können, um Werte live bei der Simulation vom Operator aus Silab zu manipulieren
# Das Framework bietet teilweise mehr Ein/Ausgänge als hier im Interface sichtbar -> Siehe versteckte DPU Automation_Framework_LfE

DPUInterface Automation_OperatorInterface
{
	Computer = {ASS};
	Index = 0;
	TreeviewGroup = "Automation";
	Interface_Postfix = "_Automation";
	VARSet =
	{
	#### Eingänge ins Framework (zur Manipulation der Automation vom Operator aus)
		# Über einen Rechtsklick im Silabbaum auf den Werten können Sie im Kontextmenü einen Schalter oder ein Eingabefeld öffnen
		# An Aus
		ActivateLong,					# Funktioniert wie ein Button jede Flanke von 0 auf 1 in diesem Wert switched den Zustand
		ActivateLatandLong,				# Funktioniert wie ein Button jede Flanke von 0 auf 1 in diesem Wert switched den Zustand
		ActivateLat,					# Funktioniert wie ein Button jede Flanke von 0 auf 1 in diesem Wert switched den Zustand

		# Parameter und Manöver
		# Bei jedem Sprung im Wert wird der entsprechende Wert angepasst
		Change_vSet_HMI,		    	# Ändert v set im hmi[kmh]
		Change_vSet_Controller,			# Ändert v set im controller[kmh]
		Change_vSet_HMIandController,	# Ändert v set im controller und im hmi[kmh]
		Change_vLim,					# Ändert v lim [kmh]

		Change_GapSet_HMI,		    	# Ändert gap set im hmi[s]
		Change_GapSet_Controller,		# Ändert gap set im controller[s]
		Change_GapSet_HMIandController, # Ändert gap set im controller und im hmi[s]

		Trigger_LaneChange_Left,		# Triggert Spurwechsel [Funktioniert wie ein Button jede Flanke von 0 auf 1]
		Trigger_LaneChange_Right,		# Triggert Spurwechsel [Funktioniert wie ein Button jede Flanke von 0 auf 1]
		Trigger_LaneChange_Abort,		# Triggert Spurwechselabbruch [Funktioniert wie ein Button jede Flanke von 0 auf 1]
		Change_LaneChange_Time,			# Bei jedem Sprung im Wert wird die Spurwechselzeit auf den entsprechenden Wert gestellt [s]

		Trigger_StandStill,				# Triggert Anhalten [Funktioniert wie ein Button jede Flanke von 0 auf 1 ändert Zustand]

		# stille Fehlerfälle simulieren
		Corrupt_Lat,					# Funktioniert wie ein Button jede Flanke von 0 auf 1 in diesem Wert switched den Zustand
		Corrupt_Long,					# Funktioniert wie ein Button jede Flanke von 0 auf 1 in diesem Wert switched den Zustand
		Corrupt_LatandLong,				# Funktioniert wie ein Button jede Flanke von 0 auf 1 in diesem Wert switched den Zustand

	#### Ausgänge aus dem Framework (Zur Betrachtung der Werte, der Automation)
		# Über einen Rechtsklick im Silabbaum auf den Werten können Sie im Kontextmenü einen Schalter oder ein Eingabefeld öffnen
		# An Aus
		StateLat,						# Aktueller Zustand Funktion Lateral [0 aus 1 an]
		StateLong,						# Aktueller Zustand Funktion Longitudinal [0 aus 1 an]
		StateLatAndLong,				# Aktueller Zustand Funktion Lateral+Longitudinal [0 mind. eines von beiden aus 1 beides an]

		Value_vSet_Controller,			# Aktueller Wert [kmh]
		Value_vSet_HMI,					# Aktueller Wert [kmh]
		Value_vLim,						# Aktueller Wert [kmh]

		Value_Gap_Controller,			# Aktueller Wert [s]
		Value_Gap_HMI,					# Aktueller Wert [s]

		Value_LaneChange_Time,			# Aktueller Wert [s]
		State_LaneChange,				# Aktueller Zustand der Spurwechselfunktion [0 inaktiv >0 verschiedene Zustände der aktiven Funktion]

		State_StandStill				# Aktueller Zustand der Anhaltefunktion [1 aktiv 0 inaktiv]



	};
};

# folgende Datei enthält alle Regler und Verschaltungen. Normalerweise müssen Sie hier keine Änderungen vornehmen
include includes/AutomationDYN.inc
# folgende Dateien enthalten die Verknüpfungen zum jeweiligen Mockup. Es sollte nur das für das jeweilige Mockup vorhanden sein oder das jeweils andere auskommentiert werden
includeif includes/Automation_Mockup_statischerFahrsimulator.inc
#includeif includes/Automation_Mockup_Einzelplatz.inc
#includeif includes/Automation_Mockup_Sitzkiste.inc


#### Weitere Informationen und häufige Fehlerfälle


# Für engere Kurven und hohe Geschwindigkeiten muss der Wert höher gesetzt werden. Im Fahrsim führt dies jedoch zu Schwingungen am Lenkrad
# ~SteeringwheelGainKlw.Multiplicator = 180;

# Im Normalfall folgt das Fahrzeug der aktuellen Spur. Bei einer sich aufteilenden Spur kommt es teils zu komischen Verhalten. Hierfür kann
# im Area2 oder Course der Wert liegt auf Targetroute auf 1 gesetzt werden. Der Querregler folgt dieser Route dann. Ansonsten muss über
# HH und den Wert Heading aus dem Querregler eine eigene dynamische Version erstellt werden.
