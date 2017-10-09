#ifndef BULLET_H
#define BULLET_H

#include "gitem.h"

class Bullet : public GItem
{
public:
    Bullet(int posX, int posY, int speed,Scene *scene);
    void refresh();
};

#endif // BULLET_H
