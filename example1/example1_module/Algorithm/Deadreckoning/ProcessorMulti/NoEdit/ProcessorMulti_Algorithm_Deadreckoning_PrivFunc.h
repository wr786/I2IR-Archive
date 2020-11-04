//You need not to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_DEADRECKONING_PRIVFUNC_H
#define PROCESSORMULTI_ALGORITHM_DEADRECKONING_PRIVFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Deadreckoning_PrivFunc ProcessorMulti_Algorithm_Deadreckoning_PrivFunc
	\ingroup ProcessorMulti_Algorithm_Deadreckoning
	\brief ProcessorMulti_Algorithm_Deadreckoning_PrivFunc defines the PrivFunc in ProcessorMulti_Algorithm_Deadreckoning.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Deadreckoning_PrivFunc
	@{
*/

/*! \file ProcessorMulti_Algorithm_Deadreckoning_PrivFunc.h
	 Defines the PrivFunc of ProcessorMulti_Algorithm_Deadreckoning
*/

//*******************Please add other headers below*******************


#include "../Edit/ProcessorMulti_Algorithm_Deadreckoning_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG ProcessorMulti_Algorithm_Deadreckoning

/*! bool ProcessorMulti_Algorithm_Deadreckoning_setParamsVarsOpenNode(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
	\brief [required] Function pointer type for interface function of setting node's parameters and variables while openning node.
	\param [in] qstrConfigName The config-name of the node.
	\param [in] qstrNodeType The type-name of the node.
	\param [in] qstrNodeClass The class-name of the node.
	\param [in] qstrNodeName The node-name of the node.
	\param [in,out] paramsPtr The parameters(\ref Node::paramsptr) to be loaded.
	\param [in,out] varsPtr The variables(\ref Node::varsptr) to be set
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr);

/*! bool ProcessorMulti_Algorithm_Deadreckoning_handleVarsCloseNode(void * paramsPtr, void * varsPtr)
	\brief [required] Function pointer type for interface function of handling node's variables while closing node.
	\param [in] paramsPtr The parameters(\ref Node::paramsptr) for setting variables.
	\param [in,out] varsPtr The variables(\ref Node::varsptr) to be handled
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr);

/*! void ProcessorMulti_Algorithm_Deadreckoning_getInternalTrigger(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
	\brief [optional] Function pointer type for interface function of getting node's internal trigger.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr) that contains internal trigger.
	\param [out] internalTrigger The internal trigger.
	\param [out] internalTriggerSignal The internal trigger signal embelished by QString.
	\details To embelish internal trigger signal:
	- QString(SIGNAL(<internal trigger signal>));
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal);

/*! void ProcessorMulti_Algorithm_Deadreckoning_initializeOutputData(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
	\brief [required] Function pointer type for interface function of initializing node's output data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] outputDataPtr The output data embelished by boost::shared_pointer<void>.
	\details To initialize output data:
	- outputDataPtr=boost::shared_ptr<void> (new OutputDataType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr);

/*! void ProcessorMulti_Algorithm_Deadreckoning_getMultiInputDataSize(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
	\brief [required] Function pointer type for interface function of getting multi input data size.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] inputDataSize The required multi input data size. (see InputNode::grabInputData(int grabSize))
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize);

/*! bool ProcessorMulti_Algorithm_Deadreckoning_processMultiInputData(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
	\brief [required] Function pointer type for interface function of processing multi input data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [in] inputParams The multi input parameters of input node.
	\param [in] inputData The multi input data of input node.
	\param [out] outputData The output data.
	\param [out] outputPortIndex The index of output port to send output data.
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex);

/*! @}*/ 

#endif