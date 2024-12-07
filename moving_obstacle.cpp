#include "moving_obstacle.h"



MovingObstacle::MovingObstacle(int x, int y, int width, int height, const QString& imagePath, int dx, int dy)
    : obstacle(x, y, width, height, imagePath), dx(dx), dy(dy) {}

// void MovingObstacle::updatePosition() {
//     setPos(x() + dx, y() + dy);
// }

void MovingObstacle::set_speed(int s){
    speed=s;

}
void MovingObstacle::set_bound(int x, int x2){
    x_max = x;
    x_min = x2;

}

int MovingObstacle::getmaxrange()
{
    return x_max;
}

int MovingObstacle::getminrange()
{
    return x_min;
}

bool MovingObstacle::getdirection()
{
    return direction;
}
void MovingObstacle::setdirection(bool x)
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

