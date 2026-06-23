
	DPUVoiceChatSNDX Chat
	{
		Index = 50;
		Computer = {OPERATOR,SNDX};
		TreeviewGroup = "Sound";
	};

	OPERATOR.Chat.Out1.ServerName = SNDX;
	SNDX.Chat.Out1.ServerName = OPERATOR;

