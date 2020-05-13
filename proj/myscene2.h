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
        explicit MyScene2(QObject *parent = nullptr);
        //! A Destructor.
        ~MyScene2();
        //! Method for creating path.
        /*!
        Used for creating json file with street positions.
        */
        void createStreet1(QColor street_color = nullptr);
        //! Method for creating path.
        /*!
          Used for creating json file with street positions.
        */
        void createStreet2(QColor street_color = nullptr);
        //! Method for creating path.
        /*!
          Used for creating json file with street positions.
        */
        void createStreet3(QColor street_color = nullptr);
        //! Method for creating path.
        /*!
          Used for creating json file with street positions.
        */
        void createStreet4(QColor street_color = nullptr);
        //! Method for creating path.
        /*!
          Used for creating json file with street positions.
        */
        void createStreet5(QColor street_color = nullptr);
        //! Convert string with street coordinates to json QString.
        /*!
          \return  String with coordinates of items from the map
        */
        QString toJson();
        //! Save json QString to file.
        void toFile();
        //! Create list of line with cordinates.
        /*!
          Load map of coordinates from file, store them to the list of lines.
        */
        void loadLinesFromFile();
        //! Get paths from the map.
        /*!
          \return  Vector of paths from the map
        */
        QVector<Path*> getPaths();

    protected:
        QList<MyLineItem*> lineList;    /*!< A list of references to MyLineItems object*/
        QList<QLine> loadedLines;       /*!< A list of Qline objects */
        QVector<Path*> paths;           /*!< A Vector of references to Path objects */
};

#endif // MYSCENE2_H
