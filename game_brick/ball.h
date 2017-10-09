#ifndef BALL_H
#define BALL_H

#include "QPoint"
#include "QPixmap"
#include "paddle.h"
#include "gitem.h"

class Paddle;
class Ball : public GItem
{
public:
    Ball(QPoint pos,int speed);
    void move();
    void speedOverturn(bool isX);
    bool getStart() const;
    void setStart(bool value);
    bool m_start;
};

#endif // BALL_H
