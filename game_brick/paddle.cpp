#include "paddle.h"
#include "ball.h"

Paddle::Paddle(QPoint pos, int speed,Ball *_ball)
    :GItem()
{
    curPix = QPixmap(":/res/res/paddle.png");
    posX = pos.x();
    posY = pos.y();
    h = curPix.height();
    w = curPix.width();
    this->speedX = speed;
    ball = _ball;
}

void Paddle::moveLeft()
{
    int newPos = posX - speedX;
    if(newPos > 0)
        posX = newPos;
}

void Paddle::moveRight()
{
    int newPos = posX +speedX;
    if(newPos < 600 - w)
        posX = newPos;
}

void Paddle::fire()
{
    ball->setStart(true);
}

