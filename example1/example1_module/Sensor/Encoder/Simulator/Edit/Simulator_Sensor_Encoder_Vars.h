//You need to modify this file.

#ifndef SIMULATOR_SENSOR_ENCODER_VARS_H
#define SIMULATOR_SENSOR_ENCODER_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Encoder_Vars Simulator_Sensor_Encoder_Vars
	\ingroup Simulator_Sensor_Encoder
	\brief Simulator_Sensor_Encoder_Vars defines the Vars in Simulator_Sensor_Encoder.
*/

/*! \addtogroup Simulator_Sensor_Encoder_Vars
	@{
*/

/*! \file Simulator_Sensor_Encoder_Vars.h
	 Defines the Vars of Simulator_Sensor_Encoder
*/

//*******************Please add other headers below*******************
#include <fstream>

#include "Simulator_Sensor_Encoder_ParamsData.h"

//The Vars is defined as below
/*! \class Simulator_Sensor_Encoder_Vars 
	\brief The Vars of Simulator_Sensor_Encoder.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Encoder_Vars 
{
public:
	/*! \fn Simulator_Sensor_Encoder_Vars()
		\brief The constructor of Simulator_Sensor_Encoder_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Encoder_Vars() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_Encoder_Vars()
		\brief The destructor of Simulator_Sensor_Encoder_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Encoder_Vars() 
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
