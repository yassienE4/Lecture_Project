#ifndef BASELEVEL_H
#define BASELEVEL_H

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "steve.h"


class baselevel : public QObject
{
Q_OBJECT
public:
    baselevel(QGraphicsScene *scene);
    void initialize();
    void keyPressEvent(QKeyEvent * e);
private slots:
    void update();
private:
    steve *m_steve;
    QGraphicsScene *m_scene;
};

#endif // BASELEVEL_H