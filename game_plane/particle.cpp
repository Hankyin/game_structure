#include "particle.h"
#include "QDebug"
Particle::Particle(Scene *scene, int posX, int posY)
    :GItem(scene,posX,posY)
{
    curPix = new QPixmap(":/res/res/bullet.png");
    w = curPix->width();
    h = curPix->height();
}

void Particle::refresh()
{
    //upSpeed();
    moveRight();
    moveDown();
}

void Particle::upSpeed()
{
    //此处速度的类型有问题
    speedX += accFacter * speedX;
    speedY += accFacter * speedY;
}

void Particle::setAccFacter(int value)
{
    accFacter = value;
}
