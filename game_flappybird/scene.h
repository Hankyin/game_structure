#ifndef SCENE_H
#define SCENE_H

#include "QPainter"
#include "QMap"
#include "QList"
#include "QWidget"
#include "QKeyEvent"
#include "QPainter"
#include "gitem.h"

/*
 * Scene是游戏场景基类，子类继承Scene后，
 * 调用addItem添加场景中的游戏物件，Scene会自动绘制
 * 调用registerKey注册按键事件，Scene会自动调用
 *
 */
class GItem;

class Scene
{
public:
    Scene();
    bool pause;
    typedef void (Scene::*CallBack)();
    virtual void refresh() ;
    void registerKey(const QString key,CallBack callback);
    void respondKey();
    void addItem(GItem *newItem);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual Scene* sceneStart();
    virtual int sceneFinish();
    virtual void draw(QPainter *painter);
protected:
    void cleanItem();
    void setFinishStatus(int status);
    void setBackGround(const QPixmap &bg = QPixmap());
private:
    QPixmap bgPix;
    int finishStatus;//场景结束状态，0代表没结束
    QMap<QString,bool> keydowns;
    QMap<QString,CallBack> actions;
    QList<GItem*> *items;
};

#endif // SCENE_H
