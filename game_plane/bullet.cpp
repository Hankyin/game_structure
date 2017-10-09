#include "bullet.h"

Bullet::Bullet(int posX, int posY, int speed, Scene *scene)
    :GItem(scene)
{
    curPix = new QPixmap(":/res/res/bullet.png");
    this->posX = posX;
    this->posY = posY;
    this->w = curPix->width();
    this->h = curPix->height();
    this->speedY = speed;
}

void Bullet::refresh()
{
    moveUp();
}


/*
 *
 * 子弹有生命值，当子弹碰到敌人或边界，生命值为零，就删除。
 * 这个设计还可以用在粒子效果中的粒子上。
 * */
