#include "skinselect.h"
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsScene>
#include <QFontDatabase>

#include <QLabel>
#include <QMovie>
#include "steve.h"

skinselect::skinselect(Game* game)
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


    QPushButton* steve_Button = new QPushButton();
    steve_Button->setFixedSize(buttonimage.size());
    steve_Button->move(448,600);
    steve_Button->setText("Steve");
    steve_Button->setObjectName(QString("steve_Button"));
    steve_Button->setToolTip("Change Skin to Steve");
    steve_Button->setStyleSheet(
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



    addWidget(steve_Button);
    connect(steve_Button, &QPushButton::clicked, this, &skinselect::selectsteve);

    QPushButton* alex_Button = new QPushButton();
    alex_Button->setFixedSize(buttonimage.size());
    alex_Button->move(850,600);
    alex_Button->setText("Alex");
    alex_Button->setObjectName(QString("alex_Button"));
    alex_Button->setToolTip("Change Skin to Alex");
    alex_Button->setStyleSheet(
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



    addWidget(alex_Button);
    connect(alex_Button, &QPushButton::clicked, this, &skinselect::selectalex);


    // QLabel stevelabel;
    // QMovie *stevegif = new QMovie(":/images/stevepreview.gif");
    // stevelabel.setMovie(stevegif);
    // stevegif->start();
    // stevelabel.resize(stevegif->scaledSize());
    // stevelabel.show();

    /*
    QMovie *alexgif = new QMovie(":/images/alexpreview.gif");
    alexlabel.setMovie(alexgif);
    alexgif->start();
    alexlabel.resize(alexgif->scaledSize());
    alexlabel.show();

    alexlabel.resize(alexgif->scaledSize());
    alexlabel.move(645, 500); // Adjust the position as needed
    addWidget(&alexlabel);
    */


    QPushButton* mario_Button = new QPushButton();
    mario_Button->setFixedSize(buttonimage.size());
    mario_Button->move(46,600);
    mario_Button->setText("Mario");
    mario_Button->setObjectName(QString("mario_Button"));
    mario_Button->setToolTip("Change Skin to Mario");
    mario_Button->setStyleSheet(
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



    addWidget(mario_Button);
    connect(mario_Button, &QPushButton::clicked, this, &skinselect::selectmario);



}

void skinselect::selectsteve()
{
    //go back to main
    steve::skin_static = 1;
    game->closemenu();
    game->openmenu();
}

void skinselect::selectalex()
{
    //go back to main
    steve::skin_static = 2;
    game->closemenu();
    game->openmenu();
}

void skinselect::selectmario()
{
    steve::skin_static = 3;
    game->closemenu();
    game->openmenu();
}
