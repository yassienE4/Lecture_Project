#include "baselevel.h"
#include<moving_enemy.h>
#include <QDebug>
#include <QPointF>
#include <QSoundEffect>
#include<QGraphicsScene>
#include<QGraphicsItem>


baselevel::baselevel(QGraphicsScene *scene, Game* game) : QObject(), m_steve(nullptr), m_game(game)
{
    m_scene = scene;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &baselevel::update);
    timer->start(16);//60 fps

    // QTimer* spawnTimer = new QTimer(this);
    // connect(spawnTimer, &QTimer::timeout, this, &baselevel::spawn_enemy);
    // spawnTimer->start(2000);

    isopen = true;




}

baselevel::~baselevel()
{
    qDebug() << "destructer called";
    delete m_steve;
    m_scene->clear();
    disconnect(); // if glitch remove this line
    delete m_scene;
    delete m_game;
    delete timer;
    delete Steve;
    delete pause;
    delete back_button1;
    delete proxyButton;
    delete scoreText;

    //delete sounds

    delete dingsound;
    delete bowsound;
    delete fireballsound;
    delete ghastsound;


}

void baselevel::initialize()
{
    m_steve = new steve();
    m_scene->addItem(m_steve);
    m_steve->setPos(100,325);
    m_scene->installEventFilter(this);

    QPixmap pixmap(":/images/pausemenu.png");
    pixmap =pixmap.scaled(6500,720);
    pause = new QGraphicsPixmapItem(pixmap);
    pause->setOpacity(0.5);

    portaltouched = false;

    //nportal->setOpacity(0.25);

    m_scene->addItem(&h);
    invincibilityTimer.start();

    score = 0; // Initialize score to 0
    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score: %1").arg(score));
    scoreText->setDefaultTextColor(Qt::white);
    scoreText->setFont(QFont("Arial", 16));
    scoreText->setPos(0, 100); // Position on the screen
    m_scene->addItem(scoreText);

    fontId = QFontDatabase::addApplicationFont(":/fonts/mcfont.ttf");
    fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    graceperiod = 1000;
    inair= false;

    if(shop::doublejumpbought)
        maxjump = 1;
    else
        maxjump = 0;
    jumpcount = 0;

    if(shop::gunbought)
        replaceArrowWithGun();

    ghastsound->setSource(QUrl("qrc:/sounds/ghastcharge.wav"));
    ghastsound->setVolume(1);
    fireballsound->setSource(QUrl("qrc:/sounds/ghastball.wav"));
    fireballsound->setVolume(1);

    gunitem = nullptr;


}
void baselevel::checkdiamondcolide()
{
    QSoundEffect *diamondsound = new QSoundEffect(this);
    diamondsound->setSource(QUrl("qrc:/sounds/levelup.wav"));
    diamondsound->setVolume(1);
    for(auto * dia : diamond)
    {
        QRectF diamondBox = dia->boundingRect().translated(dia->pos());
        QRectF steveRightBox = m_steve->mapRectToScene(m_steve->getrightBoundingBox());
        QRectF steveLeftBox = m_steve->mapRectToScene(m_steve->getleftBoundingBox());
        QRectF steveUpBox = m_steve->mapRectToScene(m_steve->getupBoundingBox());
        QRectF steveDownBox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());

        if((steveRightBox.intersects(diamondBox)) || (steveLeftBox.intersects(diamondBox)) || (steveUpBox.intersects(diamondBox)) || (steveDownBox.intersects(diamondBox)))
        {
            score++; // Increment score
            scoreText->setPlainText(QString("Score: %1").arg(score)); // Update displayed score
            dia->setPos(100000, 10000);
            m_scene->removeItem(dia); // Move diamond out of view or delete it
            diamondsound->play();
        }
    }
}

void baselevel::checkpaused()
{
    if(ispaused)
    {
        if(!pausemenushown)
        {
            m_scene->addItem(pause); // transparant pix map
            QPixmap buttonimage(":/images/mcbuttonimage");

            QSoundEffect *buttonsound = new QSoundEffect(this);
            buttonsound->setSource(QUrl("qrc:/sounds/buttonclick.wav"));
            buttonsound->setVolume(1);

            QPointF scenePos = m_game->mapToScene(448, 600);

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

            back_button1->move(scenePos.x(),scenePos.y());
            connect(back_button1, &QPushButton::clicked, this, [this, buttonsound]() {
                buttonsound->play();
                back_button();
            });
            pausemenushown = true;
        }

    }
    else
    {
        if(pausemenushown)
        {
            m_scene->removeItem(pause);
            m_scene->removeItem(proxyButton);
            pausemenushown = false;
        }
    }
}

void baselevel::back_button()
{
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

void baselevel::addspikes(spikes *s)
{
    m_scene->addItem(s);
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
            if(!inair)
            {
                m_steve->setvelocity(-15);
                jumpcount++;
            }

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
    if(e->key() == Qt::Key_C)
    {
        if(!charging)
        {
            charging = true;
            chargetime.start();
            qDebug() << "called";
            //addbow();
        }
    }

}

void baselevel::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left || e->key() == Qt::Key_A)
    {
        leftpressed = false;
        //if(!spacepressed)
        //{
            m_steve->setstate(Static);
        //}
    }
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_D)
    {
        rightpressed = false;
        //if(!spacepressed)
        //{
            m_steve->setstate(Static);
        //}
    }
    if((e->key() == Qt::Key_Up || e->key() == Qt::Key_W || e->key() == Qt::Key_Space) && !m_steve->getjump())
    {
        spacepressed = false;

        if (!leftpressed && !rightpressed) {
            m_steve->setstate(Static);
        }
    }
    if(e->key() == Qt::Key_C)
    {
        if(charging)
        {
            charging = false;
            if(chargetime.elapsed()>1000)
            {
                qDebug() << "shoot";
                shootarrow();
            }
            else
                chargetime.restart();
        }
    }
}

void baselevel::addbow()
{
    int x = m_steve->x();
    int y = m_steve->y();
    bool d = m_steve->getdirection();
    if(shop::gunbought)
    {
        if(!gunitem)
        {
            gunitem = new gun(x,y,d);
            m_scene->addItem(gunitem);
        }
    }
    else
    {
    if(!bowitem)
    {
        bowitem = new bow(x,y,d);
        m_scene->addItem(bowitem);
    }
    }


}




void baselevel::shootarrow()
{
    if (shop::gunbought) {
        shootgun();
        return;
    }

    bowsound->setSource(QUrl("qrc:/sounds/bowsound.wav"));
    bowsound->setVolume(1);
    bowsound->play();
    int x = m_steve->x();
    int y = m_steve->y();
    bool d = m_steve->getdirection();
    arrows.push_back(new arrow(x,y,d));
    m_scene->addItem(arrows.back());

}
void baselevel::shootgun() {
    // Play gun sound
    // QSoundEffect* gunsound = new QSoundEffect(this);
    // //gunsound->setSource(QUrl("qrc:/sounds/gunsound.wav"));
    // gunsound->setVolume(1);
    // gunsound->play();

    // Get player position and direction
    int x = m_steve->x();
    int y = m_steve->y();
    bool direction = m_steve->getdirection();

    // Create a new bullet and add it to the scene
    auto* new_bullet = new bullet(x, y, direction);
    m_scene->addItem(new_bullet);

    // Track the bullet in the vector
    bullets.push_back(new_bullet);
}


void baselevel::movebullets() {
    for (auto it = bullets.begin(); it != bullets.end();) {
        bullet* current_bullet = *it;

        // Move bullet based on its direction
        if (current_bullet->get_bullet_direction()) {
            current_bullet->moveBy(10, 0); // Move right
        } else {
            current_bullet->moveBy(-10, 0); // Move left
        }

        // Apply gravity (if part of bullet behavior)
        current_bullet->bullet_gravity();

        // Remove bullet if off-screen
        if (current_bullet->x() < 0 || current_bullet->x() > m_scene->width()) {
            m_scene->removeItem(current_bullet);
            delete current_bullet;
            it = bullets.erase(it); // Remove from vector
        } else {
            ++it;
        }
    }
}

void baselevel::checkbullethitenemy() {
    for (auto it = bullets.begin(); it != bullets.end();) {
        bullet* bullet = *it;
        QRectF bulletBox = bullet->boundingRect().translated(bullet->pos());
        bool bulletDeleted = false;

        for (auto enemyIt = enemies.begin(); enemyIt != enemies.end();) {
            moving_enemy* enemy = *enemyIt;
            QRectF enemyBox = enemy->boundingRect().translated(enemy->pos());

            if (bulletBox.intersects(enemyBox)) {
                m_scene->removeItem(bullet);
                m_scene->removeItem(enemy);
                delete bullet;
                delete enemy;
                enemyIt = enemies.erase(enemyIt);
                it = bullets.erase(it);
                bulletDeleted = true;
                break;
            } else {
                ++enemyIt;
            }
        }

        if (!bulletDeleted) {
            ++it;
        }
    }
}





void baselevel::movearrows()
{
    for(auto arr : arrows)
    {
        double y;
        if(shop::arrowgravitybought)
            y = 0;
        else
            y = arr->getvelocity();
        if(arr->getdirection())
        {
            arr->moveBy(5,y);
        }
        else
        {
            arr->moveBy(-5,y);
        }
        arr->gravity();
    }
}

void baselevel::checkarrowhitenemy()
{
    for(auto it = arrows.begin(); it != arrows.end();)
    {
        arrow* arr = *it;
        QRectF arrowbox = arr->boundingRect().translated(arr->pos());
        bool arrowDeleted = false;
        for(auto enemyIt = enemies.begin(); enemyIt != enemies.end();)
        {
            moving_enemy* enemy = *enemyIt;
            QRectF enemybox = enemy->boundingRect().translated(enemy->pos());
            if(arrowbox.intersects(enemybox))
            {
                dingsound->setSource(QUrl("qrc:/sounds/dingsound.wav"));
                dingsound->setVolume(1);
                dingsound->play();


                m_scene->removeItem(arr);
                m_scene->removeItem(enemy);
                delete arr;
                delete enemy;
                enemyIt = enemies.erase(enemyIt);
                it = arrows.erase(it);
                arrowDeleted = true;
                break;
            }
            else
                ++enemyIt;
        }
        if (!arrowDeleted)
        {
            ++it;
        }
    }
}
void baselevel::checkarrowhitobstacle()
{
    for(auto it = arrows.begin(); it != arrows.end();)
    {
        arrow* arr = *it;
        QRectF arrowbox = arr->boundingRect().translated(arr->pos());
        bool arrowDeleted = false;
        for(auto obs: obstacles)
        {
            QRectF obstacleBox = obs->boundingRect().translated(obs->pos());
            if(arrowbox.intersects(obstacleBox))
            {
                m_scene->removeItem(arr);
                delete arr;
                it = arrows.erase(it);
                arrowDeleted = true;
                break;
            }
        }
        if (!arrowDeleted)
        {
            ++it;
        }
    }
}

void baselevel::addghast(ghast* g)
{
    m_scene->addItem(g);
}
void baselevel::shootball()
{
    //check if ghast on screen to play sound
    QRectF viewRect = m_game->mapToScene(m_game->viewport()->rect()).boundingRect();
    bool soundplayed = false;
    for(auto gh : ghasts)
    {

        if(gh->returnball() == nullptr && gh->cooldown.elapsed() > 2000) // need to add an elasped timer
        {
            gh->setball(new fireball(gh->x(),gh->y()));
            gh->setpix(2);
            bool shown = false;
            QRectF ghastRect = gh->boundingRect().translated(gh->pos());
            if(ghastRect.intersects(viewRect))
            {
                gh->shown = true;
                if(!gh->isdispenser())
                {
                    shown = gh->shown;
                    ghastsound->play();
                }
                else
                {
                    if(!soundplayed)
                        fireballsound->play();
                    soundplayed = true;
                }
            }
            else
                gh->shown = false;

            if(!gh->isdispenser())
            {
                QTimer::singleShot(300, this, [this, gh,shown]() {
                    if(shown)
                        fireballsound->play();
                    gh->setpix(1);
                    gh->cooldown.restart();
                });
            }
            else
                gh->cooldown.restart();


            m_scene->addItem(gh->returnball());
        }
    }
}

void baselevel::moveBall()
{
    for(auto gh : ghasts)
    {
        if(gh->returnball() != nullptr)
        {
            if(gh->isdispenser())
                gh->returnball()->moveBy(0,5);
            else
                gh->returnball()->moveBy(-5,0);

        }
    }
}
void baselevel::checkballcollisions()
{
    explodesound->setSource(QUrl("qrc:/sounds/explode4.wav"));
    explodesound->setVolume(1);
    for(auto gh : ghasts)
    {
        if(gh->returnball() !=nullptr)
        {
            fireball * f = gh->returnball();
            QRectF ballbox = f->boundingRect().translated(f->pos());
            //get steve box
            QRectF steveRightBox = m_steve->mapRectToScene(m_steve->getrightBoundingBox());
            QRectF steveLeftBox =  m_steve->mapRectToScene(m_steve->getleftBoundingBox());
            QRectF steveUpBox = m_steve->mapRectToScene(m_steve->getupBoundingBox());
            QRectF steveDownBox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());
            if((steveRightBox.intersects(ballbox)) || (steveLeftBox.intersects(ballbox)) || (steveUpBox.intersects(ballbox)) || (steveDownBox.intersects(ballbox)))
            {
                if(invincibilityTimer.elapsed() > graceperiod)
                {
                    h.applydamage();
                    m_steve->setstate(Static);
                    explodesound->play();
                    invincibilityTimer.restart();
                }
                if(gh->returnball()->graceperiod.elapsed() > 100) // prevent lag
                {
                    m_scene->removeItem(f);
                    delete f;
                    gh->setball(nullptr);
                }
            }
        }
    }
}
void baselevel::checkballobstacle()
{
    for(auto gh : ghasts)
    {
        if(gh->returnball() !=nullptr)
        {
            fireball * f = gh->returnball();
            QRectF ballbox = f->boundingRect().translated(f->pos());
            for(auto obs : obstacles)
            {
                QRectF obstacleBox = obs->boundingRect().translated(obs->pos());
                if(ballbox.intersects(obstacleBox) && gh->returnball())
                {
                    m_scene->removeItem(f);
                    delete f;
                    gh->setball(nullptr);
                }
            }
        }
    }
}


void baselevel::update()
{

    checkpaused();
    if(!ispaused && isopen)
    {
        checkcolide();
        animate();
        moveVertically();
        moveHorizontally();
        checkdiamondcolide();
        m_game->ensureVisible(m_steve,500,0);
        movebullets();
        checkbullethitenemy();

        QPointF scenePos = m_game->mapToScene(0,0);
        h.setPos(scenePos.x(), scenePos.y());
        scoreText->setPos(scenePos.x(),scenePos.y()+100);

        m_steve->update();
        moveEnemy();
        moveObstacle();
        checkenemycollision();
        checkspikes();
        movearrows();
        checkarrowhitenemy();
        checkarrowhitobstacle();

        //ghast functions
        shootball();
        moveBall();
        checkballcollisions();
        checkballobstacle();
        for(auto gh:ghasts)
        {
            gh->shown = false;
        }

        if(!portaltouched)
        {
            checkend();
        }
        if(h.gethealth() <= 0)
        {
            ispaused = true;
            QPointF scenePos = m_game->mapToScene(448, 600);
            QGraphicsTextItem* gameover = new QGraphicsTextItem("GAME OVER!");
            QFont font(fontFamily, 64);
            gameover->setFont(font);
            gameover->setDefaultTextColor(Qt::black);
            gameover->setPos(scenePos.x(), scenePos.y() - 350);
            m_scene->addItem(gameover);
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
        if(bowitem)
            bowitem->moveBy(-10,0);

    }
    if(rightpressed && !m_steve->getcolideright())
    {
        m_steve->moveBy(10,0);
        if(bowitem)
            bowitem->moveBy(10,0);
    }

}

void baselevel::moveVertically()
{



    obstacle* ground = m_steve->getGround(obstacles);
    int floor;
    if(ground)
    {
        floor = ground->y() + ground->boundingRect().y() - m_steve->boundingRect().height();
        inair=false;
        jumpcount = 0;
    }
    else
    {
        floor = floorlevel;
        if(m_steve->y()==520)
        {
            inair=false;
            jumpcount = 0;
        }
        else
        {
            if(jumpcount == maxjump)
                inair=true;
        }
    }




    if(m_steve->getjump())
    {


        m_steve->moveBy(0, m_steve->getvelocity());
        if(bowitem)
            bowitem->moveBy(0, m_steve->getvelocity());
        m_steve->setvelocity(m_steve->getvelocity() +1);
        if(m_steve->y() >= floor)
        {
            if(!leftpressed && !rightpressed)
            {
                m_steve->setstate(Static);
            }
            m_steve->setY(floor);
            if(bowitem)
                bowitem->setY(m_steve->y()+10);
            m_steve->setvelocity(0);
        }


        // check if hit obsticle /ground
    }
    else
    {
        if((!m_steve->getjump()) && (m_steve->y() <= floor) && !m_steve->getcolidedown())
        {
            m_steve->setvelocity(m_steve->getvelocity() +1);
            m_steve->moveBy(0, m_steve->getvelocity());
            if(bowitem)
                bowitem->moveBy(0, m_steve->getvelocity());
            if(m_steve->y() >= floor ) //||  m_steve->getcolidedown())
            {
                if(!leftpressed && !rightpressed)
                {
                    m_steve->setstate(Static);
                }
                m_steve->setY(floor);
                if(bowitem)
                    bowitem->setY(m_steve->y()+10);
                m_steve->setvelocity(0);
            }
        }
    }
}


void baselevel::checkend()
{
    QRectF stevebox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());
    QRectF nportalbox = nportal->mapRectToScene(nportal->getportalbox());
    if(stevebox.intersects(nportalbox) && !portaltouched)
    {
        portalsound->setSource(QUrl("qrc:/sounds/portalsound.wav"));
        portalsound->setVolume(1);
        portaltouched = true;
        portalsound->play();
        shop::totaldiamonds = score + shop::totaldiamonds;
        QTimer::singleShot(250, this, [this]() {
            m_game->closelevel();
            m_game->openselect();
        });
        QTimer::singleShot(2750,this,[this](){
            portalsound->stop();
        });
        isopen = false;

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
            return;
            // qDebug() << "colideright";
        }
        else
        {
            m_steve->setcolideright(false);
        }

        if(steveLeftBox.intersects(obstacleBox))
        {
            m_steve->setcolideleft(true);
            return;
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

    if(charging)
    {
        if(!shop::gunbought)
        {
        addbow();
        if(m_steve->getdirection())
        {   m_steve->setpix(7);
            bowitem->changedirection(m_steve->x(),m_steve->y(),1);
            if(chargetime.elapsed()>333)
                bowitem->setpix(3);
            if(chargetime.elapsed()>666)
                bowitem->setpix(5);
            if(chargetime.elapsed()>999)
                bowitem->setpix(7);


            return;}
        else
        {   m_steve->setpix(8);
            bowitem->changedirection(m_steve->x(),m_steve->y(),0);
            if(chargetime.elapsed()>333)
                bowitem->setpix(4);
            if(chargetime.elapsed()>666)
                bowitem->setpix(6);
            if(chargetime.elapsed()>999)
                bowitem->setpix(8);

            return;}
        }
        else
        {
            addbow();
            if(m_steve->getdirection())
            {
                m_steve->setpix(7);
                gunitem->changedirection_gun(m_steve->x(),m_steve->y(),1);
            }
            else
            {
                m_steve->setpix(8);
                gunitem->changedirection_gun(m_steve->x(),m_steve->y(),0);
            }
        }
    }
    else
    {
        if(bowitem)
        {
            delete bowitem;
            bowitem = nullptr;
            m_steve->setstate(Static);
        }
        if(gunitem)
        {
            delete gunitem;
            gunitem = nullptr;
            m_steve->setstate(Static);
        }
    }
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

void baselevel::moveObstacle()
{
    for(auto move : m_obstacles)
    {
        if(move->x() == move->getx1())
        {
            move->setdir(1);
        }
        if(move->x() == move->getx2())
        {
            move->setdir(0);
        }
        if(move->getdir())
        {
            move->moveBy(1,0);
        }
        else
        {
            move->moveBy(-1,0);
        }
    }
}

void baselevel::checkenemycollision()
{
    QRectF steveRightBox = m_steve->mapRectToScene(m_steve->getrightBoundingBox());
    QRectF steveLeftBox =  m_steve->mapRectToScene(m_steve->getleftBoundingBox());
    QRectF steveUpBox = m_steve->mapRectToScene(m_steve->getupBoundingBox());
    QRectF steveDownBox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());
    QSoundEffect *hurtsound = new QSoundEffect(this);
    hurtsound->setSource(QUrl("qrc:/sounds/hurtsound.wav"));
    hurtsound->setVolume(1);
    for(auto * ene : enemies)
    {
        QRectF enemybox = ene->boundingRect().translated(ene->pos());
        if((steveRightBox.intersects(enemybox)) || (steveLeftBox.intersects(enemybox)) || (steveUpBox.intersects(enemybox)) || (steveDownBox.intersects(enemybox)))
        {
            if(invincibilityTimer.elapsed() > graceperiod) // timer
            {
                h.applydamage();
                m_steve->setstate(Static);
                hurtsound->play();
                invincibilityTimer.restart();
            }
        }
    }

}

void baselevel::checkspikes()
{
    QRectF steveRightBox = m_steve->mapRectToScene(m_steve->getrightBoundingBox());
    QRectF steveLeftBox =  m_steve->mapRectToScene(m_steve->getleftBoundingBox());
    QRectF steveUpBox = m_steve->mapRectToScene(m_steve->getupBoundingBox());
    QRectF steveDownBox = m_steve->mapRectToScene(m_steve->getdownBoundingBox());
    QSoundEffect *hurtsound = new QSoundEffect(this);
    hurtsound->setSource(QUrl("qrc:/sounds/hurtsound.wav"));
    hurtsound->setVolume(1);
    for(auto * spi : m_spikes)
    {
        QRectF spikebox = spi->boundingRect().translated(spi->pos());
        if((steveRightBox.intersects(spikebox)) || (steveLeftBox.intersects(spikebox)) || (steveUpBox.intersects(spikebox)) || (steveDownBox.intersects(spikebox)))
        {
            if(invincibilityTimer.elapsed() > graceperiod) // timer
            {
                h.applydamage();
                m_steve->setstate(Static);
                hurtsound->play();
                invincibilityTimer.restart();
            }
        }
    }
}




void baselevel::replaceArrowWithGun() {
    if (!arrowRemoved) {
        arrowRemoved = true; // Update the state
        enableGun();         // Activate gun functionality
        qDebug() << "Arrow replaced with gun.";
    }
}

void baselevel::enableGun() {
    qDebug() << "Gun has been enabled.";

    // Remove the arrow from the scene
    if (arrowItem) {
        m_scene->removeItem(arrowItem); // Remove arrow from the scene
        delete arrowItem;      // Free memory
        arrowItem = nullptr;   // Nullify the pointer
    }
}

// void baselevel::addObstacle(obstacle* obstacle) {
//     m_obstacles.push_back(obstacle);
//     m_scene->addItem(obstacle); // Add obstacle to the scene
// }


// QGraphicsScene& baselevel::getScene() {
//     return m_scene; // Return the reference
// }


