/***
* @version: 0.0.0
* @author: Wuke
* @license: MIT Licence
* @contact: wukeee.wisdom@qq.com
* @site: ??
* @software: Qt Creator
* @file: snake.cpp
* @time: 2020/12/14 14.01
*/

#include "snake.h"
#include "qdebug.h"
Snake::Snake()
{
    int x, y;
    for(int i = 0; i < 5; i++) {
        x = 30;
        y = 30 + i * (swidth + sgap);
        QPoint p(x, y);
        SnakeBody.append(p);
    }
}
void Snake::Move(int moveFlag) {
    switch (moveFlag) {
    case 0:
        MoveUp();
        break;
    case 1:
        MoveDown();
        break;
    case 2:
        MoveLeft();
        break;
    case 3:
        MoveRight();
        break;
    default:
        break;
    }
}

void Snake::MoveUp() {
    int x = SnakeBody.last().x();
    int y = SnakeBody.last().y() - swidth - sgap;

    QPoint p = correctSnake(x, y);
    SnakeBody.append(p);
    SnakeBody.removeAt(0);

}
void Snake::MoveDown() {
    int x = SnakeBody.last().x();
    int y = SnakeBody.last().y() + swidth + sgap;
    //out of widget's maximun heigth
    QPoint p = correctSnake(x, y);
    SnakeBody.append(p);
    SnakeBody.removeAt(0);

}
void Snake::MoveLeft() {
    int x = SnakeBody.last().x() - swidth - sgap;
    int y = SnakeBody.last().y();
    QPoint p = correctSnake(x, y);
    SnakeBody.append(p);
    SnakeBody.removeAt(0);

}
void Snake::MoveRight() {
    int x = SnakeBody.last().x() + swidth + sgap;
    int y = SnakeBody.last().y();
    QPoint p = correctSnake(x, y);
    SnakeBody.append(p);
    SnakeBody.removeAt(0);
}
QPoint Snake::correctSnake(int x, int y) {
    if(x <= 0)
        x = 1500 - swidth;
    if(x >= 1500)
        x = 0 + swidth;
    if(y <= 0)
        y = 800 - swidth;
    if(y >= 800)
        y = 0 + swidth;
    QPoint p(x, y);
    return p;
}
QPoint Snake::getHead() {
    return SnakeBody.last();
}
QList<QPoint> Snake::getBody() {
    return SnakeBody;
}
