//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_MAPPING_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_MAPPING_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Mapping_ParamsData VisualizationMono_Algorithm_Mapping_ParamsData
	\ingroup VisualizationMono_Algorithm_Mapping
	\brief VisualizationMono_Algorithm_Mapping_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Mapping.
*/

/*! \addtogroup VisualizationMono_Algorithm_Mapping_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Mapping_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Mapping
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Algorithm_Mapping_Params and Input Data ProcessorMulti_Algorithm_Mapping_Data
#include<example1_module/Algorithm/Mapping/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Mapping_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Mapping_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Algorithm_Mapping_Params, Data_Type = ProcessorMulti_Algorithm_Mapping_Data
*/
#define VisualizationMono_Algorithm_Mapping_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Mapping_Params 
	\brief The Params of VisualizationMono_Algorithm_Mapping.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Mapping_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Mapping_Params()
		\brief The constructor of VisualizationMono_Algorithm_Mapping_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Mapping_Params() 
	{
        mapHeight=600;
        mapWidth=600;
        mapGrid=10;
        mapRes=0.1;
        zeroX=-100;
        zeroY=-100;
	}
	/*! \fn ~VisualizationMono_Algorithm_Mapping_Params()
		\brief The destructor of VisualizationMono_Algorithm_Mapping_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Mapping_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int mapHeight;
    int mapWidth;
    int mapGrid;
    double mapRes;
    int zeroX;
    int zeroY;
};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Mapping_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Mapping_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
