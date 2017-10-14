#ifndef ANIMATION_H
#define ANIMATION_H

#include "gitem.h"

class Animation : public GItem
{
public:
    Animation(int posX,int posY,Scene *scene);
    void refresh();
private:
    QPixmap *rawPix;
    QList<QPixmap> frameList;
    int frameNum;
    int curFrameIndex;
};

#endif // ANIMATION_H
