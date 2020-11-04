//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_DEADRECKONING_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_DEADRECKONING_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Deadreckoning_Vars VisualizationMono_Algorithm_Deadreckoning_Vars
	\ingroup VisualizationMono_Algorithm_Deadreckoning
	\brief VisualizationMono_Algorithm_Deadreckoning_Vars defines the Vars in VisualizationMono_Algorithm_Deadreckoning.
*/

/*! \addtogroup VisualizationMono_Algorithm_Deadreckoning_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Deadreckoning_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Deadreckoning
*/

//*******************Please add other headers below*******************

#include <opencv/cv.h>
#include<opencv/cxcore.h>
#include <opencv/highgui.h>
#include "../example1_module/Algorithm/Deadreckoning/VisualizationMono/Mat2img.h"
#include "VisualizationMono_Algorithm_Deadreckoning_ParamsData.h"
#include <vector>
//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Deadreckoning_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Deadreckoning.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Deadreckoning_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Deadreckoning_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Deadreckoning_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Deadreckoning_Vars() 
	{
        track=new QLabel();
        track->setAlignment(Qt::AlignCenter);

        //lastpoint.x=-10000;
        //robottrack=new cv::Mat();
        //temprobottrack=new cv::Mat();
	}
	/*! \fn ~VisualizationMono_Algorithm_Deadreckoning_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Deadreckoning_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Deadreckoning_Vars() 
	{
        if(track->parent()==NULL){
            delete track;
        }
        // robottrack->release();
         //temprobottrack->release();

	}
public:
	//*******************Please add variables below*******************
    QLabel *track;
	//累计图像
    cv::Mat robottrack;
    cv::Point2d lastpoint;
	//实时显示图像
    cv::Mat temprobottrack;
	//初始状态标志
    bool init;
};

/*! @}*/ 

#endif
