//You need to modify this file.

#ifndef STORAGEMONO_ALGORITHM_DEADRECKONING_VARS_H
#define STORAGEMONO_ALGORITHM_DEADRECKONING_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Algorithm_Deadreckoning_Vars StorageMono_Algorithm_Deadreckoning_Vars
	\ingroup StorageMono_Algorithm_Deadreckoning
	\brief StorageMono_Algorithm_Deadreckoning_Vars defines the Vars in StorageMono_Algorithm_Deadreckoning.
*/

/*! \addtogroup StorageMono_Algorithm_Deadreckoning_Vars
	@{
*/

/*! \file StorageMono_Algorithm_Deadreckoning_Vars.h
	 Defines the Vars of StorageMono_Algorithm_Deadreckoning
*/

//*******************Please add other headers below*******************

#include<fstream>
#include "StorageMono_Algorithm_Deadreckoning_ParamsData.h"

//The Vars is defined as below
/*! \class StorageMono_Algorithm_Deadreckoning_Vars 
	\brief The Vars of StorageMono_Algorithm_Deadreckoning.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Algorithm_Deadreckoning_Vars 
{
public:
	/*! \fn StorageMono_Algorithm_Deadreckoning_Vars()
		\brief The constructor of StorageMono_Algorithm_Deadreckoning_Vars. [required]
		\details ****Please add details below****

	*/
	StorageMono_Algorithm_Deadreckoning_Vars() 
	{
		
	}
	/*! \fn ~StorageMono_Algorithm_Deadreckoning_Vars()
		\brief The destructor of StorageMono_Algorithm_Deadreckoning_Vars. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Algorithm_Deadreckoning_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************

    QString path;
    QString name;
    std::ofstream posFile;
};

/*! @}*/ 

#endif
