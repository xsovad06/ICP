#include "path.h"

Path::Path(QString newName, QList<QLine> lines, QColor clr, QObject *parent) : QObject(parent)
{
    this->name = newName;
    int i=0;
    for(auto line: lines)
    {
        ++i;
        auto *myline = new MyLineItem(clr);
        myline->setLine(line);
        int timeInSec = sqrt(line.dy()*line.dy()+line.dx()*line.dx());
        this->total_time = this->total_time + timeInSec;
        this->path<<myline;
    }
    this->size = i;
}

int Path::getSize()
{
    return this->size;
}

QList <MyLineItem*> Path::getPath()
{
    return path;

}
QString Path::getName()
{
    return name;
}

int Path::getTotalTime()
{
    return this->total_time;
}

