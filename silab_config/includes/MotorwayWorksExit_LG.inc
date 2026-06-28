LandscapeTypeRight Wooded {
	Gradient = 0.1;
	TreeDensity = 3;
	MinObjdist = 10;
	MaxObjdist = 110;
	MinObjpos = 30;
	MaxObjpos = 400;
};
# Deko rechts
Object Grassland
{
	Orientation = Onwards;
	YOffset = 12.8;
	Distance = 4.5;
};
LandscapeTypeExtra Grassland
{
	Left = false;

	MinObjdist = 3.5;
	MaxObjdist = 25;

	Override = { Tree, User };
};
# Baumgruppen
LandscapeTypeExtra Wooded {
	Left = false;
	TreeDensity = 50;
	MinObjdist = 30;
	MaxObjdist = 60;
	MinObjpos = 40;
	MaxObjpos = 80;
};

LandscapeTypeExtra Wooded {
	Left = false;
	TreeDensity = 50;
	MinObjdist = 10;
	MaxObjdist = 40;
	MinObjpos = 140;
	MaxObjpos = 180;
};

LandscapeTypeExtra Wooded {
	Left = false;
	TreeDensity = 50;
	MinObjdist = 90;
	MaxObjdist =120;
	MinObjpos = 240;
	MaxObjpos = 280;
};

LandscapeTypeExtra Wooded {
	Left = false;
	TreeDensity = 50;
	MinObjdist = 80;
	MaxObjdist =110;
	MinObjpos = 90;
	MaxObjpos =130;
};

LandscapeTypeExtra Wooded {
	Left = false;
	TreeDensity = 50;
	MinObjdist = 30;
	MaxObjdist = 60;
	MinObjpos = 340;
	MaxObjpos = 380;
};


LandscapeTypeLeft Farmed {
	Gradient = 0.1;
	OverlayDensity = 1;
	#FieldDensity = 1;
	#MinObjdist = 10;
	MaxObjdist = 110;
	MinObjpos = 0;
	MaxObjpos = 400;
	WaySetback = (7, 2);
};
# Deko links
Object Meadow
{
	Orientation = Towards;
	YOffset = -12.8;
	Distance = 4.5;
};
LandscapeTypeExtra Alley2 {
	Left = true;
	Objdist = (15, 2);
	Objangle = 0;
	MinObjdist = 110;
	MaxObjdist = 135;
	MinObjpos = 50;
	MaxObjpos = 350;
};

