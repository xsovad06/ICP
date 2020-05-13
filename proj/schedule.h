/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
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
         * Create a time schedule of lines. There are slots for 5 paths.
         * To each path new Drive object is allocated.
         * List of path names is created.
         * \param paths QVector of all paths
         * \param scene pointer to graphics scene with map
         */
        Schedule(QVector<Path*> paths, QGraphicsScene *scene);
        //! A destructor.
        ~Schedule();

        //! A function that manages move of trams depending on actual time.
        /*!
         * \brief start
         * For actual time it searches match with an item in the time schedule of every path.
         * If the match is found the function for making a move is called.
         * \param actTime actual time
         * \param timeRev flag of reverse timer, false means regular timer
         */
        void start(QTime actTime,bool timeRev);
        //! A function that loads times for schedule from file.
        /*!
         * \brief loadTimes
         * Times of departures of each tram are read from file "stops.txt".
         * They are saved to a separate List for each path.
         */
        void loadTimes();
        //! A function that finds out index of next stop of tram on required path.
        /*!
         * \brief getDriveStreet
         * Just call another function Drive::getNextStreet() for corresponding path.
         * \param pathName name of path the next stop is needed for.
         * \return an index of next stop.
         */
        int getDriveStreet(QString pathName);

    private:
        QGraphicsScene *scene;          /*!< Pointer to scene where trams will be drawn */
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
        Drive *drive1;                  /*!< A Drive object for path1 */
        Drive *drive2;                  /*!< A Drive object for path2 */
        Drive *drive3;                  /*!< A Drive object for path3 */
        Drive *drive4;                  /*!< A Drive object for path4 */
        Drive *drive5;                  /*!< A Drive object for path5 */
};

#endif // SCHEDULE_H
