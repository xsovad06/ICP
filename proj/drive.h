#ifndef DRIVE_H
#define DRIVE_H

#include <QObject>
#include <QTime>
#include "myscene.h"
#include "path.h"
#include "tram.h"

class Drive {
    public:
        explicit Drive(Path * path, QGraphicsScene *scene);
        void move(bool timeRev);
        void moveBack(bool timeRev);
        void setDirection(bool reverse);

    private:
        Path *path;
        QGraphicsScene *scene;
        bool timeRev;
        Tram *tram = nullptr;
        int street = 0;
        double part= 0;
};

#endif // DRIVE_H
