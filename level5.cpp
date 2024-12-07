#include "level5.h"
#include <QVector>
#include <QRandomGenerator>
#include <QList>
using namespace std;
level5::level5(QGraphicsScene *scene, Game * game) : baselevel(scene,game)
{

}

void level5::initialize()
{
    QPixmap backgroundpixmap(":/images/level5scene");

    QGraphicsPixmapItem* background1 = new QGraphicsPixmapItem(backgroundpixmap);
    baselevel::setbackground(background1);

    nportal = new portal(6100, 120+200);
    baselevel::addportal(nportal);

    baselevel::floorlevel = 720-200;

    baselevel::initialize();
    baselevel::graceperiod = 10000; // half the grace period
    h.applydamage();
    h.applydamage(); // half health

    m_startpos = 0;
    o=0;
    s=0;
    obstacles.push_back(new obstacle(0,710,5000,10,":/images/groundimage.png")); // ground
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(0,0,1,1000,":/images/groundimage.png")); // left wall
    baselevel::addobstacle(obstacles[o++]);
    obstacles.push_back(new obstacle(6500,0,1,1000,":/images/groundimage.png")); // right wall
    baselevel::addobstacle(obstacles[o++]);

    // randomizes the level
    QVector<int> numbers = {1, 2, 3,4};
    random_device rd;
    mt19937 g(rd());
    shuffle(numbers.begin(), numbers.end(), g);
    addblock = false;
    addblock2 = false;
    if( (numbers[0] == 1 && numbers[1] == 3) || (numbers[1] == 1 && numbers[2] == 3)|| (numbers[2] == 1 && numbers[3] == 3)) // check if module1 is directly before module2
        addblock = true;

    if( (numbers[0] == 4 && numbers[1] == 3) || (numbers[1] == 4 && numbers[2] == 3)|| (numbers[2] == 4 && numbers[3] == 3)) // check if module4 is directly before module2
        addblock2 = true;
    for(int num : numbers)
    {
        switch(num){
        case 1:
            init1();
            break;
        case 2:
            init2();
            break;
        case 3:
            init3();
            break;
        case 4:
            init4();
            break;
        }
    }





}

void level5::init1()
{
    for(int i =0; i<2;i++)
    {
    obstacles.push_back(new obstacle(100+m_startpos,600,100,100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);
    diamond.push_back(new diamonds(300+m_startpos,350));
    baselevel::adddiamond(diamond.back());
    diamond.push_back(new diamonds(400+m_startpos,350));
    baselevel::adddiamond(diamond.back());

    for (int i = 0; i < 4; ++i) {
        int xPos = 200 + m_startpos + i * 100;
        m_spikes.push_back(new spikes(xPos, 582 + 69, 100, 69));
        baselevel::addspikes(m_spikes.back());
    }

    m_startpos = m_startpos + 500;
    }
    diamond.push_back(new diamonds(m_startpos-375,525));
    baselevel::adddiamond(diamond.back());
    obstacles.push_back(new obstacle(100+m_startpos,600, 100, 100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);
    m_startpos = m_startpos + 100;
}

void level5::init2()
{
    obstacles.push_back(new obstacle(100+m_startpos,600,100,100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);

    obstacles.push_back(new obstacle(500+m_startpos,500,100,100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);
    diamond.push_back(new diamonds(525+m_startpos,350));
    baselevel::adddiamond(diamond.back());

    obstacles.push_back(new obstacle(900+m_startpos,400,100,100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);
    diamond.push_back(new diamonds(925+m_startpos,250));
    baselevel::adddiamond(diamond.back());

    obstacles.push_back(new obstacle(1300+m_startpos,300,100,400,":/images/sculkpillar.png"));
    baselevel::addobstacle(obstacles[o++]);
    diamond.push_back(new diamonds(1325+m_startpos,150));
    baselevel::adddiamond(diamond.back());

    for (int i = 0; i < 10; ++i) {
        int xPos = 200 + m_startpos + i * 110;
        m_spikes.push_back(new spikes(xPos, 582 + 69, 100, 69));
        baselevel::addspikes(m_spikes.back());
    }

    m_startpos = m_startpos + 1400;
}

void level5::init3()
{
    if(addblock || addblock2) // wall only needed if init1 is b4 init3
    {
        obstacles.push_back(new obstacle(m_startpos+99,400,1,1,":/images/groundimage.png")); // small left wall to block fireball
        baselevel::addobstacle(obstacles[o++]);
    }

    for(int i =0; i <3; i++)
    {
    obstacles.push_back(new obstacle(100+m_startpos,600,200,100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);
    diamond.push_back(new diamonds(125+m_startpos,350));
    baselevel::adddiamond(diamond.back());
    ghasts.push_back(new ghast(m_startpos+125,0,true));
    baselevel::addghast(ghasts.back());

    enemies.push_back(new moving_enemy(400+m_startpos,600,550+m_startpos,300+m_startpos)); // spawns enemy at pos 500(x),280(y) and moves from 400-600x
    baselevel::spawn_enemy(enemies.back());

    m_startpos = m_startpos + 500;
    }
    obstacles.push_back(new obstacle(100+m_startpos,600,200,100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);
    diamond.push_back(new diamonds(125+m_startpos,350));
    baselevel::adddiamond(diamond.back());
    m_startpos = m_startpos + 200;

    ghasts.push_back(new ghast(m_startpos+170,300,false));
    baselevel::addghast(ghasts.back());
    m_startpos = m_startpos + 300;


}

void level5::init4()
{
    obstacles.push_back(new obstacle(100+m_startpos,600,100,100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);

    for (int i = 0; i < 12; ++i) {
        int xPos = 200 + m_startpos + i * 100;
        m_spikes.push_back(new spikes(xPos, 582 + 69, 100, 69));
        baselevel::addspikes(m_spikes.back());
        m_spikes.back()->makelava();
    }
    int sync;
    for (int i = 0; i < 3; ++i) {
        int xPos = 300 + m_startpos + i * 400;
        if(i==0) {sync = -50;}
        if(i==1) {sync = 50;}
        if(i==2) {sync = -50;}
        MovingObstacle* movingObstacle = new MovingObstacle(xPos+sync, 600, 60, 60, ":/images/sculkbrick.png", xPos-100, xPos+100);
        obstacles.push_back(movingObstacle);
        m_obstacles.push_back(movingObstacle);
        baselevel::addobstacle(obstacles[o++]);
        //if(i !=2)
        //{
        ghasts.push_back(new ghast(xPos-sync,0,true));
        baselevel::addghast(ghasts.back());
        //}
    }

    obstacles.push_back(new obstacle(1400+m_startpos,600,100,100,":/images/sculkbrick.png"));
    baselevel::addobstacle(obstacles[o++]);
    m_startpos = m_startpos + 1400;
}
