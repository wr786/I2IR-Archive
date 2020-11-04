//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_LIDAR_URG_VARS_H
#define VISUALIZATIONMONO_SENSOR_LIDAR_URG_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Lidar_URG_Vars VisualizationMono_Sensor_Lidar_URG_Vars
	\ingroup VisualizationMono_Sensor_Lidar_URG
	\brief VisualizationMono_Sensor_Lidar_URG_Vars defines the Vars in VisualizationMono_Sensor_Lidar_URG.
*/

/*! \addtogroup VisualizationMono_Sensor_Lidar_URG_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_Lidar_URG_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_Lidar_URG
*/

//*******************Please add other headers below*******************

#include <opencv2/opencv.hpp>
#include "VisualizationMono_Sensor_Lidar_URG_ParamsData.h"
#include "../example1_module/Algorithm/Deadreckoning/VisualizationMono/Mat2img.h"
//The Vars is defined as below
/*! \class VisualizationMono_Sensor_Lidar_URG_Vars 
	\brief The Vars of VisualizationMono_Sensor_Lidar_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Lidar_URG_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_Lidar_URG_Vars()
		\brief The constructor of VisualizationMono_Sensor_Lidar_URG_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Lidar_URG_Vars() 
	{
        beams=new QLabel();
        beams->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMono_Sensor_Lidar_URG_Vars()
		\brief The destructor of VisualizationMono_Sensor_Lidar_URG_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Lidar_URG_Vars() 
	{
        if(beams->parent()==NULL){
            delete beams;
        }
	}
public:
	//*******************Please add variables below*******************

    QLabel *beams;
	//图像坐标系下激光扫描的角度范围
    double startangle;
    double endangle;
    double resolution;
    cv::Mat laserMap;
    cv::Mat mapshow;
    bool init;

};

/*! @}*/ 

#endif
