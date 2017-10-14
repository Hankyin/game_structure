#ifndef PIPES_H
#define PIPES_H

#include "gitem.h"
#include "QList"

class Pipes : public GItem
{
public:
    Pipes(Scene *scene,int speed);
    void refresh();
    void draw(QPainter *painter);
    bool contain(int x, int y);
    bool contain(QRect &rec);
private:
    QList<GItem*> pipeList;
    QList<GItem*> pipeopList;
    int intervalOfPipe;//左右两个管子之间的距离
    int pipeSpace;//上下两个管子之间的距离
};

#endif // PIPES_H
