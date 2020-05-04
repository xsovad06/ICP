#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    myTimer->setInterval(1000);
    myTime=new QTime(0,0,0);
    timeSpeed=1;

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
    *myTime=myTime->addSecs(timeSpeed);
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



























