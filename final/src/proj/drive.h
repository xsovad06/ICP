/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
#ifndef DRIVE_H
#define DRIVE_H

#include <QObject>
#include <QTime>
#include "myscene.h"
#include "path.h"
#include "tram.h"

//!  Class responsible for animation of tram's moving.
/*!
 * \brief The Schedule class
 * For each path is created one Drive obj, which represents a tram and keeps information about its location.
 * There is only one tram for each path and it exists from the first start of the tram until the application is ended.
 */
class Drive {
    public:
        //! A constructor.
        /*!
         * \brief Drive
         * Just sets path and scene from parameters to obj attributes.
         * \param path pointer to path the tram is moving on.
         * \param scene pointer to graphics scene with map.
         */
        explicit Drive(Path * path, QGraphicsScene *scene);
        //! A function for animation of move forward - from start stop to end stop.
        /*!
         * \brief move
         * Changes location of tram to one part of street forward and calls new Tram obj to draw its position.
         * In case reverse time it does opposite way.
         * \param timeRev flag of reverse timer, false means regular timer.
         */
        void move(bool timeRev);
        //! A function for animation of move backward - from end stop to start stop.
        /*!
         * \brief moveBack
         * Changes location of tram to one part of street backward and calls new Tram obj to draw its position.
         * In case reverse time it does opposite way.
         * It works a little bit different than function move() with reverse time.
         * \param timeRev flag of reverse timer, false means regular time.r
         */
        void moveBack(bool timeRev);
        //! A function returns index of next street.
        /*!
         * \brief getDriveStreet
         * Gets obj attribute Street and inc/dec it according to which dirrection was made the last.
         * Plus fixes some possible bugs of overranged index.
         * \return an index of next stop.
         */
        int getNextStreet();

    private:
        Path *path;                 /*!< Pointer to path this Drive is corresponding to */
        QGraphicsScene *scene;      /*!< Pointer to scene the tram is animated */
        bool timeRev;               /*!< Flag that indicates reverse time */
        Tram *tram = nullptr;       /*!< Pointer to obj Tram in order to painting tram location */
        int street = 0;             /*!< Index of street the tram is located on */
        double part= 0;             /*!< Part of street the tram is located on */
        bool revDirection=false;    /*!< Item to save the last dirrection of move, false = forward */
};

#endif // DRIVE_H
