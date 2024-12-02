#ifndef GHAST_H
#define GHAST_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "fireball.h"
#include "QElapsedTimer"

class ghast : public QGraphicsPixmapItem
{
public:
    ghast(int x, int y);
    void setpix(int);
    fireball* returnball(); // basically if not null dont spawn another
    void setball(fireball *);
    QElapsedTimer cooldown;
    bool shown; // for sound check
private:
    QPixmap right;
    QPixmap rightcharge;
    fireball * fireballitem;

};

#endif // GHAST_H
