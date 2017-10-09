#ifndef SCENEEND_H
#define SCENEEND_H

#include "scene.h"

class SceneEnd:public Scene
{
public:
    SceneEnd();
    virtual void needDraw(QWidget *widget);
    void restartGame();
};

#endif // SCENEEND_H
