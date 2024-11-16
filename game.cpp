#include "game.h"
#include "mainmenu.h"
#include "levelselect.h"
#include "level1.h"

Game::Game(int width, int height)
{
    //disable scroll wheel horrizontly and verticly
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //set res
    this->setFixedSize(width, height);

    gamescene = new mainmenu(this);
    this->setScene(gamescene);
}

void Game::closemenu()
{
    this->hide();
}

void Game::openselect()
{
    gamescene = new levelselect(this);
}

void Game::openlevel1()
{
    this->hide();
    QGraphicsScene* level1Scene = new QGraphicsScene();
    class level1* level = new class level1(level1Scene);
    level->initialize();
    this->setScene(level1Scene);
}
