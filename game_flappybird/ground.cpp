#include "ground.h"

Ground::Ground(Scene *scene, int posX, int posY,int speed)
    :GItem(scene,posX,posY)
{
    curPix = new QPixmap(":/picture/res/picture/ground.png");
    speedX = speed;
}

void Ground::refresh()
{
    //不加一会导致地面右侧闪一下
    if(posX < 288-336+1)
    {
        posX = 0;
    }
    moveLeft();
}
