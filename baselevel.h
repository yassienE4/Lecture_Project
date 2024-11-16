#ifndef BASELEVEL_H
#define BASELEVEL_H

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "steve.h"
#include "obstacle.h"


class baselevel : public QObject
{
Q_OBJECT
public:
    baselevel(QGraphicsScene *scene);
    void initialize();
    void keyPressEvent(QKeyEvent * e);
    void setbackground(QGraphicsPixmapItem* x);
private slots:
    void update();
private:
    steve *m_steve;
    QGraphicsScene *m_scene;
    QTimer *timer;
};

#endif // BASELEVEL_H
