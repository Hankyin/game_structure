#ifndef PARTICLE_H
#define PARTICLE_H

#include "gitem.h"
#include "scene.h"

class Particle : public GItem
{
public:
    Particle(Scene *scene,int posX = 0,int posY = 0);
    void refresh();
    void setAccFacter(int value);
protected:
    void upSpeed();
    int accFacter;//加速度

};

#endif // PARTICLE_H
