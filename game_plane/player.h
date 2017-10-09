#ifndef PLAYER_H
#define PLAYER_H

#include "gitem.h"
#include "bullet.h"
#include "QList"

class Player : public GItem
{
public:
    Player(int posX,int posY,int speed,Scene *scene);
    void fire();
private:
    QList<Bullet*> bulletList;
    QList<QPixmap*> pixList;
};

#endif // PLAYER_H
