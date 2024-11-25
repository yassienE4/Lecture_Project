#ifndef MOVING_ENEMY_H
#define MOVING_ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include<QGraphicsScene>

class moving_enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    moving_enemy(int startpos, int ypos,int maxpos, int minpos);

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
    int verticalDistance; // Distance moved in the vertical direction
    int allowedHorizontalMovement; // Horizontal range limit
    int allowedVerticalMovement; // Vertical range limit

    bool direction;

    QPixmap right;
    QPixmap left;
public slots:
    //void move();
signals:
    void gameOver();

};

#endif // MOVING_ENEMY_H
