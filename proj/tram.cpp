#include "tram.h"
#include <QtDebug>
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Tram::Tram(QPointF *start,QPointF *end,float loc, QGraphicsItem *parent) :
    QObject(), QGraphicsEllipseItem(parent)
{
 /*   QLineF line(*start,*end);
    this->location=*start;
    this->end=*end;
    anim=new QVariantAnimation(this);
    anim->setDuration(sqrt(line.dy()*line.dy()+line.dx()*line.dx())*1000);
    connect(anim, &QVariantAnimation::valueChanged,this,&Tram::onAnimation);
    anim->setStartValue(location);
    anim->setEndValue(*end);
    anim->start();*/

    this->line={*start,*end};
    this->loc = loc;









}

/*Tram::Tram(Path *path, QGraphicsItem *parent) :
    QObject(), QGraphicsEllipseItem(parent)
{
    this->path=path;
    auto line = path->getPath().first();
    this->location=line->line().p1();
    this->end=path->getPath().at(8)->line().p2();

    anim=new QVariantAnimation(this);
    anim->setDuration(5000);
    connect(anim, &QVariantAnimation::valueChanged,this,&Tram::onAnimation);

    anim->setStartValue(location);
    anim->setEndValue(end);

    anim->setKeyValueAt(0.5,path->getPath().at(0)->line().p2());
  /*  anim->setKeyValueAt(0.5,path->getPath().at(1)->line().p2());
    anim->setKeyValueAt(1,path->getPath().at(2)->line().p2());
    anim->setKeyValueAt(1,path->getPath().at(3)->line().p2());
    anim->setKeyValueAt(1,path->getPath().at(4)->line().p2());
    anim->setKeyValueAt(1,path->getPath().at(5)->line().p2());
    anim->setKeyValueAt(1,path->getPath().at(6)->line().p2());
    anim->setKeyValueAt(1,path->getPath().at(7)->line().p2());
    anim->start();
    //connect(anim,SIGNAL(finished()),this,SLOT(nextAnimation()));
}*/





void Tram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   /* painter->drawLine(line());
    painter->setPen(QPen({Qt::black},5));
    painter->drawEllipse(location, 10, 10);*/

    painter->drawLine(line);
    painter->setPen(QPen({Qt::black},5));
    painter->drawEllipse(line.pointAt(loc), 10, 10);


}

void Tram::onAnimation(const QVariant &val)
{
    location=val.toPointF();
    update();
}
void Tram::nextAnimation()
{
    qDebug()<<"rrr";
}
