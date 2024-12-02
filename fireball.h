#ifndef FIREBALL_H
#define FIREBALL_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QElapsedTimer>

class fireball : public QGraphicsPixmapItem
{
public:
    fireball(int x, int y);
    QElapsedTimer graceperiod;
private:
    QPixmap ball;
};

#endif // FIREBALL_H
