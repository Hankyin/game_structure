#ifndef ANIMATION_H
#define ANIMATION_H

#include "gitem.h"

class Animation : public GItem
{
public:
    Animation(Scene *scene, const QString pix,int frameNum = 4, int durationPerFrame = 1, int posX = 0, int posY = 0);
    void refresh();
    void rotate(int angle);
private:
    QPixmap *rawPix;
    QList<QPixmap> frameList;
    int frameNum;
    int curFrameIndex;
    int durationPerFrame;
    int curFrameShowTime;
};

#endif // ANIMATION_H
