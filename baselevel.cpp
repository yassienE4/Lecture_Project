#include "baselevel.h"
#include<moving_enemy.h>
#include <QDebug>



baselevel::baselevel(QGraphicsScene *scene, Game* game) : QObject(), m_steve(nullptr), m_game(game)
{
    m_scene = scene;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &baselevel::update);
    timer->start(16);//60 fps

    // QTimer* spawnTimer = new QTimer(this);
    // connect(spawnTimer, &QTimer::timeout, this, &baselevel::spawn_enemy);
    // spawnTimer->start(2000);

}

baselevel::~baselevel()
{
    delete m_steve;
    delete m_scene;
    delete m_game;
    delete timer;
    delete Steve;
    delete pause;
    delete back_button1;
    delete proxyButton;
}

void baselevel::initialize()
{
    m_steve = new steve();
    m_scene->addItem(m_steve);
    m_steve->setPos(100,325);
    m_scene->installEventFilter(this);

    QPixmap pixmap(":/images/pausemenu.png");
    pixmap =pixmap.scaled(5000,720);
    pause = new QGraphicsPixmapItem(pixmap);
    pause->setOpacity(0.5);

    portaltouched = false;

    //nportal->setOpacity(0.25);

    m_scene->addItem(&h);
    invincibilityTimer.start();



}

void baselevel::checkpaused()
{
    if(ispaused)
    {
        if(!pausemenushown)
        {
            m_scene->addItem(pause); // transparant pix map
            QPixmap buttonimage(":/images/mcbuttonimage");
            int fontId = QFontDatabase::addApplicationFont(":/fonts/mcfont.ttf");
            QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);

            back_button1 = new QPushButton();
            back_button1->setFixedSize(buttonimage.size());
            back_button1->setText("Back to Main Menu");
            back_button1->setObjectName(QString("back_button"));
            back_button1->setToolTip("Goes back to main menu");
            back_button1->setStyleSheet(
                "QPushButton {"
                "    border: none;"                // Remove border
                "    background-image: url(:/images/mcbuttonimage);" // Set the image as background
                "    background-repeat: no-repeat;"
                "    background-position: center;"
                "    color: white;"                // Set text color
                "    font-family: '" + fontFamily + "';" // Set the custom font
                               "    font-size: 16px;"             // Set text size
                               "    text-align: center;"          // Center the text
                               "}"
                );



            proxyButton = m_scene->addWidget(back_button1);
            int pos = m_steve->x() - 100;
            if(pos < 448)
                pos = 448;
            back_button1->move(pos,600);
            connect(back_button1, &QPushButton::clicked, this, &baselevel::back_button);
            pausemenushown = true;
        }

    }
    else
    {
        if(pausemenushown)
        {
            m_scene->removeItem(pause);
            pausemenushown = false;
        }
        if(back_button1)
        {
            m_scene->removeItem(proxyButton);
        }
    }
}

void baselevel::back_button()
{
    qDebug() << "works";
    m_game->closelevel();
    m_game->openselect();
}

void baselevel::addobstacle(obstacle* o)
{
    m_scene->addItem(o);
}

void baselevel::adddiamond(diamonds* d)
{
    m_scene->addItem(d);
}

void baselevel::addportal(portal * p)
{
    m_scene->addItem(p);
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
    if(e->key() == Qt::Key_Escape)
    {
        if(pausecount %2 == 0)
        {
            ispaused = true;
        }
        else
        {
            ispaused = false;
        }
        pausecount++;
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

    checkpaused();
    if(!ispaused)
    {
        animate();
        moveVertically();
        moveHorizontally();
        checkgrounded();
        checkcolide();
        checkdiamondcolide();
        m_game->ensureVisible(m_steve,500,0);
        m_steve->update();
        moveEnemy();
        checkenemycollision();
        if(!portaltouched)
        {
            checkend();
        }

    }

}

void baselevel::moveHorizontally()
{
    if(leftpressed && rightpressed) return; //cant go left and right at same time
    if(!leftpressed && !rightpressed) return; // no button pressed
    if(leftpressed && !m_steve->getcolideleft())
    {
        m_steve->moveBy(-10,0);
        if(m_steve->x()>500)
            h.moveBy(-10,0);

    }
    if(rightpressed && !m_steve->getcolideright())
    {
        m_steve->moveBy(10,0);
        if(m_steve->x()>500)
            h.moveBy(10,0);
    }

}

void baselevel::moveVertically()
{
    //gravity
    obstacle* ground = m_steve->isGrounded(obstacles);
    int floor;
    if(ground)
    {
        floor = ground->y() + ground->boundingRect().y() - m_steve->boundingRect().height();
    }
    else
        floor = 320;



    if(m_steve->getjump())
    {


        m_steve->moveBy(0, m_steve->getvelocity());
        m_steve->setvelocity(m_steve->getvelocity() +1);
        if(m_steve->y() >= floor)
        {
            if(!leftpressed && !rightpressed)
            {
                m_steve->setstate(Static);
            }
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
            if(m_steve->y() >= floor ) //||  m_steve->getcolidedown()
            {
                if(!leftpressed && !rightpressed)
                {
                    m_steve->setstate(Static);
                }
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

void baselevel::checkdiamondcolide()
{
    for(auto * dia : diamond)
    {
        QRectF diamondBox = dia->boundingRect().translated(dia->pos());
        QRectF steveRightBox = m_steve->mapRectToScene(m_steve->getrightBoundingBox());
        QRectF steveLeftBox =  m_steve->mapRectToScene(m_steve->getleftBoundingBox());
        QRectF steveUpBox = m_steve->mapRectToScene(m_steve->getupBoundingBox());
        QRectF steveDownBox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());

        if((steveRightBox.intersects(diamondBox)) || (steveLeftBox.intersects(diamondBox)) || (steveUpBox.intersects(diamondBox)) || (steveDownBox.intersects(diamondBox)))
        {
            // add one to score
            qDebug() << "score+1";
            dia->setPos(100000,10000); // should be delete
            // add one to score
        }
    }
}

void baselevel::checkend()
{
    QRectF stevebox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());
    QRectF nportalbox = nportal->mapRectToScene(nportal->getportalbox());
    if(stevebox.intersects(nportalbox) && !portaltouched)
    {
        qDebug() << "End Game";
        portaltouched = true;
        QTimer::singleShot(250, this, [this]() {
            m_game->closelevel();
            m_game->openselect();
        });

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
            // qDebug() << "colideright";
        }
        else
        {
            m_steve->setcolideright(false);
        }

        if(steveLeftBox.intersects(obstacleBox))
        {
            m_steve->setcolideleft(true);
            // qDebug() << "colideleft";
        }
        else
        {
            m_steve->setcolideleft(false);
        }

        if(steveUpBox.intersects(obstacleBox))
        {
            m_steve->setcolideup(true);
            // qDebug() << "colideup";
        }
        else
        {
            m_steve->setcolideup(false);
        }

        if(steveDownBox.intersects(obstacleBox) && !m_steve->getgrounded())
        {
            m_steve->setcolidedown(true);
            //qDebug() << "colidedown";
        }
        else
        {
            m_steve->setcolidedown(false);
        }
    }
}

void baselevel::animate()
{
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
            switch(rcount)
            {
            case 0:
                m_steve->setpix(3);
                // qDebug() << "animate";
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

void baselevel::spawn_enemy(moving_enemy* enemy)
{
    m_scene->addItem(enemy);
}


void baselevel::moveEnemy()
{
    // Horizontal movement

    for(auto enemy : enemies)
    {
        if(enemy->x() == enemy->getmaxrange()) //enemy->getmaxrange()
        {
            enemy->setdirection(0);
        }
        if(enemy->x() == enemy->getminrange())
        {
            enemy->setdirection(1);
        }
        if(enemy->getdirection())
        {
            enemy->moveBy(1,0);
        }
        else
        {
            enemy->moveBy(-1,0);
        }
    }

}

void baselevel::checkenemycollision()
{
    for(auto * ene : enemies)
    {
        QRectF enemybox = ene->boundingRect().translated(ene->pos());
        QRectF steveRightBox = m_steve->mapRectToScene(m_steve->getrightBoundingBox());
        QRectF steveLeftBox =  m_steve->mapRectToScene(m_steve->getleftBoundingBox());
        QRectF steveUpBox = m_steve->mapRectToScene(m_steve->getupBoundingBox());
        QRectF steveDownBox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());

        if((steveRightBox.intersects(enemybox)) || (steveLeftBox.intersects(enemybox)) || (steveUpBox.intersects(enemybox)) || (steveDownBox.intersects(enemybox)))
        {

            qDebug() << "enemy colided";
            if(invincibilityTimer.elapsed() > graceperiod) // timer
            {
                h.applydamage();
                invincibilityTimer.restart();
            }
            else
                qDebug() << "collision ignored";

        }
    }
}


//fix the end game function
// void baselevel::endGame(){
//     QMessageBox::critical(nullptr, "Game Over", "The enemy has touched Steve! Game Over.");
//      m_scene->deleteLater();
// }
