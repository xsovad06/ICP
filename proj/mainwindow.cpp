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
    init_scene2();

    sched = new Schedule(paths, ui->graphicsView->scene());
    sched->loadTimes();

    connect(ui->Button_zoom_in, SIGNAL(clicked()), this, SLOT(zoom_in()));
    connect(ui->Button_zoom_out, SIGNAL(clicked()), this, SLOT(zoom_out()));
    connect(ui->zoom_slider, SIGNAL(valueChanged(int)), this, SLOT(zoom_slider(int)));
    ui->zoom_slider->setValue(100);
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
    auto *map_scene = new MyScene(ui->graphicsView);
    ui->graphicsView->setScene(map_scene);


/******************* Create and save mini map **********************/
  /*map_scene->createStreet1();
    map_scene->createStreet2(Qt::lightGray);
    map_scene->createStreet3(Qt::darkGreen);
    map_scene->createStreet4(Qt::yellow);
    map_scene->createStreet5(Qt::green);
    map_scene->toFile();*/

/************************* Load mini map ***************************/
    map_scene->loadLinesFromFile();
    paths = map_scene->getPaths();
/*******************************************************************/

    for(int i = 0; i < paths.size(); ++i)
    {
        foreach(QGraphicsItem *line, paths.at(i)->getPath())
        {
            map_scene->addItem(line);
        }
    }
    map = map_scene;
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::init_scene2() {
    auto *mini_map_scene = new MyScene2(ui->graphicsView_path);
    ui->graphicsView_path->setScene(mini_map_scene);

/******************* Create and save mini map **********************/
    /*mini_map_scene->createStreet1();
    mini_map_scene->createStreet2(Qt::lightGray);
    mini_map_scene->createStreet3(Qt::darkGreen);
    mini_map_scene->createStreet4(Qt::yellow);
    mini_map_scene->createStreet5(Qt::green);
    mini_map_scene->toFile();*/

/************************* Load mini map ***************************/
    mini_map_scene->loadLinesFromFile();
    paths2 = mini_map_scene->getPaths();
/*******************************************************************/

    miniMap = mini_map_scene;
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::repaintMiniMap() {
    if (!sceneItemsDeleted && (actualMiniMapPath != -1)) {
        foreach(QGraphicsItem *line, miniMap->items())
        {
            miniMap->removeItem(line);
        }
        miniMap->setBackgroundBrush(Qt::white);
        sceneItemsDeleted = true;
    }
    if (getPathNumber() == 0) {
        int nextStopIndex = sched->getDriveStreet(paths.at(actualMiniMapPath)->getName());
        int i = 0;
        int x = 0;
        int y = 0;
        auto *text_name = new QGraphicsSimpleTextItem();
        text_name->setText("Stop " + QString::number(i));
        text_name->setRotation(-45);
        text_name->setPos(x,y);
        miniMap->addItem(text_name);
        foreach(QGraphicsItem *line, paths2.at(actualMiniMapPath)->getPath())
        {
            x = x + 60;
            ++i;
            auto *text = new QGraphicsSimpleTextItem();
            text->setText("Stop " + QString::number(i));
            text->setRotation(-45);
            text->setPos(x,y);
            miniMap->addItem(text);
            miniMap->addItem(line);
        }
        sceneItemsDeleted = false;
        miniMap->addEllipse(QRectF((nextStopIndex * 60) -5, 15, 8,8), QPen({Qt::red},9));
        auto *text = new QGraphicsTextItem("Next stop");
        text->setPos((nextStopIndex * 60) -5, 40);
        text->setDefaultTextColor(Qt::red);
        miniMap->addItem(text);
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
    qreal scale = n/90.0;
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
    // Hard repaint scene
    ui->graphicsView->scale(1.00000000001, 1.00000000001);

    /************************** ANIMATION ****************************/
    sched->start(*myTime, timeRev);

}

void MainWindow::speedUp() {
    if(timeSpeed != 1024) {
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

void MainWindow::setActualMiniMapPath(int value) {
    actualMiniMapPath = value;
}

int MainWindow::getPathNumber() {
    if (map->highlighted_name != "") {
        QString street = map->highlighted_name;
        QString number = street.remove(0,6);;
        setActualMiniMapPath(number.toInt());
        return 0;
    }
    else return -1;
}
