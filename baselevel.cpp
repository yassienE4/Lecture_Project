#include "baselevel.h"

baselevel::baselevel(QGraphicsScene *scene) : QObject(), m_steve(nullptr)
{
    m_scene = new QGraphicsScene(scene);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &baselevel::update);
    timer->start(16);//60 fps
}

void baselevel::initialize()
{
    m_steve = new steve();
    m_scene->addItem(m_steve);
    m_steve->setPos(100,500);

}
void baselevel::setbackground(QGraphicsPixmapItem *x)
{
    m_scene->addItem(x);
    x->setPos(0,0);
    x->setZValue(-1);
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
    if((e->key() == Qt::Key_Up || e->key() == Qt::Key_W || e->key() == Qt::Key_Space) && !m_steve->getjump())
    {
        m_steve->setstate(Jumping);
        m_steve->setvelocity(-15);
    }

}

void baselevel::update()
{
    //gravity
    if(m_steve->getjump())
    {
        m_steve->moveBy(0, m_steve->getvelocity());
        m_steve->setvelocity(m_steve->getvelocity() +1);
        // check if hit obsticle /ground
        if(true)
        {
            m_steve->setstate(Jumping);
            m_steve->setY(500); //500 temp
        }
    }

}
