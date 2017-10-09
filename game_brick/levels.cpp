#include "levels.h"

Levels::Levels(QList<Brick *> *bricks)
{
    curLevel = 1;

    this->bricks = bricks;
    setLevelInfo();
}

void Levels::loadLevel()
{
    qDeleteAll(*bricks);
    this->bricks->clear();
    for(QPoint bkPoint : levelInfo.at(curLevel-1))
    {
        Brick *newBrick = new Brick(bkPoint.x(),bkPoint.y(),curLevel);
        bricks->append(newBrick);
    }
    reqKilling = bricks->size();
}

void Levels::setLevelInfo()
{
    totalLevel = 2;
    //第一关
    QList<QPoint> level_1;
    level_1.append(QPoint(250,50));
    //第二关
    QList<QPoint> level_2;
    level_2.append(QPoint(200,50));
    level_2.append(QPoint(300,50));
    level_2.append(QPoint(400,50));
    //第三关
    QList<QPoint> level_3;
    level_3.append(QPoint(100,50));
    level_3.append(QPoint(500,50));
    level_3.append(QPoint(250,100));

    levelInfo.append(level_1);
    levelInfo.append(level_2);
    levelInfo.append(level_3);
}

bool Levels::levelUp()
{
    curLevel++;
    if(curLevel > totalLevel)
    {
        return false;
    }
    loadLevel();
    return true;
}

bool Levels::isFinish(int numKilling)
{
    if(numKilling < reqKilling)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Levels::levelInit()
{
    curLevel = 1;
    loadLevel();
}
