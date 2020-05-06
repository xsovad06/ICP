#include "myscene.h"
#include <QDebug>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{

}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    for (auto *item: items(event->scenePos()))
    {
        if (auto street = dynamic_cast<QGraphicsLineItem*>(item); street) {
            qDebug() << "Street." << endl;
        }
    }
}

void MyScene::createStreet1(QColor street_color)
{
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    auto *line6 = new MyLineItem(street_color);
    auto *line7 = new MyLineItem(street_color);
    auto *line8 = new MyLineItem(street_color);
    auto *line9 = new MyLineItem(street_color);
    line1->setLine(0,0,150,200);
    line2->setLine(150,200,170,300);
    line3->setLine(170,300,200,320);
    line4->setLine(200,320,270,305);
    line5->setLine(270,305,300,280);
    line6->setLine(300,280,400,200);
    line7->setLine(400,200,420,100);
    line8->setLine(420,100,500,47);
    line9->setLine(500,47,580,32);
    addItem(line1);
    addItem(line2);
    addItem(line3);
    addItem(line4);
    addItem(line5);
    addItem(line6);
    addItem(line7);
    addItem(line8);
    addItem(line9);

    lineList<<line1;
    lineList<<line2;
    lineList<<line3;
    lineList<<line4;
    lineList<<line5;
    lineList<<line6;
    lineList<<line7;
    lineList<<line8;
    lineList<<line9;
}

void MyScene::createStreet2(QColor street_color)
{
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    line1->setLine(0,300,50,250);
    line2->setLine(50,250,70,190);
    line3->setLine(70,190,150,100);
    line4->setLine(150,100,190,50);
    line5->setLine(190,50,315,5);
    addItem(line1);
    addItem(line2);
    addItem(line3);
    addItem(line4);
    addItem(line5);

    lineList<<line1;
    lineList<<line2;
    lineList<<line3;
    lineList<<line4;
    lineList<<line5;
}

void MyScene::createStreet3(QColor street_color)
{
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    auto *line6 = new MyLineItem(street_color);
    auto *line7 = new MyLineItem(street_color);
    line1->setLine(10,95,80,25);
    line2->setLine(80,25,130,30);
    line3->setLine(130,30,190,48);
    line4->setLine(190,48,315,3);
    line5->setLine(315,3,420,5);
    line6->setLine(420,5,500,45);
    line7->setLine(500,45,580,30);
    addItem(line1);
    addItem(line2);
    addItem(line3);
    addItem(line4);
    addItem(line5);
    addItem(line6);
    addItem(line7);

    lineList<<line1;
    lineList<<line2;
    lineList<<line3;
    lineList<<line4;
    lineList<<line5;
    lineList<<line6;
    lineList<<line7;
}
void MyScene::createStreet4(QColor street_color)
{
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    auto *line6 = new MyLineItem(street_color);
    auto *line7 = new MyLineItem(street_color);
    auto *line8 = new MyLineItem(street_color);
    line1->setLine(250,5,300,45);
    line2->setLine(300,45,375,47);
    line3->setLine(375,47,418,100);
    line4->setLine(418,100,398,200);
    line5->setLine(398,200,420,245);
    line6->setLine(420,245,512,300);
    line7->setLine(512,300,590,315);
    line8->setLine(590,315,630,387);
    addItem(line1);
    addItem(line2);
    addItem(line3);
    addItem(line4);
    addItem(line5);
    addItem(line6);
    addItem(line7);
    addItem(line8);

    lineList<<line1;
    lineList<<line2;
    lineList<<line3;
    lineList<<line4;
    lineList<<line5;
    lineList<<line6;
    lineList<<line7;
    lineList<<line8;
}

void MyScene::createStreet5(QColor street_color)
{
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    auto *line6 = new MyLineItem(street_color);
    auto *line7 = new MyLineItem(street_color);
    line1->setLine(300,370,270,305);
    line2->setLine(270,305,260,240);
    line3->setLine(260,240,265,180);
    line4->setLine(265,180,325,115);
    line5->setLine(325,115,418,100);
    line6->setLine(418,100,485,150);
    line7->setLine(485,150,600,175);
    addItem(line1);
    addItem(line2);
    addItem(line3);
    addItem(line4);
    addItem(line5);
    addItem(line6);
    addItem(line7);

    lineList<<line1;
    lineList<<line2;
    lineList<<line3;
    lineList<<line4;
    lineList<<line5;
    lineList<<line6;
    lineList<<line7;
}

//convert lines form MyScene->lineList to json QString
QString MyScene::toJson()
{
    QJsonDocument jDoc;
    QJsonObject jObj;
    QJsonArray jArr;

    for(auto itm:lineList)
    {
        jArr.append(QJsonObject({{"x1",itm->line().x1()},{"y1",itm->line().y1()},
                                 {"x2",itm->line().x2()},{"y2",itm->line().y2()}}));
    }
    jObj={{"lines",jArr}};
    jDoc.setObject(jObj);
    return jDoc.toJson(QJsonDocument::Compact);
}
// save json QString to file
void MyScene::toFile()
{
    QString str=toJson();
    QFile file("json.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << str;
        file.close();
    }
}
//load lines from file to MyScene::loadedLines
void MyScene::fromFile()
{
    QString str=toJson();
    QFile file("/home/dami/Dokumenty/2BITlet/ICP/json.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument jDoc = QJsonDocument::fromJson(data);
        QJsonObject jObj = jDoc.object();
        QJsonArray posArr = jObj.value("lines").toArray();
        foreach(const QJsonValue & val, posArr)
        {
            int x1=val.toObject().value("x1").toInt();
            int x2=val.toObject().value("x2").toInt();
            int y1=val.toObject().value("y1").toInt();
            int y2=val.toObject().value("y2").toInt();
            loadedLines<<QLine(x1,y1,x2,y2);
        }
    }
}

//add lines from MyScene::loadedLines to scene
void MyScene::loadLines()
{
    fromFile();
    for(auto line : loadedLines)
    {
        auto line_1 = new MyLineItem(Qt::gray);
        line_1->setLine(line);
        addItem(line_1);
        //addLine(line);
    }
    /*auto virtual_line = new MyLineItem();
    virtual_line->paint_ellipse(, 600, 175);
     line7->setLine(485,150,600,175);
     line8->setLine(590,315,630,387);
     line7->setLine(500,45,580,30);
     line9->setLine(500,47,580,32);*/
}
