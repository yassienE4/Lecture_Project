#include "fireball.h"

fireball::fireball(int x, int y)
{
    ball = QPixmap(":/images/fireball");

    setPixmap(ball.scaled(100, 100, Qt::KeepAspectRatio));
    setPos(x+40,y+60);
    graceperiod.start();
}
