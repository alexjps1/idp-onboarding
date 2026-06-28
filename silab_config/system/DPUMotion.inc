DPUInterface MotionControl
{
		Computer = {MOTION};
		Index = 0; # bei DPUInterface ist der Index egal
		TreeviewGroup = "Fahrdynamik";
		TreeviewGroup~en = "Vehicle Dynamics";

		Interface_Postfix = "_MotionControl";
		VARSet = {
			# Anteil der Gierbewegung, der durch das Bewegungssystem übernommen wird
			MotionYawPerc,
			MotionRollPerc,
			MotionPitchPerc
		};
};


# Defaultwerte
MotionControl.MotionYawPerc = 25;
MotionControl.MotionRollPerc = 100;
MotionControl.MotionPitchPerc = 100;

# Systemspezifisches Bewegungssystem
include system/SYSMotion.inc
