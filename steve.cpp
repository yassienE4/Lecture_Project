#include "steve.h"

steve::steve()  {
    playerpixmap = QPixmap(":/images/steve.png");
    leftplayerpixmap = QPixmap(":/images/steveleft.png");
    rightplayerpixmap = QPixmap(":/images/steve.png");
    int scaledWidth = playerpixmap.width() * 200 / playerpixmap.height();
    playerpixmap = playerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);
    rightplayerpixmap = rightplayerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);
    leftplayerpixmap = leftplayerpixmap.scaled(scaledWidth, 200, Qt::KeepAspectRatio);

    rightmoving = QPixmap(":/images/stevemoveright1");
    int movescaled = rightmoving.width() * 200 / rightmoving.height();
    leftmoving = QPixmap(":/images/stevemoveleft1");
    rightmoving = rightmoving.scaled(movescaled, 200,Qt::KeepAspectRatio );
    leftmoving = leftmoving.scaled(movescaled, 200,Qt::KeepAspectRatio );

    rightmoving2 = QPixmap(":/images/stevemoveright2");
    leftmoving2 = QPixmap(":/images/stevemoveleft2");
    rightmoving2 = rightmoving2.scaled(movescaled, 200,Qt::KeepAspectRatio );
    leftmoving2 = leftmoving2.scaled(movescaled, 200,Qt::KeepAspectRatio );

    setPixmap(playerpixmap);
    state = Static;
    player_velocity=0;
    direction = 1;

    setboundingboxes();
    //setOpacity(0.5); // to check bounding box
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

obstacle *steve::isGrounded(const QList<obstacle *> & obstacles)
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

// obstacle* steve::isBlockedHorizontally(const QList<QGraphicsItem*>& items, int& direction) {
//     direction = 0;
//     for(QGraphicsItem* item : items) {
//         GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
//         if(entity != nullptr) {
//             QRectF rect(x(), y(), boundingRect().width(), boundingRect().height());
//             QRectF leftRect(item->x() - 3, item->y() + 3, 10, item->boundingRect().height() - 6);
//             if (rect.intersects(leftRect)) {
//                 direction += 1;
//                 return entity;
//             }
//             QRectF rightRect(item->x() + item->boundingRect().width() + 3, item->y() + 3, 10, item->boundingRect().height() - 6);
//             if (rect.intersects(rightRect)) {
//                 direction -= 1;
//                 return entity;
//             }
//         }
//     }
//     return nullptr;
// }



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


//testing bounding box

void steve::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    // qDebug() << "Painting steve item";


        // painter->setPen(QPen(Qt::red));
        // painter->setBrush(Qt::transparent);
        // painter->drawRect(rightBoundingBox);

        // painter->setPen(QPen(Qt::blue));
        // painter->drawRect(leftBoundingBox);

        // painter->setPen(QPen(Qt::green));
        // painter->drawRect(upBoundingBox);

        painter->setPen(QPen(Qt::yellow));
        painter->drawRect((getdownBoundingBox()));

        QGraphicsPixmapItem::paint(painter, option, widget);

}

