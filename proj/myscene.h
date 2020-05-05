#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include "mylineitem.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject *parent = nullptr);
    void createStreet1(QColor street_color = nullptr);
    void createStreet2(QColor street_color = nullptr);
    void createStreet3(QColor street_color = nullptr);
    void createStreet4(QColor street_color = nullptr);
    void createStreet5(QColor street_color = nullptr);


    QString toJson();
    void toFile();
    void fromFile();
    void loadLines();
protected:
    QList <MyLineItem*> lineList;
    QList<QLine> loadedLines;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    //virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    //virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:

};

#endif // MYSCENE_H
