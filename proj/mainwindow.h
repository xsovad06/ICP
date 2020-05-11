#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdlib.h>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QJsonDocument>
#include <QMainWindow>
#include "myscene.h"
#include "myscene2.h"
#include "mylineitem.h"
#include "path.h"
#include "drive.h"
#include "schedule.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        int getPathNumber();
        void setActualMiniMapPath(int value);

    private:
        void init_scene();
        void init_scene2();
        Ui::MainWindow *ui;
        QTimer *myTimer;
        QTime *myTime;
        float timeSpeed;
        bool timeRev = false;
        QVector <Path*> paths;
        QVector <Path*> paths2;
        Schedule *sched;
        int actualMiniMapPath = -1;
        bool deleted = false;
        MyScene2* miniMap;
        MyScene* map;

    private slots:
        void zoom_in();
        void zoom_out();
        void zoom_slider(int n);
        void startTimer();
        void onTimer();
        void speedUp();
        void speedDown();
        void speedReverse();
        void repaintMiniMap();
};
#endif // MAINWINDOW_H
