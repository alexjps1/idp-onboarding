			DMS.cfg_aoi1 = 49; #Taste 1 zum Testen an Workstation 
			
			DPUKeyboardState KeyState
			{
				Computer = {OPERATOR};
				Index = 290;
			};
			
			DPUKeyboard keyboard
			{
				Computer = {OPERATOR};
				Index = 340;
			};
			
		
			Connections = 
			{
				KeyState.H -> DMS.lfe_wheel_hands_on_id, #Taste H als Input 1 für Hands-on-Erkennung
				keyboard.Key <-> DMS.world_intersec_id 
			};
		
		
		
