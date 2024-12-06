#include "gun.h"

gun::gun(int x, int y, bool d)
{
    right_gun = QPixmap(":/images/try_gun_right").scaled(100, 100, Qt::KeepAspectRatio);
    left_gun = QPixmap(":/images/try_gun_left").scaled(100, 100, Qt::KeepAspectRatio);
    // right1 = QPixmap(":/images/bowright1.png").scaled(100, 100, Qt::KeepAspectRatio);
    // left1 = QPixmap(":/images/bowleft1.png").scaled(100, 100, Qt::KeepAspectRatio);
    // right2 = QPixmap(":/images/bowright2.png").scaled(100, 100, Qt::KeepAspectRatio);
    // left2 = QPixmap(":/images/bowleft2.png").scaled(100, 100, Qt::KeepAspectRatio);
    // right3 = QPixmap(":/images/bowright3.png").scaled(100, 100, Qt::KeepAspectRatio);
    // left3 = QPixmap(":/images/bowleft3.png").scaled(100, 100, Qt::KeepAspectRatio);
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
    // if(x == 3)
    //     setPixmap(right1);
    // if(x == 4)
    //     setPixmap(left1);
    // if(x == 5)
    //     setPixmap(right2);
    // if(x == 6)
    //     setPixmap(left2);
    // if(x == 7)
    //     setPixmap(right3);
    // if(x == 8)
    //     setPixmap(left3);


}

bool gun::getdirection_gun()
{
    return dir_gun;
}

