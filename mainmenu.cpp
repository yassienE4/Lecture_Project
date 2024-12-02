#include "mainmenu.h"
#include "levelselect.h"
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsScene>
#include <QFontDatabase>
#include <QSoundEffect>
#include <QRandomGenerator>

mainmenu::mainmenu(Game* game): QGraphicsScene()
{
    this->game = game;

    backgroundMusic = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    backgroundMusic->setAudioOutput(audioOutput);
    int random = QRandomGenerator::global()->bounded(2);
    if(random ==1)
        backgroundMusic->setSource(QUrl("qrc:/sounds/moogcity.mp3"));
    else
        backgroundMusic->setSource(QUrl("qrc:/sounds/wethands.mp3"));
    audioOutput->setVolume(1);
    backgroundMusic->setLoops(QMediaPlayer::Infinite);
    backgroundMusic->play();

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


    QPushButton* skinSelector = new QPushButton();
    skinSelector->setFixedSize(buttonimage.size());
    skinSelector->move(448,500);
    skinSelector->setText("Change Skin");
    skinSelector->setObjectName(QString("skinSelector"));
    skinSelector->setToolTip("Change Skins");
    skinSelector->setStyleSheet(
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

    QPushButton* shop_Button = new QPushButton();
    shop_Button->setFixedSize(buttonimage.size());
    shop_Button->move(448,400);
    shop_Button->setText("Open Shop");
    shop_Button->setObjectName(QString("shop_Button"));
    shop_Button->setToolTip("Open Shop");
    shop_Button->setStyleSheet(
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


    QSoundEffect *buttonsound = new QSoundEffect(this);
    buttonsound->setSource(QUrl("qrc:/sounds/buttonclick.wav"));
    buttonsound->setVolume(1);

    addWidget(newGame_Button);
    connect(newGame_Button, &QPushButton::clicked, this, [this, buttonsound] ()
    {
        buttonsound->play();   // Play sound
        new_game();
    });

    addWidget(skinSelector);
    connect(skinSelector, &QPushButton::clicked, this, [this, buttonsound] ()
    {
        buttonsound->play();
        mainmenu::skinSelector();
    });

    addWidget(shop_Button);
    connect(shop_Button, &QPushButton::clicked, this, [this, buttonsound] ()
            {
                buttonsound->play();
                mainmenu::openshop();
            });
}

void mainmenu::new_game()
{
    game->closemenu();
    game->openselect();

}

void mainmenu::skinSelector()
{
    game->closemenu();
    game->openskinselect();
}

void mainmenu::openshop()
{
    game->closemenu();
    game->openshop();
}
