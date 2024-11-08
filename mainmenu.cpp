#include "mainmenu.h"

#include <QPushButton>
#include <QGraphicsScene>

mainmenu::mainmenu(Game* game): QGraphicsScene(game)
{
    this->game = game;
    QPushButton* newGame_Button = new QPushButton();
    newGame_Button->setText("New Game");
    newGame_Button->setObjectName(QString("newGame_Button"));
    newGame_Button->setToolTip("New Game");
    newGame_Button->setGeometry(QRect(640, 360, 100, 32)); // puts button at coords 640,360 with width/height 100/32
    newGame_Button->setAutoFillBackground(false);

    this->addWidget(newGame_Button);
    //connect(newGame_Button, SIGNAL(clicked()), this, SLOT(new_game()));
    connect(newGame_Button, &QPushButton::clicked, this, &mainmenu::new_game);
}

void mainmenu::new_game()
{
    game->scene()->clear();
}
