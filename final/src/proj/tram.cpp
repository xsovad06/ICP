/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
#include "tram.h"
#include <QtDebug>
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Tram::Tram(QPointF *start, QPointF *end, float loc, QGraphicsItem *parent) :
    QObject(), QGraphicsEllipseItem(parent) {
    this->line = {*start, *end};
    this->loc = loc;
}

void Tram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QPen({Qt::black}, 5));
    painter->drawEllipse(line.pointAt(loc), 8, 8);
    painter->setPen(QPen({Qt::red}, 5));
    painter->drawEllipse(line.pointAt(loc), 4, 4);
}

