#include "shop.h"

shop::shop(Game* game)
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


    QPushButton* buy_thing = new QPushButton();
    buy_thing->setFixedSize(buttonimage.size());
    buy_thing->move(448,600);
    buy_thing->setText("Buy x");
    buy_thing->setObjectName(QString("buy_thing"));
    buy_thing->setToolTip("Purchase thing");
    buy_thing->setStyleSheet(
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
    addWidget(buy_thing);
    connect(buy_thing, &QPushButton::clicked, this, [this, buttonsound]() {
        buttonsound->play();
        purchase1();
    });

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
    addWidget(back_Button);
    connect(back_Button, &QPushButton::clicked, this, [this, buttonsound]() {
        buttonsound->play();
        back();
    });

}
void shop::back()
{
    game->closemenu();
    game->openmenu();
}

void shop::purchase1()
{
    qDebug() << totaldiamonds;
}
