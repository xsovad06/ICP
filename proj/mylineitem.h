#ifndef MYLINEITEM_H
#define MYLINEITEM_H

#include <QGraphicsLineItem>

class MyLineItem : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    explicit MyLineItem(QColor color = Qt::black, QGraphicsItem *parent = nullptr);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

private slots:
    void repaint(int second);

private:
    qreal mTime = -1;
};

#endif // MYLINEITEM_H
