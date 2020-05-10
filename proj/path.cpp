#include "path.h"

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
        this->totalTime = this->totalTime + timeInSec;
    }
    this->size = i;
}

int Path::getSize() {
    return this->size;
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
    return this->totalTime;
}

