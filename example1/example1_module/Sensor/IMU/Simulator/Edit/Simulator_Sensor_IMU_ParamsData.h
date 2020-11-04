//You need to modify this file.

#ifndef SIMULATOR_SENSOR_IMU_PARAMSDATA_H
#define SIMULATOR_SENSOR_IMU_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_IMU_ParamsData Simulator_Sensor_IMU_ParamsData
	\ingroup Simulator_Sensor_IMU
	\brief Simulator_Sensor_IMU_ParamsData defines the ParamsData in Simulator_Sensor_IMU.
*/

/*! \addtogroup Simulator_Sensor_IMU_ParamsData
	@{
*/

/*! \file Simulator_Sensor_IMU_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_IMU
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_IMU_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_IMU_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_IMU_Params 
	\brief The Params of Simulator_Sensor_IMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_IMU_Params 
{
public:
	/*! \fn Simulator_Sensor_IMU_Params()
		\brief The constructor of Simulator_Sensor_IMU_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_IMU_Params() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_IMU_Params()
		\brief The destructor of Simulator_Sensor_IMU_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_IMU_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class Simulator_Sensor_IMU_Data 
	\brief The Data of Simulator_Sensor_IMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_IMU_Data 
{
public:
	/*! \fn Simulator_Sensor_IMU_Data()
		\brief The constructor of Simulator_Sensor_IMU_Data. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_IMU_Data() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_IMU_Data()
		\brief The destructor of Simulator_Sensor_IMU_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_IMU_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************

    long timestamp;
	//仅需要使用IMU的偏航角数据
    double yaw;
};

/*! \def Simulator_Sensor_IMU_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_IMU_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
