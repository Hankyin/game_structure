#ifndef SCENE_H
#define SCENE_H

#include "QPainter"
#include "QMap"
#include "QList"
#include "QWidget"
#include "QKeyEvent"
#include "QPainter"
#include "gitem.h"


class Scene
{
public:
    Scene();
    bool pause;
    typedef void (Scene::*CallBack)();

    virtual void refresh() ;
    void registerKey(const QString key,CallBack callback);
    void respondKey();
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual Scene* sceneStart();
    virtual int sceneFinish();
    virtual void needDraw(QWidget *widget);
protected:
    void addItem(GItem *newItem);
    void cleanItem();
    void setFinishStatus(int status);
private:
    int finishStatus;//场景结束状态，0代表没结束
    QMap<QString,bool> keydowns;
    QMap<QString,CallBack> actions;
    QList<GItem*> *items;
};

#endif // SCENE_H
