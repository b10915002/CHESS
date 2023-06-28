#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include "gameManager.h"
#include <QTimer>

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
    void mousePressEvent(QMouseEvent *event);
    void SetChess();
    void SetHighlight();
    void GameLose(QString);
    void GameFirst();
    Position kingPos;

protected:
    QGraphicsScene *gameScene;
    QGraphicsPixmapItem *item;
    QGraphicsPixmapItem *back;
    QList <QGraphicsItem *> listG;
    bool started;
    QTimer *timer;
    int timelimit;
    QTimer *timer1;
    int timelimit1;

private slots:
    void on_pushButton_clicked();
    void GameTime();

};
#endif // MAINWINDOW_H
