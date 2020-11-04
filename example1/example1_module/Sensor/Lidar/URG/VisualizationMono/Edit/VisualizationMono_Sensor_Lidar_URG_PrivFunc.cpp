//You need to program this file.

#include "../NoEdit/VisualizationMono_Sensor_Lidar_URG_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Sensor_Lidar_URG_Params * params=(VisualizationMono_Sensor_Lidar_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_Lidar_URG_Vars * vars=(VisualizationMono_Sensor_Lidar_URG_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,range);
    GetParamValue(xmlloader,params,interval);
    GetParamValue(xmlloader,params,imageradius);
    GetParamValue(xmlloader,params,frontonly);
    GetParamValue(xmlloader,params,laserbeam);
    if(params->frontonly)
    {
        vars->laserMap=cv::Mat::zeros(params->imageradius,params->imageradius*2,CV_8UC3);;
    }
    else
    {
        vars->laserMap=cv::Mat::zeros(params->imageradius*2,params->imageradius*2,CV_8UC3);
    }

    vars->init=true;
    vars->beams->setText("Opened");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Sensor_Lidar_URG_Params * params=(VisualizationMono_Sensor_Lidar_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_Lidar_URG_Vars * vars=(VisualizationMono_Sensor_Lidar_URG_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->beams->setText("Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Sensor_Lidar_URG_Params * params=(VisualizationMono_Sensor_Lidar_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_Lidar_URG_Vars * vars=(VisualizationMono_Sensor_Lidar_URG_Vars *)varsPtr;
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
	VisualizationMono_Sensor_Lidar_URG_Params * params=(VisualizationMono_Sensor_Lidar_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_Lidar_URG_Vars * vars=(VisualizationMono_Sensor_Lidar_URG_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Sensor_Lidar_URG_Params, Data_Type = Simulator_Sensor_Lidar_URG_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Sensor_Lidar_URG_Params * params=(VisualizationMono_Sensor_Lidar_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_Lidar_URG_Vars * vars=(VisualizationMono_Sensor_Lidar_URG_Vars *)varsPtr;
	QVector<Simulator_Sensor_Lidar_URG_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<Simulator_Sensor_Lidar_URG_Data *> draindata; copyQVector(draindata,drainData);
    if(draindata.size()==0){vars->beams->setText("No Data");return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
		//图像坐标系内的激光扫描角度范围区间
        vars->startangle=90-drainparams.front()->rng/2;
        vars->endangle=90+drainparams.front()->rng/2;
        vars->resolution=drainparams.front()->res;
        double pi=3.1415926535897932384626433832795/180.0;
		//固定机器人在图像中心
        int centerx=params->imageradius;
        int centery=params->imageradius;
		//首次调用函数即绘制网格，之后不再绘制
        int n=params->range/params->interval;
        int radiusstep=params->imageradius/n;

        if(!vars->init){
            for(int i=1;i<=n;i++)
            {
                int radius=i*radiusstep;

                cv::circle(vars->laserMap,cv::Point2d(params->imageradius,params->imageradius),radius,cv::Scalar(255,0,0),1);
            }


            for(int i=0;i<360/params->angleinterval;i++){
                cv::line(vars->laserMap,cv::Point2d(centerx,centery),
                    cv::Point2d(centerx+
                               params->imageradius*3*cos(params->angleinterval*i*pi),
                             centery-params->imageradius*3*sin(params->angleinterval*i*pi)),cv::Scalar(255,0,0));

            }
             cv::circle(vars->laserMap,cv::Point2d(params->imageradius,params->imageradius),3,cv::Scalar(0,0,255),4);
        }
        else{
            vars->init=false;
        }
		
		//将激光可见范围缩放至图像中，定义缩放系数
        double ratio=double(params->imageradius)/double(params->range);
        n=draindata.front()->datasize;


        vars->mapshow=vars->laserMap.clone();
        for(int i=0;i<n;i++)
        {
            double theta=(vars->startangle+vars->resolution*i)*pi;
            double distance=ratio*(draindata.front()->data[i]);
			//在图像坐标系下，激光点位置与激光器位置距离在图像坐标轴方向上投影分别为x,y
            int x=int(distance*cos(theta));
            int y=int(distance*sin(theta));
//            qDebug()<<x<<" "<<y<<" "<<distance<<endl;
			//绘制激光束或激光点
            if(params->laserbeam && distance>1)
            {             
                cv::line(vars->mapshow,cv::Point2d(centerx,centery),cv::Point2d(x+centerx,-y+centery),cv::Scalar(0,255,0),1);
            }
            else
            {
                cv::circle(vars->mapshow,cv::Point2d(x+centerx,-y+centery),1,cv::Scalar(0,255,0),1);
            }
        }
		//绘制时间戳
        char timestamp[50];
        sprintf(timestamp,"timestamp=%d",draindata.front()->timestamp);
        cv::putText(vars->mapshow,timestamp,cv::Point2d(20,20),FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(255,255,255),0.5);
        QImage img=cvMat2QImage(vars->mapshow);
        vars->beams->setPixmap(QPixmap::fromImage(img));
        return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Sensor_Lidar_URG_Params * params=(VisualizationMono_Sensor_Lidar_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_Lidar_URG_Vars * vars=(VisualizationMono_Sensor_Lidar_URG_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->beams);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

