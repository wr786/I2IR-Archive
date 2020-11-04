//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_MAPPING_PARAMSDATA_H
#define PROCESSORMULTI_ALGORITHM_MAPPING_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Mapping_ParamsData ProcessorMulti_Algorithm_Mapping_ParamsData
	\ingroup ProcessorMulti_Algorithm_Mapping
	\brief ProcessorMulti_Algorithm_Mapping_ParamsData defines the ParamsData in ProcessorMulti_Algorithm_Mapping.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Mapping_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algorithm_Mapping_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algorithm_Mapping
*/

//*******************Please add other headers below*******************
#include "transform.h"

//2 input data header(s) refered

//Defines Params ProcessorMulti_Algorithm_Deadreckoning_Params and Input Data ProcessorMulti_Algorithm_Deadreckoning_Data
#include<example1_module/Algorithm/Deadreckoning/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Deadreckoning_ParamsData.h>
//Defines Params Simulator_Sensor_Lidar_URG_Params and Input Data Simulator_Sensor_Lidar_URG_Data
#include<example1_module/Sensor/Lidar/URG/Simulator/Edit/Simulator_Sensor_Lidar_URG_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algorithm_Mapping_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Algorithm_Deadreckoning_Params, Data_Type = ProcessorMulti_Algorithm_Deadreckoning_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = Simulator_Sensor_Lidar_URG_Params, Data_Type = Simulator_Sensor_Lidar_URG_Data
*/
#define ProcessorMulti_Algorithm_Mapping_INPUTPORTSSIZE QList<int>()<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Algorithm_Mapping_Params 
	\brief The Params of ProcessorMulti_Algorithm_Mapping.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Mapping_Params 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Mapping_Params()
		\brief The constructor of ProcessorMulti_Algorithm_Mapping_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Mapping_Params() 
	{
        mapWidth = 600;//构造函数中赋值可以让SDK自动往XML文件中写一个默认值
        mapHeight = 600;
        zeroX = -100;
        zeroY = -500;
        mapRes = 0.100000;
        mapGrid=10;
	}
	/*! \fn ~ProcessorMulti_Algorithm_Mapping_Params()
		\brief The destructor of ProcessorMulti_Algorithm_Mapping_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Mapping_Params() 
	{

	}
public:
	//*******************Please add variables below*******************
    int mapWidth;//地图宽 单位 pixel
    int mapHeight;//地图高 单位 pixel
    int zeroX;//图像左上角x坐标 单位 pixel
    int zeroY;//图像左上角y坐标 单位 pixel
    double mapRes;//每个像素大小  单位 m/pixel
    double mapGrid;//网格宽度 单位 m

};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algorithm_Mapping_Data 
	\brief The Data of ProcessorMulti_Algorithm_Mapping.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Mapping_Data 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Mapping_Data()
		\brief The constructor of ProcessorMulti_Algorithm_Mapping_Data. [required]
		\details ****Please add details below****

	*/
    ProcessorMulti_Algorithm_Mapping_Data(int w, int h)
	{
        width = w;
        height = h;
        if(width > 0 && height > 0)
                {
                    map = new unsigned char * [height];//列优先
                    for(int i = 0 ; i < height ; i ++)
                    {
                        map[i] = new unsigned char [width];
                    }
                }
                else
                {
                    map = NULL;
                }
	}
	/*! \fn ~ProcessorMulti_Algorithm_Mapping_Data()
		\brief The destructor of ProcessorMulti_Algorithm_Mapping_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Mapping_Data() 
	{
        if(map != NULL)
            {
                for(int i = 0 ; i < height ; i ++)
                {
                    delete map[i];
                }
                delete [] map;
                map = NULL;
            }
	}
public:
	//*******************Please add variables below*******************

        unsigned char ** map;//地图指针
        int width;//不得不再存一份，因为析构的时候需要用
        int height;
        long timestamp_laser,timestamp_deadreconing;
        int mapX ,mapY;

};

/*! \def ProcessorMulti_Algorithm_Mapping_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algorithm_Mapping_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
