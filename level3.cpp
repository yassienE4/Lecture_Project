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

    // adding obstacles
    obstacles.push_back(new obstacle(400,620,400,100,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(800,500,200,50,":/images/woodenblock.png")); // block at 400,400 size 400/100
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(1200,670,300,50,":/images/woodenblock.png")); // block at 1200,670
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(1500,600,250,50,":/images/woodenblock.png")); // block at 1500,600
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(1800,650,200,50,":/images/woodenblock.png")); // block at 1800,650
    baselevel::addobstacle(obstacles[o++]);  //(newchanges)

    obstacles.push_back(new obstacle(2100,670,200,50,":/images/woodenblock.png")); // block at 1800,650
    baselevel::addobstacle(obstacles[o++]);  //wooden block 6
    obstacles.push_back(new obstacle(2300,620,200,50,":/images/woodenblock.png")); // block at 1800,650
    baselevel::addobstacle(obstacles[o++]);  //wooden block 7
    obstacles.push_back(new obstacle(2500,570,200,50,":/images/woodenblock.png")); // block at 1800,650
    baselevel::addobstacle(obstacles[o++]);  //wooden block 8
    //obstacles.push_back(new obstacle(3200,670,200,100,":/images/woodenblock.png")); // block at 1800,650
    //baselevel::addobstacle(obstacles[o++]);  //wooden block 9
    obstacles.push_back(new obstacle(3400,670,200,100,":/images/woodenblock.png")); // block at 1800,650
    baselevel::addobstacle(obstacles[o++]);  //wooden block 10


    //adding enemy
    enemies.push_back(new moving_enemy(500,520,600,400)); // spawns enemy at pos 500(x),280(y) and moves from 400-600x
    baselevel::spawn_enemy(enemies[0]);
    enemies.push_back(new moving_enemy(1300,570,1400,1200)); // spawns enemy at 1300(x),570(y) moves between 1200-1400x
    baselevel::spawn_enemy(enemies[1]); //newchanges

    //adding diamonds
    diamond.push_back(new diamonds(800,400)); // diamond at 800,400
    baselevel::adddiamond(diamond[0]);
    diamond.push_back(new diamonds(900,400)); // diamond at 900,400
    baselevel::adddiamond(diamond[1]);

    diamond.push_back(new diamonds(1250,570)); // diamond at 1250(x),670(y)(newchanges)
    baselevel::adddiamond(diamond[2]);
    diamond.push_back(new diamonds(1550,500)); // diamond at 1550(x),550(y)
    baselevel::adddiamond(diamond[3]);
    diamond.push_back(new diamonds(1850,550)); // diamond at 1850(x),650(y)
    baselevel::adddiamond(diamond[4]);

    diamond.push_back(new diamonds(2100,570)); // diamond at 1850(x),650(y)
    baselevel::adddiamond(diamond[5]);
    diamond.push_back(new diamonds(2300,520)); // diamond at 1850(x),650(y)
    baselevel::adddiamond(diamond[6]);
    diamond.push_back(new diamonds(2500,470)); // diamond at 1850(x),650(y)
    baselevel::adddiamond(diamond[7]);
    diamond.push_back(new diamonds(2400,670)); // diamond at 1850(x),650(y)
    baselevel::adddiamond(diamond[8]);
    diamond.push_back(new diamonds(2450,670)); // diamond at 1850(x),650(y)
    baselevel::adddiamond(diamond[9]);



    //adding spikes
    int s = 0;
    m_spikes.push_back(new spikes(1000,650,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(1050,650,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(1100,650,50,69));
    baselevel::addspikes(m_spikes[s++]);

    m_spikes.push_back(new spikes(2800,650,50,69));
    baselevel::addspikes(m_spikes[s++]); //spike number 4
    m_spikes.push_back(new spikes(2850,650,50,69));
    baselevel::addspikes(m_spikes[s++]); //spike number 5
    m_spikes.push_back(new spikes(2900,650,50,69));
    baselevel::addspikes(m_spikes[s++]); //spike number 6
    m_spikes.push_back(new spikes(2950,650,50,69));
    baselevel::addspikes(m_spikes[s++]); //spike number 6

    // adding spikes in between block
    m_spikes.push_back(new spikes(3200,650,50,69));
    baselevel::addspikes(m_spikes[s++]); //spike number 7
    m_spikes.push_back(new spikes(3250,650,50,69));
    baselevel::addspikes(m_spikes[s++]); //spike number 8
    m_spikes.push_back(new spikes(3300,650,50,69));
    baselevel::addspikes(m_spikes[s++]); //spike number 9

    //adding ghasts
    ghasts.push_back(new ghast(1000,0,false));
    baselevel::addghast(ghasts[0]);
    ghasts.push_back(new ghast(1500,300,true)); // spawns a ghast near new wooden blocks and diamonds
    baselevel::addghast(ghasts[1]);
    ghasts.push_back(new ghast(2100,350,false)); // spawns a ghast near new wooden blocks and diamonds
    baselevel::addghast(ghasts[2]);
    ghasts.push_back(new ghast(2500,350,false)); // spawns a ghast near new wooden blocks and diamonds
    baselevel::addghast(ghasts[3]);
    ghasts.push_back(new ghast(3000,450,false)); // spawns a ghast near new wooden blocks and diamonds
    baselevel::addghast(ghasts[4]);
    // ghasts.push_back(new ghast(1000,0,false));
    // baselevel::addghast(ghasts[2]);

}

