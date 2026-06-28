1. Diesen Ordner ins Projekt ziehen, 

2. folgenden Textblock in den zu erweiternden DPU-Pool ziehen:
	include	DMS\includes\DMSInstrumentcluster.inc
	include	DMS\includes\DPUDMS.inc
	include	DMS\includes\ConnectionsFaSi.inc (stattdessen \ConnectionsWorkstation für Workstation. Für Soundausgabe müssten dann in DMSInstrumentencluster ggf. die PCs der DPUSNDXWavplayer z.B. zu OPERATOR geändert werden)
	
Achtung: Die Reihenfolge hier ist wichtig, da nacheinander zuerst Eingänge mit konstanten Default-Werten belegt und danach mit Ausgängen überschrieben werden!

3. DPUDMS.dll in SILAB\bin kopieren

(4.) Falls Silab die Sound-Dateien nicht finden kann, die beiden Parameter SoundPath  In "DMS\includes\DMSInstrumentcluster.inc" einkommentieren bzw. anpassen:
SoundPath = "<SILAB-Laufwerk>:\SILAB\Projects\<dein Projekt>\DMS\sounds\";
(am statischen FaSi: "D:\SILAB\Projects\MA_SchneiderV2\DMS\sounds\"; (letzten Backslash nicht vergessen!)