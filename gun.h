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
    bool dir_gun;
};

#endif // GUN_H
