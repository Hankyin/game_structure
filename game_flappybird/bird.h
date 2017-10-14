#ifndef BIRD_H
#define BIRD_H

#include "gitem.h"
#include "animation.h"

class Bird : public GItem
{
public:
    Bird(Scene *scene,int posX,int posY,double garvity);
    void refresh();
    void draw(QPainter *painter);
    void jump();
private:
    Animation *anim;
    void animRefreshAngle();
    void animRefreshPos();
};

#endif // BIRD_H
