#ifndef LEVEL2_H
#define LEVEL2_H

#include "baselevel.h"
#include <QGraphicsRectItem>
#include <QList>
class level2 : public virtual baselevel // inhert from baselevel
{
    Q_OBJECT
private:
public:
    level2(QGraphicsScene *scene, Game* game);
    void initialize();
};

#endif // LEVEL2_H