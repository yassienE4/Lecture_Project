#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>

class Game : public QGraphicsView
{
    Q_OBJECT //needed for qt
    public:
        Game(int w, int h); // constructor with width and height paramters
        void closemenu();
        void openselect();
        void closelevel();
        void openlevel1();
        void openlevel2();
        void openlevel3();
        void openlevel4();
        void openlevel5();
        void openskinselect();
        void openmenu();
        void openshop();
    private:
        QGraphicsScene* gamescene; // the scene for the game


};


#endif // GAME_H
