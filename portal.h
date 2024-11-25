#ifndef PORTAL_H
#define PORTAL_H
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QDebug>

class portal : public QGraphicsPixmapItem
{
public:
    portal(int x, int y);
    void setboundingbox(int x, int y);
    QRectF getportalbox();
private:
    QRectF portalbox;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PORTAL_H
