#include "drive.h"

Drive::Drive(Path * path, QGraphicsScene *scene) {
    this->path = path;
    this->scene = scene;
}

void Drive::move(bool timeRev) {
    if (street == 0 && part <0) {
        part = 0;
    }
                                //number of street in this path
    if (street >= 0 && street < path->getPath().size()) {
        //concrete street of path
        auto line = path->getPath().at(street);
        // duration of the street in pixels aka seconds
        double dur = (sqrt(line->line().dy() * line->line().dy() + line->line().dx() * line->line().dx()));
        //if tram is in interval of the street
        if (part >= 0 && part <= dur) {
            if(tram != nullptr){
              //delete tram from last move
                delete tram;
            }
            //start point and end point of street
            auto s = line->line().p1();
            auto e = line->line().p2();
            //paint a new tram position
            tram = new Tram(&s, &e, part / dur);
            scene->addItem(tram);
            //change tram position
            if (!timeRev){
                ++part;
            }
            else if (part >= 0){
            --part;
            }
        }
        else {
            //move to another street
            if (!timeRev) {
                ++street;
                part = 0;
            }
            // time is reversed, dont change street
            else if ((part > 0)) {
                part = (sqrt(line->line().dy() * line->line().dy() + line->line().dx()*line->line().dx()));
            }
            // change street
            else {
                --street;
                line = path->getPath().at(street);
                part = (sqrt(line->line().dy() * line->line().dy() + line->line().dx() * line->line().dx()));
            }
        }
     }
    else {
        --street;
        auto line = path->getPath().at(street);
        part = (sqrt(line->line().dy() * line->line().dy() + line->line().dx() * line->line().dx()));
    }
}

void Drive::moveBack(bool timeRev) {
    if (street >= 0 && street < path->getPath().size()) {
        auto line = path->getPath().at(street);
        double dur = (sqrt(line->line().dy() * line->line().dy() + line->line().dx() * line->line().dx()));

        if (part >= 0 && part <= dur) {
            delete tram;
            auto s = line->line().p1();
            auto e = line->line().p2();
            tram = new Tram(&s, &e, part / dur);
            scene->addItem(tram);
            if (timeRev){
                ++part;
            }
            else if (part >= 0){
                --part;
            }
        }
        else {
            if (timeRev) {
                if (street == 0 && part < 0) {
                    part = 0;
                }
                else {
                    ++street;
                    part = 0;
                }
            }
            else if (street > 0) {
                if ((part > 0)) {
                    part = (sqrt(line->line().dy() * line->line().dy() + line->line().dx() * line->line().dx()));
                }
                else {
                    --street;
                    line = path->getPath().at(street);
                    part = (sqrt(line->line().dy() * line->line().dy() + line->line().dx() * line->line().dx()));
                }
            }
        }
     }
    else {
        --street;
        auto line = path->getPath().at(street);
        part = (sqrt(line->line().dy() * line->line().dy() + line->line().dx() * line->line().dx()));
    }
}
