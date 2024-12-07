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
    static bool gunbought;
    bool isGunPurchased() const;
private:
    Game* game;
    QString fontFamily;
    QPixmap buttonimage;
    QGraphicsTextItem *textItem = new QGraphicsTextItem(nullptr);
    QGraphicsTextItem *insufficientFunds = new QGraphicsTextItem(nullptr);
    QSoundEffect* buttonsound;
    static bool gunPurchased;
public slots:
    void purchase1(QPushButton *);
    void back();
    void purchaseGun(QPushButton *);
signals:
    void gunPurchasedSignal();
};

#endif // SHOP_H
