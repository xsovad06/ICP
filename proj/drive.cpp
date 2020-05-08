#include "drive.h"

Drive::Drive(Path * path, QTime actTime, QGraphicsScene *scene)
{
    this->path=path;
    this->actTime=actTime;
    this->scene=scene;
}

void Drive::move(bool timeRev)
{
    if(street==0&&part==-1)
    {
        part=0;
    }
    if(street>=0 && street<path->getPath().size())
    {
        auto line =path->getPath().at(street);
        double dur =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
        if(part>=0&&part<=dur)
        {
            scene->removeItem(tram);
            auto s=line->line().p1();
            auto e=line->line().p2();
            tram = new Tram(&s,&e,part/dur);
            scene->addItem(tram);
            if(!timeRev)++part;
            else if(part>=0) --part;
            if(street==street<path->getPath().size()-1&&part==int(dur))
            {
                scene->removeItem(tram);
            }
        }
        else if(part==-1&&street==0)
        {
            part=0;
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
                if((street==path->getPath().size()-1)&&(part>0))
                {
                    part =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
                }
                else
                {
                    --street;
                    line =path->getPath().at(street);
                    part =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
                }
            }
        }
     }
    else
    {
        --street;
        auto line =path->getPath().at(street);
        part =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
    }
}

void Drive::moveBack(bool timeRev)
{
    if(street>=0 && street<path->getPath().size())
    {
        auto line =path->getPath().at(street);
        double dur =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
        if(part>=0&&part<=dur)
        {
            scene->removeItem(tram);

            auto s=line->line().p1();
            auto e=line->line().p2();
            tram = new Tram(&s,&e,part/dur);
            scene->addItem(tram);
            if(timeRev)++part;
            else if(part>=0) --part;
            if(street==street<path->getPath().size()-1&&part==dur)
            {
                scene->removeItem(tram);
            }
        }
        else
        {
            if(timeRev)
            {
                if(street==0 && part<0)
                {
                    part =0;
                }
                else
                {
                    ++street;
                    part=0;
                }

            }
            else if(street>0)
            {
                if((street==path->getPath().size()-1)&&(part>0))
                {
                    part =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
                }
                else
                {
                    --street;
                    line =path->getPath().at(street);
                    part =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
                }
            }
        }
     }
    else
    {
        --street;
        auto line =path->getPath().at(street);
        part =(sqrt(line->line().dy()*line->line().dy()+line->line().dx()*line->line().dx()));
    }
}
