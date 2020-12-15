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

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateGame()));
    init();
}

MainGame::~MainGame()
{
    delete ui;
}
void MainGame::init() {
    qDebug() << "Main init...";
    snake = new Snake();
    food = setFood();
    moveFlag = 1;
    timer->start(timerInterval);
}
void MainGame::GameInit() {
    init();
}
bool MainGame::EatFood() {
    int food_center_x = food.topLeft().x() + fwidth;
    int food_center_y = food.topLeft().y() + fheight;
    int snake_x = snake->getHead().x();
    int snake_y = snake->getHead().y();
    double r = pow((snake->getWidth()), 2) + pow((0.8 * snake->getWidth()),2);
    double distance = pow(qAbs(food_center_x - snake_x), 2) + pow(qAbs(food_center_y - snake_y), 2);
    if(distance <= (r - 50)) {
        snake->getReward();
        return true;
    }
    return false;
}
QRect MainGame::setFood() {
    int seed = QTime::currentTime().msec();
    qsrand(uint(seed));
    int x = qrand() % 1480;
    int y = qrand() % 780;
    QPoint topLeft(x, y);
    QPoint bottomRight(x + fwidth, y + fheight);
    QRect food(topLeft, bottomRight);
    return food;
}

void MainGame::UpdateGame() {
    snake->Move(moveFlag);
    if(snake->isDead())
        timer->stop();
    if(EatFood()) {
        food = setFood();
    }
    update();
}
void MainGame::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Up:
        if(moveFlag != 1)
            moveFlag = 0;
        break;

    case Qt::Key_Down:
        if(moveFlag != 0)
            moveFlag = 1;
        break;

    case Qt::Key_Left:
        if(moveFlag != 3)
            moveFlag = 2;
        break;

    case Qt::Key_Right:
        if(moveFlag != 2)
            moveFlag = 3;
        break;

    case Qt::Key_Space:
        if(event->isAutoRepeat())
            event->ignore();
        else if(snake->isAlive)
            timer->start(timerInterval/4);
        break;

    case Qt::Key_Escape:
        if(timer->isActive() && snake->isAlive)
            timer->stop();
        if(!timer->isActive() && snake->isAlive)
            timer->start(timerInterval);
        if(!snake->isAlive)
            GameInit();
        break;

    default:
        break;
    }
}

void MainGame::keyReleaseEvent(QKeyEvent* event) {
    if(!event->isAutoRepeat() && event->key() == Qt::Key_Space) {
        timer->start(timerInterval);
    }
}

void MainGame::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QBrush brush;

    painter.setRenderHint(QPainter::Antialiasing);
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    //draw snake
    for(int i = 0; i < snake->getBody().length(); i++) {
        QPoint p = snake->getBody().at(i);
        painter.drawRect(p.x(), p.y(), 20, 20);
    }
    //draw food
    brush.setColor(Qt::red);
    painter.setBrush(brush);
    painter.drawEllipse(food.topLeft().x(), food.topLeft().y(), fwidth, fheight);

    if(!snake->isAlive) {
        QFont font("Helvetica [Cronyx]", 30 , QFont::ExtraLight, false);
        painter.setFont(font);
        QPoint p((this->width() - 300)/2 + 60, (this->height() -150)/2);
        painter.drawText(p,"Game Over!");
        font.setPointSize(17);
        painter.setFont(font);
        painter.drawText(p.x(), p.y() + 40, " Press Esc to restart");
    }
}









