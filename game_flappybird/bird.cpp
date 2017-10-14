#include "bird.h"

Bird::Bird(Scene *scene, int posX, int posY, double garvity)
    :GItem(scene,posX,posY)
{
    anim = new Animation(scene,QString(":/picture/res/picture/bird_yellow.png"),4,5,posX,posY);
    h = anim->rect().height();
    w = anim->rect().width();
    speedY = 3;
    angle = 0;
    accFactor = garvity;
}

void Bird::refresh()
{
    animRefreshAngle();
    moveDown();
    if(posY + h > 450)
        setPos(posX,450 - h);
    //更新动画
    anim->setPos(posX,posY);
    anim->refresh();
}

void Bird::draw(QPainter *painter)
{
    anim->draw(painter);
}

void Bird::jump()
{
    setAngle(-35);
    speedY = -10;
}

void Bird::animRefreshAngle()
{
    if(angle < 90)
    {
        anim->setAngle(angle += 5);
    }
}
