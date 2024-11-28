#ifndef BOW_H
#define BOW_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class bow : public QGraphicsPixmapItem
{
public:
    bow(int x, int y, bool d);
    void setpix(int);
    bool getdirection();
    void changedirection(int x, int y,bool d);
private:
    QPixmap right;
    QPixmap left;
    QPixmap right1;
    QPixmap left1;
    QPixmap right2;
    QPixmap left2;
    QPixmap right3;
    QPixmap left3;
    bool dir;
};

#endif // BOW_H
