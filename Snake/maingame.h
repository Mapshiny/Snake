#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include <snake.h>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QtGlobal>
#include <QTime>
#include <QtMath>
namespace Ui {
class MainGame;
}

class MainGame : public QWidget
{
    Q_OBJECT
public:
    void GameInit();
    bool EatFood();
    explicit MainGame(QWidget *parent = nullptr);
    ~MainGame();

protected:
    void init();
    QRect setFood();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);


protected slots:
    void UpdateGame();

private:
    int timerInterval = 120;
    int fwidth = 8;
    int fheight = 8;
    Snake* snake;
    QRect food;
    QTimer* timer;
    int moveFlag;
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
