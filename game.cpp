#include "game.h"
#include "mainmenu.h"
#include "levelselect.h"
#include "skinselect.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "shop.h"


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

void Game::openmenu()
{

    // QGraphicsScene* menu = new mainmenu(this);
    // this->setScene(menu);
    // this->show();
    this->setScene(gamescene);
    this->show();

}

void Game::openselect()
{
    QGraphicsScene* levelSelectScene = new levelselect(this);
    this->setScene(levelSelectScene);
    this->show();
}

void Game::openskinselect()
{
    QGraphicsScene * skinscene = new skinselect(this);

    this->setScene(skinscene);
    this->show();
}

void Game::openshop()
{
    QGraphicsScene* shopscene = new shop(this);
    this->setScene(shopscene);
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
    QGraphicsScene* menuScene = new QGraphicsScene();
    menuScene->setSceneRect(0, 0, 1280, 720); // Example default scene size
    this->setScene(menuScene); // Set to a default or empty scene
    this->setSceneRect(0,0,1280,720);
    this->show();
}

void Game::openlevel2()
{
    QGraphicsScene* level2Scene = new QGraphicsScene();
    level2Scene->setSceneRect(0, 0, 1280, 720);
    class level2* level = new class level2(level2Scene, this);
    level->initialize();
    this->setSceneRect(0,0,5000,720); // 5000 is level width, 720 height
    this->setScene(level2Scene);
    this->show();
}

void Game::openlevel3()
{
    QGraphicsScene* level3Scene = new QGraphicsScene();
    level3Scene->setSceneRect(0, 0, 1280, 720);
    class level3* level = new class level3(level3Scene, this);
    level->initialize();
    this->setSceneRect(0,0,5000,720); // 5000 is level width, 720 height
    this->setScene(level3Scene);
    this->show();
}

void Game::openlevel4()
{
    QGraphicsScene* level4Scene = new QGraphicsScene();
    level4Scene->setSceneRect(0, 0, 1280, 720);
    class level4* level = new class level4(level4Scene, this);
    level->initialize();
    this->setSceneRect(0,0,5000,720); // 5000 is level width, 720 height
    this->setScene(level4Scene);
    this->show();
}

void Game::openlevel5()
{
    QGraphicsScene* level5Scene = new QGraphicsScene();
    level5Scene->setSceneRect(0, 0, 1280, 720);
    class level5* level = new class level5(level5Scene, this);
    level->initialize();
    this->setSceneRect(0,0,5000,720); // 5000 is level width, 720 height
    this->setScene(level5Scene);
    this->show();
}
