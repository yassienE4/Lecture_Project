#include "arrow.h"

arrow::arrow(int x, int y, bool d)
{
    right = QPixmap(":/images/arrow");
    left = QPixmap(":/images/arrowleft");
    if(d)
        setPixmap(right.scaled(100, 28, Qt::KeepAspectRatio));
    else
        setPixmap(left.scaled(100, 28, Qt::KeepAspectRatio));

    setPos(x,y);
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
