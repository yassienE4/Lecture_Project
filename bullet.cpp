#include "bullet.h"

bullet::bullet(int x, int y, bool d)
{
    right_bullet = QPixmap(":/images/bulletright");
    left_bullet = QPixmap(":/images/bulletleft ");
    if(d)
    {   setPixmap(right_bullet.scaled(100, 28, Qt::KeepAspectRatio));
        setPos(x+40,y+40);}
    else
    {   setPixmap(left_bullet.scaled(100, 28, Qt::KeepAspectRatio));
        setPos(x,y+40);}


    dir_bullet = d;
}


bool bullet::get_bullet_direction()
{
    return dir_bullet;
}

double bullet::bullet_getvelocity()
{
    return velocityY_bullet;
}

void bullet::bullet_gravity()
{
    velocityY_bullet += 0.01;
}
