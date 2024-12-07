#include "moving_obstacle.h"



MovingObstacle::MovingObstacle(int x, int y, int width, int height, const QString& imagePath, int dx, int dy)
    : obstacle(x, y, width, height, imagePath), dx(dx), dy(dy) {}

void MovingObstacle::updatePosition() {
    setPos(x() + dx, y() + dy);
}

