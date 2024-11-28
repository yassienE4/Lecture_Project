#include "arrow.h"

arrow::arrow(int x, int y, bool d)
{
    right = QPixmap(":/images/arrow");
    left = QPixmap(":/images/arrowleft");
    if(d)
    {   setPixmap(right.scaled(100, 28, Qt::KeepAspectRatio));
        setPos(x+40,y+40);}
    else
    {   setPixmap(left.scaled(100, 28, Qt::KeepAspectRatio));
        setPos(x,y+40);}


    dir = d;
}


bool arrow::getdirection()
{
    return dir;
}

double arrow::getvelocity()
{
    return velocityY;
}

void arrow::gravity()
{
    velocityY += 0.01;
}
