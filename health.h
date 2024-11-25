#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>

class health : public QGraphicsPixmapItem
{
public:
    health();
    void applydamage();
    int gethealth();
private:
    int healthpoints;
    QPixmap heart;
    QPixmap twohearts;
    QPixmap threehearts;
    QPixmap fourhearts;
    QPixmap nohearts;
};

#endif // HEALTH_H
