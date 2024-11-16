#include "levelselect.h"
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsScene>

levelselect::levelselect(Game* game)
{
    this->game = game;

    QPixmap background(":/images/background_select");
    background = background.scaled(1280,720, Qt::KeepAspectRatioByExpanding);
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(background);
    addItem(backgroundItem);
    backgroundItem->setZValue(-1);


    QPushButton* level1_Button = new QPushButton();
    level1_Button->setText("Level 1");
    level1_Button->setObjectName(QString("level1_Button"));
    level1_Button->setToolTip("Opens Level 1");
    level1_Button->setGeometry(QRect(640, 360, 100, 32)); // puts button at coords 640,360 with width/height 100/32
    level1_Button->setAutoFillBackground(false);
/*
    QPushButton* level2_Button = new QPushButton();
    level2_Button->setText("Level 2");
    level2_Button->setObjectName(QString("level2_Button"));
    level2_Button->setToolTip("Opens Level 2");
    level2_Button->setGeometry(QRect(640, 320, 100, 32)); // puts button at coords 640,320 with width/height 100/32
    level2_Button->setAutoFillBackground(false);

    QPushButton* level3_Button = new QPushButton();
    level3_Button->setText("Level 3");
    level3_Button->setObjectName(QString("level3_Button"));
    level3_Button->setToolTip("Opens Level 3");
    level3_Button->setGeometry(QRect(640, 280, 100, 32)); // puts button at coords 640,280 with width/height 100/32
    level3_Button->setAutoFillBackground(false);

    QPushButton* level4_Button = new QPushButton();
    level4_Button->setText("Level 4");
    level4_Button->setObjectName(QString("level4_Button"));
    level4_Button->setToolTip("Opens Level 4");
    level4_Button->setGeometry(QRect(640, 240, 100, 32)); // puts button at coords 640,240 with width/height 100/32
    level4_Button->setAutoFillBackground(false);

    QPushButton* level5_Button = new QPushButton();
    level5_Button->setText("Level 5");
    level5_Button->setObjectName(QString("level5_Button"));
    level5_Button->setToolTip("Opens Level 5");
    level5_Button->setGeometry(QRect(640, 200, 100, 32)); // puts button at coords 640,200 with width/height 100/32
    level5_Button->setAutoFillBackground(false);
*/


    addWidget(level1_Button);
    /*
    addWidget(level2_Button);
    addWidget(level3_Button);
    addWidget(level4_Button);
    addWidget(level5_Button);
*/

    connect(level1_Button, &QPushButton::clicked, this, &levelselect::level1);
    /*
    connect(level2_Button, &QPushButton::clicked, this, &levelselect::level2);
    connect(level3_Button, &QPushButton::clicked, this, &levelselect::level3);
    connect(level4_Button, &QPushButton::clicked, this, &levelselect::level4);
    connect(level5_Button, &QPushButton::clicked, this, &levelselect::level5);
*/
}

void levelselect::level1()
{
    game->closemenu();
    game->openlevel1();
}

void levelselect::level2()
{
}
void levelselect::level3()
{
}
void levelselect::level4()
{
}
void levelselect::level5()
{
}
