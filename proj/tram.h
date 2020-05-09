#ifndef TRAM_H
#define TRAM_H

#include <QGraphicsEllipseItem>
#include <QVariantAnimation>
#include <QtDebug>
#include <QPen>
#include <QPainter>
#include "path.h"



class Tram : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
    public:
        explicit Tram(QPointF *start,QPointF *end, float loc, QGraphicsItem *parent = nullptr);
        //explicit Tram(Path *path, QGraphicsItem *parent = nullptr);


    protected:
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

    private:
        QLineF line;
        float loc;

};

#endif // TRAM_H
