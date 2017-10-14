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
    GItem(Scene *scene, int posX, int posY,const QString &pix);
    void setPos(int posX,int posY);
    void setSpeed(double vX,double vY);
    void setAccFactor(double factor);
    void setAngle(int angle);
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUp();
    virtual void moveDown();
    virtual void refresh();
    virtual void draw(QPainter *painter);
    virtual void upspeed();
    virtual bool contain(int x,int y);
    virtual bool contain(QRect &rec);
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
    double speedX;
    double speedY;
    double accFactor;
    QPixmap *curPix;
    bool alive;
    int angle;
};

#endif // GITEM_H
