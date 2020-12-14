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

    timer = new QTimer();
    timer->setInterval(300);
    connect(timer, SIGNAL(timeout()), this, SLOT(testMove()));
    timer->start();
}
void MainGame::testMove() {
//    if(count == 0) {
//        snake->MoveRight();
//        count += 2;
//        update();
//    }
//    else {
//        snake->MoveFoward();
//        count--;
//        update();
//    }
    snake->MoveDown();
    update();
}
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
