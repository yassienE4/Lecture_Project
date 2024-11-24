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
    QGraphicsScene* levelSelectScene = new levelselect(this);
    this->setScene(levelSelectScene);
    this->show();
}

void Game::openlevel1()
{
    QGraphicsScene* level1Scene = new QGraphicsScene();
    level1Scene->setSceneRect(0, 0, 1280, 720);
    class level1* level = new class level1(level1Scene, this);
    level->initialize();
    this->setSceneRect(0,0,5000,720); // 5000 is level width, 720 height
    this->setScene(level1Scene);
    this->show();
}

void Game::closelevel()
{
    QGraphicsScene* currentScene = this->scene();
    QGraphicsScene* menuScene = new QGraphicsScene();
    menuScene->setSceneRect(0, 0, 1280, 720); // Example default scene size
    this->setScene(menuScene); // Set to a default or empty scene
    this->show();
}
