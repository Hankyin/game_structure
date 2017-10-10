#ifndef GITEM_H
#define GITEM_H

#include "QPixmap"
#include "QRect"
#include "QPainter"
#include "scene.h"

class Scene;

class GItem
{
public:
    GItem(Scene *scene,int posX = 0,int posY = 0);
    GItem(int _posX,int _posY,int _h,int _w);
    void setPos(int posX,int posY);
    void setSpeed(int vX,int vY);
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUp();
    virtual void moveDown();
    virtual void refresh();
    virtual void draw(QPainter *painter);
    bool isAlive() const;
    void setAlive(bool value);
    QRect& rect();
    QPixmap& pix();

protected:
    Scene *scene;
    int posX;
    int posY;
    int h;
    int w;
    QRect _rect;
    int speedX;
    int speedY;
    QPixmap *curPix;
    bool alive;
};

#endif // GITEM_H
