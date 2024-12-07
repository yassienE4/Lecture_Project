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




    // enemies.push_back(new moving_enemy(300,500,600,400)); // spawns enemy at pos 500(x),420(y) and moves from 400-600x
    // baselevel::spawn_enemy(enemies[0]);

    // enemies.push_back(new moving_enemy(1000,420,1100,900)); // spawns enemy at pos 1000(x),420(y) and moves from 900-1100x
    // baselevel::spawn_enemy(enemies[1]);

    // enemies.push_back(new moving_enemy(1500,420,1600,1400)); // spawns enemy at pos 1500(x),420(y) and moves from 1400-1600x
    // baselevel::spawn_enemy(enemies[2]);

    // enemies.push_back(new moving_enemy(2000,420,2100,1900)); // spawns enemy at pos 2000(x),420(y) and moves from 1900-2100x
    // baselevel::spawn_enemy(enemies[3]);

    // enemies.push_back(new moving_enemy(2500,420,2600,2400)); // spawns enemy at pos 2500(x),420(y) and moves from 2400-2600x
    // baselevel::spawn_enemy(enemies[4]);

    // enemies.push_back(new moving_enemy(3000,420,3100,2900)); // spawns enemy at pos 3000(x),420(y) and moves from 2900-3100x
    // baselevel::spawn_enemy(enemies[5]);

    // enemies.push_back(new moving_enemy(3500,420,3600,3400)); // spawns enemy at pos 3500(x),420(y) and moves from 3400-3600x
    // baselevel::spawn_enemy(enemies[6]);

    // enemies.push_back(new moving_enemy(4000,420,4100,3900)); // spawns enemy at pos 4000(x),420(y) and moves from 3900-4100x
    // baselevel::spawn_enemy(enemies[7]);

    // enemies.push_back(new moving_enemy(4500,420,4600,4400)); // spawns enemy at pos 4500(x),420(y) and moves from 4400-4600x
    // baselevel::spawn_enemy(enemies[8]);

    // enemies.push_back(new moving_enemy(5000,420,5100,4900)); // spawns enemy at pos 5000(x),420(y) and moves from 4900-5100x
    // baselevel::spawn_enemy(enemies[9]);
    int brickHeight = 100; // Adjust this according to the actual brick height
    int extraOffset = 0;
//these works:
    // enemies.push_back(new moving_enemy(300, 600 - brickHeight - extraOffset, 200, 100));
    // baselevel::spawn_enemy(enemies[0]);

    // // For the second brick (900,600), we position the enemy at Y = 600 - brickHeight - extraOffset
    // enemies.push_back(new moving_enemy(1000, 600 - brickHeight - extraOffset, 1100, 900));
    // baselevel::spawn_enemy(enemies[1]);

    // // For the third brick (1500,600), we position the enemy at Y = 600 - brickHeight - extraOffset
    // enemies.push_back(new moving_enemy(1500, 600 - brickHeight - extraOffset, 1600, 1400));
    // baselevel::spawn_enemy(enemies[2]);

    enemies.push_back(new moving_enemy(300, 600 - brickHeight - extraOffset, 500, 300)); // First brick
    baselevel::spawn_enemy(enemies[0]);

    enemies.push_back(new moving_enemy(900, 600 - brickHeight - extraOffset, 1100, 900)); // Second brick
    baselevel::spawn_enemy(enemies[1]);

    enemies.push_back(new moving_enemy(1500, 600 - brickHeight - extraOffset, 1700, 1500)); // Third brick
    baselevel::spawn_enemy(enemies[2]);

    // obstacles.push_back(new obstacle(300, 600, 200, 100, ":/images/mossybrick.png", 300, 500, 5));
    // baselevel::addobstacle(obstacles[o++]);

    // obstacles.push_back(new obstacle(900, 600, 200, 100, ":/images/mossybrick.png", 900, 1100, 3));
    // baselevel::addobstacle(obstacles[o++]);

    // Creating multiple moving mossy bricks at different heights
    obstacles.push_back(new obstacle(300, 600, 200, 100, ":/images/mossybrick.png", 300, 500, 5));  // Brick 1
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(900, 500, 200, 100, ":/images/mossybrick.png", 900, 1100, 5));  // Brick 2
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(1500, 550, 200, 100, ":/images/mossybrick.png", 1500, 1700, 5)); // Brick 3
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(2000, 600, 200, 100, ":/images/mossybrick.png", 2000, 2200, 5));  // Brick 4
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(2500, 650, 200, 100, ":/images/mossybrick.png", 2500, 2700, 5)); // Brick 5
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(3000, 550, 200, 100, ":/images/mossybrick.png", 3000, 3200, 5));  // Brick 6
    baselevel::addobstacle(obstacles[o++]);

}
