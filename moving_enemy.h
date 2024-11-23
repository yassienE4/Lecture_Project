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
    int m_speed;
    int m_x_min;
    int m_x_max;
    baselevel* m_level;

public slots:
    void move();
signals:
    void gameOver();

};

#endif // MOVING_ENEMY_H
