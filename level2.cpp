#include "level2.h"

level2::level2(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level2::initialize()
{
    QPixmap backgroundpixmap(":/images/level2scene.png");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    nportal = new portal(4500, 120); // change 1000 to the end of the level
    baselevel::addportal(nportal);

    baselevel::initialize();

}
