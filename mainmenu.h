#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include "game.h"
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include <QAudioOutput>

class mainmenu : public QGraphicsScene
{
    Q_OBJECT // needed for qt
    public:
        mainmenu(Game* game); // main menu takes game as a paramter
    private:
        Game* game;
        QGraphicsTextItem *textItem = new QGraphicsTextItem(nullptr);
        QMediaPlayer *backgroundMusic;
        QAudioOutput *audioOutput;
    public slots:
        void new_game(); // for the button "New Game"
        void skinSelector();
        void openshop();

};

#endif // MAINMENU_H
