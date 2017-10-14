#include "pipes.h"
#include "utils.h"

Pipes::Pipes(Scene *scene,int speed)
    :GItem(scene,0,0)
{
    intervalOfPipe = 200;
    pipeSpace = 100;
    speedX = speed;
    for(int i = 0;i < 3;i++)
    {
        GItem *pipe = new GItem(scene,i * intervalOfPipe + 500,Utils::getRand(192,320),//512-320=192
                                QString(":/picture/res/picture/pipe.png"));
        pipe->setSpeed(speed,0);
        pipeList.append(pipe);

        GItem *pipeop = new GItem(scene,pipeList.at(i)->rect().left(),
                                  pipeList.at(i)->rect().top() - pipeSpace - 320,
                                QString(":/picture/res/picture/pipe_op.png"));
        pipeop->setSpeed(speed,0);
        pipeopList.append(pipeop);
    }
}

void Pipes::refresh()
{
    for(int i = 0;i < pipeList.size();i++)
    {
        pipeList.at(i)->setSpeed(speedX,0);
        pipeopList.at(i)->setSpeed(speedX,0);
        pipeList.at(i)->moveLeft();
        pipeopList.at(i)->moveLeft();
        if(pipeList.at(i)->rect().left() < -60)
        {
            int next = (i == 0 ? 2 : i - 1);
            pipeList.at(i)->setPos(pipeList.at(next)->rect().right() + intervalOfPipe,
                                   Utils::getRand(192,320));
            pipeopList.at(i)->setPos(pipeList.at(i)->rect().left(),
                                     pipeList.at(i)->rect().top() - pipeSpace - 320);
        }
    }
}

void Pipes::draw(QPainter *painter)
{
    for(int i = 0;i < pipeList.size();i++)
    {
        pipeList.at(i)->draw(painter);
        pipeopList.at(i)->draw(painter);
    }
}

bool Pipes::contain(int x, int y)
{
    bool c = false;
    for(int i = 0;i < 3;i++)
    {
        c = pipeList.at(i)->contain(x,y) || pipeopList.at(i)->contain(x,y);
        if(c)
        {
            break;
        }
    }
    return c;
}

bool Pipes::contain(QRect &rec)
{
    bool c = false;
    for(int i = 0;i < 3;i++)
    {
        c = pipeList.at(i)->contain(rec) || pipeopList.at(i)->contain(rec);
        if(c)
        {
            break;
        }
    }
    return c;
}
