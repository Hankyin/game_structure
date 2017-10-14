#include "animation.h"

Animation::Animation(int posX, int posY, Scene *scene)
    :GItem(scene,posX,posY)
{
    rawPix = new QPixmap(":/res/res/solider_0_.png");
    frameNum = 4;
    for(int i = 0;i < frameNum;i++)
    {
        QPixmap p = rawPix->copy(i * rawPix->width()/4,0,rawPix->width()/4,rawPix->height());
        frameList.append(p);
    }
    curFrameIndex = 0;
    //TODO 把w和h的赋值写在父类中。
    w = frameList[curFrameIndex].width();
    h = frameList[curFrameIndex].height();
}

void Animation::refresh()
{
    curPix = &frameList[curFrameIndex];
    if(curFrameIndex < 3)
    {
        curFrameIndex++;
    }
    else
    {
        curFrameIndex = 0;
    }
}
