//You need to program this file.

#include "../NoEdit/Simulator_Sensor_IMU_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Sensor_IMU_Params * params=(Simulator_Sensor_IMU_Params *)paramsPtr;
	Simulator_Sensor_IMU_Vars * vars=(Simulator_Sensor_IMU_Vars *)varsPtr;
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
    vars->file.open(QString("%1/%2").arg(vars->path).arg(vars->name).toStdString().c_str(),std::ios::in);
    return vars->file.is_open();
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Sensor_IMU_Params * params=(Simulator_Sensor_IMU_Params *)paramsPtr;
	Simulator_Sensor_IMU_Vars * vars=(Simulator_Sensor_IMU_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->file.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	Simulator_Sensor_IMU_Params * params=(Simulator_Sensor_IMU_Params *)paramsPtr;
	Simulator_Sensor_IMU_Vars * vars=(Simulator_Sensor_IMU_Vars *)varsPtr;
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

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	Simulator_Sensor_IMU_Params * params=(Simulator_Sensor_IMU_Params *)paramsPtr;
	Simulator_Sensor_IMU_Vars * vars=(Simulator_Sensor_IMU_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new Simulator_Sensor_IMU_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Sensor_IMU_Params * params=(Simulator_Sensor_IMU_Params *)paramsPtr;
	Simulator_Sensor_IMU_Vars * vars=(Simulator_Sensor_IMU_Vars *)varsPtr;
	Simulator_Sensor_IMU_Data * outputdata=(Simulator_Sensor_IMU_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    char ctmp;
    double dtmp;
    if(vars->file.eof())
        return 0;
    vars->file>>ctmp;
    vars->file>>ctmp;
    vars->file>>ctmp;
    vars->file>>outputdata->timestamp;
    vars->file>>dtmp;
    vars->file>>dtmp;
    vars->file>>dtmp;
    vars->file>>dtmp;
    vars->file>>outputdata->yaw;
	outputdata->yaw=-outputdata->yaw;
   // std::cout<<outputdata->timestamp<<" "<<outputdata->yaw<<std::endl;
    timeStamp=QTime::fromMSecsSinceStartOfDay(outputdata->timestamp);
	return 1;
}

