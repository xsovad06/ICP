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
    myTime = new QTime(0, 0, 0, 0);
    init_scene();

    sched = new Schedule(paths, ui->graphicsView->scene());
    sched->loadTimes();

    connect(ui->Button_zoom_in, SIGNAL(clicked()), this, SLOT(zoom_in()));
    connect(ui->Button_zoom_out, SIGNAL(clicked()), this, SLOT(zoom_out()));
    connect(ui->zoom_slider, SIGNAL(valueChanged(int)), this, SLOT(zoom_slider(int)));

    connect(myTimer, SIGNAL(timeout()), this, SLOT(onTimer()));
    connect(ui->timePlayBtn, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(ui->spdUpBtn, SIGNAL(clicked()), this, SLOT(speedUp()));
    connect(ui->spdDownBtn, SIGNAL(clicked()), this, SLOT(speedDown()));
    connect(ui->spdRevBtn, SIGNAL(clicked()), this, SLOT(speedReverse()));

    connect(myTimer, SIGNAL(timeout()), this, SLOT(repaintMiniMap()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::init_scene() {
    auto *mini_map_scene = new MyScene2(ui->graphicsView_path);
    ui->graphicsView_path->setScene(mini_map_scene);

//////////////////Create and save mini map//////////////////////
    /*mini_map_scene->createStreet1();
    mini_map_scene->createStreet2(Qt::lightGray);
    mini_map_scene->createStreet3(Qt::darkGreen);
    mini_map_scene->createStreet4(Qt::yellow);
    mini_map_scene->createStreet5(Qt::green);
    mini_map_scene->toFile();*/
////////////////////////////////////////////////////////////////
////////////////////////// load mini map ////////////////////////////
    mini_map_scene->loadLinesFromFile();
    paths2 = mini_map_scene->getPaths();
////////////////////////////////////////////////////////////////

    auto *map_scene = new MyScene(ui->graphicsView);
    ui->graphicsView->setScene(map_scene);

////////////////Create and save map////////////////////////
  /*map_scene->createStreet1();
    map_scene->createStreet2(Qt::lightGray);
    map_scene->createStreet3(Qt::darkGreen);
    map_scene->createStreet4(Qt::yellow);
    map_scene->createStreet5(Qt::green);
    map_scene->toFile();*/
//////////////////////////////////////////////////////////
  ////////////////////// load map ////////////////
    map_scene->loadLinesFromFile();
    paths = map_scene->getPaths();
///////////////////////////////////////////////////////    

    for(int i = 0; i < paths.size(); ++i)
    {
        foreach(QGraphicsItem *line, paths.at(i)->getPath())
        {
            map_scene->addItem(line);
        }
    }
    map = map_scene;
    miniMap = mini_map_scene;
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::repaintMiniMap() {
    if (!deleted && (actualMiniMapPath != -1)) {
        foreach(QGraphicsItem *line, miniMap->items())
        {
            miniMap->removeItem(line);
        }
        miniMap->setBackgroundBrush(Qt::white);
        deleted = true;
    }
    QString street = map->highlighted_name;
    if (street != "") {
        QString number =  street.remove(0,6);;
        actualMiniMapPath = number.toInt();
        foreach(QGraphicsItem *line, paths2.at(actualMiniMapPath)->getPath())
        {
            miniMap->addItem(line);
        }
        deleted = false;
    }
    ui->graphicsView_path->setRenderHint(QPainter::Antialiasing);
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
    qreal scale = n / 10.0;
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
    // Repaint scene
    ui->graphicsView->scale(1.00000000001, 1.00000000001);

    /************************** ANIMATION ****************************/
    sched->start(*myTime, timeRev);

}

void MainWindow::speedUp() {
    if(timeSpeed != 2048) {
        timeSpeed *= 2;
        QString speed;
        QTextStream(&speed) << timeSpeed;
        ui->timeSpdLab->setText(speed + "x");
    }
}

void MainWindow::speedDown() {
    if(timeSpeed != 0.125) {
        timeSpeed /= 2;
        QString speed;
        QTextStream(&speed) << timeSpeed;
        ui->timeSpdLab->setText(speed + "x");
    }
}

void MainWindow::speedReverse() {
   timeRev =! timeRev;
}
