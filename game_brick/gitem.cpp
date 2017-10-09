#include "gitem.h"

//游戏中所有物体的父类
GItem::GItem()
{
    posX = 0;
    posY = 0;
    h = 0;
    w = 0;
    speedX = 0;
    speedY = 0;
    alive = true;
}

GItem::GItem(int _posX, int _posY, int _h, int _w)
{
    posX = _posX;
    posY = _posY;
    h = _h;
    w = _w;
}

void GItem::setPos(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}
