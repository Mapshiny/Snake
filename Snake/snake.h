#ifndef SNAKE_H
#define SNAKE_H

#include <QPoint>
#include <QList>

class Snake
{
public:
    void Move(int);
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    QPoint correctSnake(int, int);
    QPoint getHead();
    QList<QPoint> getBody();
    Snake();

private:
    qint32 swidth = 20;
    qint32 sheight = 20;
    qint32 sgap = 2;

    QPoint head;
    QList<QPoint> SnakeBody;//point of snake in Topleft
};

#endif // SNAKE_H
