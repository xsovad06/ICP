#include "mylineitem.h"
#include <QtDebug>
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

MyLineItem::MyLineItem(QColor color, QGraphicsItem *parent) : QObject(), QGraphicsLineItem(parent)
{
    setPen(QPen({color}, 3));
}

void MyLineItem::repaint(int second){
    mTime = second;
    update();
}

void MyLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->drawLine(line());
    painter->setPen(QPen({Qt::blue},5));
    painter->drawEllipse(line().pointAt(0), 2, 2);
    if(mTime != -1) {
        painter->setPen(QPen({Qt::red},5));
        painter->drawEllipse(line().pointAt(mTime), 3, 3);
    }
}
