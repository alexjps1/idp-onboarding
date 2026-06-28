SILAB System 
{
	LaunchData1A = ("Daten aufzeichnen.",VAR_SAVEDATA,LD_BOOL_DEFAULT,"1");
	LaunchData1B = ("Dateiname",VAR_DATAFILENAME,LD_EDIT_DEFAULT,"Data");
	LaunchData2A = ("Aufsetzpunkt auswählen",SCN_SetupPoint,LD_COMBO_DEFAULT,"SetupPoint1");
	WatchdogDispatchConfig = 200000;
	WatchdogControllerInit = 200000;
	WatchdogPeriod = 5000;
}; 

include system/SYSBirdsEye.inc