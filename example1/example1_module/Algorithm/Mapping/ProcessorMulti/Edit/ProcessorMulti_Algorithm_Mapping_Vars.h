//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_MAPPING_VARS_H
#define PROCESSORMULTI_ALGORITHM_MAPPING_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Mapping_Vars ProcessorMulti_Algorithm_Mapping_Vars
	\ingroup ProcessorMulti_Algorithm_Mapping
	\brief ProcessorMulti_Algorithm_Mapping_Vars defines the Vars in ProcessorMulti_Algorithm_Mapping.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Mapping_Vars
	@{
*/

/*! \file ProcessorMulti_Algorithm_Mapping_Vars.h
	 Defines the Vars of ProcessorMulti_Algorithm_Mapping
*/

//*******************Please add other headers below*******************


#include "ProcessorMulti_Algorithm_Mapping_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Algorithm_Mapping_Vars 
	\brief The Vars of ProcessorMulti_Algorithm_Mapping.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Mapping_Vars 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Mapping_Vars()
		\brief The constructor of ProcessorMulti_Algorithm_Mapping_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Mapping_Vars() 
	{
        map = NULL;
	}
	/*! \fn ~ProcessorMulti_Algorithm_Mapping_Vars()
		\brief The destructor of ProcessorMulti_Algorithm_Mapping_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Mapping_Vars() 
	{

	}
public:
	//*******************Please add variables below*******************
    unsigned char ** map;
};

/*! @}*/ 

#endif
