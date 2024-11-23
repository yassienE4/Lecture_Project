#include "moving_enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>


moving_enemy::moving_enemy(baselevel* level, const QString& imagePath) : QObject(), m_level(level) {
    setPixmap(QPixmap(":/images/movingenemy.png").scaled(50, 50));
    setPos(rand() % (m_x_max - m_x_min) + m_x_min, 0);
     QTimer *timer = new QTimer(this);
     connect(timer, &QTimer::timeout, this, &moving_enemy::move);
     timer->start(16);





}
void moving_enemy::set_speed(int s){
    m_speed=s;

}
void moving_enemy::set_bound(int x_min, int x_max){
    m_x_max = x_max;
    m_x_min = x_min;

}
void::moving_enemy::move(){
    setPos(x(),y()+m_speed);
    if (y() > 600) { // Assuming screen height is 600
        scene()->removeItem(this);
        delete this;
    }
    if (m_level && m_level->getSteve() && collidesWithItem(m_level->getSteve())) {
        emit gameOver();
    }
    }


