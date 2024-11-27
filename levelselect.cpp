#include "levelselect.h"
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsScene>
#include <QFontDatabase>
#include <QSoundEffect>

levelselect::levelselect(Game* game)
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

    QSoundEffect *buttonsound = new QSoundEffect(this);
    buttonsound->setSource(QUrl("qrc:/sounds/buttonclick.wav"));
    buttonsound->setVolume(1);

    QPushButton* level1_Button = new QPushButton();
    level1_Button->setFixedSize(buttonimage.size());
    level1_Button->move(448,200);
    level1_Button->setText("Level 1");
    level1_Button->setObjectName(QString("level1_Button"));
    level1_Button->setToolTip("Opens Level 1");
    level1_Button->setStyleSheet(
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

    QPushButton* level2_Button = new QPushButton();
    level2_Button->setFixedSize(buttonimage.size());
    level2_Button->move(448,300);
    level2_Button->setText("Level 2");
    level2_Button->setObjectName(QString("level2_Button"));
    level2_Button->setToolTip("Opens Level 2");
    level2_Button->setStyleSheet(
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

    QPushButton* level3_Button = new QPushButton();
    level3_Button->setFixedSize(buttonimage.size());
    level3_Button->move(448,400);
    level3_Button->setText("Level 3");
    level3_Button->setObjectName(QString("level3_Button"));
    level3_Button->setToolTip("Opens Level 3");
    level3_Button->setStyleSheet(
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


    QPushButton* level4_Button = new QPushButton();
    level4_Button->setFixedSize(buttonimage.size());
    level4_Button->move(448,500);
    level4_Button->setText("Level 4");
    level4_Button->setObjectName(QString("level4_Button"));
    level4_Button->setToolTip("Opens Level 4");
    level4_Button->setStyleSheet(
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


    QPushButton* level5_Button = new QPushButton();
    level5_Button->setFixedSize(buttonimage.size());
    level5_Button->move(448,600);
    level5_Button->setText("Level 5");
    level5_Button->setObjectName(QString("level5_Button"));
    level5_Button->setToolTip("Opens Level 5");
    level5_Button->setStyleSheet(
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


    QPushButton* back_Button = new QPushButton();
    back_Button->setFixedSize(buttonimage.size());
    back_Button->move(850,600);
    back_Button->setText("Back");
    back_Button->setObjectName(QString("back_Button"));
    back_Button->setToolTip("Opens main menu");
    back_Button->setStyleSheet(
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



    addWidget(level1_Button);

    addWidget(level2_Button);
    addWidget(level3_Button);
    addWidget(level4_Button);
    addWidget(level5_Button);
    addWidget(back_Button);


    connect(level1_Button, &QPushButton::clicked, this, [this, buttonsound]() {
        buttonsound->play();
        level1();
    });

    connect(level2_Button, &QPushButton::clicked, this, [this, buttonsound]() {
        buttonsound->play();
        level2();
    });

    connect(level3_Button, &QPushButton::clicked, this, [this, buttonsound]() {
        buttonsound->play();
        level3();
    });

    connect(level4_Button, &QPushButton::clicked, this, [this, buttonsound]() {
        buttonsound->play();
        level4();
    });

    connect(level5_Button, &QPushButton::clicked, this, [this, buttonsound]() {
        buttonsound->play();
        level5();
    });

    connect(back_Button, &QPushButton::clicked, this, [this, buttonsound]() {
        buttonsound->play();
        back();
    });

}

void levelselect::level1()
{
    game->closemenu();
    game->openlevel1();
}

void levelselect::level2()
{
    game->closemenu();
    game->openlevel2();
}
void levelselect::level3()
{
    game->closemenu();
    game->openlevel3();
}
void levelselect::level4()
{
    game->closemenu();
    game->openlevel4();
}
void levelselect::level5()
{
    game->closemenu();
    game->openlevel5();
}
void levelselect::back()
{
    game->closemenu();
    game->openmenu();
}
