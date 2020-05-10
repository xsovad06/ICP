#include "schedule.h"

#define W8ONENDSTOP 30

Schedule::Schedule(QVector<Path*>paths, QGraphicsScene *scene) {
    this->drive1 = new Drive(paths.at(0), scene);
    this->drive2 = new Drive(paths.at(1), scene);
    this->drive3 = new Drive(paths.at(2), scene);
    this->drive4 = new Drive(paths.at(3), scene);
    this->drive5 = new Drive(paths.at(4), scene);

    this->path1=paths.size()>0?paths.at(0):nullptr;
    this->path2=paths.size()>1?paths.at(1):nullptr;
    this->path3=paths.size()>2?paths.at(2):nullptr;
    this->path4=paths.size()>3?paths.at(3):nullptr;
    this->path5=paths.size()>4?paths.at(4):nullptr;

    this->scene = scene;
}

void Schedule::start(QTime actTime, bool timeRev) {
    for(auto sTime : spoj1)
    {
        if((sTime <= actTime) && (actTime <= sTime.addSecs(path1->getTotalTime()+10)))
        {
            drive1->move(timeRev);
        }
        else if(sTime.addSecs(path1->getTotalTime() + 30) <= actTime &&
                actTime <= sTime.addSecs(path1->getTotalTime() * 2 + W8ONENDSTOP))
        {
            drive1->moveBack(timeRev);
        }
    }
    for(auto sTime : spoj2)
    {
        if((sTime <= actTime) && (actTime <= sTime.addSecs(path2->getTotalTime())))
        {
            drive2->move(timeRev);
        }
        else if(sTime.addSecs(path2->getTotalTime() + 30) <= actTime &&
                actTime <= sTime.addSecs(path2->getTotalTime() * 2 + W8ONENDSTOP))
        {
            drive2->moveBack(timeRev);
        }
    }
    for(auto sTime : spoj3)
    {
        if((sTime <= actTime) && (actTime <= sTime.addSecs(path3->getTotalTime())))
        {
            drive3->move(timeRev);
        }
        else if(sTime.addSecs(path3->getTotalTime()+30) <= actTime &&
                actTime <= sTime.addSecs(path3->getTotalTime() * 2 + W8ONENDSTOP))
        {
            drive3->moveBack(timeRev);
        }
    }
    for(auto sTime : spoj4)
    {
        if((sTime <= actTime) && (actTime <= sTime.addSecs(path4->getTotalTime())))
        {
            drive4->move(timeRev);
        }
        else if(sTime.addSecs(path4->getTotalTime()+30) <= actTime &&
                actTime <= sTime.addSecs(path4->getTotalTime() * 2 + W8ONENDSTOP))
        {
            drive4->moveBack(timeRev);
        }
    }
    for(auto sTime : spoj5)
    {
        if((sTime <= actTime) && (actTime <= sTime.addSecs(path5->getTotalTime())))
        {
            drive5->move(timeRev);
        }
        else if(sTime.addSecs(path5->getTotalTime() + 30) <= actTime &&
                actTime <= sTime.addSecs(path5->getTotalTime() * 2 + W8ONENDSTOP))
        {
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
    QList<QString> pathNames;

    pathNames<<(path1!=nullptr?path1->getName():"nothing");
    pathNames<<(path2!=nullptr?path2->getName():"nothing");
    pathNames<<(path3!=nullptr?path3->getName():"nothing");
    pathNames<<(path4!=nullptr?path4->getName():"nothing");
    pathNames<<(path5!=nullptr?path5->getName():"nothing");

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
                    for(auto time: lineList)
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
