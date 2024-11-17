#include "steve.h"

steve::steve()  {
    playerpixmap = QPixmap(":/images/steve.png");
    leftplayerpixmap = QPixmap(":/images/steveleft.png");
    rightplayerpixmap = QPixmap(":/images/steve.png");
    int scaledWidth = playerpixmap.width() * 200 / playerpixmap.height();
    playerpixmap = playerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);
    rightplayerpixmap = rightplayerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);
    leftplayerpixmap = leftplayerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);
    setPixmap(playerpixmap);
    state = Static;
    player_velocity=0;
}


void steve::setstate(PlayerState x)
{
    state = x;
}
void steve::setvelocity(int x)
{
    player_velocity = x;
}
PlayerState steve::getstate()
{
    return state;
}
int steve::getvelocity()
{
    return player_velocity;
}
bool steve::getjump()
{
    return state == Jumping;
}
void steve::setdirection(bool x)
{
    direction = x;
    if(direction)
    {
        setPixmap(rightplayerpixmap);
    }
    else
    {
        setPixmap(leftplayerpixmap);
    }
}
