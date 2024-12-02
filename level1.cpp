#include "level1.h"
level1::level1(QGraphicsScene *scene, Game * game) : baselevel(scene,game) {}

void level1::initialize()
{

    QPixmap backgroundpixmap(":/images/level1scene");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    // adding portal (transports to level2, levelselect for now)
    nportal = new portal(4500, 120);
    baselevel::addportal(nportal);
    baselevel::floorlevel = 320;
    baselevel::initialize();
    //
    // add obstacles and stuff
    int o = 0;
    obstacles.push_back(new obstacle(0,517,5000,10,":/images/groundimage.png")); // ground
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(0,0,1,1000,":/images/groundimage.png")); // left wall
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(5000,0,1,1000,":/images/groundimage.png")); // right wall
    baselevel::addobstacle(obstacles[o++]);


    obstacles.push_back(new obstacle(400,420,400,100,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(700,300,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(1500,420,300,100,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(1700,350,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(2200,390,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(2400,340,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(2600,290,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(2800,240,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(3300,420,300,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);





    // adding coins(diamonds)
    diamond.push_back(new diamonds(500,300)); // diamond at 500,300
    baselevel::adddiamond(diamond[0]);
    diamond.push_back(new diamonds(800,180)); // diamond at 500,300
    baselevel::adddiamond(diamond[1]);
    diamond.push_back(new diamonds(1600,300)); // diamond at 500,300
    baselevel::adddiamond(diamond[2]);
    diamond.push_back(new diamonds(1700,220)); // diamond at 500,300
    baselevel::adddiamond(diamond[3]);
    diamond.push_back(new diamonds(1800,220)); // diamond at 500,300
    baselevel::adddiamond(diamond[4]);
    diamond.push_back(new diamonds(2200,270)); // diamond at 500,300
    baselevel::adddiamond(diamond[5]);
    diamond.push_back(new diamonds(2400,220)); // diamond at 500,300
    baselevel::adddiamond(diamond[6]);
    diamond.push_back(new diamonds(2600,170)); // diamond at 500,300
    baselevel::adddiamond(diamond[7]);
    diamond.push_back(new diamonds(2800,120)); // diamond at 500,300
    baselevel::adddiamond(diamond[8]);
    diamond.push_back(new diamonds(3300,300)); // diamond at 500,300
    baselevel::adddiamond(diamond[9]);
    diamond.push_back(new diamonds(3400,300)); // diamond at 500,300
    baselevel::adddiamond(diamond[10]);
    diamond.push_back(new diamonds(3500,300)); // diamond at 500,300
    baselevel::adddiamond(diamond[11]);





    // adding enemies
    enemies.push_back(new moving_enemy(500,320,600,400)); // spawns enemy at pos 500(x),280(y) and moves from 400-600x
    baselevel::spawn_enemy(enemies[0]);

    enemies.push_back(new moving_enemy(1900,420,2000,1800)); // spawns enemy at pos 500(x),280(y) and moves from 400-600x
    baselevel::spawn_enemy(enemies[1]);
    enemies.push_back(new moving_enemy(3700,420,4200,3600)); // spawns enemy at pos 500(x),280(y) and moves from 400-600x
    baselevel::spawn_enemy(enemies[2]);


    //adding spikes
    int s = 0;
    m_spikes.push_back(new spikes(1000,451,50,69));
    baselevel::addspikes(m_spikes[s++]);

    m_spikes.push_back(new spikes(2950,451,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(3000,451,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(3050,451,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(3100,451,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(3150,451,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(3200,451,50,69));
    baselevel::addspikes(m_spikes[s++]);


    //adding ghasts
    ghasts.push_back(new ghast(1000,0));
    baselevel::addghast(ghasts[0]);

}

