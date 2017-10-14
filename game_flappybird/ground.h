#ifndef GROUND_H
#define GROUND_H

#include "gitem.h"

class Ground : public GItem
{
public:
    Ground(Scene *scene,int posX,int posY,int speed);
    void refresh();
};

#endif // GROUND_H
