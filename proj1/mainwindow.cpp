#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    myTimer->setInterval(1000);
    myTime=new QTime(0,0,0);
    timeSpeed=1;

    init_scene();

   /* auto myscene= dynamic_cast<MyScene*>(ui->graphicsView->scene());
    if(myscene)
    {
        myscene->toFile();
    }*/



    connect(ui->Button_zoom_in, SIGNAL(clicked()), this, SLOT(zoom_in()));
    connect(ui->Button_zoom_out, SIGNAL(clicked()), this, SLOT(zoom_out()));
    connect(ui->zoom_slider, SIGNAL(valueChanged(int)), this, SLOT(zoom_slider(int)));

    connect(myTimer,SIGNAL(timeout()),this,SLOT(onTimer()));
    connect(ui->timePlayBtn,SIGNAL(clicked()),this,SLOT(startTimer()));
    connect(ui->spdUpBtn,SIGNAL(clicked()),this,SLOT(speedUp()));
    connect(ui->spdDownBtn,SIGNAL(clicked()),this,SLOT(speedDown()));
    connect(ui->spdRevBtn,SIGNAL(clicked()),this,SLOT(speedReverse()));





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_scene()
{
    // Create pointer to our graphic scene
    auto *map_scene = new MyScene(ui->graphicsView);
    ui->graphicsView->setScene(map_scene);

  /*  map_scene->createStreet1();
    map_scene->createStreet2(Qt::lightGray);
    map_scene->createStreet3(Qt::darkGreen);
    map_scene->createStreet4(Qt::yellow);
    map_scene->createStreet5(Qt::green);*/


    //map_scene->loadLines();

    setPaths();
    for(int i=0;i<paths.size();++i)
    {
        int ttime=0;
        foreach(QGraphicsItem *line, paths.at(i)->getPath().keys())
        {
            map_scene->addItem(line);
        }
        foreach(int sec, paths.at(i)->getPath().values())
        {
            ttime+=sec;
        }
        qDebug()<<ttime;
    }

}

void MainWindow::zoom_in()
{
    auto actual_value = ui->zoom_slider->value();
    if (actual_value != 100) {
        ui->graphicsView->scale(1.25, 1.25);
        ui->zoom_slider->setValue(ui->zoom_slider->value() + 10);
    }
}

void MainWindow::zoom_out()
{
    auto actual_value = ui->zoom_slider->value();
    if (actual_value != 1) {
        ui->graphicsView->scale(0.8, 0.8);
        ui->zoom_slider->setValue(ui->zoom_slider->value() - 10);
    }
}

void MainWindow::zoom_slider(int n)
{
    auto original_matrix = ui->graphicsView->transform();
    qreal scale = n/10.0;
    ui->graphicsView->setTransform(QTransform(scale, original_matrix.m12(), original_matrix.m21(), scale, original_matrix.dx(), original_matrix.dy()));
}


void MainWindow::startTimer()
{
    if(!myTimer->isActive())
    {
        myTimer->start();
    }
    else
    {
        myTimer->stop();
    }
}

void  MainWindow::onTimer()
{
    QString str = myTime->toString("hh : mm : ss");
    ui->timeShowLab->setText(str);
    *myTime=myTime->addMSecs(1000*timeSpeed);
}
void MainWindow::speedUp()
{
    timeSpeed*=2;
    QString speed;
    QTextStream(&speed)<<timeSpeed;
    ui->timeSpdLab->setText(speed);
}
void MainWindow::speedDown()
{
    timeSpeed/=2;
    QString speed;
    QTextStream(&speed)<<timeSpeed;
    ui->timeSpdLab->setText(speed);
}
void MainWindow::speedReverse()
{
    timeSpeed*=-1;
    QString speed;
    QTextStream(&speed)<<timeSpeed;
    ui->timeSpdLab->setText(speed);
}

void MainWindow::loadLinesfromFile()
{
    QFile file("/home/ixpo-u/Plocha/skola/icp/proj/json.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument jDoc = QJsonDocument::fromJson(data);
        QJsonObject jObj = jDoc.object();
        QJsonArray posArr = jObj.value("lines").toArray();
        foreach(const QJsonValue & val, posArr)
        {
            int x1=val.toObject().value("x1").toInt();
            int x2=val.toObject().value("x2").toInt();
            int y1=val.toObject().value("y1").toInt();
            int y2=val.toObject().value("y2").toInt();
            loadedLines<<QLine(x1,y1,x2,y2);
        }
    }
}


void MainWindow::setPaths()
{
    loadLinesfromFile();
    int i=0;
    QList<QLine> lineGroup1;
    QList<QLine> lineGroup2;
    QList<QLine> lineGroup3;
    QList<QLine> lineGroup4;
    QList<QLine> lineGroup5;
    for(auto line : loadedLines)
    {
        if(i<9)
        {
            lineGroup1<<line;
        }
        else if(i<14)
        {
            lineGroup2<<line;
        }
        else if(i<21)
        {
            lineGroup3<<line;
        }
        else if(i<29)
        {
            lineGroup4<<line;
        }
        else if(i<37)
        {
            lineGroup5<<line;
        }
        ++i;
    }
        auto path1 = new Path("p1",lineGroup1,Qt::blue);
        auto path2 = new Path("p2",lineGroup2,Qt::red);
        auto path3 = new Path("p3",lineGroup3,Qt::green);
        auto path4 = new Path("p4",lineGroup4,Qt::yellow);
        auto path5 = new Path("p5",lineGroup5,Qt::darkGray);

        paths<<path1<<path2<<path3<<path4<<path5;
}

























