#############################################################
## Lateral and longitudinal control of the EGO-vehicle 
#############################################################

#############################################################
## Longitudinal control
## Sensor: ~AutTRFSensor 
## Distance/velocity control: ~DVControl
## Acceleration control: ~AxControl
## For details see respective documentation of the DPUs

DPUDVControl ~DVControl
{
	Computer = {ASS};
	Index = 61;
	TreeviewGroup = "Automation";
	dMin = 2.0; # Minimal distance to front vehicle 10m};
};

DPUAxControlLUT ~AxControl
{
	Computer = {ASS};
	Index = 203;
	TreeviewGroup = "Automation";
	# use same path defined in ~MSTVeda.ConfigPath
	LUTAccel = "mstVedaAutoPar.BMW/Accel_BMW5.lut";
	LUTDecel = "mstVedaAutoPar.BMW/Decel_BMW5.lut";
};

DPUATBTRFSensor ~AutTRFSensor
 {
	 Computer = {ASS};
	 Index = 400;
	 TreeviewGroup = "Automation";
	 CombineTLAndRU = true;
	 ScanMinDist = 150;
	 THWScan = 5;
 };
TRFX.ODB = true;

DPUAmplifier ~corrupt_long
{
	Computer = {ASS};
	Index = 52;
	TreeviewGroup = "Automation";
	#Multiplicator = 0 unterbricht Verbindung zur Fahrdynamik lateral
};


#############################################################
## Lateral control
## Sensor and controller: ~MacAdamLAC
## For details see documentation of the DPU

DPUATBMacAdamLAC ~MacAdamLAC
{
	Computer = {ASS};
	Index = 51;
	TreeviewGroup = "Automation";
	TLaneChangeDead =0;
	TFadeIn = 2.5;
	Heading = 8; #follows target lane specified within Area2 or Course
};              
DPUAmplifier ~corrupt_lat
{
	Computer = {ASS};
	Index = 51;
	TreeviewGroup = "Automation";
	#Multiplicator = 0 unterbricht Verbindung zur Fahrdynamik lateral
};
DPUAmplifier ~SteeringwheelGainKlw			#Festlegen Parameter des Lenkaktuators
{
	Computer = {ASS};
	Index = 51;
	Multiplicator = 60; ##Für stärkeres Lenken und kleinere Kurven höher setzen z.B. 180
	TreeviewGroup = "Automation";
};
DPUAmplifier ~Steeringwheel_i_SW_ControlPosition	#Festlegen Parameter des Lenkaktuators
{
	Computer = {ASS};
	Index = 51;
	Multiplicator = 57.2958;
	TreeviewGroup = "Automation";
};

Connections = 
{
	# activate 
	~corrupt_long.Out -> ~DVControl.Activate,
	~corrupt_long.Out -> ~AutTRFSensor.Activate,
	~Automation_Framework_LfE.active_lat -> ~MacAdamLAC.Activate,
	~Automation_Framework_LfE.active_long  -> ~corrupt_long.In,
	~Automation_Framework_LfE.active_lat -> ~corrupt_lat.In,

	# control signals
	~Automation_Framework_LfE.lc_left -> ~MacAdamLAC.LaneChange_Left,
	~Automation_Framework_LfE.lc_right -> ~MacAdamLAC.LaneChange_Right,
	~Automation_Framework_LfE.lc_abort -> ~MacAdamLAC.LaneChange_Abort,
	~Automation_Framework_LfE.standstill -> ~DVControl.StandStill,
	~Automation_Framework_LfE.vset_controller_mps -> ~DVControl.vTarget,
	~Automation_Framework_LfE.gap_set_controller_s -> ~DVControl.TDistTarget,
	
	# status signals
	~MacAdamLAC.LaneChange_State -> ~Automation_Framework_LfE.lane_change_state,
	VDyn.v -> ~Automation_Framework_LfE.v_actual,
	
	# stillen Fehlerfall ermöglichen
	~Automation_Framework_LfE.corrupt_long -> ~corrupt_long.Multiplicator,
	~Automation_Framework_LfE.corrupt_lat -> ~corrupt_lat.Multiplicator,
	

	# => ~DVControl
	VDyn.v <-> ~DVControl.v,
	~AutTRFSensor.NearestD -> ~DVControl.dTO,
	~AutTRFSensor.NearestV -> ~DVControl.vTO,
	
	# => ~AxControl
	Mockup.AcceleratorPedal <-> ~AxControl.GasPedalIn,
	Mockup.BrakePedal <-> ~AxControl.BrakeIn,
	~DVControl.ActivateAxControl <-> ~AxControl.Activate,
	~DVControl.axTarget <-> ~AxControl.axTarget,
	VDyn.v <-> ~AxControl.v,
	VDyn.v <-> ~AutTRFSensor.v,
	
	# => Vehicle dynamics
	~AxControl.GasPedalOut <-> VDyn.AcceleratorPedal,
	~AxControl.BrakeOut <-> VDyn.BrakePedal,
	
	# sensors
	~AutTRFSensor.LeftLaneExist -> ~Automation_Framework_LfE.left_lane_exist,
	~AutTRFSensor.RightLaneExist -> ~Automation_Framework_LfE.right_lane_exist,
	~AutTRFSensor.LeftLaneClear -> ~Automation_Framework_LfE.left_lane_free,
	~AutTRFSensor.RightLaneClear -> ~Automation_Framework_LfE.right_lane_free,
	
	# => ~MacAdamLAC 
	VDyn.X -> ~MacAdamLAC.X,
	VDyn.Y -> ~MacAdamLAC.Y,
	VDyn.yaw -> ~MacAdamLAC.yaw,
	VDyn.vyaw -> ~MacAdamLAC.vyaw,
	VDyn.v -> ~MacAdamLAC.v,
	
	# Framework
	Mockup.AcceleratorPedal -> ~Automation_Framework_LfE.gas,
	Mockup.BrakePedal -> ~Automation_Framework_LfE.brake,
	Mockup.IndicatorLeft -> ~Automation_Framework_LfE.button_lc_left,
	Mockup.IndicatorRight -> ~Automation_Framework_LfE.button_lc_right
	
	
};



DPUSCNXHedgehogKiller ~Automation_Framework_LfE_HH_1
{
	Computer = {"ASS"};
	Index = 10;
	Family = "AutomationTest";		#war "automation", von mir zum testen gändert in AutomationTest (max)
	Name1 = "available";
	Default1 = 0.0;
	Name2 = "long_io";
	Default2 = 0.0;
	Name3 = "lat_io";
	Default3 = 0.0;
	Name4 = "long_lat_io";
	Default4 = 0.0;
	Name5 = "corrupt_long";
	Default5 = 1.0;
	Name6 = "corrupt_lat";
	Default6 = 1.0;
	Name7 = "corrupt_long_lat";
	Default7 = 1.0;
};
DPUSCNXHedgehogKiller ~Automation_Framework_LfE_HH_2
{
	Computer = {"ASS"};
	Index = 10;
	Family = "AutomationTest2";			#war "automation", von mir zum testen gändert in AutomationTest2 (max)
	Name1 = "vset_contr_hmi";
	Default1 = 0.0;
	Name2 = "vset_contr";
	Default2 = 0.0;
	Name3 = "vset_hmi";
	Default3 = 0.0;
	Name4 = "set_vlim";
	Default4 = 0.0;
	Name5 = "set_gap_contr_hmi";
	Default5 = 0.0;
	Name6 = "set_gap_contr";
	Default6 = 0.0;
	Name7 = "set_gap_hmi";
	Default7 = 0.0;
};

DPUSCNXHedgehogKiller ~Automation_Framework_LfE_HH_3
{
	Computer = {"ASS"};
	Index = 10;
	Family = "AutomationStandstill";			#war "automation", von mir zum testen gändert in AutomationStandstill (max)
	Name1 = "lc_time";
	Default1 = 0.0;
	Name2 = "lc_left";
	Default2 = 0.0;
	Name3 = "lc_right";
	Default3 = 0.0;
	Name4 = "lc_abort";
	Default4 = 0.0;
	Name5 = "standstill";
	Default5 = 0.0;
};
Connections =
{
# Hedgehogs
~Automation_Framework_LfE_HH_1.Out1 <-> ~Automation_Framework_LfE.hh_available,
~Automation_Framework_LfE_HH_1.Out2 <-> ~Automation_Framework_LfE.hh_long_io,
~Automation_Framework_LfE_HH_1.Out3 <-> ~Automation_Framework_LfE.hh_lat_io,
~Automation_Framework_LfE_HH_1.Out4 <-> ~Automation_Framework_LfE.hh_long_lat_io,
~Automation_Framework_LfE_HH_1.Out5 <-> ~Automation_Framework_LfE.hh_corrupt_long,
~Automation_Framework_LfE_HH_1.Out6 <-> ~Automation_Framework_LfE.hh_corrupt_lat,
~Automation_Framework_LfE_HH_1.Out7 <-> ~Automation_Framework_LfE.hh_corrupt_long_lat,

~Automation_Framework_LfE_HH_2.Out1 <-> ~Automation_Framework_LfE.hh_vset_contr_hmi,
~Automation_Framework_LfE_HH_2.Out2 <-> ~Automation_Framework_LfE.hh_vset_contr,
~Automation_Framework_LfE_HH_2.Out3 <-> ~Automation_Framework_LfE.hh_vset_hmi,
~Automation_Framework_LfE_HH_2.Out4 <-> ~Automation_Framework_LfE.hh_set_vlim,

~Automation_Framework_LfE_HH_2.Out5 <-> ~Automation_Framework_LfE.hh_set_gap_contr_hmi,
~Automation_Framework_LfE_HH_2.Out6 <-> ~Automation_Framework_LfE.hh_set_gap_contr,
~Automation_Framework_LfE_HH_2.Out7 <-> ~Automation_Framework_LfE.hh_set_gap_hmi,


~Automation_Framework_LfE_HH_3.Out1 <-> ~Automation_Framework_LfE.hh_lc_time,
~Automation_Framework_LfE_HH_3.Out2 <-> ~Automation_Framework_LfE.hh_lc_left,
~Automation_Framework_LfE_HH_3.Out3 <-> ~Automation_Framework_LfE.hh_lc_right,
~Automation_Framework_LfE_HH_3.Out4 <-> ~Automation_Framework_LfE.hh_lc_abort,
~Automation_Framework_LfE_HH_3.Out5 <-> ~Automation_Framework_LfE.hh_standstill,

# OperatorInterface
 Automation_OperatorInterface.ActivateLong -> ~Automation_Framework_LfE.sim_long_io,
 Automation_OperatorInterface.ActivateLat -> ~Automation_Framework_LfE.sim_lat_io,
 Automation_OperatorInterface.ActivateLatandLong -> ~Automation_Framework_LfE.sim_long_lat_io,
 Automation_OperatorInterface.Corrupt_Long -> ~Automation_Framework_LfE.sim_corrupt_long,
 Automation_OperatorInterface.Corrupt_Lat -> ~Automation_Framework_LfE.sim_corrupt_lat,
 Automation_OperatorInterface.Corrupt_LatandLong -> ~Automation_Framework_LfE.sim_corrupt_long_lat,
 Automation_OperatorInterface.Change_vSet_HMI -> ~Automation_Framework_LfE.sim_vset_hmi,
 Automation_OperatorInterface.Change_vSet_HMIandController -> ~Automation_Framework_LfE.sim_vset_contr_hmi,
 Automation_OperatorInterface.Change_vSet_Controller -> ~Automation_Framework_LfE.sim_vset_contr,
 Automation_OperatorInterface.Change_vLim -> ~Automation_Framework_LfE.sim_set_vlim,
 Automation_OperatorInterface.Change_GapSet_HMI -> ~Automation_Framework_LfE.sim_set_gap_hmi,
 Automation_OperatorInterface.Change_GapSet_Controller -> ~Automation_Framework_LfE.sim_set_gap_contr,
 Automation_OperatorInterface.Change_GapSet_HMIandController -> ~Automation_Framework_LfE.sim_set_gap_contr_hmi,
 Automation_OperatorInterface.Trigger_LaneChange_Left -> ~Automation_Framework_LfE.sim_lc_left,
 Automation_OperatorInterface.Trigger_LaneChange_Right -> ~Automation_Framework_LfE.sim_lc_right,
 Automation_OperatorInterface.Trigger_LaneChange_Abort -> ~Automation_Framework_LfE.sim_lc_abort,
 Automation_OperatorInterface.Change_LaneChange_Time -> ~Automation_Framework_LfE.sim_lc_time,
 Automation_OperatorInterface.Trigger_StandStill -> ~Automation_Framework_LfE.sim_standstill,
 
 ~Automation_Framework_LfE.active_lat -> Automation_OperatorInterface.StateLat,
 ~Automation_Framework_LfE.active_long -> Automation_OperatorInterface.StateLong,
 ~Automation_Framework_LfE.active_lat_and_long -> Automation_OperatorInterface.StateLatAndLong,
 ~Automation_Framework_LfE.vset_controller_kmph -> Automation_OperatorInterface.Value_vSet_Controller,
 ~Automation_Framework_LfE.vset_hmi_kmph -> Automation_OperatorInterface.Value_vSet_HMI,
 ~Automation_Framework_LfE.vlim_kmph -> Automation_OperatorInterface.Value_vLim,
 ~Automation_Framework_LfE.gap_set_controller_s -> Automation_OperatorInterface.Value_Gap_Controller,
 ~Automation_Framework_LfE.gap_set_hmi_s -> Automation_OperatorInterface.Value_Gap_HMI,
 ~Automation_Framework_LfE.lc_time -> Automation_OperatorInterface.Value_LaneChange_Time,
 ~MacAdamLAC.LaneChange_State -> Automation_OperatorInterface.State_LaneChange,
 ~Automation_Framework_LfE.standstill -> Automation_OperatorInterface.State_StandStill
		
  
};


