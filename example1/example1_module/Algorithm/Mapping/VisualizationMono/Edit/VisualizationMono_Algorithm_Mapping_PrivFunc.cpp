//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Mapping_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Mapping_Params * params=(VisualizationMono_Algorithm_Mapping_Params *)paramsPtr;
	VisualizationMono_Algorithm_Mapping_Vars * vars=(VisualizationMono_Algorithm_Mapping_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
        GetParamValue(xmlloader,params,mapWidth);//从xml读取
        GetParamValue(xmlloader,params,mapHeight);
        GetParamValue(xmlloader,params,zeroX);
        GetParamValue(xmlloader,params,zeroY);
        GetParamValue(xmlloader,params,mapRes);
        GetParamValue(xmlloader,params,mapGrid);
        vars->lasermap=cv::Mat::zeros(abs(params->mapHeight),abs(params->mapWidth),CV_8UC3);
        vars->init=true;
		vars->image->setText("Opened");
        return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Mapping_Params * params=(VisualizationMono_Algorithm_Mapping_Params *)paramsPtr;
	VisualizationMono_Algorithm_Mapping_Vars * vars=(VisualizationMono_Algorithm_Mapping_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/

        vars->image->setText("Closed");
        return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Algorithm_Mapping_Params * params=(VisualizationMono_Algorithm_Mapping_Params *)paramsPtr;
	VisualizationMono_Algorithm_Mapping_Vars * vars=(VisualizationMono_Algorithm_Mapping_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Mapping_Params * params=(VisualizationMono_Algorithm_Mapping_Params *)paramsPtr;
	VisualizationMono_Algorithm_Mapping_Vars * vars=(VisualizationMono_Algorithm_Mapping_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Algorithm_Mapping_Params, Data_Type = ProcessorMulti_Algorithm_Mapping_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Algorithm_Mapping_Params * params=(VisualizationMono_Algorithm_Mapping_Params *)paramsPtr;
	VisualizationMono_Algorithm_Mapping_Vars * vars=(VisualizationMono_Algorithm_Mapping_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Mapping_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Algorithm_Mapping_Data *> draindata; copyQVector(draindata,drainData);
    if(draindata.size()==0){
        vars->image->setText("No Data");

        return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
	//网格宽（像素数
    int interval = params->mapGrid /params->mapRes;
	//仅在首次调用时绘制网格
    if(vars->init){
    for(int i=interval;i<params->mapWidth;i+=interval)
    {
       cv::Point2d start=cv::Point2d(i,0);
       cv::Point2d end=cv::Point2d(i,abs(params->mapHeight));
       cv::line(vars->lasermap,start,end,cv::Scalar(255,0,0));
    }
    for(int i=interval;i<abs(params->mapHeight);i+=interval)
    {
       cv::Point2d start=cv::Point2d(0,i);
       cv::Point2d end=cv::Point2d(abs(params->mapWidth),i);
       cv::line(vars->lasermap,start,end,cv::Scalar(255,0,0));
    }
    }
    else{
        vars->init=false;
    }


    for(int i = 0 ; i <params->mapHeight ; i ++)
    {
        for(int j = 0 ; j < params->mapWidth ; j ++)
        {
           // if(draindata.front()->map[i][j] == 1)
           // {
            //    if(vars->lasermap.at<cv::Vec3b>(i,j)[1]!=255)
                    vars->lasermap.at<cv::Vec3b>(i,j)[1]=draindata.front()->map[i][j];
            //}
        }
    }
    char timestamp[50];
	
    vars->mapshow=vars->lasermap.clone();
	//绘制实时位置
    cv::circle(vars->mapshow,cv::Point2d(draindata.front()->mapX/ params->mapRes-params->zeroX,draindata.front()->mapY/ params->mapRes-params->zeroY),1,cv::Scalar(0,0,255),2);
	//绘制数据源的时间戳
    sprintf(timestamp,"timestamp_deadreckoning=%d",draindata.front()->timestamp_deadreconing);
    cv::putText(vars->mapshow,timestamp,cv::Point2d(20,20),FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(255,255,255),0.5);
    sprintf(timestamp,"timestamp_laser=%d",draindata.front()->timestamp_laser);
    cv::putText(vars->mapshow,timestamp,cv::Point2d(20,50),FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(255,255,255),0.5);
    QImage img=cvMat2QImage(vars->mapshow);
    vars->image->setPixmap(QPixmap::fromImage(img));
    return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Algorithm_Mapping_Params * params=(VisualizationMono_Algorithm_Mapping_Params *)paramsPtr;
	VisualizationMono_Algorithm_Mapping_Vars * vars=(VisualizationMono_Algorithm_Mapping_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->image);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

