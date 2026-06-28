DPUSGEWeather SGEWeather 

{ 
	Computer = {LOCALHOST}; 
	Index = 55; 
	Rain.ViewAngle = 40; 
	Rain.MaxDensity = 20000; 
	Rain.VolMax = 0.3; 
	Rain.Speed = 20; 
	Rain.Length = 0.7; 
}; 

	Connections = 
{ 
	VDyn.v -> SGEWeather.v, 
	TRFX.Trafficdata -> SGEWeather.ExternalTimeStamp 
};