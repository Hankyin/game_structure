#include "sceneend.h"

SceneEnd::SceneEnd()
{
    registerKey("r",(CallBack)&SceneEnd::restartGame);
}

void SceneEnd::needDraw(QWidget *widget)
{
    QPainter painter(widget);
    painter.drawText(QPoint(100,250),"游戏结束,按r重新开始");
}

void SceneEnd::restartGame()
{
    setFinishStatus(1);
}

