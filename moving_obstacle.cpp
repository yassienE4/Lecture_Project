#include "moving_obstacle.h"



MovingObstacle::MovingObstacle(int x, int y, int width, int height, const QString& imagePath, int xmin, int xmax)
    : obstacle(x, y, width, height, imagePath), x1(xmin), x2(xmax) {}

int MovingObstacle::getx1()
{
    return x1;
}

int MovingObstacle::getx2()
{
    return x2;
}

int MovingObstacle::getdir()
{
    return dir;
}

void MovingObstacle::setdir(int x)
{
    dir = x;
}
