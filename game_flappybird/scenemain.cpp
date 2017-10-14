#include "scenemain.h"

SceneMain::SceneMain()
    :Scene()
{
    setBackGround(QPixmap(":/picture/res/picture/bg_day.png"));
    speed = 3;//地面和水管的移动速度
    ground = new Ground(this,0,480,speed);
    bird = new Bird(this,50,50,1);
    pipes = new Pipes(this,speed);
    overLabel = new GItem(this,50,150,":/picture/res/picture/gameover.png");
    addItem(pipes);
    addItem(ground);
    addItem(bird);

    registerKey("j",(CallBack)&SceneMain::jump);
}

bool SceneMain::collision(GItem *item1, GItem *item2)
{
    return item1->contain(item2->rect()) || item2->contain(item1->rect().topLeft().x(),item1->rect().topLeft().y());
}

void SceneMain::refresh()
{
    Scene::refresh();
    if(collision(bird,pipes))
    {
        gameOver();
    }
}

void SceneMain::gameOver()
{
    ground->setSpeed(0,0);
    pipes->setSpeed(0,0);
    addItem(overLabel);
}

void SceneMain::jump()
{
    bird->jump();
}
