#include "steve.h"

steve::steve()  {
    playerpixmap = QPixmap(":/images/steve.png");
    leftplayerpixmap = QPixmap(":/images/steveleft.png");
    rightplayerpixmap = QPixmap(":/images/steve.png");
    int scaledWidth = playerpixmap.width() * 200 / playerpixmap.height();
    playerpixmap = playerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);
    rightplayerpixmap = rightplayerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);
    leftplayerpixmap = leftplayerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);

    rightmoving = QPixmap(":/images/stevemoveright1");
    int movescaled = rightmoving.width() * 200 / rightmoving.height();
    leftmoving = QPixmap(":/images/stevemoveleft1");
    rightmoving = rightmoving.scaled(movescaled, 200,Qt::KeepAspectRatio );
    leftmoving = leftmoving.scaled(movescaled, 200,Qt::KeepAspectRatio );

    rightmoving2 = QPixmap(":/images/stevemoveright2");
    leftmoving2 = QPixmap(":/images/stevemoveleft2");
    rightmoving2 = rightmoving2.scaled(movescaled, 200,Qt::KeepAspectRatio );
    leftmoving2 = leftmoving2.scaled(movescaled, 200,Qt::KeepAspectRatio );

    setPixmap(playerpixmap);
    state = Static;
    player_velocity=0;
    direction = 1;
}


void steve::setstate(PlayerState x)
{
    state = x;
}
void steve::setpix(int p)
{
    if(p == 1)
        setPixmap(rightplayerpixmap);
    if(p == 2)
        setPixmap(leftplayerpixmap);
    if(p == 3)
        setPixmap(rightmoving);
    if(p == 4)
        setPixmap(leftmoving);
    if(p == 5)
        setPixmap(rightmoving2);
    if(p==6)
        setPixmap(leftmoving2);
    return;
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
    return (state == Jumping);
}
void steve::setdirection(bool x)
{
    direction = x;
}
bool steve::getdirection()
{
    return direction;
}
