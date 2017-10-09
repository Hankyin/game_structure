#ifndef PADDLE_H
#define PADDLE_H
#include "QWidget"
#include "QPixmap"
#include "QRect"
#include "gitem.h"

class Ball;

class Paddle :public GItem
{
public:
    explicit Paddle(QPoint pos, int speed, Ball *_ball);
    Ball *ball;
    void moveLeft();
    void moveRight();
    void fire();
};

#endif // PADDLE_H
