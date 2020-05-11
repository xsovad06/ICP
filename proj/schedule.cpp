#include "schedule.h"

#define WAITONEND 30

Schedule::Schedule(QVector<Path*> paths, QGraphicsScene *scene) {
    this->drive1 = new Drive(paths.at(0), scene);
    this->drive2 = new Drive(paths.at(1), scene);
    this->drive3 = new Drive(paths.at(2), scene);
    this->drive4 = new Drive(paths.at(3), scene);
    this->drive5 = new Drive(paths.at(4), scene);


    this->path1 = paths.size() > 0 ? paths.at(0) : nullptr;
    this->path2 = paths.size() > 1 ? paths.at(1) : nullptr;
    this->path3 = paths.size() > 2 ? paths.at(2) : nullptr;
    this->path4 = paths.size() > 3 ? paths.at(3) : nullptr;
    this->path5 = paths.size() > 4 ? paths.at(4) : nullptr;

    pathNames<<(path1 != nullptr ? path1->getName() : "nothing");
    pathNames<<(path2 != nullptr ? path2->getName() : "nothing");
    pathNames<<(path3 != nullptr ? path3->getName() : "nothing");
    pathNames<<(path4 != nullptr ? path4->getName() : "nothing");
    pathNames<<(path5 != nullptr ? path5->getName() : "nothing");

    this->scene = scene;
}

void Schedule::start(QTime actTime, bool timeRev) {
    for(auto sTime : spoj1)
    {
        if ((sTime <= actTime) && (actTime <= sTime.addSecs(path1->getTotalTime()))) {
            drive1->move(timeRev);
        }
        else if (sTime.addSecs(path1->getTotalTime() + WAITONEND) <= actTime &&
                actTime <= sTime.addSecs(path1->getTotalTime() * 2 + WAITONEND)) {
            drive1->moveBack(timeRev);
        }
    }
    for(auto sTime : spoj2)
    {
        if ((sTime <= actTime) && (actTime <= sTime.addSecs(path2->getTotalTime()))) {
            drive2->move(timeRev);
        }
        else if (sTime.addSecs(path2->getTotalTime() + WAITONEND) <= actTime &&
                actTime <= sTime.addSecs(path2->getTotalTime() * 2 + WAITONEND)) {
            drive2->moveBack(timeRev);
        }
    }
    for(auto sTime : spoj3)
    {
        if ((sTime <= actTime) && (actTime <= sTime.addSecs(path3->getTotalTime()))) {
            drive3->move(timeRev);
        }
        else if (sTime.addSecs(path3->getTotalTime() + WAITONEND) <= actTime &&
                actTime <= sTime.addSecs(path3->getTotalTime() * 2 + WAITONEND)) {
            drive3->moveBack(timeRev);
        }
    }
    for(auto sTime : spoj4)
    {
        if ((sTime <= actTime) && (actTime <= sTime.addSecs(path4->getTotalTime()))) {
            drive4->move(timeRev);
        }
        else if (sTime.addSecs(path4->getTotalTime() + WAITONEND) <= actTime &&
                actTime <= sTime.addSecs(path4->getTotalTime() * 2 + WAITONEND)) {
            drive4->moveBack(timeRev);
        }
    }
    for(auto sTime : spoj5)
    {
        if ((sTime <= actTime) && (actTime <= sTime.addSecs(path5->getTotalTime()))) {
            drive5->move(timeRev);
        }
        else if (sTime.addSecs(path5->getTotalTime() + WAITONEND) <= actTime &&
                actTime <= sTime.addSecs(path5->getTotalTime() * 2 + WAITONEND)) {
            drive5->moveBack(timeRev);
        }
    }
}

Schedule::~Schedule() {
    delete drive1;
    delete drive2;
    delete drive3;
    delete drive4;
    delete drive5;

}

void Schedule::loadTimes() {
    QFile file("stops.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;
        QList<QString> lineList;
        while (in.readLineInto(&line))
        {
            if(line != ";") {
                lineList << line;
            }
            else {
                if(lineList.first() == pathNames.at(0)) {
                    lineList.removeFirst();
                    for(auto time : lineList)
                    {
                        spoj1 << QTime::fromString(time);
                    }
                    lineList.clear();
                }
                else if(lineList.first() == pathNames.at(1)) {
                    lineList.removeFirst();
                    for(auto time : lineList)
                    {
                        spoj2 << QTime::fromString(time);
                    }
                    lineList.clear();
                }
                else if(lineList.first() == pathNames.at(2)) {
                    lineList.removeFirst();
                    for(auto time : lineList)
                    {
                        spoj3 << QTime::fromString(time);
                    }
                    lineList.clear();
                }
                else if(lineList.first() == pathNames.at(3)) {
                    lineList.removeFirst();
                    for(auto time : lineList)
                    {
                        spoj4 << QTime::fromString(time);
                    }
                    lineList.clear();
                }
                else if(lineList.first() == pathNames.at(4)) {
                    lineList.removeFirst();
                    for(auto time : lineList)
                    {
                        spoj5 << QTime::fromString(time);
                    }
                    lineList.clear();
                }
            }
        }
        file.close();
    }
}

int Schedule::getDriveStreet(QString pathName)
{
    if (pathName == pathNames.at(0)) {
        return drive1->getNextStreet();
    }
    else if (pathName == pathNames.at(1)) {
        return drive2->getNextStreet();
    }
    else if (pathName == pathNames.at(2)) {
        return drive3->getNextStreet();
    }
    else if (pathName == pathNames.at(3)) {
        return drive4->getNextStreet();
    }
    else if (pathName == pathNames.at(4)) {
        return drive5->getNextStreet();
    }
    else {
        return -1;
    }
};
