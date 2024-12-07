#include "spikes.h"

spikes::spikes(int x, int y, int width, int height)
{
    this->width = width;
    this->height= height;

    setPos(x,y);

    setPixmap(QPixmap(":/images/spike.png").scaled(width, height));
}

int spikes::getwidth() const{
    return width;
}
int spikes:: getheight()const {
    return height;
}

void spikes::makelava()
{
    setPixmap(QPixmap(":/images/lava.png").scaled(width, height));
}
