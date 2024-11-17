#include "baselevel.h"


baselevel::baselevel(QGraphicsScene *scene) : QObject(), m_steve(nullptr)
{
    m_scene = scene;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &baselevel::update);
    timer->start(16);//60 fps
}

void baselevel::initialize()
{
    m_steve = new steve();
    m_scene->addItem(m_steve);
    m_steve->setPos(100,320);
    m_scene->installEventFilter(this);

}

bool baselevel::eventFilter(QObject *obj, QEvent *event) // scenes cant be focused so i overloaded
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        keyPressEvent(keyEvent);
        return true;
    }
    else if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        keyReleaseEvent(keyEvent);
        return true;
    }
    return QObject::eventFilter(obj, event);
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
        leftpressed = true;
        m_steve->setdirection(0);
    }
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_D)
    {
        rightpressed = true;
        m_steve->setdirection(1);
    }
    if((e->key() == Qt::Key_Up || e->key() == Qt::Key_W || e->key() == Qt::Key_Space) && !m_steve->getjump())
    {
        spacepressed = true;
        //m_steve->setstate(Jumping);
        //m_steve->setvelocity(-15);
    }

}

void baselevel::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left || e->key() == Qt::Key_A)
    {
        leftpressed = false;
    }
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_D)
    {
        rightpressed = false;
    }
    if((e->key() == Qt::Key_Up || e->key() == Qt::Key_W || e->key() == Qt::Key_Space) && !m_steve->getjump())
    {
        spacepressed = false;
    }
}

void baselevel::update()
{
    moveHorizontally();
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

void baselevel::moveHorizontally()
{
    if(leftpressed && rightpressed) return; //cant go left and right at same time
    if(!leftpressed && !rightpressed) return; // no button pressed
    if(leftpressed)
    {
        m_steve->moveBy(-10,0);
    }
    if(rightpressed)
        m_steve->moveBy(10,0);
}

void baselevel::moveVertically()
{

}
