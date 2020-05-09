#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <QTime>
#include "myscene.h"
#include "path.h"
#include "tram.h"
#include "drive.h"

class Schedule
{
public:
    Schedule(QVector<Path*>paths, QGraphicsScene *scene);
    ~Schedule();
    void start(QTime actTime,bool timeRev);


private:
    QMap <QTime,Path*> allSpojs;
    QGraphicsScene *scene;

    QList<QTime> spoj1;
    QList<QTime> spoj2;
    QList<QTime> spoj3;
    QList<QTime> spoj4;
    QList<QTime> spoj5;

    Path* path1;
    Path* path2;
    Path* path3;
    Path* path4;
    Path* path5;

    Drive *drive1;
    Drive *drive2;
    Drive *drive3;
    Drive *drive4;
    Drive *drive5;


};

#endif // SCHEDULE_H
