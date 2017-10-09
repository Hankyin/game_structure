#include "scenestart.h"

SceneStart::SceneStart()
{
    registerKey("r",(CallBack)&SceneStart::startGame);
}

void SceneStart::needDraw(QWidget *widget)
{
    QPainter painter(widget);
    painter.drawText(QPoint(300,250),"按r键开始,w发射子弹，a和d移动挡板");
}

void SceneStart::startGame()
{
    setFinishStatus(1);
}

