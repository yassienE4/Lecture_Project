#include "baselevel.h"
#include <QDebug>

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
void baselevel::addobstacle(obstacle* o)
{
    m_scene->addItem(o);
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
        if(!m_steve->getjump())
        {
            m_steve->setstate(Moving);
        }

    }
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_D)
    {
        rightpressed = true;
        m_steve->setdirection(1);
        if(!m_steve->getjump())
        {
            m_steve->setstate(Moving);
        }
    }
    if((e->key() == Qt::Key_Up || e->key() == Qt::Key_W || e->key() == Qt::Key_Space) && !m_steve->getjump())
    {
        spacepressed = true;
        m_steve->setstate(Jumping);
        m_steve->setvelocity(-15);
    }

}

void baselevel::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left || e->key() == Qt::Key_A)
    {
        leftpressed = false;
        if(!spacepressed)
        {
            m_steve->setstate(Static);
        }
    }
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_D)
    {
        rightpressed = false;
        if(!spacepressed)
        {
            m_steve->setstate(Static);
        }
    }
    if((e->key() == Qt::Key_Up || e->key() == Qt::Key_W || e->key() == Qt::Key_Space) && !m_steve->getjump())
    {
        spacepressed = false;

        if (!leftpressed && !rightpressed) {
            m_steve->setstate(Static);
        }
    }
}

void baselevel::update()
{
    animate();
    moveVertically();
    moveHorizontally();
    checkgrounded();
    checkcolide();
    m_steve->update();
}

void baselevel::moveHorizontally()
{
    if(leftpressed && rightpressed) return; //cant go left and right at same time
    if(!leftpressed && !rightpressed) return; // no button pressed
    if(leftpressed && !m_steve->getcolideleft())
    {
        m_steve->moveBy(-10,0);
    }
    if(rightpressed && !m_steve->getcolideright())
    {
        m_steve->moveBy(10,0);
    }
}
/*
void baselevel::moveVertically()
{
    //gravity

    if(m_steve->getjump())
    {

        m_steve->moveBy(0, m_steve->getvelocity());
        m_steve->setvelocity(m_steve->getvelocity() +1); // velocity++
        if(m_steve->y() >= 320)
        {
            if(!leftpressed && !rightpressed)
            {
                m_steve->setstate(Static);
            }
            m_steve->setY(320);
            m_steve->setvelocity(0);
        }


        if(m_steve->getcolidedown())
        {
            m_steve->setvelocity(0);
            m_steve->setY(m_steve->y() - m_steve->getvelocity());
            if(!leftpressed && !rightpressed)
            {
                m_steve->setstate(Static);
            }
        }
    }
    else
    {
        if(m_steve->getcolidedown())
        {
            m_steve->setvelocity(0);
            m_steve->setY(m_steve->y() - m_steve->getvelocity());
            if(!leftpressed && !rightpressed)
            {
                m_steve->setstate(Static);
            }
        }
        else
        {
            if((!m_steve->getjump()) && (m_steve->y() <= 320))
            {
                m_steve->setvelocity(m_steve->getvelocity() +1);
                m_steve->moveBy(0, m_steve->getvelocity()+10);
                if(m_steve->y() >= 320)
                {
                    if(!leftpressed && !rightpressed)
                    {
                        m_steve->setstate(Static);
                    }
                    m_steve->setY(320);
                    m_steve->setvelocity(0);
                }
            }
        }


    }
}
*/

void baselevel::moveVertically()
{
    //gravity

    if(m_steve->getjump())
    {


        m_steve->moveBy(0, m_steve->getvelocity());
        m_steve->setvelocity(m_steve->getvelocity() +1);
        if(m_steve->y() >= 320 ||  m_steve->getcolidedown())
        {
            if(!leftpressed && !rightpressed)
            {
                m_steve->setstate(Static);
            }
            int floor = !m_steve->getcolidedown() ? 320 : m_steve->y();
            m_steve->setY(floor);
            m_steve->setvelocity(0);
        }


        // check if hit obsticle /ground
    }
    else
    {
        if((!m_steve->getjump()) && (m_steve->y() <= 320) && !m_steve->getcolidedown())
        {
            m_steve->setvelocity(m_steve->getvelocity() +1);
            m_steve->moveBy(0, m_steve->getvelocity());
            if(m_steve->y() >= 320 ) //||  m_steve->getcolidedown()
            {
                if(!leftpressed && !rightpressed)
                {
                    m_steve->setstate(Static);
                }
                int floor = !m_steve->getcolidedown() ? 320 : m_steve->y();
                m_steve->setY(floor);
                m_steve->setvelocity(0);
            }
        }
    }
}

void baselevel::checkgrounded()
{
    if(m_steve->getvelocity()==0 && m_steve->getcolidedown())
    {
        m_steve->setgrounded(true);
    }
    else
    {
        m_steve->setgrounded(false);
    }
}
void baselevel::checkcolide()
{
    for(auto * obs : obstacles)
    {
        QRectF obstacleBox = obs->boundingRect().translated(obs->pos()); // turning obs into a qrectf to compare with steve boundingboxes(also qrectf)
        QRectF steveRightBox = m_steve->mapRectToScene(m_steve->getrightBoundingBox());
        QRectF steveLeftBox =  m_steve->mapRectToScene(m_steve->getleftBoundingBox());
        QRectF steveUpBox = m_steve->mapRectToScene(m_steve->getupBoundingBox());
        QRectF steveDownBox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());

        if(steveRightBox.intersects(obstacleBox))
        {
            m_steve->setcolideright(true);
            qDebug() << "colideright";
        }
        else
        {
            m_steve->setcolideright(false);
        }

        if(steveLeftBox.intersects(obstacleBox))
        {
            m_steve->setcolideleft(true);
            qDebug() << "colideleft";
        }
        else
        {
            m_steve->setcolideleft(false);
        }

        if(steveUpBox.intersects(obstacleBox))
        {
            m_steve->setcolideup(true);
            qDebug() << "colideup";
        }
        else
        {
            m_steve->setcolideup(false);
        }

        if(steveDownBox.intersects(obstacleBox) && !m_steve->getgrounded())
        {
            m_steve->setcolidedown(true);
            qDebug() << "colidedown";
        }
        else
        {
            m_steve->setcolidedown(false);
        }
    }
}

void baselevel::animate()
{
    static int frameCounter = 0;
    frameCounter = (frameCounter + 1) % 12; //control animation speed
    if (frameCounter != 0)
        return;
    if(m_steve->getstate() == Static)
    {
        if(m_steve->getdirection())
            m_steve->setpix(1);
        else
            m_steve->setpix(2);
    }
    if((m_steve->getstate() == Moving) || m_steve->getjump())
    {
        if(m_steve->getdirection())
        {
            static int rcount = 0;
            switch(rcount)
            {
            case 0:
                m_steve->setpix(3);
                break;
            case 1:
                m_steve->setpix(1);
                break;
            case 2:
                m_steve->setpix(5);
                break;
            case 3:
                m_steve->setpix(1);
            }
            rcount = (rcount+1)%4;
        }
        else
        {
            static int lcount = 0;
            switch(lcount)
            {
            case 0:
                m_steve->setpix(4);
                break;
            case 1:
                m_steve->setpix(2);
                break;
            case 2:
                m_steve->setpix(6);
                break;
            case 3:
                m_steve->setpix(2);
                break;
            }
            lcount = (lcount+1)%4;
        }
    }
}
