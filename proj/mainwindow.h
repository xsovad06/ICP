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
    void init_scene();
    Ui::MainWindow *ui;
    QTimer *myTimer;
    QTime *myTime;
    float timeSpeed;

private slots:
    void zoom_in();
    void zoom_out();
    void zoom_slider(int n);
    void startTimer();
    void onTimer();
    void speedUp();
    void speedDown();
    void speedReverse();

};
#endif // MAINWINDOW_H
