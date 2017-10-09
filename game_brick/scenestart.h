#ifndef SCENESTART_H
#define SCENESTART_H

#include "scene.h"

class SceneStart:public Scene
{
public:
    SceneStart();
    void needDraw(QWidget *widget);
    void startGame();
};

#endif // SCENESTART_H
