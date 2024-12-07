#include "level3.h"

level3::level3(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level3::initialize()
{
    QPixmap backgroundpixmap(":/images/level3scene");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    nportal = new portal(4500, 120+200); // change 1000 to the end of the level
    baselevel::addportal(nportal);

    baselevel::floorlevel = 720-200;

    baselevel::initialize();
    int o =0;
    obstacles.push_back(new obstacle(0,710,5000,10,":/images/groundimage.png")); // ground
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(0,0,1,1000,":/images/groundimage.png")); // left wall
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(5000,0,1,1000,":/images/groundimage.png")); // right wall
    baselevel::addobstacle(obstacles[o++]);


    obstacles.push_back(new obstacle(400,720,400,100,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(700,600,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);


    enemies.push_back(new moving_enemy(500,620,600,400)); // spawns enemy at pos 500(x),280(y) and moves from 400-600x
    baselevel::spawn_enemy(enemies[0]);


    //adding spikes
    int s = 0;
    m_spikes.push_back(new spikes(1000,720,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(1000,720,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(1000,720,50,69));
    baselevel::addspikes(m_spikes[s++]);

    //adding ghasts
    ghasts.push_back(new ghast(1000,0,false));
    baselevel::addghast(ghasts[0]);

}

