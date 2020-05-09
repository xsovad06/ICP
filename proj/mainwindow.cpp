#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    timeSpeed = 1;
    ui->setupUi(this);
    myTimer = new QTimer(this);
    myTimer->setInterval(1000 / timeSpeed);
    myTime = new QTime(0,0,0);
    init_scene();

    sched=new Schedule(paths,ui->graphicsView->scene());


    connect(ui->Button_zoom_in, SIGNAL(clicked()), this, SLOT(zoom_in()));
    connect(ui->Button_zoom_out, SIGNAL(clicked()), this, SLOT(zoom_out()));
    connect(ui->zoom_slider, SIGNAL(valueChanged(int)), this, SLOT(zoom_slider(int)));

    connect(myTimer, SIGNAL(timeout()), this, SLOT(onTimer()));
    connect(ui->timePlayBtn, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(ui->spdUpBtn, SIGNAL(clicked()), this, SLOT(speedUp()));
    connect(ui->spdDownBtn, SIGNAL(clicked()), this, SLOT(speedDown()));
    connect(ui->spdRevBtn, SIGNAL(clicked()), this, SLOT(speedReverse()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::init_scene() {
    auto *map_scene = new MyScene(ui->graphicsView);
    ui->graphicsView->setScene(map_scene);

    // Create map in case of creating json file
 /*   map_scene->createStreet1();
    map_scene->createStreet2(Qt::lightGray);
    map_scene->createStreet3(Qt::darkGreen);
    map_scene->createStreet4(Qt::yellow);
    map_scene->createStreet5(Qt::green);

    map_scene->toFile();*/
    map_scene->loadLinesfromFile();

    paths = map_scene->getPaths();
    for(int i = 0; i < paths.size(); ++i)
    {
        foreach(QGraphicsItem *line, paths.at(i)->getPath())
        {
            map_scene->addItem(line);
        }
    }
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::zoom_in() {
    auto actual_value = ui->zoom_slider->value();
    if (actual_value != 100) {
        ui->graphicsView->scale(1.25, 1.25);
        ui->zoom_slider->setValue(ui->zoom_slider->value() + 10);
    }
}

void MainWindow::zoom_out() {
    auto actual_value = ui->zoom_slider->value();
    if (actual_value != 1) {
        ui->graphicsView->scale(0.8, 0.8);
        ui->zoom_slider->setValue(ui->zoom_slider->value() - 10);
    }
}

void MainWindow::zoom_slider(int n) {
    auto original_matrix = ui->graphicsView->transform();
    qreal scale = n/10.0;
    ui->graphicsView->setTransform(QTransform(scale, original_matrix.m12(), original_matrix.m21(), scale, original_matrix.dx(), original_matrix.dy()));
}

void MainWindow::startTimer() {
    if(!myTimer->isActive()) {
        myTimer->start();
    }
    else {
        myTimer->stop();
    }
}

void  MainWindow::onTimer() {
    QString str = myTime->toString("hh : mm : ss");
    ui->timeShowLab->setText(str);
    if(timeRev) {
        *myTime = myTime->addMSecs(-1000);
    }
    else {
        *myTime = myTime->addMSecs(1000);
    }

    myTimer->setInterval(1000 / timeSpeed);
    //repaint scene
    ui->graphicsView->scale(1.00000000001, 1.00000000001);

    /************************** ANIMATION ****************************/
   // static Drive *jazdaPtr;

    /*if(*myTime >= QTime(0, 0, 5, 0) && (*myTime < QTime(0, 15, 30, 0))) {
        static Drive jazda = Drive(paths.at(0), *myTime,ui->graphicsView->scene());
        jazdaPtr = &jazda;
        jazda.move(timeRev);
    }
    if(*myTime >= QTime(0, 16, 50, 0) && (*myTime < QTime(0, 35, 34, 0))) {
        static Drive jazda = *jazdaPtr;
        jazdaPtr = &jazda;
        jazda.moveBack(timeRev);
    }
    if(*myTime >= QTime(0, 50, 51, 0) && (*myTime < QTime(1, 5, 54, 0))) {
        static Drive jazda = *jazdaPtr;
        jazdaPtr = &jazda;
        jazda.move(timeRev);
    }*/
    sched->start(*myTime,timeRev);

}

void MainWindow::speedUp() {
    timeSpeed *= 2;
    QString speed;
    QTextStream(&speed) << timeSpeed;
    ui->timeSpdLab->setText(speed);
}

void MainWindow::speedDown() {
    timeSpeed /= 2;
    QString speed;
    QTextStream(&speed) << timeSpeed;
    ui->timeSpdLab->setText(speed);
}

void MainWindow::speedReverse() {
   timeRev=!timeRev;
}
