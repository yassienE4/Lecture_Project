#include "level2.h"

level2::level2(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level2::initialize()
{
    // Set background
    QPixmap backgroundpixmap(":/images/level2scene.png");
    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    // Portal at the end of the level
    nportal = new portal(4500, 120 + 200);
    baselevel::addportal(nportal);

    // Floor level
    baselevel::floorlevel = 720 - 200;

    baselevel::initialize();

    int o = 0; // Obstacle index
    int s = 0; // Spike index
    int d = 0; // Diamond index

    // Ground and walls
    obstacles.push_back(new obstacle(0, 710, 5000, 10, ":/images/groundimage.png")); // Ground
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(0, 0, 1, 1000, ":/images/groundimage.png")); // Left wall
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(5000, 0, 1, 1000, ":/images/groundimage.png")); // Right wall
    baselevel::addobstacle(obstacles[o++]);

    // Platforms and stepping bricks
    obstacles.push_back(new obstacle(400, 600, 200, 100, ":/images/mossybrick.png")); // First platform
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(800, 500, 200, 100, ":/images/mossybrick.png")); // Second platform
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(1100, 400, 150, 100, ":/images/mossybrick.png")); // Stepping stone to high area
    baselevel::addobstacle(obstacles[o++]);

    // obstacles.push_back(new obstacle(1500, 500, 200, 100, ":/images/mossybrick.png")); // Higher platform
    // baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(1900, 350, 200, 100, ":/images/mossybrick.png")); // Far high platform
    baselevel::addobstacle(obstacles[o++]);

    // Spikes on the ground
    for (int i = 600; i <= 1400; i += 200) {
        m_spikes.push_back(new spikes(i, 710 - 69, 100, 69)); // Spikes
        baselevel::addspikes(m_spikes[s++]);
    }

    // Lava pools
    for (int i = 2200; i <= 2600; i += 100) {
        m_spikes.push_back(new spikes(i, 710 - 50, 100, 20));
        m_spikes.back()->makelava(); // Make it lava
        baselevel::addspikes(m_spikes[s++]);
    }

    // Moving obstacles
    MovingObstacle* movingObstacle1 = new MovingObstacle(1400, 450, 150, 80, ":/images/block.png", 1300, 1500);
    obstacles.push_back(movingObstacle1);
    m_obstacles.push_back(movingObstacle1);
    baselevel::addobstacle(obstacles[o++]);

    MovingObstacle* movingObstacle2 = new MovingObstacle(2100, 500, 200, 100, ":/images/block.png", 2000, 2200);
    obstacles.push_back(movingObstacle2);
    m_obstacles.push_back(movingObstacle2);
    baselevel::addobstacle(obstacles[o++]);

    // Additional stepping bricks for high areas
    obstacles.push_back(new obstacle(2500, 400, 100, 50, ":/images/mossybrick.png")); // Stepping stone for lava area
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(2900, 450, 150, 80, ":/images/block.png")); // Reward area platform
    baselevel::addobstacle(obstacles[o++]);

    // Adding diamonds at challenging yet reachable positions
    diamond.push_back(new diamonds(500, 550)); // On first platform
    baselevel::adddiamond(diamond[d++]);

    diamond.push_back(new diamonds(850, 400)); // On second platform
    baselevel::adddiamond(diamond[d++]);

    diamond.push_back(new diamonds(1150, 300)); // Above stepping stone
    baselevel::adddiamond(diamond[d++]);

    diamond.push_back(new diamonds(1550, 450)); // Near high platform
    baselevel::adddiamond(diamond[d++]);

    diamond.push_back(new diamonds(2000, 300)); // Above moving obstacle
    baselevel::adddiamond(diamond[d++]);

    diamond.push_back(new diamonds(2600, 380)); // Above stepping brick near lava
    baselevel::adddiamond(diamond[d++]);

    diamond.push_back(new diamonds(3000, 400)); // Reward on last platform
    baselevel::adddiamond(diamond[d++]);

    // Adding enemies
    enemies.push_back(new moving_enemy(500, 520, 600, 400)); // On the first platform
    baselevel::spawn_enemy(enemies[0]);

    enemies.push_back(new moving_enemy(800, 420, 900, 700)); // On the second platform
    baselevel::spawn_enemy(enemies[1]);

    // enemies.push_back(new moving_enemy(1500, 420, 1550, 1450)); // On the moving obstacle at (1400,450)
    // baselevel::spawn_enemy(enemies[2]);

    // enemies.push_back(new moving_enemy(1900, 270, 2000, 1800)); // On the high platform
    // baselevel::spawn_enemy(enemies[2]);

    enemies.push_back(new moving_enemy(2900, 370, 3000, 2800)); // On the last platform near lava
    baselevel::spawn_enemy(enemies[2]);

}


