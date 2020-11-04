//You need to modify this file.

#ifndef STORAGEMONO_ALGORITHM_DEADRECKONING_PARAMSDATA_H
#define STORAGEMONO_ALGORITHM_DEADRECKONING_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Algorithm_Deadreckoning_ParamsData StorageMono_Algorithm_Deadreckoning_ParamsData
	\ingroup StorageMono_Algorithm_Deadreckoning
	\brief StorageMono_Algorithm_Deadreckoning_ParamsData defines the ParamsData in StorageMono_Algorithm_Deadreckoning.
*/

/*! \addtogroup StorageMono_Algorithm_Deadreckoning_ParamsData
	@{
*/

/*! \file StorageMono_Algorithm_Deadreckoning_ParamsData.h
	 Defines the ParamsData of StorageMono_Algorithm_Deadreckoning
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Algorithm_Deadreckoning_Params and Input Data ProcessorMulti_Algorithm_Deadreckoning_Data
#include<example1_module/Algorithm/Deadreckoning/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Deadreckoning_ParamsData.h>

//0 new input data type(s) created

/*! \def StorageMono_Algorithm_Deadreckoning_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Algorithm_Deadreckoning_Params, Data_Type = ProcessorMulti_Algorithm_Deadreckoning_Data
*/
#define StorageMono_Algorithm_Deadreckoning_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class StorageMono_Algorithm_Deadreckoning_Params 
	\brief The Params of StorageMono_Algorithm_Deadreckoning.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Algorithm_Deadreckoning_Params 
{
public:
	/*! \fn StorageMono_Algorithm_Deadreckoning_Params()
		\brief The constructor of StorageMono_Algorithm_Deadreckoning_Params. [required]
		\details ****Please add details below****

	*/
	StorageMono_Algorithm_Deadreckoning_Params() 
	{
		
	}
	/*! \fn ~StorageMono_Algorithm_Deadreckoning_Params()
		\brief The destructor of StorageMono_Algorithm_Deadreckoning_Params. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Algorithm_Deadreckoning_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def StorageMono_Algorithm_Deadreckoning_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define StorageMono_Algorithm_Deadreckoning_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif