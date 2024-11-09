#include "baselevel.h"

baselevel::baselevel(QGraphicsScene *scene) : QObject(), m_scene(scene), m_steve(nullptr)
{

}
void baselevel::initialize()
{
    m_steve = new steve();
    m_scene->addItem(m_steve);
    m_steve->setPos(100,500);

    // obsticals will be here
}


void baselevel::keyPressEvent(QKeyEvent * e)
{
    if(e->key() == Qt::Key_Left || e->key() == Qt::Key_A)
    {
        m_steve->moveBy(-10, 0);
    }
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_D)
    {
        m_steve->moveBy(10, 0);
    }
    if(e->key() == Qt::Key_Up || e->key() == Qt::Key_W || e->key() == Qt::Key_Space)
    {

    }

}
