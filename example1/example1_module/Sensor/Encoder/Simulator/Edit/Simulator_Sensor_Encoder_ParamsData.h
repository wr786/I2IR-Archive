//You need to modify this file.

#ifndef SIMULATOR_SENSOR_ENCODER_PARAMSDATA_H
#define SIMULATOR_SENSOR_ENCODER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Encoder_ParamsData Simulator_Sensor_Encoder_ParamsData
	\ingroup Simulator_Sensor_Encoder
	\brief Simulator_Sensor_Encoder_ParamsData defines the ParamsData in Simulator_Sensor_Encoder.
*/

/*! \addtogroup Simulator_Sensor_Encoder_ParamsData
	@{
*/

/*! \file Simulator_Sensor_Encoder_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_Encoder
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_Encoder_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_Encoder_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_Encoder_Params 
	\brief The Params of Simulator_Sensor_Encoder.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Encoder_Params 
{
public:
	/*! \fn Simulator_Sensor_Encoder_Params()
		\brief The constructor of Simulator_Sensor_Encoder_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Encoder_Params() 
	{
        disPerPulse=0.003846154;//每个脉冲代表的距离值，如当前两帧脉冲差为20，走过的距离即为disPerPulse*20 (m)
        pulseMax=30000;//最大脉冲数，编码器返回脉冲数达到该值即清零重新计数
	}
	/*! \fn ~Simulator_Sensor_Encoder_Params()
		\brief The destructor of Simulator_Sensor_Encoder_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Encoder_Params() 
	{

	}
public:
	//*******************Please add variables below*******************
    double disPerPulse;
    int pulseMax;

};
//The Output Data is defined as below
/*! \class Simulator_Sensor_Encoder_Data 
	\brief The Data of Simulator_Sensor_Encoder.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Encoder_Data 
{
public:
	/*! \fn Simulator_Sensor_Encoder_Data()
		\brief The constructor of Simulator_Sensor_Encoder_Data. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Encoder_Data() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_Encoder_Data()
		\brief The destructor of Simulator_Sensor_Encoder_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Encoder_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************

    long timestamp;
    int pulse;//脉冲数
};

/*! \def Simulator_Sensor_Encoder_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_Encoder_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
