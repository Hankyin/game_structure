#include "scenemain.h"

SceneMain::SceneMain():Scene()
{
    score = 0;
    numKill = 0;
    status = GAME_STATUE::GAMEPALYING;
    ball = new Ball(QPoint(300,380),10);
    paddle = new Paddle(QPoint(250,400),10,ball);
    bricks = new QList<Brick*>();
    level = new Levels(bricks);
    //初始化关卡
    level->levelInit();
    updateItem();

    registerKey("a",(CallBack)&SceneMain::eventRespond1);
    registerKey("d",(CallBack)&SceneMain::eventRespond2);
    registerKey("w",(CallBack)&SceneMain::eventRespond3); 
}

void SceneMain::eventRespond1()
{
    paddle->moveLeft();
}
void SceneMain::eventRespond2()
{
    paddle->moveRight();
}

void SceneMain::eventRespond3()
{
    ball->setStart(true);
}

void SceneMain::updateItem()
{
    cleanItem();
    addItem(ball);
    addItem(paddle);
    for(int i = 0;i < bricks->size();i++)
    {
        GItem *a = bricks->at(i);
        addItem(a);
    }
}

void SceneMain::refresh()
{
    //暂停
    if(pause)
    {
        return;
    }
    respondKey();
    ball->move();

    //碰撞与打砖块
    this->collision(ball,paddle);
    for(int i = 0;i < bricks->size();i++)
    {
        Brick *curBrick = bricks->at(i);
        if(collision(ball,curBrick))
        {
            int res = curBrick->hurt();
            if(res)
            {
                kill(res);
            }
        }
    }
    //关卡完成检测
    if(level->isFinish(numKill))
    {
        pause = true;
        ball->setStart(false);
        numKill = 0;
        if(!level->levelUp())
        {
            //升级失败，说明通关
            setFinishStatus(1);
        }
        updateItem();
        ball->setPos(paddle->posX + paddle->w/2,paddle->posY - ball->h);
        pause = false;
    }
}

bool SceneMain::collision(Ball *ball, GItem *item2)
{
    if(item2->alive)
    {
        QRect recBall(ball->posX,ball->posY,ball->w,ball->h);
        QRect recOther(item2->posX,item2->posY,item2->w,item2->h);
        //如果是从上下左右碰撞
        if((recOther.contains(recBall.bottomLeft()) && recOther.contains(recBall.bottomRight())) ||
                (recOther.contains(recBall.topLeft()) && recOther.contains(recBall.topRight())))
        {
            ball->speedOverturn(false);
            return true;
        }
        else if((recOther.contains(recBall.topLeft()) && recOther.contains(recBall.bottomLeft())) ||
                (recOther.contains(recBall.topRight()) && recOther.contains(recBall.bottomRight())))
        {
            ball->speedOverturn(true);
            return true;
        }
        //如果是从角上碰撞
        if(recOther.contains(recBall.bottomLeft()) || recOther.contains(recBall.bottomRight()) ||
                recOther.contains(recBall.topLeft()) || recOther.contains(recBall.topRight()))
        {
            ball->speedOverturn(true);
            ball->speedOverturn(false);
            return true;
        }
    }
    return false;
}


bool SceneMain::isPause()
{
    return this->pause;
}

void SceneMain::kill(int newScore)
{
    numKill++;
    score += newScore;
}

Scene *SceneMain::sceneStart()
{
    paddle->setPos(250,400);
    ball->setPos(paddle->posX + paddle->w/2,paddle->posY - ball->h);
    level->levelInit();
    updateItem();
    ball->setStart(false);
    setFinishStatus(0);
    return this;
}


