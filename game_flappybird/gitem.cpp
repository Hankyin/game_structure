#include "gitem.h"
#include "QMatrix"

//游戏中所有物体的父类
GItem::GItem(Scene *scene, int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
    h = 0;
    w = 0;
    speedX = 0;
    speedY = 0;
    accFactor = 0;
    angle = 0;
    alive = true;
    curPix = new QPixmap();
    this->scene = scene;
}

GItem::GItem(Scene *scene, int posX, int posY, const QString &pix)
{
    this->posX = posX;
    this->posY = posY;
    curPix = new QPixmap(pix);
    h = curPix->height();
    w = curPix->width();
    speedX = 0;
    speedY = 0;
    accFactor = 0;
    angle = 0;
    alive = true;
    this->scene = scene;
}

void GItem::setPos(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}

void GItem::setSpeed(double vX, double vY)
{
    speedX = vX;
    speedY = vY;
}

void GItem::setAccFactor(double factor)
{
    accFactor = factor;
}

void GItem::setAngle(int angle)
{
    this->angle = angle;
}

void GItem::moveLeft()
{
    upspeed();
    posX -= speedX;
}

void GItem::moveRight()
{
    upspeed();
    posX += speedX;
}

void GItem::moveUp()
{
    upspeed();
    posY -= speedY;
}

void GItem::moveDown()
{
    upspeed();
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
    QMatrix matrix;
    matrix.rotate(angle);
    w = pix().transformed(matrix).width();
    h = pix().transformed(matrix).height();
//    w = curPix->width();
//    h = curPix->height();
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

void GItem::draw(QPainter *painter)
{
    if(isAlive())
    {
        if(!curPix->isNull())
        {
//            painter->translate(posX,posY + 10);
//            painter->rotate(angle);
//            painter->drawPixmap(0,0,pix().width(),pix().height(),pix());
//            painter->rotate(0);
//            painter->translate(-posX,-posY);
            QMatrix matrix;
            matrix.rotate(angle);
            painter->drawPixmap(rect(),pix().transformed(matrix));
        }
    }
}

void GItem::upspeed()
{
    speedX += accFactor;
    speedY += accFactor;
}

bool GItem::contain(int x, int y)
{
    return rect().contains(x,y);
}

bool GItem::contain(QRect &rec)
{
    return rect().contains(rec);
}
