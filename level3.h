#ifndef LEVEL3_H
#define LEVEL3_H

#include "baselevel.h"
#include <QGraphicsRectItem>
#include <QList>
class level3 : public baselevel // inhert from baselevel
{
    Q_OBJECT
private:
public:
    level3(QGraphicsScene *scene, Game* game);
    void initialize();
};

#endif // LEVEL3_H
