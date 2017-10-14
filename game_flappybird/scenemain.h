#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "scene.h"
#include "ground.h"
#include "bird.h"
#include "pipes.h"

class SceneMain : public Scene
{
public:
    SceneMain();
private:
    int speed;
    Ground *ground;
    Bird *bird;
    Pipes *pipes;
    GItem *overLabel;
    bool collision(GItem *item1,GItem *item2);
    void refresh();
    void gameOver();
    //按键响应函数
    void jump();

};

#endif // SCENEMAIN_H
