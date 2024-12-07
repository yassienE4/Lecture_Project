#ifndef SPIKES_H
#define SPIKES_H

#include <QGraphicsPixmapItem>

class spikes : public QGraphicsPixmapItem
{
public:
    spikes(int x, int y, int width, int height);
    int getwidth() const;
    int getheight() const;
    void makelava();
private:
    // dimensions of obstacle
    int width;
    int height;
};

#endif // SPIKES_H



