#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "particle.h"
#include "gitem.h"
#include "QList"

class ParticleSystem :public GItem
{
public:
    ParticleSystem(int posX,int posY,int numParticles, Scene *scene);
    void draw(QPainter *painter);
    void refresh();
private:
    void initParticles();
    int numParticles;
    QList<Particle*> particleList;
};

#endif // PARTICLESYSTEM_H
