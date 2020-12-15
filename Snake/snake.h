#ifndef SNAKE_H
#define SNAKE_H

#include <QPoint>
#include <QList>

class Snake
{
public:
    bool isAlive = true;

public:
    void Init();
    bool isDead();
    void getReward();
    void Move(int);
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    QPoint correctSnake(int, int);
    QPoint getHead();
    int getWidth();
    int getHeight();
    QList<QPoint> getBody();
    Snake();

private:
    int swidth = 20;
    int sheight = 20;
    int sgap = 2;
    int length = 50;

    QPoint head;
    QList<QPoint> SnakeBody;//point of snake in Topleft
};

#endif // SNAKE_H
