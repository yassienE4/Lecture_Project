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
<<<<<<< HEAD
    bool isGunPurchased() const;
=======
    static bool doublejumpbought;
>>>>>>> effa7394409c7908543ea16e4266c4a56755e350
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
<<<<<<< HEAD
signals:
    void gunPurchasedSignal();
=======
    void purchasedoublejump(QPushButton *);
>>>>>>> effa7394409c7908543ea16e4266c4a56755e350
};

#endif // SHOP_H
