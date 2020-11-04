//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_DEADRECKONING_VARS_H
#define PROCESSORMULTI_ALGORITHM_DEADRECKONING_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Deadreckoning_Vars ProcessorMulti_Algorithm_Deadreckoning_Vars
	\ingroup ProcessorMulti_Algorithm_Deadreckoning
	\brief ProcessorMulti_Algorithm_Deadreckoning_Vars defines the Vars in ProcessorMulti_Algorithm_Deadreckoning.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Deadreckoning_Vars
	@{
*/

/*! \file ProcessorMulti_Algorithm_Deadreckoning_Vars.h
	 Defines the Vars of ProcessorMulti_Algorithm_Deadreckoning
*/

//*******************Please add other headers below*******************


#include "ProcessorMulti_Algorithm_Deadreckoning_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Algorithm_Deadreckoning_Vars 
	\brief The Vars of ProcessorMulti_Algorithm_Deadreckoning.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Deadreckoning_Vars 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Deadreckoning_Vars()
		\brief The constructor of ProcessorMulti_Algorithm_Deadreckoning_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Deadreckoning_Vars() 
	{

        lastpulsenum=-1;
        initOriValue=0;
        isInit=false;

	}
	/*! \fn ~ProcessorMulti_Algorithm_Deadreckoning_Vars()
		\brief The destructor of ProcessorMulti_Algorithm_Deadreckoning_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Deadreckoning_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    //定义初始位置坐标，使之与轨迹图坐标对齐，参见配置文件config.xml设置
    double initx;
    double inity;
    double initori;
    //上一帧数据
    double lastx;
    double lasty;
    double lastori;
    short lastpulsenum;//用来判断溢出
    QTime qlasttimestamp;
    bool isInit;//判断是否为首帧数据
    double initOriValue;//航向角初始值
    const double PI=3.1415926535;
};

/*! @}*/ 

#endif
