//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_CORE_VARS_H
#define PROCESSORMULTI_PROCESSOR_CORE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_Core_Vars ProcessorMulti_Processor_Core_Vars
	\ingroup ProcessorMulti_Processor_Core
	\brief ProcessorMulti_Processor_Core_Vars defines the Vars in ProcessorMulti_Processor_Core.
*/

/*! \addtogroup ProcessorMulti_Processor_Core_Vars
	@{
*/

/*! \file ProcessorMulti_Processor_Core_Vars.h
	 Defines the Vars of ProcessorMulti_Processor_Core
*/

//*******************Please add other headers below*******************


#include "ProcessorMulti_Processor_Core_ParamsData.h"
#include "PIDControler.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Processor_Core_Vars 
	\brief The Vars of ProcessorMulti_Processor_Core.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_Core_Vars 
{
public:
	/*! \fn ProcessorMulti_Processor_Core_Vars()
		\brief The constructor of ProcessorMulti_Processor_Core_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_Core_Vars() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_Core_Vars()
		\brief The destructor of ProcessorMulti_Processor_Core_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_Core_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    PIDControler pid;
    bool reverse = false;
    double prev_odom;
    int baseSteer = 40;
    int filterRange = 5;
    short k_p = 20;
    short k_i = 0;
    short k_d = 13;
    int straightThreshold = 30;
    int straightSpeed = 150;
    int infDistance = 17867;
    int backwardDistance = 50;
    int safeAngle = 45;
    int safeDistance = 50;
    int forwardDetectRange = 5;
};

/*! @}*/ 

#endif
