#ifndef BRICK_H
#define BRICK_H

#include "gitem.h"

class Brick :public GItem
{
public:
    Brick(int posx,int posy,int lifes = 1);
    int hurt();
private:
    int lifes;
    int score;
    QList<QPixmap> *pixList;
    bool updatePix();
};

#endif // BRICK_H
