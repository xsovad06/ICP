#include "path.h"

Path::Path(QString newName,QList<QLine> lines, QColor clr, QObject *parent) : QObject(parent)
{
    this->name=newName;
    int i=0;
    for(auto line:lines)
    {
        ++i;
        auto *myline = new MyLineItem(clr);
        myline->setLine(line);
        int timeInSec = 10;
        this->path.insert(myline,timeInSec);
    }
    this->size=i;
}

int Path::getSize()
{
    return this->size;
}
QMap <MyLineItem*,int> Path::getPath()
{
    return path;
}
QString Path::getName()
{
    return name;
}
