//Generally you need not to program this file.

#include "VisualizationMono_Algorithm_Mapping_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMono_Algorithm_Mapping_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMono_Algorithm_Mapping_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMono_Algorithm_Mapping_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMono_Algorithm_Mapping_Vars());
	/*======No Need to Program======*/
}

