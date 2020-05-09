#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>
#include "path.h"

//!  Class represents scene with map.
/*!
  Scene is contains of streets whitch are joined into the path.
*/
class MyScene : public QGraphicsScene {
    public:
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
        void loadLinesfromFile();
        //! Create vector of lists of Line items.
        /*!
          From loaded data create vector of lists of Line items
          that represents appropriate path.
        */
        void setPaths();
        //! Return created vector.
        QVector<Path*> getPaths();
        //! Convert string with street coordinates to json QString.
        QString toJson();
        //! Save json QString to file.
        void toFile();
        bool pathHighlighted = false;   /*!< If path highlighted then true, false otherwise*/


    protected:
        QList<MyLineItem*> lineList;    /*!< A list of references to MyLineItems object*/
        QList<QLine> loadedLines;       /*!< A list of Qline objects */
        QVector<Path*> paths;           /*!< A Vector of references to Path objects */

        //! Method for highlighting path when clicked on the street.
        /*!
          Overriden method.
        */
        virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MYSCENE_H
