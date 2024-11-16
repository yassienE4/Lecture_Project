#ifndef STEVE_H
#define STEVE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QObject>
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
 Q_OBJECT
public:
    steve();
    void setstate(PlayerState x);
    void setvelocity(int x);
    PlayerState getstate();
    int getvelocity();
    bool getjump();
private:
    QPixmap playerpixmap;
    PlayerState state;
    int player_velocity;
};

#endif // STEVE_H
