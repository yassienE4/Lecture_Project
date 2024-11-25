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

    obstacles.push_back(new obstacle(400,420,400,100,":/images/woodenblock.png")); // need to empty qlist after level1 ends
    baselevel::addobstacle(obstacles[1]);

    /*      fix these
    obstacle spike1(560,120,25,20,":/images/block.png");
    obstacle wooden_block(300,200,200,50,":/images/block.png"); //want to place coins above it
    obstacle block2(560,330,20,20,":/images/block.png");
    obstacle spike2(560,400,25,20,":/images/block.png");
    obstacle spike3(560,475,25,20,":/images/block.png");
    obstacle block3(400,550,40,40,":/images/block.png");
    obstacle wooden_block2(500,650,200,50,":/images/block.png"); // will have a spike at the end making the player jump
    obstacle spike_on_block(500,700,25,20,":/images/block.png");
    obstacle block4(400,900,20,20,":/images/block.png");
    obstacle block5(560,950,20,20,":/images/block.png");
    obstacle wooden_block3(300,1050,200,50,":/images/block.png"); //want to place coins above it
    */

    // adding coins(diamonds)
    diamond.push_back(new diamonds(500,300));
    baselevel::adddiamond(diamond[0]);




    // must declare coin here (doing a class named coin)


}
