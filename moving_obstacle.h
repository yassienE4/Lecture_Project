#ifndef MOVING_OBSTACLES_H
#define MOVING_OBSTACLES_H

#include "obstacle.h"

class MovingObstacle : public obstacle {
public:
    MovingObstacle(int x, int y, int width, int height, const QString& imagePath, int dx, int dy);
    int getx1();
    int getx2();
    int getdir();
    void setdir(int x);


private:
    int x1; // Horizontal speed
    int x2; // Vertical speed
    int dir;
};

#endif // MOVING_OBSTACLES_H

