#include "steve.h"

steve::steve()
{
    height = 200;
    setskin(skin_static);
    setPixmap(playerpixmap);
    state = Static;
    player_velocity=0;
    direction = 1;

    setboundingboxes();
    //setOpacity(0.5); // to check bounding box
}

void steve::setskin(int x)
{
    if(x ==1)
    {
        playerpixmap = QPixmap(":/images/steve.png");
        leftplayerpixmap = QPixmap(":/images/steveleft.png");
        rightplayerpixmap = QPixmap(":/images/steve.png");
        int scaledWidth = playerpixmap.width() * height / playerpixmap.height();
        playerpixmap = playerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);
        rightplayerpixmap = rightplayerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);
        leftplayerpixmap = leftplayerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);

        rightmoving = QPixmap(":/images/stevemoveright1.png");
        int movescaled = rightmoving.width() * height / rightmoving.height();
        leftmoving = QPixmap(":/images/stevemoveleft1.png");
        rightmoving = rightmoving.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftmoving = leftmoving.scaled(movescaled, height,Qt::KeepAspectRatio );

        rightmoving2 = QPixmap(":/images/stevemoveright2.png");
        leftmoving2 = QPixmap(":/images/stevemoveleft2.png");
        rightmoving2 = rightmoving2.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftmoving2 = leftmoving2.scaled(movescaled, height,Qt::KeepAspectRatio );

        rightholding = QPixmap(":/images/steveholdingright.png");
        leftholding = QPixmap(":/images/steveholdingleft.png");
        rightholding = rightholding.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftholding = leftholding.scaled(movescaled, height,Qt::KeepAspectRatio );
    }
    if(x ==2)
    {
        playerpixmap = QPixmap(":/images/alexright.png");
        leftplayerpixmap = QPixmap(":/images/alexleft.png");
        rightplayerpixmap = QPixmap(":/images/alexright.png");
        int scaledWidth = playerpixmap.width() * height / playerpixmap.height();
        playerpixmap = playerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);
        rightplayerpixmap = rightplayerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);
        leftplayerpixmap = leftplayerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);

        rightmoving = QPixmap(":/images/alexrightwalk1.png");
        int movescaled = rightmoving.width() * height / rightmoving.height();
        leftmoving = QPixmap(":/images/alexleftwalk1.png");
        rightmoving = rightmoving.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftmoving = leftmoving.scaled(movescaled, height,Qt::KeepAspectRatio );

        rightmoving2 = QPixmap(":/images/alexrightwalk2.png");
        leftmoving2 = QPixmap(":/images/alexleftwalk2.png");
        rightmoving2 = rightmoving2.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftmoving2 = leftmoving2.scaled(movescaled, height,Qt::KeepAspectRatio );

        rightholding = QPixmap(":/images/alexholdingright.png");
        leftholding = QPixmap(":/images/alexholdingleft.png");
        rightholding = rightholding.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftholding = leftholding.scaled(movescaled, height,Qt::KeepAspectRatio );
    }
    if(x ==3)
    {
        playerpixmap = QPixmap(":/images/marioright.png");
        leftplayerpixmap = QPixmap(":/images/marioleft.png");
        rightplayerpixmap = QPixmap(":/images/marioright.png");
        int scaledWidth = playerpixmap.width() * height / playerpixmap.height();
        playerpixmap = playerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);
        rightplayerpixmap = rightplayerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);
        leftplayerpixmap = leftplayerpixmap.scaled(scaledWidth, height, Qt::KeepAspectRatio);

        rightmoving = QPixmap(":/images/mariorightwalk1.png");
        int movescaled = rightmoving.width() * height / rightmoving.height();
        leftmoving = QPixmap(":/images/marioleftwalk1.png");
        rightmoving = rightmoving.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftmoving = leftmoving.scaled(movescaled, height,Qt::KeepAspectRatio );

        rightmoving2 = QPixmap(":/images/mariorightwalk2.png");
        leftmoving2 = QPixmap(":/images/marioleftwalk2.png");
        rightmoving2 = rightmoving2.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftmoving2 = leftmoving2.scaled(movescaled, height,Qt::KeepAspectRatio );

        rightholding = QPixmap(":/images/marioholdingright.png");
        leftholding = QPixmap(":/images/marioholdingleft.png");
        rightholding = rightholding.scaled(movescaled, height,Qt::KeepAspectRatio );
        leftholding = leftholding.scaled(movescaled, height,Qt::KeepAspectRatio );
    }
}


void steve::setstate(PlayerState x)
{
    state = x;
}
void steve::setpix(int p)
{
    if(p == 1)
        setPixmap(rightplayerpixmap);
    if(p == 2)
        setPixmap(leftplayerpixmap);
    if(p == 3)
        setPixmap(rightmoving);
    if(p == 4)
        setPixmap(leftmoving);
    if(p == 5)
        setPixmap(rightmoving2);
    if(p==6)
        setPixmap(leftmoving2);
    if(p==7)
        setPixmap(rightholding);
    if(p==8)
        setPixmap(leftholding);
    return;
}
void steve::setvelocity(int x)
{
    player_velocity = x;
}
PlayerState steve::getstate()
{
    return state;
}
int steve::getvelocity()
{
    return player_velocity;
}
bool steve::getjump()
{
    return (state == Jumping);
}
void steve::setdirection(bool x)
{
    direction = x;
}
bool steve::getdirection()
{
    return direction;
}

//colide set/get

bool steve::getcolideright()
{
    return colideright;
}
bool steve::getcolideleft()
{
    return colideleft;
}
bool steve::getcolideup()
{
    return colideup;
}
bool steve::getcolidedown()
{
    return colidedown;
}
bool steve::getgrounded()
{
    return grounded;
}
void steve::setcolideright(bool x)
{
    colideright = x;
}
void steve::setcolideleft(bool x)
{
    colideleft = x;
}
void steve::setcolideup(bool x)
{
    colideup =x;
}
void steve::setcolidedown(bool x)
{
    colidedown = x;
}
void steve::setgrounded(bool x)
{
    grounded = x;
}
//bounding box getters

QRectF steve::getrightBoundingBox()
{
    return rightBoundingBox;
}
QRectF steve::getleftBoundingBox()
{
    return leftBoundingBox;
}
QRectF steve::getupBoundingBox()
{
    return upBoundingBox;
}
QRectF steve::getdownBoundingBox()
{
    return downBoundingBox;
}

void steve::setboundingboxes()
{
    int width = playerpixmap.width();
    int height = playerpixmap.height();
    int x = (width - (width / 3)) / 2;
    rightBoundingBox = QRectF(width/2,10, width/6, (height-20));
    leftBoundingBox = QRectF(width/3, 10, width / 6, (height-20));

    upBoundingBox = QRectF(x+10, 0, (width/3 - 20), height / 12);
    downBoundingBox = QRectF(x+10, (height-height/12), (width/3 -20), height / 12);
}

obstacle *steve::getGround(const QList<obstacle *> & obstacles)
{
    QRectF rect(x(), y() + boundingRect().height() - 5, boundingRect().width(), 5);
    for(auto * item : obstacles)
    {
        QRectF otherRect(item->x() + item->boundingRect().x() + 6, item->y() + item->boundingRect().y(), item->boundingRect().width() - 3, 5);
        if(rect.intersects(otherRect)) {
            return item;
        }
    }
    return nullptr;
}
void steve::equipGun() {
    // Code to equip the gun, e.g., changing the image or state
    qDebug() << "Gun equipped!";
}

//testing bounding box
/*
void steve::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    qDebug() << "Painting steve item";


        painter->setPen(QPen(Qt::red));
        painter->setBrush(Qt::transparent);
        painter->drawRect(rightBoundingBox);

        painter->setPen(QPen(Qt::blue));
        painter->drawRect(leftBoundingBox);

        painter->setPen(QPen(Qt::green));
        painter->drawRect(upBoundingBox);

        painter->setPen(QPen(Qt::yellow));
        painter->drawRect(downBoundingBox);

        QGraphicsPixmapItem::paint(painter, option, widget);

}
*/
