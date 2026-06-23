			DPULookUpTable ~MCSNDRPM2GrainCenter
			{
				Computer = {SNDX};
				Index = 1000;
				TreeviewGroup = "Sound";
				
				NSamplingPoints = 10;
				SamplingPoint1  = 1190; Sample1 = 0.03007854;
				SamplingPoint2  = 1764; Sample2 = 0.091178095;
				SamplingPoint3  = 2228; Sample3 = 0.139806964;
				SamplingPoint4  = 3392; Sample4 = 0.358634393;
				SamplingPoint5  = 4105; Sample5 = 0.528833505;
				SamplingPoint6  = 4644; Sample6 = 0.589618902;
				SamplingPoint7  = 5404; Sample7 = 0.711189696;
				SamplingPoint8  = 5768; Sample8 = 0.759818013;
				SamplingPoint9  = 6730; Sample9 = 0.869231728;
				SamplingPoint10 = 7000; Sample10 = 0.954331283;
			};
			
			DPULookUpTable ~MCSNDThrottle2LowGain
			{
				Computer = {SNDX};
				Index = 1000;
				TreeviewGroup = "Sound";
				NSamplingPoints = 2;
#				SamplingPoint1 = 0.0; Sample1 = 0.437;
#				SamplingPoint2 = 1.0; Sample2 = 0.9;
				
				SamplingPoint1 = 0.0; Sample1 = 0.7;
				SamplingPoint2 = 1.0; Sample2 = 1.0;
				
			};
			
			DPULookUpTable ~MCSNDThrottle2MidGain
			{
				Computer = {SNDX};
				Index = 1000;
				TreeviewGroup = "Sound";
				NSamplingPoints = 2;
#				SamplingPoint1 = 0.0; Sample1 = 0.7058;
#				SamplingPoint2 = 1.0; Sample2 = 1.2;
				SamplingPoint1 = 0.0; Sample1 = 0.7058;
				SamplingPoint2 = 1.0; Sample2 = 1.4;
				
			};
			
			DPUAmplifier ~MCSNDThrottle
			{
				Computer = {SNDX};
				Index = 900;
				TreeviewGroup = "Sound";
			};
			
			Connections =
			{
				~MCSNDThrottle.Out -> ~MCSNDThrottle2LowGain.In,
				~MCSNDThrottle.Out -> ~MCSNDThrottle2MidGain.In
				
			};
						
			DPUSNDXGranular ~MCSNDGranular
			{
				Computer = {SNDX};
				Index = 1010;
				TreeviewGroup = "Sound";
				FNSample = "granular\SWEEP_1000-12000_BikeEngine.wav";
				#FNSample = "granular\BMW_hinten_3_mono_filtered.wav";
				#FNSample = "granular\BMW_vorne_1_mono_filtered.wav";
				#FNSample = "granular\BMW_hinten_3.wav";
				Y = 0.0;
				Z = 0.0;
				VolumeL = 0;
				VolumeR = 1;
			};
			
			Connections =
			{
				~MCSNDRPM2GrainCenter.Out -> ~MCSNDGranular.GrainCloudCenter,
				~MCSNDThrottle2LowGain.Out -> ~MCSNDGranular.LowGain,
				~MCSNDThrottle2MidGain.Out -> ~MCSNDGranular.MidGain,
				
				VDyn.RPM -> ~MCSNDRPM2GrainCenter.In,
				VDyn.AcceleratorPedal -> ~MCSNDThrottle.In
			};
			
			
			
			DPUAmplifier ~MCSNDRPM2Freq
			{
				Computer = {OPERATOR};
				Index = 1000;
				TreeviewGroup = "Sound";
				
				Multiplicator = 2; # Anzahl Zylinder
				Divisor = 120;
			};
						
			#DPUSNDXSine MCSNDSine
			
			DPUSNDXSawTriPulse ~MCSNDSeat
			{
				Computer = {OPERATOR};
				TreeviewGroup = "Sound";
				Index = 1010;
				Type = 0;
			};
			
			
			Connections =
			{
				VDyn.RPM -> ~MCSNDRPM2Freq.In
				//,
				//~MCSNDRPM2Freq.Out -> ~MCSNDSeat.Frequency
			};
			
