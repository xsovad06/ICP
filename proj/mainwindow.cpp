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
    timeSpeed = 1;
    ui->setupUi(this);
    myTimer = new QTimer(this);
    myTimer->setInterval(1000/timeSpeed);
    myTime = new QTime(0,0,0);
    init_scene();

   /* auto mapScene= dynamic_cast<mapScene*>(ui->graphicsView->scene());
    if(mapScene)
    {
        mapScene->toFile();
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

/*  Create map in case of creating json file
    map_scene->createStreet1();
    map_scene->createStreet2(Qt::lightGray);
    map_scene->createStreet3(Qt::darkGreen);
    map_scene->createStreet4(Qt::yellow);
    map_scene->createStreet5(Qt::green);

    map_scene->loadLines();*/

    map_scene->setPaths();
    paths = map_scene->getPaths();
    for(int i=0;i < paths.size();++i)
    {
        foreach(QGraphicsItem *line, paths.at(i)->getPath())
        {
            map_scene->addItem(line);
        }
        qDebug()<< "Total time in sec: " << paths.at(i)->getTotalTime();
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
    if(!myTimer->isActive()) {
        myTimer->start();
    }
    else {
        myTimer->stop();
    }
}

void  MainWindow::onTimer()
{
    QString str = myTime->toString("hh : mm : ss");
        ui->timeShowLab->setText(str);
        if(timeRev)
        {
            *myTime=myTime->addMSecs(-1000);
        }
        else
        {
            *myTime=myTime->addMSecs(1000);
        }

        myTimer->setInterval(1000/timeSpeed);
        //repaint scene
        ui->graphicsView->scale(1.00000000001,1.00000000001);

        /************************** ANIMATION ****************************/
        static Drive jazda(paths.at(0),*myTime,ui->graphicsView->scene());
        jazda.move(timeRev);
        /*static Drive jazda1(paths.at(1),*myTime,ui->graphicsView->scene());
        jazda1.move(timeRev);
        static Drive jazda2(paths.at(2),*myTime,ui->graphicsView->scene());
        jazda2.move(timeRev);
        static Drive jazda3(paths.at(3),*myTime,ui->graphicsView->scene());
        jazda3.move(timeRev);
        static Drive jazda4(paths.at(4),*myTime,ui->graphicsView->scene());
        jazda4.move(timeRev);*/
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
   timeRev=!timeRev;
}






















