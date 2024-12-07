#ifndef MOVING_OBSTACLES_H
#define MOVING_OBSTACLES_H

#include "obstacle.h"

class MovingObstacle : public obstacle {
public:
    MovingObstacle(int x, int y, int width, int height, const QString& imagePath, int dx, int dy);

    // void updatePosition(); // Function to move the obstacle
    void set_speed(int s);

    void set_bound(int x_min, int x_max);

    int getmaxrange();
    int getminrange();
    bool getdirection();
    void setdirection(bool x);

private:
    int speed; // Speed of vertical movement
    int x_min; // Minimum horizontal bound
    int x_max; // Maximum horizontal bound
    int horizontalDistance; // Distance moved in the current horizontal direction

    int allowedHorizontalMovement; // Horizontal range limit


    bool direction;

    QPixmap right;
    QPixmap left;
};

#endif // MOVING_OBSTACLES_H

