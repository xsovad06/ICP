#ifndef PATH_H
#define PATH_H

#include <QObject>
#include "mylineitem.h"
#include <QtMath>
//#include <QList>


class Path : public QObject {
    Q_OBJECT
    public:
        //explicit Path(QObject *parent = nullptr);
        Path(QString newName, QList<QLine> lines, QColor clr = Qt::black, QObject *parent = nullptr);
        int getSize();
        QList <MyLineItem*> getPath();
        QString getName();
        int getTotalTime();
        void setPathWidth(int penWidth, int penWidthStop);
        bool highlighted = false;

    private:
        QString name;
        QList <MyLineItem*> path;
        int size;
        int totalTime = 0;
};

#endif // PATH_H
