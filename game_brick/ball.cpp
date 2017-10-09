#include "ball.h"
#include "paddle.h"

Ball::Ball(QPoint pos,int speed)
    :GItem()
{
    curPix = QPixmap(":/res/res/360logo.png");
    h = curPix.height();
    w = curPix.width();
    posX = pos.x();
    posY = pos.y();
    speedX = speed;
    speedY = -speed;
    m_start = false;
}

void Ball::move()
{
    if(m_start)
    {
        if(posX < 0 || posX > 600 - w)
        {
            speedOverturn(true);
        }
        if(posY < 0 || posY > 450 - h)
        {
            speedOverturn(false);
        }
        posX += speedX;
        posY += speedY;
    }
}

void Ball::speedOverturn(bool isX)
{
    if(isX)
        speedX *= -1;
    else
        speedY *= -1;
}

bool Ball::getStart() const
{
    return m_start;
}

void Ball::setStart(bool value)
{
    m_start = value;
}
