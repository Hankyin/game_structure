#ifndef LEVELS_H
#define LEVELS_H

#include "QList"
#include "QPoint"
#include "brick.h"

class Levels
{
public:
    Levels(QList<Brick *> *bricks);
    void loadLevel();
    void setLevelInfo();
    bool levelUp();
    bool isFinish(int numKilling);
    void levelInit();
private:
    int curLevel;
    int totalLevel;
    int reqKilling;//升级下一关所需打碎的砖块数
    QList<Brick*> *bricks;
    QList<QList<QPoint>> levelInfo;
};

#endif // LEVELS_H
