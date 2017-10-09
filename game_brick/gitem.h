#ifndef GITEM_H
#define GITEM_H

#include "QPixmap"

class GItem
{
public:
    GItem();
    GItem(int _posX,int _posY,int _h,int _w);
    int posX;
    int posY;
    int h;
    int w;
    int speedX;
    int speedY;
    QPixmap curPix;
    bool alive;
    void setPos(int posX,int posY);
};

#endif // GITEM_H
