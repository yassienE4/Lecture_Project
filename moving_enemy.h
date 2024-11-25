#ifndef MOVING_ENEMY_H
#define MOVING_ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include<QGraphicsScene>
#include "baselevel.h"

class baselevel;

class moving_enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    moving_enemy(baselevel* level, const QString& enemyImage);

    void set_speed(int s);

    void set_bound(int x_min, int x_max);

private:
    baselevel* m_level; // Pointer to the game level
    int m_speed = 5; // Speed of vertical movement
    int m_x_min = 0; // Minimum horizontal bound
    int m_x_max = 800; // Maximum horizontal bound
    int m_direction = 1; // Direction of horizontal movement (1 = right, -1 = left)
    int m_horizontalDistance = 0; // Distance moved in the current horizontal direction
    int m_verticalDistance = 0; // Distance moved in the vertical direction
    int m_allowedHorizontalMovement = 20; // Horizontal range limit
    int m_allowedVerticalMovement = 25; // Vertical range limit

public slots:
    void move();
signals:
    void gameOver();

};

#endif // MOVING_ENEMY_H
