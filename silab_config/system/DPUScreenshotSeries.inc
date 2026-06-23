DPUCounter ~ScrCount {
	Computer = {DATA};
	Index = 0;

	Start = 1;
	Delta = 1;
};

DPUComparator ~ScrComp {
	Computer = {DATA};
	Index = 2;

	Min = 0;
	Max = 750;
};

Connections = {
	~ScrCount.Out -> ~ScrComp.In,
	~ScrComp.Greater -> ~ScrCount.Reset,
	~ScrComp.LessEqual -> ~ScrCount.Start,

	~ScrComp.Greater -> SIGView.Screenshot
};

SIGView.ScreenshotDir = "Data\Screenshots\";
SIGView.ScreenshotBasename = "Shot";
SIGView.WritePerStep = 100000;
