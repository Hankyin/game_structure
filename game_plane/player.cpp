#include "player.h"

Player::Player(int posX, int posY, int speed, Scene *scene)
    :GItem(scene)
{
    this->posX = posX;
    this->posY = posY;
    this->speedX = speed;
    this->speedY = speed;
    pixList.append(new QPixmap(":/res/res/player1.png"));
    pixList.append(new QPixmap(":/res/res/player2.png"));
    curPix = pixList.at(0);
    this->w = curPix->width();
    this->h = curPix->height();
}

void Player::fire()
{
    Bullet *newBullet = new Bullet(posX + w/2,posY,10,scene);
    bulletList.append(newBullet);
    scene->addItem(newBullet);
}
