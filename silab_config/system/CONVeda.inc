			Connections = 
			{
				#
				# Verbindung Mockup -> Fahrdynamik
				#
				Mockup.Ignition -> VDyn.Ignition,
				Mockup.Starter -> VDyn.Starter,
				Mockup.HandBrake -> VDyn.HandBrake,
				Mockup.Gear -> VDyn.Gear,
				Mockup.SteeringWheel -> VDyn.SteeringWheel,
				Mockup.AcceleratorPedal -> VDyn.AcceleratorPedal,
				Mockup.BrakePedal -> VDyn.BrakePedal,
				Mockup.ClutchPedal -> VDyn.ClutchPedal,

				#
				# Verbindung Fahrdynamik -> Mockup/Kombidisplay
				#
				VDyn.v -> Display.v,
				VDyn.RPM -> Display.RPM
			};
