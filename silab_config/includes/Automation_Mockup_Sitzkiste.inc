	
	Connections = 
{
	
	
	# Lenken direkt über Fahrdynamik
	#Mockup.SteeringWheel -> MacAdamLAC.SteeringWheelIn,
	#MacAdamLAC.SteeringWheelOut -> VDyn.SteeringWheel
	
	# Lenken über SensoWheel
	Mockup.SteeringWheel -> ~MacAdamLAC.SteeringWheelIn,
	~corrupt_lat.Out -> ~Steeringwheel.EnableWheelPositionControl,
	~MacAdamLAC.SteeringWheelOut -> ~Steeringwheel.ControlPosition,
	~Automation_Framework_LfE.active_lat -> ~SteeringwheelGainKlw.In,
	~SteeringwheelGainKlw.Out -> ~Steeringwheel.GainKlw,
	~Automation_Framework_LfE.active_lat -> ~Steeringwheel_i_SW_ControlPosition.In,
	~Steeringwheel_i_SW_ControlPosition.Out -> ~Steeringwheel.i_SW_ControlPosition,
	~Steeringwheel.WheelTorque -> ~Automation_Framework_LfE.steering_force
	
		
	# Buttons im Fahrsim verbinden


	

};