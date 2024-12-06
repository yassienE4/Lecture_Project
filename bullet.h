#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class bullet : public QGraphicsPixmapItem
{
public:
    bullet(int x, int y, bool d);
    bool get_bullet_direction();
    void bullet_gravity();
    double bullet_getvelocity();
private:
    QPixmap right_bullet;
    QPixmap left_bullet;
    bool dir_bullet;
    double velocityY_bullet;
};


#endif // BULLET_H
