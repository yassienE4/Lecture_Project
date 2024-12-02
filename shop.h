#ifndef SHOP_H
#define SHOP_H

#include <QGraphicsScene>
#include <QLabel>
#include <QSoundEffect>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QFontDatabase>
#include <QGraphicsTextItem>
#include "game.h"

class shop : public QGraphicsScene
{
    Q_OBJECT
public:
    shop(Game* game);
    static int totaldiamonds; // static so that all instances share
    static bool arrowgravitybought;
private:
    Game* game;
    QGraphicsTextItem *textItem = new QGraphicsTextItem(nullptr);
    QGraphicsTextItem *insufficientFunds = new QGraphicsTextItem(nullptr);
public slots:
    void purchase1(QPushButton *);
    void back();
};

#endif // SHOP_H
