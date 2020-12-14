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
void Snake::MoveRight() {
    int x = SnakeBody.last().x() + swidth + sgap;
    //out of widget's maximum width
    if(x >= 1500)
        x = 0;
    int y = SnakeBody.last().y();
    QPoint p(x, y);
    SnakeBody.append(p);
    SnakeBody.removeAt(0);
    qDebug() << "move Right...";
}

void Snake::MoveDown() {
    int x = SnakeBody.last().x();
    int y = SnakeBody.last().y() + swidth + sgap;
    //out of widget's maximun heigth
    if(y >= 800)
        y = 0;
    QPoint p(x, y);
    SnakeBody.append(p);
    SnakeBody.removeAt(0);
    qDebug() << "move Forward...";
}
QPoint Snake::getHead() {
    return SnakeBody.last();
}
QList<QPoint> Snake::getBody() {
    return SnakeBody;
}
