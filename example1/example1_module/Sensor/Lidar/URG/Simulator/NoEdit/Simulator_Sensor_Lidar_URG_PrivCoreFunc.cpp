//Generally you need not to program this file.

#include "Simulator_Sensor_Lidar_URG_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=Simulator_Sensor_Lidar_URG_INPUTPORTSSIZE;
	outputPortsNumber=Simulator_Sensor_Lidar_URG_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new Simulator_Sensor_Lidar_URG_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new Simulator_Sensor_Lidar_URG_Vars());
	/*======No Need to Program======*/
}

