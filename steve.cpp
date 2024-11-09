#include "steve.h"

steve::steve() {
    playerpixmap = QPixmap(":/images/steve.png");

}

void steve::keyPressEvent(QKeyEvent * e)
{
    if(e->key() == Qt::Key_Left || e->key() == Qt::Key_A)
    {
        setPos(x()-10, y());
    }
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_D)
    {
        setPos(x()+10, y());
    }
    if(e->key() == Qt::Key_Up || e->key() == Qt::Key_W || e->key() == Qt::Key_Space)
    {

    }

}
