#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include "game.h"

class mainmenu : public QGraphicsScene
{
    Q_OBJECT // needed for qt
    public:
        mainmenu(Game* game); // main menu takes game as a paramter
    private:
        Game* game;
    private slots:
        void new_game(); // for the button "New Game"

};

#endif // MAINMENU_H
