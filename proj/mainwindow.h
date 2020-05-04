#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QTimer>
#include <QDateTime>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *myTimer;
    QTime *myTime;
    int timeSpeed;

private slots:
    void startTimer();
    void onTimer();
    void speedUp();
    void speedDown();
    void speedReverse();

};
#endif // MAINWINDOW_H
