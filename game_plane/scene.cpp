#include "scene.h"

Scene::Scene()
{
    this->pause = false;
    items = new QList<GItem*>;
    setFinishStatus(0);
}

void Scene::registerKey(const QString key,CallBack callback)
{
    keydowns.insert(key,false);
    actions.insert(key,callback);
}

void Scene::respondKey()
{
    //注册事件响应
    QMap<QString,bool>::iterator i = keydowns.begin();
    while (i != keydowns.end())
    {
        if(keydowns[i.key()])
        {
            CallBack fun;
            fun = actions[i.key()];
            (this->*fun)();
        }
        ++i;
    }
}

void Scene::refresh()
{
    if(this->pause)
        return;
    respondKey();
    for(int i = 0; i < items->size();i++)
    {
        items->at(i)->refresh();
    }
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_P)
        pause = !pause;
    if(keydowns.contains(event->text()))
    {
        keydowns[event->text()] = true;
    }
}

void Scene::keyReleaseEvent(QKeyEvent *event)
{
    if(keydowns.contains(event->text()))
    {
        keydowns[event->text()] = false;
    }
}

Scene *Scene::sceneStart()
{
    setFinishStatus(0);
    QMap<QString,bool>::iterator i = keydowns.begin();
    while(i != keydowns.end())
    {
        keydowns[i.key()] = false;
        ++i;
    }
    return this;
}

int Scene::sceneFinish()
{
    return finishStatus;
}

void Scene::needDraw(QWidget *widget)
{
    QPainter painter(widget);
    for(int i = 0; i < items->size();i++)
    {
        GItem *a = items->at(i);
        if(a->isAlive())
        {
            QRect rect = a->rect();
            painter.drawPixmap(rect,a->pix());
        }
    }
}

void Scene::addItem(GItem *newItem)
{
    items->append(newItem);
}

void Scene::cleanItem()
{
    //qDeleteAll(*items);
    items->clear();
}

void Scene::setFinishStatus(int status)
{
    finishStatus = status;
}

