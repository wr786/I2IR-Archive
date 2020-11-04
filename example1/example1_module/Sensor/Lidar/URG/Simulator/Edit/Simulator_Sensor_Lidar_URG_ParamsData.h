//You need to modify this file.

#ifndef SIMULATOR_SENSOR_LIDAR_URG_PARAMSDATA_H
#define SIMULATOR_SENSOR_LIDAR_URG_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Lidar_URG_ParamsData Simulator_Sensor_Lidar_URG_ParamsData
	\ingroup Simulator_Sensor_Lidar_URG
	\brief Simulator_Sensor_Lidar_URG_ParamsData defines the ParamsData in Simulator_Sensor_Lidar_URG.
*/

/*! \addtogroup Simulator_Sensor_Lidar_URG_ParamsData
	@{
*/

/*! \file Simulator_Sensor_Lidar_URG_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_Lidar_URG
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_Lidar_URG_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_Lidar_URG_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_Lidar_URG_Params 
	\brief The Params of Simulator_Sensor_Lidar_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Lidar_URG_Params 
{
public:
	/*! \fn Simulator_Sensor_Lidar_URG_Params()
		\brief The constructor of Simulator_Sensor_Lidar_URG_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Lidar_URG_Params() 
	{
        nearfilter=5;
        farfilter=3000;
		
	}
	/*! \fn ~Simulator_Sensor_Lidar_URG_Params()
		\brief The destructor of Simulator_Sensor_Lidar_URG_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Lidar_URG_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

    short nearfilter;//滤除距离返回值过小的点
    short farfilter;//滤除距离返回值过大的点
    double rng;//激光角度范围
    double res;//角度分辨最小单位
    double unit;//激光测距值与真实距离的比例关系，如返回值为100，距离值应为100/unit=100/100=1m
};

//The Output Data is defined as below
/*! \class Simulator_Sensor_Lidar_URG_Data 
	\brief The Data of Simulator_Sensor_Lidar_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Lidar_URG_Data 
{
public:
	/*! \fn Simulator_Sensor_Lidar_URG_Data()
		\brief The constructor of Simulator_Sensor_Lidar_URG_Data. [required]
		\details ****Please add details below****

	*/
    Simulator_Sensor_Lidar_URG_Data(int dataSize)
	{
        datasize=dataSize;
        if(datasize>0){
            data=new short[dataSize];
        }
        else{
            data=NULL;
        }
	}
	/*! \fn ~Simulator_Sensor_Lidar_URG_Data()
		\brief The destructor of Simulator_Sensor_Lidar_URG_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Lidar_URG_Data() 
	{
        if(data!=NULL){
            delete []data;
            data=NULL;
        }
	}
public:
	//*******************Please add variables below*******************

    long timestamp;
    int datasize;//jiguangshushuliang
    short *data;//shujuzhizhen
};

/*! \def Simulator_Sensor_Lidar_URG_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_Lidar_URG_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
