#ifndef BASELEVEL_H
#define BASELEVEL_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include "steve.h"
#include "obstacle.h"
#include <QDebug>
#include "game.h"
#include <QMessageBox>
#include<QWidget>
#include "diamonds.h"
#include <QFontDatabase>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include "portal.h"
#include "moving_enemy.h"





class baselevel : public QObject
{
Q_OBJECT
public:
    baselevel(QGraphicsScene *scene, Game *game);
    ~baselevel();
    steve*  getSteve();
    void initialize();
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent *e);
    void setbackground(QGraphicsPixmapItem* x);
    void moveHorizontally();
    void moveVertically();
    void checkcolide();
    void checkgrounded();
    void animate();
    void addobstacle(obstacle* o);
    bool eventFilter(QObject *obj, QEvent *event);
    bool colideright();
    bool colideleft();
    bool colideup();
    bool colidedown();
    void adddiamond(diamonds * d);
    void addportal(portal * p);
    void checkdiamondcolide();
    void checkpaused();
    void back_button();
    void checkend();
    QGraphicsScene* getScene() const;

    void spawn_enemy(moving_enemy* enemy);
    void moveEnemy();
    void checkenemycollision();
public slots:
    // void spawn_enemy();
    //void endGame();
private slots:
    void update();
protected:
    QList<obstacle*> obstacles;
    QList<diamonds*> diamond;
    QList<moving_enemy*> enemies;
    portal* nportal;
private:
    steve *m_steve;
    QGraphicsScene *m_scene;
    Game *m_game;
    QTimer *timer;
    bool leftpressed, rightpressed, spacepressed;
    QGraphicsRectItem* Steve;
    bool ispaused;
    bool pausemenushown = false;
    int pausecount;
    QGraphicsPixmapItem * pause;
    QPushButton* back_button1;
    QGraphicsProxyWidget *proxyButton;
    bool portaltouched;
    int frameCounter;
    int rcount;
    int lcount;

};

#endif // BASELEVEL_H
