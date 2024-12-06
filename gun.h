#ifndef GUN_H
#define GUN_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class gun : public QGraphicsPixmapItem
{
public:
    gun(int x, int y, bool d);
    void setpix_gun(int);
    bool getdirection_gun();
    void changedirection_gun(int x, int y,bool d);
private:
    QPixmap right_gun;
    QPixmap left_gun;
    QPixmap right1_gun;
    QPixmap left1_gun;
    QPixmap right2_gun;
    QPixmap left2_gun;
    QPixmap right3_gun;
    QPixmap left3_gun;
    bool dir_gun;
};

#endif // GUN_H
