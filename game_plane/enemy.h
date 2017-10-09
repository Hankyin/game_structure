#ifndef ENEMY_H
#define ENEMY_H

#include "gitem.h"
#include "QList"
#include "qglobal.h"

class Enemy : public GItem
{
public:
    Enemy(int id,Scene *scene);
    void fire();
    int Id;
    void reSet();
    void refresh();
private:
    QList<QPixmap*> pixList;
    int getRand(int start,int end);
};

#endif // ENEMY_H
