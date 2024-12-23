#ifndef LEVEL5_H
#define LEVEL5_H

#include "baselevel.h"
#include <QGraphicsRectItem>
#include <QList>
class level5 : public baselevel // inhert from baselevel
{
    Q_OBJECT
private:
    int m_startpos;
    int o;
    int s;
    bool addblock;
    bool addblock2;
public:
    level5(QGraphicsScene *scene, Game* game);
    void initialize();
    void init1();
    void init2();
    void init3();
    void init4();
};

#endif // LEVEL5_H
