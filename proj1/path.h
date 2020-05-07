#ifndef PATH_H
#define PATH_H

#include <QObject>
#include "myscene.h"
#include "mylineitem.h"
#include <QtMath>


class Path : public QObject
{
    Q_OBJECT
public:
    //explicit Path(QObject *parent = nullptr);
    Path(QString newName,QList<QLine> lines, QColor clr=Qt::black, QObject *parent = nullptr);
    int getSize();
    QList <MyLineItem*> getPath();
    QString getName();

private:
    QString name;
    //roads 1 by 1 with their times
    QList <MyLineItem*> path;
    int size;
};

#endif // PATH_H
