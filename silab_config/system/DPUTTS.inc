	# 1st alternative: use operating system's TTS ability
	DPUTTSServer TTS
	{
		Computer = {TTS};
		Index = 20;
		TreeviewGroup = "Sound";
	};

	DPUTTSClient TTSClient
	{
		Computer = {TTS};
		Index = 50;
		TreeviewGroup = "Sound";
	};
	
	# 2nd alternative: use embedded Pico engine
	DPUTTSServerPico TTSPico
	{
		Computer = {TTSP};
		Index = 20;
		TreeviewGroup = "Sound";
	};

	DPUTTSClientSNDX TTSClientPico
	{
		Computer = {TTSP};
		Index = 50;
		TreeviewGroup = "Sound";
		ServerIP = "TTSP";
	};
	
	# in any case: support hedgehogs
	DPUTTSSCNX TTSSCNX
	{
		Computer = {TTS,TTSP};
		Index = 51;
		TreeviewGroup = "Sound";
	};
	
	includeif system/SYSTTSParams.inc
	


