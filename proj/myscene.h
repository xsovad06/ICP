#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>
#include "mylineitem.h"
#include "path.h"
#include "myscene2.h"

//!  Class represents scene with map.
/*!
  Scene is contains of streets whitch are joined into the path.
*/
class MyScene : public QGraphicsScene {
    public:
        //! A constructor.
        explicit MyScene(QObject *parent = nullptr);
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
        //! Create list of line with cordinates.
        /*!
          Load map of coordinates from file, store them to the list of lines.
        */
        void loadLinesFromFile();
        //! Convert string with street coordinates to json QString.
        /*!
          \return  String with coordinates of items from the map
        */
        QString toJson();
        //! Save json QString to file.
        void toFile();
        //! Get paths from the map.
        /*!
          \return  Vector of paths from the map
        */
        QVector<Path*> getPaths();

        bool pathHighlighted = false;   /*!< When path highlighted then true, false otherwise*/
        QString highlighted_name;       /*!< Name of the highlighted path*/
        int pathHighlightedIndex;       /*!< Index of the highlighted path*/

    protected:
        //! Method for highlighting path when clicked on the street.
        /*!
          Overriden method.
        */
        virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

        QList<MyLineItem*> lineList;    /*!< A list of references to MyLineItems object*/
        QList<QLine> loadedLines;       /*!< A list of Qline objects */
        QVector<Path*> paths;           /*!< A Vector of references to Path objects */

};

#endif // MYSCENE_H
