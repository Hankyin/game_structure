#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "scene.h"
#include "player.h"
#include "enemy.h"
#include "particlesystem.h"

class SceneMain:public Scene
{
public:
    SceneMain();

private:
    Player *player;
    ParticleSystem *parSys;
    QList<Enemy*> enemyList;
    int enemyNum;

    //按键响应函数
    void playerUp();
    void playerDown();
    void playerLeft();
    void playerRight();
    void playerFire();
};

#endif // SCENEMAIN_H
