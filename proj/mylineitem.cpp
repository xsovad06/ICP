#include "mylineitem.h"
#include <QtDebug>
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

MyLineItem::MyLineItem(QColor color, QGraphicsItem *parent) : QGraphicsLineItem(parent)
{
    setPen(QPen({color}, 3));
}

void MyLineItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
  //  qDebug() << event->pos() << event->scenePos() << event->screenPos() << endl;
  //  QGraphicsLineItem::mousePressEvent(event);
}

void MyLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->drawLine(line());
    painter->setPen(QPen({Qt::blue},5));
    painter->drawEllipse(line().pointAt(0), 2, 2);
    painter->drawEllipse(line().pointAt(1), 2, 2);
}


