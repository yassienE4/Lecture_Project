#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class arrow : public QGraphicsPixmapItem
{
public:
    arrow(int x, int y, bool d);
    bool getdirection();
    void gravity();
    double getvelocity();
private:
    QPixmap right;
    QPixmap left;
    bool dir;
    double velocityY;
};

#endif // ARROW_H
