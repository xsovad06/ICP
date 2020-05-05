#ifndef MYLINEITEM_H
#define MYLINEITEM_H

#include <QGraphicsLineItem>

class MyLineItem : public QGraphicsLineItem
{
public:
    explicit MyLineItem(QColor color = Qt::black, QGraphicsItem *parent = nullptr);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

private:

};

#endif // MYLINEITEM_H
