//You need not to modify this file.

/*! \defgroup VisualizationMono_Algorithm_Mapping VisualizationMono_Algorithm_Mapping
	\ingroup VisualizationMono_Library Algorithm_Mapping_NodeClass
	\brief VisualizationMono_Algorithm_Mapping defines the Algorithm_Mapping in VisualizationMono.
*/

#ifndef VISUALIZATIONMONO_ALGORITHM_MAPPING_PRIVCOREFUNC_H
#define VISUALIZATIONMONO_ALGORITHM_MAPPING_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Mapping_PrivCoreFunc VisualizationMono_Algorithm_Mapping_PrivCoreFunc
	\ingroup VisualizationMono_Algorithm_Mapping
	\brief VisualizationMono_Algorithm_Mapping_PrivCoreFunc defines the PrivCoreFunc in VisualizationMono_Algorithm_Mapping.
*/

/*! \addtogroup VisualizationMono_Algorithm_Mapping_PrivCoreFunc
	@{
*/

/*! \file VisualizationMono_Algorithm_Mapping_PrivCoreFunc.h
	 Defines the PrivCoreFunc of VisualizationMono_Algorithm_Mapping
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMono_Algorithm_Mapping_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMono_Algorithm_Mapping

/*! void VisualizationMono_Algorithm_Mapping_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void VisualizationMono_Algorithm_Mapping_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void VisualizationMono_Algorithm_Mapping_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif