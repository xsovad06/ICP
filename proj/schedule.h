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
    Path* path1;
    Path* path2;
    Drive *drive1;
    Drive *drive2;


};

#endif // SCHEDULE_H
