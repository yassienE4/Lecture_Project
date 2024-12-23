#include "moving_enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>


moving_enemy::moving_enemy(int startpos, int ypos ,int maxpos, int minpos) : QObject(), direction(1), horizontalDistance(0),verticalDistance(0) {
    right = QPixmap(":/images/movingenemyright.png");
    left = QPixmap(":/images/movingenemyleft.png");

    right = right.scaled(75, 150,Qt::KeepAspectRatio );
    left = left.scaled(75,150,Qt::KeepAspectRatio);

    x_max = maxpos;
    x_min = minpos;

    setPixmap(right);

    setPos(startpos,ypos);

    allowedHorizontalMovement = 20;
    allowedVerticalMovement = 25;



}
void moving_enemy::set_speed(int s){
    speed=s;

}
void moving_enemy::set_bound(int x, int x2){
    x_max = x;
    x_min = x2;

}

int moving_enemy::getmaxrange()
{
    return x_max;
}

int moving_enemy::getminrange()
{
    return x_min;
}

bool moving_enemy::getdirection()
{
    return direction;
}
void moving_enemy::setdirection(bool x)
{
    direction = x;
    if(x)
    {
        setPixmap(right);
    }
    else
    {
        setPixmap(left);
    }
}


