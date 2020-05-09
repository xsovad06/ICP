#include "schedule.h"

Schedule::Schedule(QVector<Path*>paths, QGraphicsScene *scene)
{
   // allSpojs.insert(QTime(0,0,5,0),paths.at(0));
   // allSpojs.insert(QTime(1,5,0,0),paths.at(0));
    this->drive1=new Drive(paths.at(0), scene);
    this->drive2=new Drive(paths.at(1), scene);
    this->drive3=new Drive(paths.at(2), scene);
    this->drive4=new Drive(paths.at(3), scene);
    this->drive5=new Drive(paths.at(4), scene);

    this->path1=paths.at(0);
    this->path2=paths.at(1);
    this->path3=paths.at(2);
    this->path4=paths.at(3);
    this->path5=paths.at(4);

   /* this->spoj1.append(QTime(0,0,5,0));
    this->spoj1.append(QTime(0,5,5,0));
    this->spoj2.append(QTime(1,0,5,0));
    this->spoj2.append(QTime(0,1,5,0));
    this->spoj3.append(QTime(0,4,5,0));
    this->spoj4.append(QTime(1,2,0,0));
    this->spoj5.append(QTime(1,1,0,0));*/
    this->scene=scene;
}

void Schedule::start(QTime actTime, bool timeRev)
{
  /*  //for(auto sTime: allSpojs.keys())
    for(auto sTime: spoj1)
    {
        if((sTime<=actTime) && (actTime <= sTime.addSecs(allSpojs.value(sTime)->getTotalTime())))
        {
            drive1->move(timeRev);
        }
        else if(sTime.addSecs(allSpojs.value(sTime)->getTotalTime()+30)<=actTime &&
                actTime <= sTime.addSecs(allSpojs.value(sTime)->getTotalTime()*2+30))
        {
            drive1->moveBack(timeRev);
        }
    }*/

    for(auto sTime: spoj1)
    {
        if((sTime<=actTime) && (actTime <= sTime.addSecs(path1->getTotalTime())))
        {
            drive1->move(timeRev);
        }
        else if(sTime.addSecs(path1->getTotalTime()+30)<=actTime &&
                actTime <= sTime.addSecs(path1->getTotalTime()*2+30))
        {
            drive1->moveBack(timeRev);
        }
    }
    for(auto sTime: spoj2)
    {
        if((sTime<=actTime) && (actTime <= sTime.addSecs(path2->getTotalTime())))
        {
            drive2->move(timeRev);
        }
        else if(sTime.addSecs(path2->getTotalTime()+30)<=actTime &&
                actTime <= sTime.addSecs(path2->getTotalTime()*2+30))
        {
            drive2->moveBack(timeRev);
        }
    }
    for(auto sTime: spoj3)
    {
        if((sTime<=actTime) && (actTime <= sTime.addSecs(path3->getTotalTime())))
        {
            drive3->move(timeRev);
        }
        else if(sTime.addSecs(path3->getTotalTime()+30)<=actTime &&
                actTime <= sTime.addSecs(path3->getTotalTime()*2+30))
        {
            drive3->moveBack(timeRev);
        }
    }
    for(auto sTime: spoj4)
    {
        if((sTime<=actTime) && (actTime <= sTime.addSecs(path4->getTotalTime())))
        {
            drive4->move(timeRev);
        }
        else if(sTime.addSecs(path4->getTotalTime()+30)<=actTime &&
                actTime <= sTime.addSecs(path4->getTotalTime()*2+30))
        {
            drive4->moveBack(timeRev);
        }
    }
    for(auto sTime: spoj5)
    {
        if((sTime<=actTime) && (actTime <= sTime.addSecs(path5->getTotalTime())))
        {
            drive5->move(timeRev);
        }
        else if(sTime.addSecs(path5->getTotalTime()+30)<=actTime &&
                actTime <= sTime.addSecs(path5->getTotalTime()*2+30))
        {
            drive5->moveBack(timeRev);
        }
    }
}

Schedule::~Schedule()
{
    delete drive1;
    delete drive2;
    delete drive3;
    delete drive4;
    delete drive5;

}
void Schedule::loadTimes()
{
    QList<QString>pathNames;

    pathNames<<path1->getName()<<path2->getName()<<path3->getName()<<path4->getName()<<path5->getName();
    QFile file("/home/ixpo-u/Plocha/skola/icp/proj/stops.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString line;
        QList<QString> lineList;
        while (in.readLineInto(&line))
        {
            if(line!=";")
            {
                lineList<<line;
            }
            else
            {
                if(lineList.first()==pathNames.at(0))
                {
                    lineList.removeFirst();
                    for(auto time:lineList)
                    {
                        spoj1<<QTime::fromString(time);
                    }
                    lineList.clear();
                }
                else if(lineList.first()==pathNames.at(1))
                {
                    lineList.removeFirst();
                    for(auto time:lineList)
                    {
                        spoj2<<QTime::fromString(time);
                    }
                    lineList.clear();
                }
                else if(lineList.first()==pathNames.at(2))
                {
                    lineList.removeFirst();
                    for(auto time:lineList)
                    {
                        spoj3<<QTime::fromString(time);
                    }
                    lineList.clear();
                }
                else if(lineList.first()==pathNames.at(3))
                {
                    lineList.removeFirst();
                    for(auto time:lineList)
                    {
                        spoj4<<QTime::fromString(time);
                    }
                    lineList.clear();
                }
                else if(lineList.first()==pathNames.at(4))
                {
                    lineList.removeFirst();
                    for(auto time:lineList)
                    {
                        spoj5<<QTime::fromString(time);
                    }
                    lineList.clear();
                }
            }
        }
        file.close();
    }
}




















