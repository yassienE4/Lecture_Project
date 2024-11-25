#include "health.h"

health::health()
{
    healthpoints = 4;
    heart = QPixmap(":/images/heart.png").scaledToHeight(50, Qt::SmoothTransformation);
    twohearts = QPixmap(":/images/2hearts.png").scaledToHeight(50, Qt::SmoothTransformation);
    threehearts = QPixmap(":/images/3hearts.png").scaledToHeight(50, Qt::SmoothTransformation);
    fourhearts = QPixmap(":/images/4hearts.png").scaledToHeight(50, Qt::SmoothTransformation);
    nohearts = QPixmap(":/images/nohearts.png").scaledToHeight(50, Qt::SmoothTransformation);



    setPixmap(fourhearts);
}

void health::applydamage()
{
    healthpoints--;
    if(healthpoints ==3)
        setPixmap(threehearts);
    if(healthpoints ==2)
        setPixmap(twohearts);
    if(healthpoints ==1)
        setPixmap(heart);
    if(healthpoints == 0)
        setPixmap(nohearts);

}
