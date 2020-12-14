/***
* @version: 0.0.0
* @author: Wuke
* @license: MIT Licence
* @contact: wukeee.wisdom@qq.com
* @site: ??
* @software: Qt Creator
* @file: maingame.cpp
* @time: 2020/12/13 18.56
*/


#include "maingame.h"
#include "ui_maingame.h"

MainGame::MainGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainGame)
{
    ui->setupUi(this);
    resize(1500,800);
    setMinimumSize(1500,800);
    setMaximumSize(1500,800);
    setWindowTitle("Snake");

//    setStyleSheet("QWidget{background:red}");
    setPalette(QPalette(Qt::black));
    setAutoFillBackground(true);
    setWindowOpacity(0.8);
    init();
}

MainGame::~MainGame()
{
    delete ui;
}
void MainGame::init(){
    qDebug() << "init...";
    snake = new Snake();
    moveFlag = Right;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(testMove()));
    timer->start(300);
}
void MainGame::testMove() {
    snake->Move(moveFlag);
    update();
}
void MainGame::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Up:
        qDebug() << "key up...";
        if(moveFlag != Down)
            moveFlag = Up;
        break;

    case Qt::Key_Down:
        qDebug() << "key down...";
        if(moveFlag != Up)
            moveFlag = Down;
        break;

    case Qt::Key_Left:
        qDebug() << "key left...";
        if(moveFlag != Right)
            moveFlag = Left;
        break;

    case Qt::Key_Right:
        qDebug() << "key right...";
        if(moveFlag != Left)
            moveFlag = Right;
        break;
    case Qt::Key_Space :
        if(event->isAutoRepeat())
        {
            qDebug() << timer->interval();
            return;
        }
        timer->start(100);
        break;
    }
}
/*
void MainGame::keyReleaseEvent(QKeyEvent* event) {
    if(event->key() == Qt::Key_Space) {
        timer->start(300);
        return;
    }
}
*/
void MainGame::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QBrush brush;

    painter.setRenderHint(QPainter::Antialiasing);
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    for(int i = 0; i < snake->getBody().length(); i++) {
        QPoint p = snake->getBody().at(i);
        painter.drawRect(p.x(), p.y(), 20, 20);
    }
}
