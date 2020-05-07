#include "drive.h"

Drive::Drive(Path * path, QTime actTime, QGraphicsScene *scene)
{
    this->path=path;
    this->actTime=actTime;
    this->scene=scene;
}

void Drive::move(bool timeRev)
{
    static int street = 0;
    static double part=0;
    if(street>=0 && street<path->getPath().size())
    {
        auto line =path->getPath().at(street);
        double dur =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
        if(part>=0&&part<=dur)
        {
            if(tram!=nullptr)
            {
                delete tram;
            }
            auto s=line->line().p1();
            auto e=line->line().p2();
            tram = new Tram(&s,&e,part/dur);
            scene->addItem(tram);
            if(!timeRev)++part;
            else if(part>=0) --part;
        }
        else
        {
            if(!timeRev)
            {
                ++street;
                part=0;
            }
            else if(street>0)
            {
                --street;
                line =path->getPath().at(street);
                part =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
            }
        }
     }
    qDebug()<<"street"<<street<<"part"<<part;
}
