#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include <snake.h>
#include <QTimer>
#include <QDebug>
#include <QPainter>
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
    void init();
protected slots:
    void testMove();
private:
    int count = 0;
    Snake* snake;
    QTimer* timer;
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
