#include "level1.h"
level1::level1(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level1::initialize()
{

    QPixmap backgroundpixmap(":/images/level1scene");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    // adding portal (transports to level2, levelselect for now)
    nportal = new portal(1000, 120); // change 1000 to the end of the level
    baselevel::addportal(nportal);

    baselevel::initialize();
    //
    // add obstacles and stuff
    obstacles.push_back(new obstacle(0,517,5000,10,":/images/groundimage.png")); // ground
    baselevel::addobstacle(obstacles[0]);

    obstacles.push_back(new obstacle(400,420,400,100,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[1]);
    obstacles.push_back(new obstacle(650,500,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[2]);



    // adding coins(diamonds)
    diamond.push_back(new diamonds(500,300)); // diamond at 500,300
    baselevel::adddiamond(diamond[0]);

    // adding enemies
    enemies.push_back(new moving_enemy(500,320,600,400)); // spawns enemy at pos 500(x),280(y) and moves from 400-600x
    baselevel::spawn_enemy(enemies[0]);






    // must declare coin here (doing a class named coin)


}
