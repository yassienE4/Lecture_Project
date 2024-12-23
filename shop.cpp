#include "shop.h"
using namespace std;

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


    QPushButton* buy_arrow = new QPushButton();
    buy_arrow->setFixedSize(buttonimage.size());
    buy_arrow->move(448,600);
    buy_arrow->setText("Remove Arrow Gravity (20)");
    buy_arrow->setObjectName(QString("buy_arrow"));
    buy_arrow->setToolTip("Purchase thing");
    buy_arrow->setStyleSheet(
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
    addWidget(buy_arrow);
    connect(buy_arrow, &QPushButton::clicked, this, [this, buttonsound, buy_arrow]() {
        buttonsound->play();
        purchase1(buy_arrow);
    });

    QPushButton* back_Button = new QPushButton();
    back_Button->setFixedSize(buttonimage.size());
    back_Button->move(850,500);
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

    //displaying diamonds
    QFont customFont(fontFamily, 50);
    textItem = new QGraphicsTextItem("Total Diamonds:" + QString::fromStdString(to_string(totaldiamonds)));
    textItem->setFont(customFont);
    textItem->setPos(360,360);
    //textItem->setDefaultTextColor(Qt::black);
    textItem->setDefaultTextColor(QColor(39,229,232));
    addItem(textItem);

    insufficientFunds = new QGraphicsTextItem("Not Enough Diamonds");
    insufficientFunds->setFont(customFont);
    insufficientFunds->setPos(500,500);





    QPushButton* buy_gun = new QPushButton();
    buy_gun->setFixedSize(buttonimage.size());
    buy_gun->move(50, 600); // Position for gun button
    buy_gun->setText("Buy Gun (30)");
    buy_gun->setObjectName(QString("buy_gun"));
    buy_gun->setToolTip("Purchase Gun");
    buy_gun->setStyleSheet(
        "QPushButton {"
        "    border: none;"
        "    background-image: url(:/images/mcbuttonimage);"
        "    background-repeat: no-repeat;"
        "    background-position: center;"
        "    color: white;"
        "    font-family: '" + fontFamily + "';"
                       "    font-size: 16px;"
                       "    text-align: center;"
                       "}"
        );
    addWidget(buy_gun);
    connect(buy_gun, &QPushButton::clicked, this, [this, buttonsound, buy_gun]() {
        buttonsound->play();
        purchaseGun(buy_gun);
    });




    QPushButton* buy_jump = new QPushButton();
    buy_jump->setFixedSize(buttonimage.size());
    buy_jump->move(850, 600); // Position for gun button
    buy_jump->setText("Buy Double Jump (50)");
    buy_jump->setObjectName(QString("buy_jump"));
    buy_jump->setToolTip("Purchase Double Jump");
    buy_jump->setStyleSheet(
        "QPushButton {"
        "    border: none;"
        "    background-image: url(:/images/mcbuttonimage);"
        "    background-repeat: no-repeat;"
        "    background-position: center;"
        "    color: white;"
        "    font-family: '" + fontFamily + "';"
                       "    font-size: 16px;"
                       "    text-align: center;"
                       "}"
        );
    addWidget(buy_jump);
    connect(buy_jump, &QPushButton::clicked, this, [this, buttonsound, buy_jump]() {
        buttonsound->play();
        purchasedoublejump(buy_jump);
    });

    if(doublejumpbought)
    {   buy_jump->setEnabled(false);
        ;}
    if(arrowgravitybought)
    {   buy_arrow->setEnabled(false);
        ;}
    if(gunbought)
    {   buy_gun->setEnabled(false);
        ;}
}
void shop::back()
{
    game->closemenu();
    game->openmenu();
}

void shop::purchase1(QPushButton * buy_arrow)
{
    if(totaldiamonds >= 20 && !arrowgravitybought)
    {
        if(items().contains(insufficientFunds))
            removeItem(insufficientFunds);
        totaldiamonds = totaldiamonds-20;
        textItem->setPlainText("Total Diamonds:" + QString::fromStdString(to_string(totaldiamonds)));
        arrowgravitybought = true;
        buy_arrow->setEnabled(false);
        QSoundEffect *purchasesound = new QSoundEffect(this);
        purchasesound->setSource(QUrl("qrc:/sounds/levelup.wav"));
        purchasesound->setVolume(1);
        purchasesound->play();
    }
    else
    {
        addItem(insufficientFunds);
    }


}

void shop::purchaseGun(QPushButton * buy_gun)
{
    if (totaldiamonds >= 30 && !gunbought)
    {
        if (items().contains(insufficientFunds))
            removeItem(insufficientFunds);
        totaldiamonds -= 30;
        textItem->setPlainText("Total Diamonds: " + QString::fromStdString(to_string(totaldiamonds)));
        gunbought = true;
        buy_gun->setEnabled(false);
        QSoundEffect *purchasesound = new QSoundEffect(this);
        purchasesound->setSource(QUrl("qrc:/sounds/levelup.wav"));
        purchasesound->setVolume(1);
        purchasesound->play();
    }
    else
    {
        addItem(insufficientFunds);
    }
}



void shop::purchasedoublejump(QPushButton * buy_jump)
{
    if (totaldiamonds >= 50 && !doublejumpbought)
    {
        if (items().contains(insufficientFunds))
            removeItem(insufficientFunds);
        totaldiamonds -= 50;
        textItem->setPlainText("Total Diamonds: " + QString::fromStdString(to_string(totaldiamonds)));
        doublejumpbought = true;
        buy_jump->setEnabled(false);
        QSoundEffect *purchasesound = new QSoundEffect(this);
        purchasesound->setSource(QUrl("qrc:/sounds/levelup.wav"));
        purchasesound->setVolume(1);
        purchasesound->play();
    }
    else
    {
        addItem(insufficientFunds);
    }
}


