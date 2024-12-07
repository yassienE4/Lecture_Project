#include "gun.h"

gun::gun(int x, int y, bool d)
{
    right_gun = QPixmap(":/images/gun_right.png").scaled(100, 100, Qt::KeepAspectRatio);
    left_gun = QPixmap(":/images/gun_left.png").scaled(100, 100, Qt::KeepAspectRatio);
    if(d)
    {
        setPos(x+65,y+10);
        setPixmap(right_gun);
    }
    else
    {
        setPos(x-25,y+10);
        setPixmap(left_gun);
    }

    setZValue(-0.5);
    dir_gun = d;
}

void gun::changedirection_gun(int x, int y,bool d)
{
    if(d)
    {
        setPos(x+65,y+10);
        setPixmap(right_gun);
    }
    else
    {
        setPos(x-25,y+10);
        setPixmap(left_gun);
    }
}

void gun::setpix_gun(int x)
{
    if(x == 1)
        setPixmap(right_gun);
    if(x == 2)
        setPixmap(left_gun);


}

bool gun::getdirection_gun()
{
    return dir_gun;
}

