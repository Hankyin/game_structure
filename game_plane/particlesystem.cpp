#include "particlesystem.h"
#include "utils.h"
#include "QDebug"

ParticleSystem::ParticleSystem(int posX, int posY,int numParticles, Scene *scene)
    :GItem(scene,posX,posY)
{
    this->numParticles = numParticles;
}

void ParticleSystem::draw(QPainter *painter)
{
    for(int i = 0;i < particleList.size();i++)
    {
        particleList.at(i)->draw(painter);
    }
}

void ParticleSystem::refresh()
{ 
    if(particleList.size() < numParticles)
    {
        Particle *p = new Particle(scene,posX,posY);
        //p->setAccFacter();
        int vx = Utils::getRand(-5,5);
        int vy = Utils::getRand(-5,5);
        qDebug()<<vx<<endl;
        qDebug()<<vy<<endl;
        p->setSpeed(vx,vy);
        particleList.append(p);
    }
    for(int i = 0;i < particleList.size();i++)
    {
        particleList.at(i)->refresh();
    }
}


