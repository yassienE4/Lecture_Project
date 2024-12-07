#ifndef LEVEL1_H
#define LEVEL1_H
#include "baselevel.h"
#include <QGraphicsRectItem>
#include <QList>
class level1 : public baselevel // inhert from baselevel
{
    Q_OBJECT
private:
public:
    level1(QGraphicsScene *scene, Game* game);
    void initialize();
};

#endif // LEVEL1_H
