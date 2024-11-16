#include "mainmenu.h"
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsScene>

mainmenu::mainmenu(Game* game): QGraphicsScene()
{
    this->game = game;

    QPixmap background(":/images/startscreen.png");
    background = background.scaled(1280,720, Qt::KeepAspectRatioByExpanding);
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(background);
    addItem(backgroundItem);
    backgroundItem->setZValue(-1);


    QPushButton* newGame_Button = new QPushButton();
    newGame_Button->setText("New Game");
    newGame_Button->setObjectName(QString("newGame_Button"));
    newGame_Button->setToolTip("New Game");
    newGame_Button->setGeometry(QRect(640, 360, 100, 32)); // puts button at coords 640,360 with width/height 100/32
    newGame_Button->setAutoFillBackground(false);



    addWidget(newGame_Button);
    connect(newGame_Button, &QPushButton::clicked, this, &mainmenu::new_game);
}

void mainmenu::new_game()
{
    game->scene()->clear();
}
