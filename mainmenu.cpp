#include "mainmenu.h"
#include "levelselect.h"
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsScene>
#include <QFontDatabase>

mainmenu::mainmenu(Game* game): QGraphicsScene()
{
    this->game = game;

    QPixmap background(":/images/background_select");
    background = background.scaled(1280,720, Qt::KeepAspectRatioByExpanding);
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(background);
    addItem(backgroundItem);
    backgroundItem->setZValue(-1);

    QPixmap buttonimage(":/images/mcbuttonimage");
    int fontId = QFontDatabase::addApplicationFont(":/fonts/mcfont.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);

    QPushButton* newGame_Button = new QPushButton();
    newGame_Button->setFixedSize(buttonimage.size());
    newGame_Button->move(448,600);
    newGame_Button->setText("New Game");
    newGame_Button->setObjectName(QString("newGame_Button"));
    newGame_Button->setToolTip("New Game");
    newGame_Button->setStyleSheet(
        "QPushButton {"
        "    border: none;"                // Remove border
        "    background-image: url(:/images/mcbuttonimage);" // Set the image as background
        "    background-repeat: no-repeat;"
        "    background-position: center;"
        "    color: white;"                // Set text color
        "    font-family: '" + fontFamily + "';" // Set the custom font
                       "    font-size: 16px;"             // Set text size
                       "    text-align: center;"          // Center the text
                       "}"
        );



    addWidget(newGame_Button);
    connect(newGame_Button, &QPushButton::clicked, this, &mainmenu::new_game);
}

void mainmenu::new_game()
{
    //game->scene()->clear();
    game->closemenu();
    game->openselect();

}
