/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
#ifndef MYLINEITEM_H
#define MYLINEITEM_H

#include <QGraphicsLineItem>
//!  Class represents one street.
class MyLineItem : public QGraphicsLineItem {
    public:
        //! A constructor.
        /*!
          Save color to the class atribute and set pen parameters.
          \param color street color
        */
        explicit MyLineItem(QColor color = Qt::black, QGraphicsItem *parent = nullptr);
        //! Method for changing pen width.
        /*!
          Set pen width for street and for stop
          \param penWidth width of the street
          \param penWidthStop width of the stop
        */
        void setPenWidth(int penWidth, int penWidthStop);

    protected:
        //! Method paint street with stop at the begining.
        /*!
          Overriden method for painting.
        */
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

    private:
        int penWidth = 4;       /*!< Width of the street */
        int penWidthStop = 6;   /*!< Width for painting Stop */
        QColor color;           /*!< Color of the street */
};

#endif // MYLINEITEM_H
