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

//!  Class represents main window.
/*!
 * \brief The MainWindow class
 * All objects are calling here.
 * This object is setup as user interface object.
 * Timer and time is initialized and started here.
 * Map and minimap initialization.
 * Schedule for all paths is setup here.
 * All connections are created here, zoom handler, time and speed
 * handler and connection for updating minimap
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        //! A constructor.
        /*!
         * \brief MainWindow
         * \param parent
         */
        MainWindow(QWidget *parent = nullptr);
        //! A Destructor.
        ~MainWindow();
        //! Method get highlighted path numember to this->actualMiniMapPath
        /*!
         * \brief getPathNumber
         * From name of path extract index of highlighted path
         * use this->setActualMiniMapPath(int value) to access
         * class atribute this->actualMiniMapPath.
         * \return integer representing result of function
         */
        int getPathNumber();
        //! Method set atribute this->actualMiniMapPath.
        /*!
         * \brief setActualMiniMapPath
         * \param value new value to be set
         */
        void setActualMiniMapPath(int value);

    private:
        //! Initialization of object MyScene.
        /*!
         * \brief init_scene
         * Connect graphic view form GUI to object MyScene, Load map from file,
         * stores data about paths, add paths to the scene object.
         */
        void init_scene();
        //! Initialization of object MyScene2.
        /*!
         * \brief init_scene2
         * Connect graphic view for minimap form GUI to object MyScene,
         * Load data about paths from file, stores data about paths.
         */
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
        //! Slot for zoom in button.
        /*!
         * \brief zoom_in
         * Handle with zoom in button, scale graphics view and increase value in zoom slider.
         */
        void zoom_in();
        //! Slot for zoom out button.
        /*!
         * \brief zoom_out
         * Handle with zoom out button, scale graphics view and decrease value in zoom slider.
         */
        void zoom_out();
        //! Slot for zoom slider.
        /*!
         * \brief zoom_slider
         * Handle with zoom slider, scale graphics view using transform matrix.
         * \param n integer representing value to be set
         */
        void zoom_slider(int n);
        //! Slot hadle with timer.
        /*!
         * \brief startTimer
         * Activate or deactivate timer.
         */
        void startTimer();
        //! Slot hadle with actions every time tick.
        /*!
         * \brief onTimer
         * Printing timer time, handle with reverse flow, handle with time speed, repain scene
         * start control proces of trams.
         */
        void onTimer();
        //! Slot hadle with time speed up.
        /*!
         * \brief speedUp
         * Increase time speed and print actual speed.
         */
        void speedUp();
        //! Slot hadle with time speed down.
        /*!
         * \brief speedDown
         * Decrease time speed and print actual speed.
         */
        void speedDown();
        //! Slot hadle with reverse time flow.
        /*!
         * \brief speedReverse
         * Activate or deactivate time reverse flow.
         */
        void speedReverse();
        //! Slot hadle with repainting minimap.
        /*!
         * \brief repaintMiniMap
         * Called on every timer tick, show path with all stops,
         * show next stop of tram, by adding items to the scene
         * and deleting them.
         */
        void repaintMiniMap();
};
#endif // MAINWINDOW_H
