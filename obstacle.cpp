#include "obstacle.h"
#include <QTimer>     // Include QTimer for the timer functionality
#include <QGraphicsPixmapItem>

// obstacle::obstacle(int x, int y, int width, int height, const QString& imagePath) {
//     this->width = width; //to solve that they both have the same name use pointer to specefify which variable
//     this->height= height;

//     setPos(x,y);

//     setPixmap(QPixmap(imagePath).scaled(width, height));



// }
// int obstacle::getwidth() const{
//     return width; //getter function
// }
// int obstacle:: getheight()const {
//     return height;
// }


// // obstacle::obstacle(int x, int y, int width, int height, const QString& imagePath, int startX, int endX, int speed)
// //     : startX(startX), endX(endX), speed(speed), movingRight(true) {
// //     setPixmap(QPixmap(imagePath).scaled(width, height));
// //     setPos(x, y);

// //     if (startX != endX && speed > 0) {
// //         moveTimer = new QTimer(this);
// //         connect(moveTimer, &QTimer::timeout, this, &obstacle::updatePosition);
// //         moveTimer->start(30);
// //     } else {
// //         moveTimer = nullptr;
// //     }
// // }

// // void obstacle::updatePosition() {
// //     if (movingRight) {
// //         if (x() + speed >= endX) {
// //             movingRight = false;
// //         } else {
// //             setX(x() + speed);
// //         }
// //     } else {
// //         if (x() - speed <= startX) {
// //             movingRight = true;
// //         } else {
// //             setX(x() - speed);
// //         }
// //     }
// // }

// // void obstacle::startMoving() {
// //     if (moveTimer)
// //         moveTimer->start();
// // }

// obstacle::obstacle(int x, int y, int width, int height, const QString& imagePath,
//                    int startX, int endX, int speed)
//     : QGraphicsPixmapItem(), startX(startX), endX(endX), speed(speed), movingRight(true) {
//     setPixmap(QPixmap(imagePath).scaled(width, height));
//     setPos(x, y);
//     moveTimer = new QTimer(this);
//     connect(moveTimer, &QTimer::timeout, this, &obstacle::updatePosition);
//     moveTimer->start(30);  // Adjust as needed
// }

// void obstacle::startMoving() {
//     if (moveTimer) {
//         moveTimer->start();
//     }
// }

// void obstacle::updatePosition() {
//     int x = pos().x();
//     if (movingRight) {
//         if (x + speed < endX) {
//             setPos(x + speed, pos().y());
//         } else {
//             movingRight = false;
//         }
//     } else {
//         if (x - speed > startX) {
//             setPos(x - speed, pos().y());
//         } else {
//             movingRight = true;
//         }
//     }
// }


obstacle::obstacle(int x, int y, int width, int height, const QString& imagePath, QObject* parent)
    : QObject(parent), pixmapItem(new QGraphicsPixmapItem()), startX(0), endX(0), speed(0), movingRight(true), moveTimer(nullptr) {
    pixmapItem->setPixmap(QPixmap(imagePath).scaled(width, height));
    pixmapItem->setPos(x, y);
}

obstacle::obstacle(int x, int y, int width, int height, const QString& imagePath, int startX, int endX, int speed, QObject* parent)
    : QObject(parent), pixmapItem(new QGraphicsPixmapItem()), startX(startX), endX(endX), speed(speed), movingRight(true) {
    pixmapItem->setPixmap(QPixmap(imagePath).scaled(width, height));
    pixmapItem->setPos(x, y);

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &obstacle::updatePosition);
    moveTimer->start(30); // Adjust as needed
}

QGraphicsPixmapItem* obstacle::getGraphicsItem() const {
    return pixmapItem;
}

void obstacle::startMoving() {
    if (moveTimer) {
        moveTimer->start();
    }
}

void obstacle::updatePosition() {
    int x = pixmapItem->pos().x();
    if (movingRight) {
        if (x + speed < endX) {
            pixmapItem->setPos(x + speed, pixmapItem->pos().y());
        } else {
            movingRight = false;
        }
    } else {
        if (x - speed > startX) {
            pixmapItem->setPos(x - speed, pixmapItem->pos().y());
        } else {
            movingRight = true;
        }
    }
}
