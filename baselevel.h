#ifndef BASELEVEL_H
#define BASELEVEL_H

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "steve.h"
#include "obstacle.h"
#include <QDebug>
#include "game.h"


class baselevel : public QObject
{
Q_OBJECT
public:
    baselevel(QGraphicsScene *scene, Game *game);
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
};

#endif // BASELEVEL_H
