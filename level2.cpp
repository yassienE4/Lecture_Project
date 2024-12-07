#include "level2.h"

level2::level2(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level2::initialize()
{
    QPixmap backgroundpixmap(":/images/level2scene.png");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    nportal = new portal(4500, 120+200); // change 1000 to the end of the level
    baselevel::addportal(nportal);

    baselevel::floorlevel = 720-200;

    baselevel::initialize();

    int o =0;
    int s = 0;
    obstacles.push_back(new obstacle(0,710,5000,10,":/images/groundimage.png")); // ground
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(0,0,1,1000,":/images/groundimage.png")); // left wall
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(5000,0,1,1000,":/images/groundimage.png")); // right wall
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(300,600, 200, 100,":/images/mossybrick.png"));
    baselevel::addobstacle(obstacles[o++]);

    m_spikes.push_back(new spikes(500,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(600,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(700,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(800,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);

    obstacles.push_back(new obstacle(900,600, 200, 100,":/images/mossybrick.png"));
    baselevel::addobstacle(obstacles[o++]);

    m_spikes.push_back(new spikes(1100,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(1200,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(1300,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.push_back(new spikes(1400,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);

    obstacles.push_back(new obstacle(1500,600, 200, 100,":/images/mossybrick.png"));
    baselevel::addobstacle(obstacles[o++]);






    int brickHeight = 100; // Adjust this according to the actual brick height
    int extraOffset = 0;

    enemies.push_back(new moving_enemy(300, 600 - brickHeight - extraOffset, 600, 400));
    baselevel::spawn_enemy(enemies[0]);

    // For the second brick (900,600), we position the enemy at Y = 600 - brickHeight - extraOffset
    enemies.push_back(new moving_enemy(1000, 600 - brickHeight - extraOffset, 1100, 900));
    baselevel::spawn_enemy(enemies[1]);

    // For the third brick (1500,600), we position the enemy at Y = 600 - brickHeight - extraOffset
    enemies.push_back(new moving_enemy(1500, 600 - brickHeight - extraOffset, 1600, 1400));
    baselevel::spawn_enemy(enemies[2]);



    // Add moving obstacles
    MovingObstacle* movingObstacle = new MovingObstacle(300, 600, 60, 60, ":/images/block.png", 200, 400);
    obstacles.push_back(movingObstacle);
    m_obstacles.push_back(movingObstacle);
    baselevel::addobstacle(obstacles.back());

    //adding lava
    m_spikes.push_back(new spikes(100,582+69,100,69));
    baselevel::addspikes(m_spikes[s++]);
    m_spikes.back()->makelava();




}
