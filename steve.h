#ifndef STEVE_H
#define STEVE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "obstacle.h"

#include <QPainter>

enum PlayerState //mainly for animations
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
    bool getdirection();
    void setpix(int p);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //used for checking bounding box pos
    void setboundingboxes();
    // coliding set/getters
    bool getcolideright();
    bool getcolideleft();
    bool getcolideup();
    bool getcolidedown();
    bool getgrounded();
    void setcolideright(bool x);
    void setcolideleft(bool x);
    void setcolideup(bool x);
    void setcolidedown(bool x);
    void setgrounded(bool x);
    //boundingbox getters
    QRectF getrightBoundingBox();
    QRectF getleftBoundingBox();
    QRectF getupBoundingBox();
    QRectF getdownBoundingBox();

    obstacle* isGrounded(const QList<obstacle*>&);

private:
    QPixmap playerpixmap;
    QPixmap leftplayerpixmap;
    QPixmap rightplayerpixmap;
    QPixmap leftmoving;
    QPixmap leftmoving2;
    QPixmap rightmoving;
    QPixmap rightmoving2;
    PlayerState state;
    int player_velocity;
    bool direction;

    //coliding bools
    bool colideright;
    bool colideleft;
    bool colideup;
    bool colidedown;
    bool grounded;

    //bounding boxes
    QRectF rightBoundingBox;
    QRectF leftBoundingBox;
    QRectF upBoundingBox;
    QRectF downBoundingBox;
};

#endif // STEVE_H
