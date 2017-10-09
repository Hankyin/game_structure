#include "brick.h"

Brick::Brick(int posx,int posy,int lifes)
{
    this->lifes = lifes;
    this->score = lifes*10;
    pixList = new QList<QPixmap>();
    pixList->append(QPixmap(":/res/res/brick1.png"));
    pixList->append(QPixmap(":/res/res/brick2.png"));
    pixList->append(QPixmap(":/res/res/brick3.png"));
    updatePix();
    posX = posx;
    posY = posy;
    w = curPix.width();
    h = curPix.height();

}

int Brick::hurt()
{
    lifes--;
    if(!updatePix())
    {
        alive = false;
        return score;
    }
    return 0;
}

bool Brick::updatePix()
{
    if(lifes)
    {
        curPix = pixList->at(lifes-1);
        return true;
    }
    return false;
}
