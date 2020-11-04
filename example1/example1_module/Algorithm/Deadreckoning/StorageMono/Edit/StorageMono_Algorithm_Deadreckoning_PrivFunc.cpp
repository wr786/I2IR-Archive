//You need to program this file.

#include "../NoEdit/StorageMono_Algorithm_Deadreckoning_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	StorageMono_Algorithm_Deadreckoning_Params * params=(StorageMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	StorageMono_Algorithm_Deadreckoning_Vars * vars=(StorageMono_Algorithm_Deadreckoning_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,path);
     GetParamValue(xmlloader,vars,name);
     vars->posFile.open(QString("%1/%2").arg(vars->path).arg(vars->name).toStdString().c_str(),std::ios::out);
    return vars->posFile.is_open();
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	StorageMono_Algorithm_Deadreckoning_Params * params=(StorageMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	StorageMono_Algorithm_Deadreckoning_Vars * vars=(StorageMono_Algorithm_Deadreckoning_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->posFile.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	StorageMono_Algorithm_Deadreckoning_Params * params=(StorageMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	StorageMono_Algorithm_Deadreckoning_Vars * vars=(StorageMono_Algorithm_Deadreckoning_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	StorageMono_Algorithm_Deadreckoning_Params * params=(StorageMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	StorageMono_Algorithm_Deadreckoning_Vars * vars=(StorageMono_Algorithm_Deadreckoning_Vars *)varsPtr;
	drainDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Algorithm_Deadreckoning_Params, Data_Type = ProcessorMulti_Algorithm_Deadreckoning_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	StorageMono_Algorithm_Deadreckoning_Params * params=(StorageMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	StorageMono_Algorithm_Deadreckoning_Vars * vars=(StorageMono_Algorithm_Deadreckoning_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Deadreckoning_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Algorithm_Deadreckoning_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    int n=draindata.size();
    for(int i=n-1;i>=0;i--){
        vars->posFile<<draindata[i]->timestamp<<'\t'<<draindata[i]->x<<'\t'<<draindata[i]->y<<'\t'<<draindata[i]->orientation<<'\n';
    }
	return 1;
}

