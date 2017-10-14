#include "particle.h"
#include "QDebug"

Particle::Particle(Scene *scene, int posX, int posY)
    :GItem(scene,posX,posY)
{
    curPix = new QPixmap(":/res/res/bullet.png");
    w = curPix->width();
    h = curPix->height();
    life = 10;
}

void Particle::refresh()
{
    //upSpeed();
    moveRight();
    moveDown();
    hurt();//每次循环减一生命值，死亡后被删除
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

void Particle::hurt()
{
    life--;
    if(!life)
    {
        setAlive(false);
    }
}
