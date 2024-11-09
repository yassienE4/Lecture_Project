#ifndef STEVE_H
#define STEVE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QObject>
#include <QKeyEvent>

enum PlayerState
{
    Moving,
    Jumping,
    Falling,
    Static
};

class steve : QGraphicsItem
{
 Q_OBJECT
public:
    steve();
private:
    QPixmap playerpixmap;
    int health;
    int score;
public slots:
    void keyPressEvent(QKeyEvent * e);
};

#endif // STEVE_H
