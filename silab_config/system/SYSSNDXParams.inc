
#Anpasssungen von SILAB Standards: Alle auf 1 und dann Regulierung über Windows eigenen Soundregler

SNDXEgoSoundSim.GlobalVolume = 1;
SNDXTRFSoundSim.GlobalVolume = 1;

	Connections = 
	{ 
		Mockup.Indicator -> SNDXEgoSoundSim.Indicator 
		#Mockup.Horn -> SNDXEgoSoundSim.Horn, 
		#Mockup.Starter -> SNDXEgoSoundSim.Starter 
	}; 