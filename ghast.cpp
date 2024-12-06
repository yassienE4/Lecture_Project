#include "ghast.h"

ghast::ghast(int x, int y,bool d)
{
    right = QPixmap(":/images/ghast.png").scaled(300, 300, Qt::KeepAspectRatio);
    rightcharge = QPixmap(":/images/ghast2.png").scaled(300, 300, Qt::KeepAspectRatio);
    dispenserpix = QPixmap(":/images/dispenser.png").scaled(100, 100, Qt::KeepAspectRatio);



    setPos(x,y);
    setPixmap(right);
    cooldown.start();


    dispenser = d;
    if(d)
        setPixmap(dispenserpix);

}

void ghast::setpix(int x)
{
    if(dispenser)
        return; //ignore
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

bool ghast::isdispenser()
{
    return dispenser;
}
