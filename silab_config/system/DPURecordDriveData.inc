#### Konfiguration der Datenaufzeichnung
DPUDataFile VDat
{
	Computer  = { DATA };
	Index = 200;

	Record = {
		VDyn.X(X),
		VDyn.Y(Y),
		VDyn.Z(Z),
		VDyn.yaw(Yaw),
		VDyn.pitch(Pitch),
		VDyn.roll(Roll),
		VDyn.v_kmh(v),
		evt.Event(VideoWrite)
	};

	OverwriteExistingFile = true;
	FileName = DriveData;
	Extension = dat;
	LaunchDataPosition = 2; # Launchdaten aus dem Weg schieben
	
	HeaderType = 1;
};


DPUKeyboardEvent evt
{
	Computer = { OPERATOR };

	Index = 10;
};
