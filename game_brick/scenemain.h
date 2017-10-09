#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "scene.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "levels.h"

class SceneMain : public Scene
{
public:
    SceneMain();
    enum GAME_STATUE{
        GAMEPALYING = 0,
        GAMEOVER = 1,
        GAMECOMPLETED = 2
    };
    Paddle *paddle;
    Ball *ball;
    QList<Brick*> *bricks;
    int score;
    int numKill;
    Levels *level;
    GAME_STATUE status;
    bool collision(Ball *ball, GItem *item2);
    bool isPause();
    void kill(int newScore);//当打碎一个砖块时，调用它，参数是砖块的分数
    void refresh();
    Scene* sceneStart();
    void eventRespond1();
    void eventRespond2();
    void eventRespond3();
    void updateItem();
};

#endif // SCENEMAIN_H
