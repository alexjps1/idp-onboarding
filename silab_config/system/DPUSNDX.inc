
	# ------------------------------------------------------------------------------------------
	# SNDX

	# Positionierung Egofahrzeug
	DPUSNDXListener SNDXListener
	{
		Computer = {SNDX};
		Index = 20;
		TreeviewGroup = "Sound";
	};

	Connections =
	{
		VDyn.v -> SNDXListener.v,
		VDyn.yaw -> SNDXListener.yaw,
		VDyn.pitch -> SNDXListener.pitch,
		VDyn.roll -> SNDXListener.roll,
		VDyn.X -> SNDXListener.X,
		VDyn.Y -> SNDXListener.Y,
		SCNX.ZOut -> SNDXListener.Z
	};

	# Sound Egofahrzeug
	DPUSNDXEgo SNDXEgoSoundSim
	{
		Computer = {SNDX};
		Index = 200;
		TreeviewGroup = "Sound";
		#GlobalVolume = 0.1;
	};

	Connections =
	{
		VDyn.v_kmh -> SNDXEgoSoundSim.v_kmh,
		VDyn.RPM -> SNDXEgoSoundSim.RPM,
		Mockup.AcceleratorPedal -> SNDXEgoSoundSim.AcceleratorPedal
	};

	# Sound Fremdverkehr
	DPUSNDXTRF SNDXTRFSoundSim
	{
		Computer = {SNDX};
		Index = 200;
		TreeviewGroup = "Sound";
	};

	# optimierte Einstellung FF, MH 13.4.2011
	SNDXTRFSoundSim.RolloffFactor = 0.7;
	SNDXTRFSoundSim.ReferenceDistance = 5;
	SNDXTRFSoundSim.Radius = 300;
	# Crossfading aktivieren FF 25.6.2020
	SNDXTRFSoundSim.FadeIn = true;
	SNDXTRFSoundSim.FadeInTime = 2000;
	SNDXTRFSoundSim.FadeOut = true;
	SNDXTRFSoundSim.FadeOutTime = 2000;


	# Sound Wetter
	DPUSNDXWavPlayer RainSound
	{
		Index = 100;
		Computer = {SNDX};
		TreeviewGroup = "Sound";

		SoundPath = "lib/sounds/diverse/";
		Sound01 = "rain.wav";

		Enable = true;
		PlaySample01 = 0;
		Loop = true;
		Volume = 0;
	};

	Connections = {
		SIGWeather.Rain -> RainSound.PlaySample01,
		#SIGWeather.Rain -> SNDXEgoSoundSim.WetRoad, # MH 5.4.19 niemand mag das WetRoad-Geräusch
		SIGWeather.Rain.Volume -> RainSound.Volume
	};

	DPUSNDXWavPlayer ThunderSound
	{
		Index = 100;
		Computer = {SNDX};
		TreeviewGroup = "Sound";

		SoundPath = "lib/sounds/diverse/";
		Sound01 = "thunder_kurz01.wav";

		Enable = true;
		PlaySample01 = 0;
		Loop = false;
		Volume = 0;
	};

	Connections = {
		SIGWeather.Thunder -> ThunderSound.PlaySample01,
		SIGWeather.Thunder.Volume -> ThunderSound.Volume
	};

	# Sound Umgebung
	DPUSNDXEnvironment SNDXEnv
	{
		Computer = {SNDX};
		Index = 40; 
		TreeviewGroup = "Sound";

		Sources = {"AmbientTown", "AmbientVillage", "Birds1", "Birds2", "Birds3", "Birds4", "BushCutting", "Construction",
			"FewPeopleInTown", "FewPeopleOnField", "Fountain", "People1", "People2", "River"};
		ReferenceDistance = 7; 
		RolloffFactor = 0.5; 
	};
	
	includeif system\SYSSNDXParams.inc

