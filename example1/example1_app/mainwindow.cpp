#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        ui->starttime->setText("71438000");//时间起点，这个可以自己调整（对应文件中的时间，在UI界面中调整）
        double speed = 2;//这个值可以自己调快（调小; 其实也可以写在UI界面中），但是不推荐，因为假如你电脑慢的话Encoder数据5ms发一次会出错   // default: 2

        //创建节点（这一块大家相应的调整为自己相对应的工程名称，还有模块名称等）
        //第一个Robot是我创建的Qt library的工程名。
        //第二个Sensor_Encoder是我使用ConfigModule创建的节点类名称
        //第三个EncoderSim是这个节点的标示符，可任意命名，只要其他节点输入输出写的是同样的就行，我个人习惯使用与这个指针名相同的名字
        //第四个config.xml是这个节点储存各种外部参数变量的文件路径，以后修改这些参数变量都可以直接在外面记事本打开编辑
        //第五个QTime()是Simulator的起始时间
        //第六个speed是模拟速率
        Simulator *EncoderSim = new Simulator("example1_module","Sensor_Encoder","EncoderSim","config.xml",QTime(),speed);//输入都有详细注释，使用IDE的话会自动提示
        EncoderSim->setOutputNodesName(QStringList()<<"Deadreckoning");//定义好输出给哪个节点，QStringList里面存储的是后续节点的标示符

        Simulator *IMUSim = new Simulator("example1_module", "Sensor_IMU", "IMUSim", "config.xml", QTime(), speed);
        IMUSim->setOutputNodesName(QStringList()<<"Deadreckoning");

        Simulator *URGSim = new Simulator("example1_module", "Sensor_Lidar_URG", "URGSim", "config.xml", QTime(), speed);
        URGSim->setOutputNodesName(QStringList()<<"URGVis;Mapping");

        VisualizationMono *URGVis = new VisualizationMono("example1_module", "Sensor_Lidar_URG", "URGVis", "config.xml");
        URGVis->setInputNodesName(QStringList()<<"URGSim");
        URGVis->connectExternalTrigger(0, DRAINSLOT);

        ProcessorMulti *Deadreckoning = new ProcessorMulti("example1_module","Algorithm_Deadreckoning","Deadreckoning","config.xml");//相对Simulator类型节点会少最后两个项
        Deadreckoning->setInputNodesName(QStringList()<<"EncoderSim"<<"IMUSim");//有输入的还需要定义输入；不同的输入端口的数据，中间用<<隔开（他们存在两个list 节点里面）
        Deadreckoning->setOutputNodesName(QStringList()<<"DRStorage;DRVis;Mapping");//同一个输出端口的数据给不同的模块，中间用';'隔开（他们存储在同一个list 节点里面，RobotSDK再解析）
        Deadreckoning->connectExternalTrigger(1, PROCESSORSLOT);//通过0号端口触发，0号端口来一个数据这个模块触发一次，接收输入、处理、得到输出; 因为是processor所以是"PROCESSORSLOT"；之前的Simulator不需要设置触发方式，RobotSDK自己会完成

        StorageMono *DRStorage = new StorageMono("example1_module", "Algorithm_Deadreckoning", "DRStorage", "config.xml");//SharedLibrary 和 NodeClass 都是一样的，通过不同的节点类型来区分
        DRStorage->setInputNodesName(QStringList()<<"Deadreckoning");
        DRStorage->connectExternalTrigger(0, DRAINSLOT);

        VisualizationMono *DRVis = new VisualizationMono("example1_module", "Algorithm_Deadreckoning", "DRVis", "config.xml");
        DRVis->setInputNodesName(QStringList()<<"Deadreckoning");
        DRVis->connectExternalTrigger(0, DRAINSLOT);

        ProcessorMulti *Mapping = new ProcessorMulti("example1_module", "Algorithm_Mapping", "Mapping", "config.xml");
        Mapping->setInputNodesName(QStringList()<<"Deadreckoning"<<"URGSim");
        Mapping->setOutputNodesName(QStringList()<<"MapShow");
        Mapping->connectExternalTrigger(1, PROCESSORSLOT);

        VisualizationMono *MapShow = new VisualizationMono("example1_module", "Algorithm_Mapping", "MapShow", "config.xml");
        MapShow->setInputNodesName(QStringList()<<"Mapping");
        MapShow->connectExternalTrigger(0, DRAINSLOT);

        //config edge
        bool isMonitor =1;
        edge.addNode(EncoderSim, 1,  isMonitor);
        edge.addNode(IMUSim, 1, isMonitor);
        edge.addNode(URGSim, 1, isMonitor);
        edge.addNode(URGVis, 0, 0);
        edge.addNode(Deadreckoning, 1, isMonitor);
        edge.addNode(DRStorage, 1, isMonitor);
        edge.addNode(DRVis, 0, isMonitor);
        edge.addNode(Mapping, 1, isMonitor);
        edge.addNode(MapShow, 0, 0);
        edge.connectAll();

        //config ui
        connect(ui->open, SIGNAL(clicked()), &edge, SLOT(openAllNodesSlot()));
        connect(ui->open, &QPushButton::clicked, this, [=]() {
            ui->open->setDisabled(true);
        });
        connect(ui->close, SIGNAL(clicked()), &edge, SLOT(closeAllNodesSlot()));
        connect(ui->close, &QPushButton::clicked, this, [=]() {
            ui->open->setDisabled(false);
        });
        connect(ui->setvalue, SIGNAL(clicked()), this, SLOT(setSimuSlot()));
        connect(this,SIGNAL(setSimuStartTimeSignal(QTime)), EncoderSim, SLOT(setStartTimeSlot(QTime)));
        connect(this,SIGNAL(setSimuStartTimeSignal(QTime)), IMUSim, SLOT(setStartTimeSlot(QTime)));
        connect(this,SIGNAL(setSimuStartTimeSignal(QTime)), URGSim, SLOT(setStartTimeSlot(QTime)));

        connect(ui->sync,SIGNAL(clicked()), EncoderSim,SLOT(syncTimeTrackSlot()));
        connect(ui->sync,SIGNAL(clicked()), IMUSim,SLOT(syncTimeTrackSlot()));
        connect(ui->sync,SIGNAL(clicked()), URGSim,SLOT(syncTimeTrackSlot()));

        connect(ui->start, SIGNAL(clicked()), EncoderSim, SLOT(startSimulatorSlot()));
        connect(ui->start, SIGNAL(clicked()), IMUSim, SLOT(startSimulatorSlot()));
        connect(ui->start, SIGNAL(clicked()), URGSim, SLOT(startSimulatorSlot()));

        connect(ui->stop, SIGNAL(clicked()), EncoderSim,SLOT(stopSimulatorSlot()));
        connect(ui->stop, SIGNAL(clicked()), IMUSim,SLOT(stopSimulatorSlot()));
        connect(ui->stop, SIGNAL(clicked()), URGSim,SLOT(stopSimulatorSlot()));
        //Visualization
        ui->tabWidget->addTab(&edge,"Monitor");
        QList<QWidget *> widgets;
        widgets= DRVis->getVisualizationWidgets();
        ui->area1->setWidget(widgets.front());
        widgets= URGVis->getVisualizationWidgets();
         ui->area2->setWidget(widgets.front());
        widgets= MapShow->getVisualizationWidgets();
        ui->area3->setWidget(widgets.front());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setSimuSlot()
{
    emit setSimuStartTimeSignal(QTime::fromMSecsSinceStartOfDay(ui->starttime->text().toInt()));
}
