#include "level4.h"

level4::level4(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level4::initialize()
{
    QPixmap backgroundpixmap(":/images/level4scene");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    nportal = new portal(4500, 120); // change 1000 to the end of the level
    baselevel::addportal(nportal);

    baselevel::initialize();
}

