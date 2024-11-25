#include "moving_enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>


moving_enemy::moving_enemy(baselevel* level, const QString& imagePath) : QObject(), m_level(level),m_direction(1), m_horizontalDistance(0),m_verticalDistance(0) {
    setPixmap(QPixmap(":/images/movingenemy.png").scaled(100, 100));
    setPos(100,400);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &moving_enemy::move);
    timer->start(16);

     m_allowedHorizontalMovement = 20;
     m_allowedVerticalMovement = 25;



}
void moving_enemy::set_speed(int s){
    m_speed=s;

}
void moving_enemy::set_bound(int x_min, int x_max){
    m_x_max = x_max;
    m_x_min = x_min;

}

void moving_enemy::move() {
    // Horizontal movement
    m_horizontalDistance += m_direction * 1; // Move 1 unit per frame
    setPos(x() + m_direction, y());

    // Change direction if horizontal distance exceeds allowed range
    if (m_horizontalDistance >= m_allowedHorizontalMovement || m_horizontalDistance <= -m_allowedHorizontalMovement) {
        m_direction *= -1; // Reverse direction
    }

    // Vertical movement: Ensure enemies stay near the ground level
    m_verticalDistance += m_speed;
    if (m_verticalDistance >= m_allowedVerticalMovement) {
        m_verticalDistance = 0;
    }

    // Collision detection with "Steve"
    if (m_level && m_level->getSteve() && collidesWithItem(m_level->getSteve())) {
        emit gameOver();
    }
}
