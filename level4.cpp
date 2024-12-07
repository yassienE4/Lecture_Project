#include "level4.h"

level4::level4(QGraphicsScene *scene, Game *game) : baselevel(scene,game)
{

}

void level4::initialize()
{
    QPixmap backgroundpixmap(":/images/level4scene");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    nportal = new portal(4500, 120+200); // portal further out, increasing level length
    baselevel::addportal(nportal);

    baselevel::floorlevel = 720-200;

    baselevel::initialize();
    int o = 0;
    obstacles.push_back(new obstacle(0,710,7000,10,":/images/groundimage.png")); // ground
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(0,0,1,1000,":/images/groundimage.png")); // left wall
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(7000,0,1,1000,":/images/groundimage.png")); // right wall
    baselevel::addobstacle(obstacles[o++]);

    // Adding challenging static obstacles
    obstacles.push_back(new obstacle(500,600,300,50,":/images/woodenblock.png"));
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(900,500,250,50,":/images/woodenblock.png"));
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(1400,550,300,50,":/images/woodenblock.png"));
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(2000,600,300,50,":/images/woodenblock.png"));
    baselevel::addobstacle(obstacles[o++]);

    // Adding enemies
    enemies.push_back(new moving_enemy(600,520,700,500)); // short-range moving enemy
    baselevel::spawn_enemy(enemies[0]);
    enemies.push_back(new moving_enemy(1500,470,1600,1400)); // positioned near a jump
    baselevel::spawn_enemy(enemies[1]);
    enemies.push_back(new moving_enemy(2800,400,2900,2700)); // guarding diamonds
    baselevel::spawn_enemy(enemies[2]);

    // Adding diamonds (placed in riskier locations)
    diamond.push_back(new diamonds(550,550)); // near an enemy
    baselevel::adddiamond(diamond[0]);
    diamond.push_back(new diamonds(950,450)); // above spikes
    baselevel::adddiamond(diamond[1]);
    diamond.push_back(new diamonds(1450,500)); // requires precision jump
    baselevel::adddiamond(diamond[2]);
    diamond.push_back(new diamonds(2550,470)); // in a high-risk area
    baselevel::adddiamond(diamond[3]);
    diamond.push_back(new diamonds(3550,370)); // far above the ground
    baselevel::adddiamond(diamond[4]);

    // Adding spikes (more clusters, tighter spaces)
    int s = 0;
    m_spikes.push_back(new spikes(800,650,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(850,650,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(2000,650,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(2050,650,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(2800,650,50,69));
    baselevel::addspikes(m_spikes[s++]);

    // Adding ghasts (higher and faster movement)
    ghasts.push_back(new ghast(1100,100,true)); // fast ghast moving in the sky
    baselevel::addghast(ghasts[0]);
    ghasts.push_back(new ghast(3000,300,false));
    baselevel::addghast(ghasts[1]);
    ghasts.push_back(new ghast(5000,100,true));
    baselevel::addghast(ghasts[2]);

    // Adding a final challenge zone (spikes + moving enemies)
    m_spikes.push_back(new spikes(5800,650,50,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(5850,650,50,69));
    baselevel::addspikes(m_spikes[s++]);
    enemies.push_back(new moving_enemy(5900,520,6100,5700));
    baselevel::spawn_enemy(enemies[3]);
}
