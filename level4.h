#ifndef LEVEL4_H
#define LEVEL4_H

#include "baselevel.h"
#include <QGraphicsRectItem>
#include <QList>
class level4 : public baselevel // inhert from baselevel
{
    Q_OBJECT
private:
public:
    level4(QGraphicsScene *scene, Game* game);
    void initialize();
};

#endif // LEVEL4_H
