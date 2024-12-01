#ifndef FIREBALL_H
#define FIREBALL_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class fireball : public QGraphicsPixmapItem
{
public:
    fireball(int x, int y);
private:
    QPixmap ball;
};

#endif // FIREBALL_H
