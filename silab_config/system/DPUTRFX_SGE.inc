			DPUTRFX TRFX
			{
				Alias = {TRF};
				Computer = {TRF};
				Index = 45;
				TreeviewGroup = "Verkehr";
				TreeviewGroup~en = "Traffic";

				AutoEnvLighting = true;
			};
			DPUTRFClient TRFClient
			{
				Computer = {VIS,MOV,BEV,SNDX};
				Index = 46;
				TreeviewGroup = "Verkehr";
				TreeviewGroup~en = "Traffic";
			};
			DPUTRFSGE TRFSGE
			{
				Alias = {TRFVISFront};
				Computer = {VIS};
				Index = 55; # nach SCNXSGE!
				TreeviewGroup = "Visualisierung";
				TreeviewGroup~en = "Visualization";
				SimCarShow = 1;
				SimCarName = Vehicles.V600.BMW645.main; #cars.BMWM3.bmwm3;
			};
			Connections =
			{
				Buttons.Privilege -> TRFX.Privilege,
				TRFX.Trafficdata -> TRFClient.Trafficdata,

				VDyn.X 		-> TRFX.EGOX,
				VDyn.Y 		-> TRFX.EGOY,
				SCNX.ZOut 	-> TRFX.EGOZ,
				VDyn.yaw 	-> TRFX.EGOyaw,
				VDyn.pitch 	-> TRFX.EGOpitch,
				VDyn.roll 	-> TRFX.EGOroll,
				VDyn.v 		-> TRFX.EGOv,
				VDyn.delta	-> TRFX.EGOdelta,
				Mockup.IndicatorLeft -> TRFX.EGOIndicatorLeft,
				Mockup.IndicatorRight -> TRFX.EGOIndicatorRight,
				Mockup.BrakePedal 	-> TRFX.EGOBrakePedal,
				Mockup.HandBrake 	-> TRFX.EGOHandBrake,
				Mockup.UpperBeam 	-> TRFX.EGOUpperBeam,
				Mockup.LowerBeam 	-> TRFX.EGOLowerBeam,
				Mockup.Gear         -> TRFX.EGOgear,

				VDyn.X 		-> TRFClient.EGOX,
				VDyn.Y 		-> TRFClient.EGOY,
				SCNX.ZOut 	-> TRFClient.EGOZ,
				VDyn.yaw 	-> TRFClient.EGOyaw,
				VDyn.pitch 	-> TRFClient.EGOpitch,
				VDyn.roll 	-> TRFClient.EGOroll,
				VDyn.v 		-> TRFClient.EGOv,
				VDyn.delta  -> TRFClient.EGOdelta,
				Mockup.IndicatorLeft -> TRFClient.EGOIndicatorLeft,
				Mockup.IndicatorRight -> TRFClient.EGOIndicatorRight,
				Mockup.BrakePedal 	-> TRFClient.EGOBrakePedal,
				Mockup.HandBrake 	-> TRFClient.EGOHandBrake,
				Mockup.UpperBeam 	-> TRFClient.EGOUpperBeam,
				Mockup.LowerBeam 	-> TRFClient.EGOLowerBeam,
				Mockup.Gear         -> TRFClient.EGOgear
			};
			
			includeif system\SYSTRFX.inc
			
