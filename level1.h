#ifndef LEVEL1_H
#define LEVEL1_H
#include "baselevel.h"
#include <QGraphicsRectItem>
class level1 : public vritual baselevel // inhert from baselevel
{
    Q_OBJECT
public:
    level1(QGraphicsScene *scene);
    void initialize();
};

#endif // LEVEL1_H
