 DPUSEPAReceiver SEPAReceiver {
 	Computer = {DATA};
 	Index = 10; 
  			
 	Server = "10.1.2.333";
  			
 	Receive = {
 		"FrameNumber",
 		"TrackingState",
 		"FrameRate",
 		"HeadPosition",
 		"HeadPositionQ",
 		"HeadRotationRodrigues",
 		"HeadRotationQ",
		"HeadHeading",
		"HeadPitch",
		"HeadRoll",
 		"GazeDirection",
 		"GazeDirectionQ",
 		"GazeOrigin",
 		"EyePosition",
		"GazeHeading",
		"GazePitch", 	 		
 		"EyeLidOpening",
 		"EyeLidOpeningQ",
 		"LeftEyelidOpening",
 		"LeftEyelidOpeningQ",
 		"RightEyelidOpening",
 		"RightEyelidOpeningQ",
 		"LeftDiagnosis",
 		"RightDiagnosis",
 		"ClosestWorldIntersection",
 		"NumericalClosestWorldIntersection",
 		"FilteredClosestWorldIntersection"
 	}; 
 };


includeif system/SYSEyetracking.inc
