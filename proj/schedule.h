#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QTime>
#include "myscene.h"
#include "path.h"
#include "tram.h"
#include "drive.h"

//!  Class represents schedule for tram rides.
/*!
 * \brief The Schedule class
 */
class Schedule {
    public:
        //! A constructor.
        /*!
         * \brief Schedule
         * \param paths QVector of all paths
         * \param scene pointer to graphics scene
         */
        Schedule(QVector<Path*> paths, QGraphicsScene *scene);
        //! A destructor.
        ~Schedule();

        //! TODO
        /*!
         * \brief start
         * \param actTime
         * \param timeRev
         */
        void start(QTime actTime,bool timeRev);
        //! TODO
        /*!
         * \brief loadTimes
         */
        void loadTimes();
        //! TODO
        /*!
         * \brief getDriveStreet
         * \param pathName
         * \return
         */
        int getDriveStreet(QString pathName);

    private:
        QMap <QTime,Path*> allSpojs;    /*!< QMap of ride time and a path */
        QGraphicsScene *scene;          /*!< Pointer to scene with all objects */
        QList<QString> pathNames;       /*!< QList of path names */
        QList<QTime> spoj1;             /*!< QList of start times for path1 */
        QList<QTime> spoj2;             /*!< QList of start times for path2 */
        QList<QTime> spoj3;             /*!< QList of start times for path3 */
        QList<QTime> spoj4;             /*!< QList of start times for path4 */
        QList<QTime> spoj5;             /*!< QList of start times for path5 */
        Path* path1;                    /*!< Pointer to path1 */
        Path* path2;                    /*!< Pointer to path2 */
        Path* path3;                    /*!< Pointer to path3 */
        Path* path4;                    /*!< Pointer to path4 */
        Path* path5;                    /*!< Pointer to path5 */
        Drive *drive1;                  /*!< Pointer to drive1 */
        Drive *drive2;                  /*!< Pointer to drive2 */
        Drive *drive3;                  /*!< Pointer to drive3 */
        Drive *drive4;                  /*!< Pointer to drive4 */
        Drive *drive5;                  /*!< Pointer to drive5 */
};

#endif // SCHEDULE_H
