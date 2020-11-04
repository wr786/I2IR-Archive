//You need to modify this file.

#ifndef SIMULATOR_SENSOR_IMU_VARS_H
#define SIMULATOR_SENSOR_IMU_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_IMU_Vars Simulator_Sensor_IMU_Vars
	\ingroup Simulator_Sensor_IMU
	\brief Simulator_Sensor_IMU_Vars defines the Vars in Simulator_Sensor_IMU.
*/

/*! \addtogroup Simulator_Sensor_IMU_Vars
	@{
*/

/*! \file Simulator_Sensor_IMU_Vars.h
	 Defines the Vars of Simulator_Sensor_IMU
*/

//*******************Please add other headers below*******************
#include <fstream>

#include "Simulator_Sensor_IMU_ParamsData.h"

//The Vars is defined as below
/*! \class Simulator_Sensor_IMU_Vars 
	\brief The Vars of Simulator_Sensor_IMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_IMU_Vars 
{
public:
	/*! \fn Simulator_Sensor_IMU_Vars()
		\brief The constructor of Simulator_Sensor_IMU_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_IMU_Vars() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_IMU_Vars()
		\brief The destructor of Simulator_Sensor_IMU_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_IMU_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************

    QString path;
    QString name;
    std::ifstream file;
};

/*! @}*/ 

#endif
