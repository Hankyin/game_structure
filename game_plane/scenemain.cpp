#include "scenemain.h"

SceneMain::SceneMain()
    :Scene()
{
    player = new Player(0,110,10,this);
    addItem(player);
    enemyNum = 4;
    for(int i = 0;i < enemyNum;i++)
    {
        Enemy *newEnemy = new Enemy(i,this);
        addItem(newEnemy);
        enemyList.append(newEnemy);
    }
    registerKey("w",(CallBack)&SceneMain::playerUp);
    registerKey("s",(CallBack)&SceneMain::playerDown);
    registerKey("a",(CallBack)&SceneMain::playerLeft);
    registerKey("d",(CallBack)&SceneMain::playerRight);
    registerKey("k",(CallBack(&SceneMain::playerFire)));

}

void SceneMain::playerUp()
{
    player->moveUp();
}

void SceneMain::playerDown()
{
    player->moveDown();
}

void SceneMain::playerLeft()
{
    player->moveLeft();
}

void SceneMain::playerRight()
{
    player->moveRight();
}

void SceneMain::playerFire()
{
    player->fire();
}
