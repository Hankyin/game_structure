#include "enemy.h"

Enemy::Enemy(int id, Scene *scene)
    :GItem(scene)
{
    this->Id = id;
    this->posX = getRand(10,350);
    this->posY = -getRand(10,100);
    this->speedX = 0;
    this->speedY = getRand(2,6);
    pixList.append(new QPixmap(":/res/res/enemy1.png"));
    pixList.append(new QPixmap(":/res/res/enemy2.png"));
    pixList.append(new QPixmap(":/res/res/enemy3.png"));
    pixList.append(new QPixmap(":/res/res/enemy4.png"));
    pixList.append(new QPixmap(":/res/res/enemy5.png"));
    curPix = pixList.at(getRand(0,4));
    this->w = curPix->width();
    this->h = curPix->height();
}

void Enemy::fire()
{

}

void Enemy::reSet()
{
    this->posX = getRand(10,350);
    this->posY = -getRand(10,100);
    curPix = pixList.at(getRand(0,4));
    this->w = curPix->width();
    this->h = curPix->height();
    this->setAlive(true);
}

void Enemy::refresh()
{
    if(posY > 600)
    {
        reSet();
    }
    moveDown();
}

int Enemy::getRand(int start, int end)
{
    //得到[start,end]之间的随机整数
    //end必须大于start
    qsrand(Id);
    return qrand()%(end - start) + start;
}
