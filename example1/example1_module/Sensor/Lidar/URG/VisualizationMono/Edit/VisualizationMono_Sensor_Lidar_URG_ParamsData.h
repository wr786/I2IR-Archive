//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_LIDAR_URG_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_LIDAR_URG_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Lidar_URG_ParamsData VisualizationMono_Sensor_Lidar_URG_ParamsData
	\ingroup VisualizationMono_Sensor_Lidar_URG
	\brief VisualizationMono_Sensor_Lidar_URG_ParamsData defines the ParamsData in VisualizationMono_Sensor_Lidar_URG.
*/

/*! \addtogroup VisualizationMono_Sensor_Lidar_URG_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_Lidar_URG_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_Lidar_URG
*/

//*******************Please add other headers below*******************

#include<cmath>
//1 input data header(s) refered

//Defines Params Simulator_Sensor_Lidar_URG_Params and Input Data Simulator_Sensor_Lidar_URG_Data
#include<example1_module/Sensor/Lidar/URG/Simulator/Edit/Simulator_Sensor_Lidar_URG_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_Lidar_URG_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Sensor_Lidar_URG_Params, Data_Type = Simulator_Sensor_Lidar_URG_Data
*/
#define VisualizationMono_Sensor_Lidar_URG_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Sensor_Lidar_URG_Params 
	\brief The Params of VisualizationMono_Sensor_Lidar_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Lidar_URG_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_Lidar_URG_Params()
		\brief The constructor of VisualizationMono_Sensor_Lidar_URG_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Lidar_URG_Params() 
	{
        range=3000;
        interval=1000;
        imageradius=300;
        frontonly=1;
        laserbeam=1;
        angleinterval=60;
	}
	/*! \fn ~VisualizationMono_Sensor_Lidar_URG_Params()
		\brief The destructor of VisualizationMono_Sensor_Lidar_URG_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Lidar_URG_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

    short range;
    short interval;//环形网格线间隔宽度
    short angleinterval;//角度网格间隔
    int imageradius;//图片将要显示的激光半径（像素数
    bool frontonly;//是否只显示前侧
    bool laserbeam;//是否显示激光束/激光点


};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_Lidar_URG_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_Lidar_URG_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
