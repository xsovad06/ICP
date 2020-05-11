#include "path.h"
#define TIMERESERVE 3

Path::Path(QString newName, QList<QLine> lines, QColor clr, QObject *parent) : QObject(parent) {
    this->name = newName;
    int i = 0;
    for(auto line: lines)
    {
        ++i;
        auto *myline = new MyLineItem(clr);
        myline->setLine(line);
        this->path<<myline;
        int timeInSec = sqrt(line.dy() * line.dy() + line.dx() * line.dx());
        this->totalTime = this->totalTime + timeInSec +TIMERESERVE;
    }
    this->size = i;
}

int Path::getSize() {
    return size;
}

QList <MyLineItem*> Path::getPath() {
    return path;
}

void Path::setPathWidth(int penWidth, int penWidthStop) {
    foreach(MyLineItem *line, path)
    {
        line->setPenWidth(penWidth, penWidthStop);
    }
}

QString Path::getName() {
    return name;
}

int Path::getTotalTime() {
    return totalTime;
}

bool Path::getHighlighted() {
    return highlighted;
}

void Path::setHighlighted(bool value) {
    highlighted = value;
}
