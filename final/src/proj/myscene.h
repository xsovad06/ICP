/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
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
 * \brief The MyScene class
 * Scene is contains of streets whitch are joined into the path.
 */
class MyScene : public QGraphicsScene {
    public:
        //! A constructor.
        /*!
         * \brief MyScene
         * \param parent reference on parent object
         */
        explicit MyScene(QObject *parent = nullptr);
        //! A destructor.
        ~MyScene();
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
        //! Create list of line with cordinates.
        /*!
         * \brief loadLinesFromFile
         * Load map of coordinates from file, store them to the list of lines.
         */
        void loadLinesFromFile();
        //! Convert string with street coordinates to json QString.
        /*!
         * \brief toJson
         * \return  String with coordinates of items from the map
         */
        QString toJson();
        //! Save json QString to file.
        /*!
         * \brief toFile
         */
        void toFile();
        //! Get paths from the map.
        /*!
         * \brief getPaths
         * \return  Vector of paths from the map
         */
        QVector<Path*> getPaths();

        bool pathHighlighted = false;   /*!< When path highlighted then true, false otherwise*/
        QString highlighted_name;       /*!< Name of the highlighted path*/
        int pathHighlightedIndex;       /*!< Index of the highlighted path*/

    protected:
        //! Method for highlighting path when clicked on the street.
        /*!
         * \brief mousePressEvent
         * Overriden method.
         * \param event
         */
        virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

        QList<MyLineItem*> lineList;    /*!< A list of references to MyLineItems object representing one path*/
        QList<QLine> loadedLines;       /*!< A list of Qline objects representing streets loaded from json */
        QVector<Path*> paths;           /*!< A Vector of references to Path objects */
};

#endif // MYSCENE_H
