//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_MAPPING_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_MAPPING_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Mapping_Vars VisualizationMono_Algorithm_Mapping_Vars
	\ingroup VisualizationMono_Algorithm_Mapping
	\brief VisualizationMono_Algorithm_Mapping_Vars defines the Vars in VisualizationMono_Algorithm_Mapping.
*/

/*! \addtogroup VisualizationMono_Algorithm_Mapping_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Mapping_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Mapping
*/

//*******************Please add other headers below*******************
#include <opencv/cv.h>
#include<opencv/cxcore.h>
#include <opencv/highgui.h>
#include "../example1_module/Algorithm/Deadreckoning/VisualizationMono/Mat2img.h"
#include "VisualizationMono_Algorithm_Mapping_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Mapping_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Mapping.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Mapping_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Mapping_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Mapping_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Mapping_Vars() 
	{
        image = new QLabel();
        image->setAlignment(Qt::AlignCenter);
        
	}
	/*! \fn ~VisualizationMono_Algorithm_Mapping_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Mapping_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Mapping_Vars() 
	{
        if(image->parent() == NULL)
                {
                    delete image;
                }
	}
public:
	//*******************Please add variables below*******************
    char * map;
    QLabel * image;
	//累计地图
    cv::Mat lasermap;
	//实时显示的地图
    cv::Mat mapshow;
    bool init;

};

/*! @}*/ 

#endif
