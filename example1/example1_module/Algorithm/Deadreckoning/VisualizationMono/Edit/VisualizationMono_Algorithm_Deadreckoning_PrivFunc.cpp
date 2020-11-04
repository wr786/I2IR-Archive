//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Deadreckoning_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Deadreckoning_Params * params=(VisualizationMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	VisualizationMono_Algorithm_Deadreckoning_Vars * vars=(VisualizationMono_Algorithm_Deadreckoning_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,mapZeroX);
    GetParamValue(xmlloader,params,mapZeroY);

    int mapW=params->mapWidth/params->mapPixelSize;
    int mapH=params->mapHeight/params->mapPixelSize;
	//构建并初始化图像
    vars->robottrack=cv::Mat::zeros(abs(mapH),abs(mapW),CV_8UC3);
	//标志变量，校验是否为首次绘图 ，首次即绘出图像中不变的元素，之后不再重复绘制
    vars->init=true;
    vars->track->setText("Opened");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Deadreckoning_Params * params=(VisualizationMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	VisualizationMono_Algorithm_Deadreckoning_Vars * vars=(VisualizationMono_Algorithm_Deadreckoning_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
   
    vars->track->setText("Closed");


	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Algorithm_Deadreckoning_Params * params=(VisualizationMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	VisualizationMono_Algorithm_Deadreckoning_Vars * vars=(VisualizationMono_Algorithm_Deadreckoning_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Deadreckoning_Params * params=(VisualizationMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	VisualizationMono_Algorithm_Deadreckoning_Vars * vars=(VisualizationMono_Algorithm_Deadreckoning_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Deadreckoning_Params * params=(VisualizationMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	VisualizationMono_Algorithm_Deadreckoning_Vars * vars=(VisualizationMono_Algorithm_Deadreckoning_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Deadreckoning_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Algorithm_Deadreckoning_Data *> draindata; copyQVector(draindata,drainData);
    if(draindata.size()==0){
        vars->track->setText("No Data");
        return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
    */
		//图像宽高像素数
        int mapW = params->mapWidth / params->mapPixelSize;
        int mapH = params->mapHeight / params->mapPixelSize;
		//网格宽像素数
        int interval = params->mapGrid / params->mapPixelSize;

		//绘制网格
        if(vars->init){
        for(int i=interval;i<mapW;i+=interval)
        {
           cv::Point2d start=cv::Point2d(i,0);
           cv::Point2d end=cv::Point2d(i,abs(mapH));
           cv::line(vars->robottrack,start,end,cv::Scalar(255,0,0));
        }
        for(int i=interval;i<abs(mapH);i+=interval)
        {
           cv::Point2d start=cv::Point2d(0,i);
           cv::Point2d end=cv::Point2d(abs(mapW),i);
           cv::line(vars->robottrack,start,end,cv::Scalar(255,0,0));
        }
        }
		//二维点：当前机器人坐标
        cv::Point2d pos=cv::Point2d(draindata.front()->x/params->mapPixelSize-params->mapZeroX,draindata.front()->y/params->mapPixelSize-params->mapZeroY);
         //  vars->trackpoints.push_back(pos);
		//每次绘出当前点到上一点连线，连线轨迹即存储于该变量
        if (!vars->init){
            cv::line(vars->robottrack,pos,vars->lastpoint,cv::Scalar(0,255,0),2);
        }
        else
        {
            vars->init=false;
        }

        vars->lastpoint=pos;

        //temprobottrack为实际绘出的图像，可在上面加实时元素，如当前坐标
        vars->temprobottrack=vars->robottrack.clone();
        char timestamp[30];
        sprintf(timestamp,"timestamp=%d",draindata.front()->timestamp);
		//加绘实时坐标点与时间戳
        cv::putText(vars->temprobottrack,timestamp,cv::Point2d(20,20),FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(255,255,255),0.5);
        cv::circle(vars->temprobottrack,pos,1,cv::Scalar(0,0,255),2);


		//图像绘制
		QImage image=cvMat2QImage(vars->temprobottrack);
		vars->track->setPixmap(QPixmap::fromImage(image));

        return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Algorithm_Deadreckoning_Params * params=(VisualizationMono_Algorithm_Deadreckoning_Params *)paramsPtr;
	VisualizationMono_Algorithm_Deadreckoning_Vars * vars=(VisualizationMono_Algorithm_Deadreckoning_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->track);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

