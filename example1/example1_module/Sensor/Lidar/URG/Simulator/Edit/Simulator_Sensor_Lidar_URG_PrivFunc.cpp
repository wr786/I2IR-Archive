//You need to program this file.

#include "../NoEdit/Simulator_Sensor_Lidar_URG_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    Simulator_Sensor_Lidar_URG_Params * params=(Simulator_Sensor_Lidar_URG_Params *)paramsPtr;
    Simulator_Sensor_Lidar_URG_Vars * vars=(Simulator_Sensor_Lidar_URG_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    GetParamValue(xmlloader,vars,path);
    GetParamValue(xmlloader,vars,filename);
    GetParamValue(xmlloader,params,nearfilter);
    GetParamValue(xmlloader,params,farfilter);

    vars->file.setFileName(QString("%1/%2").arg(vars->path).arg(vars->filename));
    if(!vars->file.open(QIODevice::ReadOnly)){
        return 0;
    }

    float tmp[3];
    vars->file.read((char*)tmp,sizeof(float)*3);
    params->rng=tmp[0];
    params->res=tmp[1];
    params->unit=tmp[2];


    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    Simulator_Sensor_Lidar_URG_Params * params=(Simulator_Sensor_Lidar_URG_Params *)paramsPtr;
    Simulator_Sensor_Lidar_URG_Vars * vars=(Simulator_Sensor_Lidar_URG_Vars *)varsPtr;
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
    Simulator_Sensor_Lidar_URG_Params * params=(Simulator_Sensor_Lidar_URG_Params *)paramsPtr;
    Simulator_Sensor_Lidar_URG_Vars * vars=(Simulator_Sensor_Lidar_URG_Vars *)varsPtr;
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
    Simulator_Sensor_Lidar_URG_Params * params=(Simulator_Sensor_Lidar_URG_Params *)paramsPtr;
    Simulator_Sensor_Lidar_URG_Vars * vars=(Simulator_Sensor_Lidar_URG_Vars *)varsPtr;
    int beamnumber=params->rng/params->res+1;
    outputDataPtr=boost::shared_ptr<void>(new Simulator_Sensor_Lidar_URG_Data(beamnumber));
    /*======Occasionally Program below/above======*/
    /*
    Function: initial output data.
    You need to program here when you need to manually initialize output data.
    */

}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
    Simulator_Sensor_Lidar_URG_Params * params=(Simulator_Sensor_Lidar_URG_Params *)paramsPtr;
    Simulator_Sensor_Lidar_URG_Vars * vars=(Simulator_Sensor_Lidar_URG_Vars *)varsPtr;
    Simulator_Sensor_Lidar_URG_Data * outputdata=(Simulator_Sensor_Lidar_URG_Data *)outputData;
    outputPortIndex=QList<int>();
    timeStamp=QTime();
    /*======Please Program below======*/
    /*
    Step 1: fill outputdata.
    Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
    E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
    Step 3: set the timeStamp for Simulator.
    */
    if(vars->file.atEnd())
        {
            return 0;
        }
        int tmp;
        vars->file.read((char *)&(tmp),sizeof(tmp));
        outputdata->timestamp=tmp;
        //duyizhenshuju
        vars->file.read((char *)outputdata->data,sizeof(short)*(outputdata->datasize));
        int i,n=outputdata->datasize;
        for(i=0;i<n;i++)
        {
            if(outputdata->data[i]<params->nearfilter||outputdata->data[i]>params->farfilter)
            {
                outputdata->data[i]=0;//不在可用范围内的数据都会赋值为0！
            }
        }
        timeStamp=QTime::fromMSecsSinceStartOfDay(outputdata->timestamp);
        return 1;
}

