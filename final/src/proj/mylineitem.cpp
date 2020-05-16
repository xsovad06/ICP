/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
#include "mylineitem.h"
#include <QtDebug>
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

MyLineItem::MyLineItem(QColor color, QGraphicsItem *parent) : QGraphicsLineItem(parent) {
    this->color = color;
    setPen(QPen({this->color}, penWidth));
}

void MyLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(pen());
    painter->drawLine(line());
    painter->setPen(QPen({Qt::blue}, penWidthStop));
    painter->drawEllipse(line().pointAt(0), 3, 3);
    painter->drawEllipse(line().pointAt(1), 3, 3);
}

void MyLineItem::setPenWidth(int penWidth, int penWidthStop) {
    this->penWidth = penWidth;
    this->penWidthStop = penWidthStop;
    setPen(QPen({this->color}, penWidth));
    update();
}
