#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>

class obstacle:public QGraphicsPixmapItem
{
public:
    // constructor to set specefic values for position and size
    obstacle(int x, int y, int width, int height,const QString& imagePath);

    // create getter functions for the dimensions of static objects
    int getwidth() const;
    int getheight() const;

private:
    // dimensions of obstacle
    int width;
    int height;

};

#endif // OBSTACLE_H
