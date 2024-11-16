#include "steve.h"

steve::steve()  {
    playerpixmap = QPixmap(":/images/steve.png");

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
    if(state == Jumping)
    {
        return true;
    }
    else {
        return false;
    }
}
