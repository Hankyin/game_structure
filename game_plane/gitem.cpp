#include "gitem.h"

//游戏中所有物体的父类
GItem::GItem(Scene *scene)
{
    posX = 0;
    posY = 0;
    h = 0;
    w = 0;
    speedX = 0;
    speedY = 0;
    alive = true;
    curPix = new QPixmap();
    this->scene = scene;
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

void GItem::moveLeft()
{
    posX -= speedX;
}

void GItem::moveRight()
{
    posX += speedX;
}

void GItem::moveUp()
{
    posY -= speedY;
}

void GItem::moveDown()
{
    posY += speedY;
}

bool GItem::isAlive() const
{
    return alive;
}

void GItem::setAlive(bool value)
{
    alive = value;
}

QRect &GItem::rect()
{
    _rect = QRect(posX,posY,w,h);
    return _rect;
}

QPixmap &GItem::pix()
{
    return *curPix;
}

void GItem::refresh()
{

}
