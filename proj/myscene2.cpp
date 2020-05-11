#include "myscene2.h"

MyScene2::MyScene2(QObject *parent) : QGraphicsScene(parent) {}

void MyScene2::createStreet1(QColor street_color) {
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    auto *line6 = new MyLineItem(street_color);
    auto *line7 = new MyLineItem(street_color);
    auto *line8 = new MyLineItem(street_color);
    auto *line9 = new MyLineItem(street_color);
    line1->setLine(0,35,60,35);
    line2->setLine(60,35,120,35);
    line3->setLine(120,35,180,35);
    line4->setLine(180,35,240,35);
    line5->setLine(240,35,300,35);
    line6->setLine(300,35,360,35);
    line7->setLine(360,35,420,35);
    line8->setLine(420,35,480,35);
    line9->setLine(480,35,540,35);
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

void MyScene2::createStreet2(QColor street_color) {
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    line1->setLine(0,35,60,35);
    line2->setLine(60,35,120,35);
    line3->setLine(120,35,180,35);
    line4->setLine(180,35,240,35);
    line5->setLine(240,35,300,35);
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

void MyScene2::createStreet3(QColor street_color) {
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    auto *line6 = new MyLineItem(street_color);
    auto *line7 = new MyLineItem(street_color);
    line1->setLine(0,35,60,35);
    line2->setLine(60,35,120,35);
    line3->setLine(120,35,180,35);
    line4->setLine(180,35,240,35);
    line5->setLine(240,35,300,35);
    line6->setLine(300,35,360,35);
    line7->setLine(360,35,420,35);
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

void MyScene2::createStreet4(QColor street_color ) {
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    auto *line6 = new MyLineItem(street_color);
    auto *line7 = new MyLineItem(street_color);
    auto *line8 = new MyLineItem(street_color);
    line1->setLine(0,35,60,35);
    line2->setLine(60,35,120,35);
    line3->setLine(120,35,180,35);
    line4->setLine(180,35,240,35);
    line5->setLine(240,35,300,35);
    line6->setLine(300,35,360,35);
    line7->setLine(360,35,420,35);
    line8->setLine(420,35,480,35);
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

void MyScene2::createStreet5(QColor street_color) {
    auto *line1 = new MyLineItem(street_color);
    auto *line2 = new MyLineItem(street_color);
    auto *line3 = new MyLineItem(street_color);
    auto *line4 = new MyLineItem(street_color);
    auto *line5 = new MyLineItem(street_color);
    auto *line6 = new MyLineItem(street_color);
    auto *line7 = new MyLineItem(street_color);
    line1->setLine(0,35,60,35);
    line2->setLine(60,35,120,35);
    line3->setLine(120,35,180,35);
    line4->setLine(180,35,240,35);
    line5->setLine(240,35,300,35);
    line6->setLine(300,35,360,35);
    line7->setLine(360,35,420,35);
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

QString MyScene2::toJson() {
    QJsonDocument jDoc;
    QJsonObject jObj;
    int j = 0;
    for(int i = 0; i < 5; ++i)
    {
        QJsonArray jArr;
        while(j < lineList.size())
        {
            jArr.append(QJsonObject({{"x1", lineList.at(j)->line().x1()}, {"y1", lineList.at(j)->line().y1()},
                                     {"x2", lineList.at(j)->line().x2()}, {"y2", lineList.at(j)->line().y2()}}));
            ++j;
            if(j == 9 || j == 14 || j == 21 || j == 29 || j == 36)
            {
                jObj.insert("street" + QString::number(i), jArr);
                break;
            }
        }
    }
    jDoc.setObject(jObj);
    return jDoc.toJson(QJsonDocument::Compact);
}

void MyScene2::toFile() {
    QString str = toJson();
    QFile file("json2.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << str;
        file.close();
    }
}

void MyScene2::loadLinesFromFile() {
    QFile file("/home/dami/Dokumenty/2BITlet/ICP/json2.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument jDoc = QJsonDocument::fromJson(data);
        QJsonObject jObj = jDoc.object();
        Path * pathPtr;
        QList<QColor> clrs = {Qt::blue, Qt::red, Qt::green, Qt::yellow, Qt::darkGray};

        for(int i = 0; i < jObj.keys().size(); ++i)
        {
            QJsonArray posArr = jObj.value("street" + QString::number(i)).toArray();
            QList<QLine> lineGroup;
            foreach(const QJsonValue &val, posArr)
            {
                int x1 = val.toObject().value("x1").toInt();
                int x2 = val.toObject().value("x2").toInt();
                int y1 = val.toObject().value("y1").toInt();
                int y2 = val.toObject().value("y2").toInt();
                lineGroup << QLine(x1, y1, x2, y2);
            }
            pathPtr = new Path("street" + QString::number(i), lineGroup, clrs.at(i % 5));
            paths.append(pathPtr);
        }
    }
}

QVector<Path*> MyScene2::getPaths() {
    return paths;
}
