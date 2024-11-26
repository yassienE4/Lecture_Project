#include "level3.h"

level3::level3(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level3::initialize()
{
    QPixmap backgroundpixmap(":/images/level1scene");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    nportal = new portal(4500, 120); // change 1000 to the end of the level
    baselevel::addportal(nportal);

    baselevel::initialize();
}

