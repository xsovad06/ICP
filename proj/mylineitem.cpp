#include "mylineitem.h"
#include <QtDebug>
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

MyLineItem::MyLineItem(QColor color, QGraphicsItem *parent) : QObject(), QGraphicsLineItem(parent)
{
    this->color = color;
    setPen(QPen({this->color}, penWidth));
}

void MyLineItem::repaint(int second){
    mTime = second;
    update();
}

void MyLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->drawLine(line());
    painter->setPen(QPen({Qt::blue}, penWidthStop));
    painter->drawEllipse(line().pointAt(0), 3, 3);
    /*if(mTime != -1) {
        painter->setPen(QPen({Qt::red},5));
        painter->drawEllipse(line().pointAt(mTime), 3, 3);
    }*/
}

void MyLineItem::setPenWidth(int penWidth, int penWidthStop)
{
    this->penWidth = penWidth;
    this->penWidthStop = penWidthStop;
    setPen(QPen({this->color}, penWidth));
    update();
}

int MyLineItem::getPenWidth()
{
    return penWidth;
}
