#include "ghast.h"

ghast::ghast(int x, int y)
{
    right = QPixmap(":/images/ghast.png").scaled(300, 300, Qt::KeepAspectRatio);
    rightcharge = QPixmap(":/images/ghast2.png").scaled(300, 300, Qt::KeepAspectRatio);



    setPos(x,y);
    setPixmap(right);
    cooldown.start();


}

void ghast::setpix(int x)
{
    if(x == 1)
        setPixmap(right);
    if(x == 2)
        setPixmap(rightcharge);
}

fireball* ghast::returnball()
{
    return fireballitem;
}

void ghast::setball(fireball* x)
{
    fireballitem = x;
}
