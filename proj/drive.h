#ifndef DRIVE_H
#define DRIVE_H

#include <QObject>
#include <QTime>
#include "path.h"
#include "tram.h"

class Drive
{
public:
    explicit Drive(Path * path, QTime actTime, QGraphicsScene *scene);

    void move(bool timeRev);


private:
    Path *path;
    QTime actTime;
    QGraphicsScene *scene;
    bool timeRev;
    Tram *tram;
};

#endif // DRIVE_H
