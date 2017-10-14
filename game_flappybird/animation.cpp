#include "animation.h"

Animation::Animation(Scene *scene,const QString pix,int frameNum,int durationPerFrame,int posX, int posY)
    :GItem(scene,posX,posY)
{
    rawPix = new QPixmap(pix);
    this->frameNum = frameNum;
    this->durationPerFrame = durationPerFrame;
    this->curFrameShowTime = 0;
    for(int i = 0;i < this->frameNum;i++)
    {
        QPixmap p = rawPix->copy(i * rawPix->width()/frameNum,0,rawPix->width()/frameNum,rawPix->height());
        frameList.append(p);
    }
    curFrameIndex = 0;
    curPix = &frameList[curFrameIndex];
}

void Animation::refresh()
{
    curFrameShowTime++;
    if(curFrameShowTime > durationPerFrame)
    {
        if(curFrameIndex < frameNum -1)
        {
            curFrameIndex++;
        }
        else
        {
            curFrameIndex = 0;
        }
        curFrameShowTime = 0;
        curPix = &frameList[curFrameIndex];
    }
}
