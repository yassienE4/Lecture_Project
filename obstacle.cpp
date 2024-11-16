#include "obstacle.h"

obstacle::obstacle(int x, int y, int width, int height, const QString& imagePath) {
    this->width = width; //to solve that they both have the same name use pointer to specefify which variable
    this->height= height;

    setPos(x,y);

    setPixmap(QPixmap(":/obstacle.jpg").scaled(width, height));



}
int obstacle::getwidth() const{
    return width; //getter function
}
int obstacle:: getheight()const {
    return height;
}
