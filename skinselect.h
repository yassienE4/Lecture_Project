#ifndef SKINSELECT_H
#define SKINSELECT_H

#include <QGraphicsScene>
#include "game.h"
#include <QLabel>

class skinselect : public QGraphicsScene
{
    Q_OBJECT
public:
    skinselect(Game* game);
private:
    Game* game;
    QLabel alexlabel;
    QLabel stevelabel;
    QLabel mariolabel;
public slots:
    void selectsteve();
    void selectalex();
    void selectmario();
};

#endif // SKINSELECT_H
