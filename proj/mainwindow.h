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
        //! A constructor.
        MainWindow(QWidget *parent = nullptr);
        //! A Destructor.
        ~MainWindow();
        //! Method get highlighted path numember to this->actualMiniMapPath.
        /*!
          From name of path extract index of highlighted path
          use this->setActualMiniMapPath(int value) to access
          class atribute this->actualMiniMapPath.
          \retval 0 if success, -1 otherwise
        */
        int getPathNumber();
        //! Method set atribute this->actualMiniMapPath.
        /*!
          \param value new value to be set
        */
        void setActualMiniMapPath(int value);

    private:
        //! Method get highlighted path numember to this->actualMiniMapPath.
        /*!
          From name of path extract index of highlighted path
          use this->setActualMiniMapPath(int value) to access
          class atribute this->actualMiniMapPath
        */
        void init_scene();
        void init_scene2();
        Ui::MainWindow *ui;             /*!< Pointer to instace of object MainWindow, main application object*/
        QTimer *myTimer;                /*!< Pointer to instace of object QTimer*/
        QTime *myTime;                  /*!< Pointer to instace of object QTime*/
        float timeSpeed;                /*!< Value represent speed of time flow*/
        bool timeRev = false;           /*!< Bool represents time reverse flow*/
        QVector <Path*> paths;          /*!< Vector of list of each street in the map*/
        QVector <Path*> paths2;         /*!< Vector of list of each street in the minimap*/
        Schedule *sched;                /*!< Pointer to instace of object Schedule*/
        int actualMiniMapPath = -1;     /*!< Index od highlighted path in the map*/
        bool sceneItemsDeleted = false; /*!< Bool represents deleted items in minimap*/
        MyScene* map;                   /*!< Pointer to instace of object MyScene, Map scene*/
        MyScene2* miniMap;              /*!< Pointer to instace of object MyScene2, MiniMap scene*/

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
