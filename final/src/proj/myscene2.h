/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
#ifndef MYSCENE2_H
#define MYSCENE2_H

#include <QGraphicsScene>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>
#include "mylineitem.h"
#include "path.h"

//!  Class represents small scene with highlighted path.
class MyScene2 : public QGraphicsScene {
    public:
        //! A constructor.
        /*!
         * \brief MyScene2
         * \param parent reference on parent object
         */
        explicit MyScene2(QObject *parent = nullptr);
        //! A Destructor.
        ~MyScene2();
        //! Method for creating path number 1.
        /*!
         * \brief createStreet1
         * Used for creating json file with street positions.
         * \param street_color represents path color
         */
        void createStreet1(QColor street_color = nullptr);
        //! Method for creating path number 2.
        /*!
         * \brief createStreet2
         * Used for creating json file with street positions.
         * \param street_color represents path color
         */
        void createStreet2(QColor street_color = nullptr);
        //! Method for creating path number 3.
        /*!
         * \brief createStreet3
         * Used for creating json file with street positions.
         * \param street_color represents path color
         */
        void createStreet3(QColor street_color = nullptr);
        //! Method for creating path number 4.
        /*!
         * \brief createStreet4
         * Used for creating json file with street positions.
         * \param street_color represents path color
         */
        void createStreet4(QColor street_color = nullptr);
        //! Method for creating path number 5.
        /*!
         * \brief createStreet5
         * Used for creating json file with street positions.
         * \param street_color represents path color
         */
        void createStreet5(QColor street_color = nullptr);
        //! Convert string with street coordinates to json QString.
        /*!
         * \brief toJson
         * \return String with coordinates of items from the map
         */
        QString toJson();
        //! Save json QString to file.
        /*!
         * \brief toFile
         */
        void toFile();
        //! Create list of line with cordinates.
        /*!
         * \brief loadLinesFromFile
         * Load map of coordinates from file, store them to the list of lines.
         */
        void loadLinesFromFile();
        //! Get paths from the map.
        /*!
         * \brief getPaths
         * \return Vector of paths from the map
         */
        QVector<Path*> getPaths();

    protected:
        QList<MyLineItem*> lineList;    /*!< A list of references to MyLineItems object representing one path*/
        QList<QLine> loadedLines;       /*!< A list of Qline objects representing streets loaded from json */
        QVector<Path*> paths;           /*!< A Vector of references to Path objects */
};

#endif // MYSCENE2_H
