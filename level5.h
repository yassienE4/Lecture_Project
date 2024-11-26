#ifndef LEVEL5_H
#define LEVEL5_H

#include "baselevel.h"
#include <QGraphicsRectItem>
#include <QList>
class level5 : public virtual baselevel // inhert from baselevel
{
    Q_OBJECT
private:
public:
    level5(QGraphicsScene *scene, Game* game);
    void initialize();
};

#endif // LEVEL5_H
