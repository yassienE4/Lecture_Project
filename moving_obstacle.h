#ifndef MOVING_OBSTACLES_H
#define MOVING_OBSTACLES_H

#include "obstacle.h"

class MovingObstacle : public obstacle {
public:
    MovingObstacle(int x, int y, int width, int height, const QString& imagePath, int dx, int dy);

    void updatePosition(); // Function to move the obstacle

private:
    int dx; // Horizontal speed
    int dy; // Vertical speed
};

#endif // MOVING_OBSTACLES_H

