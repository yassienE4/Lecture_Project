#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QTimer>

class obstacle:public QGraphicsPixmapItem,public QObject
{
       Q_OBJECT
public:
    // constructor to set specefic values for position and size
    // obstacle(int x, int y, int width, int height,const QString& imagePath);
     obstacle(int x, int y, int width, int height, const QString& imagePath, QObject* parent = nullptr);
     // constructor for moving obstacle:
     obstacle(int x, int y, int width, int height, const QString& imagePath, int startX, int endX, int speed, QObject* parent = nullptr);


    // create getter functions for the dimensions of static objects
    int getwidth() const;
    int getheight() const;
 void startMoving();
QGraphicsPixmapItem* getGraphicsItem() const;

private:
    // dimensions of obstacle
    int width;
    int height;

    int startX, endX;  // Horizontal movement bounds
    int speed;         // Speed of movement
    bool movingRight;  // Direction of movement
    QTimer* moveTimer;
     QGraphicsPixmapItem* pixmapItem;
private slots:
     void updatePosition();

};

#endif // OBSTACLE_H
