#include "portal.h"

portal::portal(int x, int y)
{
    setPos(x,y);
    setPixmap(QPixmap(":/images/Nether_Portal.png").scaled(320, 400));
    setboundingbox(x,y);
    setZValue(-0.6);
}

void portal::setboundingbox(int x, int y)
{
    int w = 160;
    int h = 240;

    portalbox = QRectF(80,80,w,h);

}

QRectF portal::getportalbox()
{
    return portalbox;
}

/*
void portal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



    qDebug() << "painting";
        painter->setPen(QPen(Qt::red));
        painter->setBrush(Qt::transparent);
        painter->drawRect(portalbox);


        QGraphicsPixmapItem::paint(painter, option, widget);

}
*/
