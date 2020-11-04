//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_DEADRECKONING_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_DEADRECKONING_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Deadreckoning_ParamsData VisualizationMono_Algorithm_Deadreckoning_ParamsData
	\ingroup VisualizationMono_Algorithm_Deadreckoning
	\brief VisualizationMono_Algorithm_Deadreckoning_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Deadreckoning.
*/

/*! \addtogroup VisualizationMono_Algorithm_Deadreckoning_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Deadreckoning_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Deadreckoning
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Algorithm_Deadreckoning_Params and Input Data ProcessorMulti_Algorithm_Deadreckoning_Data
#include<example1_module/Algorithm/Deadreckoning/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Deadreckoning_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Deadreckoning_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Algorithm_Deadreckoning_Params, Data_Type = ProcessorMulti_Algorithm_Deadreckoning_Data
*/
#define VisualizationMono_Algorithm_Deadreckoning_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Deadreckoning_Params 
	\brief The Params of VisualizationMono_Algorithm_Deadreckoning.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Deadreckoning_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Deadreckoning_Params()
		\brief The constructor of VisualizationMono_Algorithm_Deadreckoning_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Deadreckoning_Params() 
	{	
        mapWidth=60;
        mapHeight=60;
        mapZeroX=-100;
        mapZeroY=-100;
        mapPixelSize=0.10;
        mapGrid=10;
	}
	/*! \fn ~VisualizationMono_Algorithm_Deadreckoning_Params()
		\brief The destructor of VisualizationMono_Algorithm_Deadreckoning_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Deadreckoning_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	//地图显示的范围，单位为m
    double mapWidth;
    double mapHeight;
	//设置坐标点在图像坐标系中的偏移像素数：
		//图像坐标系有:
		//0---------------------->x+
		//|
		//|
		//|
		//|
		//|
		//|
		//|
		//|
		//\/y+
    double mapZeroX;
    double mapZeroY;
    double mapPixelSize;//像素尺度，每像素代表的实际距离值
    double mapGrid;//网格宽，单位m
};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Deadreckoning_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Deadreckoning_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
