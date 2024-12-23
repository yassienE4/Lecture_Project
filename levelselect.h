#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <QGraphicsScene>
#include "game.h"

class levelselect : public QGraphicsScene
{
    Q_OBJECT
public:
    levelselect(Game* game);
private:
    Game* game;
public slots:
    void level1();
    void level2();
    void level3();
    void level4();
    void level5();
    void back();
};

#endif // LEVELSELECT_H
