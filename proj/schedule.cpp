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

    this->spoj1.append(QTime(0,0,5,0));
    this->spoj1.append(QTime(0,5,5,0));
    this->spoj2.append(QTime(1,0,5,0));
    this->spoj2.append(QTime(0,1,5,0));
    this->spoj3.append(QTime(0,4,5,0));
    this->spoj4.append(QTime(1,2,0,0));
    this->spoj5.append(QTime(1,1,0,0));
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
