/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
#ifndef PATH_H
#define PATH_H

#include <QObject>
#include <QtMath>
#include "mylineitem.h"

//!  Class represents one path of tram.
/*!
  Object is consist of MyLineItems.
*/
class Path : public QObject {
    Q_OBJECT
    public:
        //! A constructor.
        /*!
          Create path with saving path name, list of instace of MyLineItems,
          total time tram drive and size of the path.
          \param newName name of the path
          \param lines list of QLine items representing streets
          \param clr color of the path
        */
        Path(QString newName, QList<QLine> lines, QColor clr, QObject *parent = nullptr);
        //! Get size of the path.
        /*!
          \return integer equals to the number of streets
        */
        int getSize();
        //! Get whole path.
        /*!
          \return list of MyLineItems
        */
        QList <MyLineItem*> getPath();
        //! Get path name.
        /*!
          \return QString representing path name
        */
        QString getName();
        //! Get total time needed for one tram drive.
        /*!
          \return integer representing total time
        */
        int getTotalTime();
        //! Set widths of the pen for path painting.
        /*!
          \param penWidth iteger representing width of pen for streets painting
          \param penWidthStop iteger representing width of pen for painting stops
        */
        void setPathWidth(int penWidth, int penWidthStop);
        //! Get value of atribute this->highlighted.
        /*!
          \return bool representing value of atribute this->highlighted
        */
        bool getHighlighted();
        //! Set value of atribute this->highlighted.
        /*!
          \param value bool representing value to be set
        */
        void setHighlighted(bool value);

    private:
        QString name;               /*!< Name of the path */
        QList <MyLineItem*> path;   /*!< QList of MyLineItems(streets) */
        int size;                   /*!< Size of the path(count of streets) */
        int totalTime = 0;          /*!< Total ride time of tram(one journey) */
        bool highlighted = false;   /*!< Bool representing if path is highlighted */
};

#endif // PATH_H
