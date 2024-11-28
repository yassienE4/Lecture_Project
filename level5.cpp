#include "level5.h"

level5::level5(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level5::initialize()
{
    QPixmap backgroundpixmap(":/images/level5scene");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    nportal = new portal(4500, 120); // change 1000 to the end of the level
    baselevel::addportal(nportal);

    baselevel::initialize();
}

