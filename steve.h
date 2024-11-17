#ifndef STEVE_H
#define STEVE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

enum PlayerState
{
    Moving,
    Jumping,
    Falling,
    Static
};

class steve : public QGraphicsPixmapItem
{
public:
    steve();
    void setstate(PlayerState x);
    void setvelocity(int x);
    PlayerState getstate();
    int getvelocity();
    bool getjump();
    void setdirection(bool x);

private:
    QPixmap playerpixmap;
    QPixmap leftplayerpixmap;
    QPixmap rightplayerpixmap;
    PlayerState state;
    int player_velocity;
    bool direction;
};

#endif // STEVE_H
