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
private:
    QPixmap playerpixmap;
};

#endif // STEVE_H
