/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *spdDownBtn;
    QPushButton *spdRevBtn;
    QLabel *timeSpdLab;
    QPushButton *spdUpBtn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *timePlayBtn;
    QLabel *timeShowLab;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Button_zoom_out;
    QSlider *zoom_slider;
    QPushButton *Button_zoom_in;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(820, 513);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spdDownBtn = new QPushButton(centralwidget);
        spdDownBtn->setObjectName(QStringLiteral("spdDownBtn"));

        horizontalLayout->addWidget(spdDownBtn);

        spdRevBtn = new QPushButton(centralwidget);
        spdRevBtn->setObjectName(QStringLiteral("spdRevBtn"));

        horizontalLayout->addWidget(spdRevBtn);

        timeSpdLab = new QLabel(centralwidget);
        timeSpdLab->setObjectName(QStringLiteral("timeSpdLab"));

        horizontalLayout->addWidget(timeSpdLab);

        spdUpBtn = new QPushButton(centralwidget);
        spdUpBtn->setObjectName(QStringLiteral("spdUpBtn"));

        horizontalLayout->addWidget(spdUpBtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        timePlayBtn = new QPushButton(centralwidget);
        timePlayBtn->setObjectName(QStringLiteral("timePlayBtn"));

        horizontalLayout_2->addWidget(timePlayBtn);

        timeShowLab = new QLabel(centralwidget);
        timeShowLab->setObjectName(QStringLiteral("timeShowLab"));

        horizontalLayout_2->addWidget(timeShowLab);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Button_zoom_out = new QPushButton(centralwidget);
        Button_zoom_out->setObjectName(QStringLiteral("Button_zoom_out"));
        Button_zoom_out->setMaximumSize(QSize(25, 25));
        Button_zoom_out->setAutoRepeatDelay(300);

        horizontalLayout_3->addWidget(Button_zoom_out);

        zoom_slider = new QSlider(centralwidget);
        zoom_slider->setObjectName(QStringLiteral("zoom_slider"));
        zoom_slider->setMinimum(1);
        zoom_slider->setMaximum(100);
        zoom_slider->setValue(10);
        zoom_slider->setSliderPosition(10);
        zoom_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(zoom_slider);

        Button_zoom_in = new QPushButton(centralwidget);
        Button_zoom_in->setObjectName(QStringLiteral("Button_zoom_in"));
        Button_zoom_in->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(Button_zoom_in);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 820, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        spdDownBtn->setText(QApplication::translate("MainWindow", " << 2x", Q_NULLPTR));
        spdRevBtn->setText(QApplication::translate("MainWindow", "reverse", Q_NULLPTR));
        timeSpdLab->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        spdUpBtn->setText(QApplication::translate("MainWindow", "2x >>", Q_NULLPTR));
        timePlayBtn->setText(QApplication::translate("MainWindow", "play/pause", Q_NULLPTR));
        timeShowLab->setText(QApplication::translate("MainWindow", "00 : 00 : 00", Q_NULLPTR));
        Button_zoom_out->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        Button_zoom_in->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ICP MAP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
