#include "diamonds.h"

diamonds::diamonds(int x, int y)
{
    setPos(x,y);
    setPixmap(QPixmap(":/images/diamonds.png").scaled(50, 50));
}
