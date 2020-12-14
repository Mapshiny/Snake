#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include <snake.h>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>

namespace Ui {
class MainGame;
}

class MainGame : public QWidget
{
    Q_OBJECT
public:
    explicit MainGame(QWidget *parent = nullptr);
    ~MainGame();

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
//    void keyReleaseEvent(QKeyEvent *);
    void init();

protected slots:
    void testMove();

private:
    int count = 0;
    Snake* snake;
    QTimer* timer;
    enum Move{Up,Down,Left,Right};
    int moveFlag;
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
