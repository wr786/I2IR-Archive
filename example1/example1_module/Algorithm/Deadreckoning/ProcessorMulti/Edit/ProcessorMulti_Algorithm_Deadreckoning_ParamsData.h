//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_DEADRECKONING_PARAMSDATA_H
#define PROCESSORMULTI_ALGORITHM_DEADRECKONING_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Deadreckoning_ParamsData ProcessorMulti_Algorithm_Deadreckoning_ParamsData
	\ingroup ProcessorMulti_Algorithm_Deadreckoning
	\brief ProcessorMulti_Algorithm_Deadreckoning_ParamsData defines the ParamsData in ProcessorMulti_Algorithm_Deadreckoning.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Deadreckoning_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algorithm_Deadreckoning_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algorithm_Deadreckoning
*/

//*******************Please add other headers below*******************
#include<cmath>

//2 input data header(s) refered

//Defines Params Simulator_Sensor_Encoder_Params and Input Data Simulator_Sensor_Encoder_Data
#include<example1_module/Sensor/Encoder/Simulator/Edit/Simulator_Sensor_Encoder_ParamsData.h>
//Defines Params Simulator_Sensor_IMU_Params and Input Data Simulator_Sensor_IMU_Data
#include<example1_module/Sensor/IMU/Simulator/Edit/Simulator_Sensor_IMU_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algorithm_Deadreckoning_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Sensor_Encoder_Params, Data_Type = Simulator_Sensor_Encoder_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = Simulator_Sensor_IMU_Params, Data_Type = Simulator_Sensor_IMU_Data
*/
#define ProcessorMulti_Algorithm_Deadreckoning_INPUTPORTSSIZE QList<int>()<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Algorithm_Deadreckoning_Params 
	\brief The Params of ProcessorMulti_Algorithm_Deadreckoning.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Deadreckoning_Params 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Deadreckoning_Params()
		\brief The constructor of ProcessorMulti_Algorithm_Deadreckoning_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Deadreckoning_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Deadreckoning_Params()
		\brief The destructor of ProcessorMulti_Algorithm_Deadreckoning_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Deadreckoning_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algorithm_Deadreckoning_Data 
	\brief The Data of ProcessorMulti_Algorithm_Deadreckoning.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Deadreckoning_Data 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Deadreckoning_Data()
		\brief The constructor of ProcessorMulti_Algorithm_Deadreckoning_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Deadreckoning_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Deadreckoning_Data()
		\brief The destructor of ProcessorMulti_Algorithm_Deadreckoning_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Deadreckoning_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************

    long timestamp;
	//姿态定义
    double x;
    double y;
    double orientation;
};

/*! \def ProcessorMulti_Algorithm_Deadreckoning_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algorithm_Deadreckoning_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
