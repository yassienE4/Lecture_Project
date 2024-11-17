#ifndef BASELEVEL_H
#define BASELEVEL_H

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "steve.h"
#include "obstacle.h"
#include <QDebug>


class baselevel : public QObject
{
Q_OBJECT
public:
    baselevel(QGraphicsScene *scene);
    void initialize();
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent *e);
    void setbackground(QGraphicsPixmapItem* x);

    void moveHorizontally();
    void moveVertically();
    void animate();

    bool eventFilter(QObject *obj, QEvent *event);
private slots:
    void update();
private:
    steve *m_steve;
    QGraphicsScene *m_scene;
    QTimer *timer;
    bool leftpressed, rightpressed, spacepressed;
};

#endif // BASELEVEL_H
