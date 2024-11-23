#ifndef BASELEVEL_H
#define BASELEVEL_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include "steve.h"
#include "obstacle.h"
#include <QDebug>
#include "game.h"
#include <QMessageBox>
#include<QWidget>



class Game;
class moving_enemy;

class baselevel : public QObject
{
Q_OBJECT
public:
    baselevel(QGraphicsScene *scene, Game *game);
    steve*  getSteve();
    void initialize();
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent *e);
    void setbackground(QGraphicsPixmapItem* x);
    void moveHorizontally();
    void moveVertically();
    void checkcolide();
    void checkgrounded();
    void animate();
    void addobstacle(obstacle* o);
    bool eventFilter(QObject *obj, QEvent *event);
    bool colideright();
    bool colideleft();
    bool colideup();
    bool colidedown();
    void check_collision();
public slots:
    void spawn_enemy();
    void endGame();
private slots:
    void update();
protected:
    QList<obstacle*> obstacles;
private:
    steve *m_steve;
    QGraphicsScene *m_scene;
    Game *m_game;
    QTimer *timer;
    bool leftpressed, rightpressed, spacepressed;
    QGraphicsRectItem* Steve;
};

#endif // BASELEVEL_H
