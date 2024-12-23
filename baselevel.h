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
#include "health.h"
#include <QMouseEvent>
#include <QSoundEffect>
#include "arrow.h"
#include "bow.h"
#include "spikes.h"
#include "fireball.h"
#include "ghast.h"
#include "shop.h"
#include"gun.h"
#include"bullet.h"
#include<vector>
#include "moving_obstacle.h"


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
    void moveObstacle();
    void checkenemycollision();
    void shootarrow();
    void movearrows();
    void checkarrowhitenemy();
    void checkarrowhitobstacle();
    void addbow();


    void checkspikes();
    void addspikes(spikes *s);

    // ghast/fireball implementations
    void addghast(ghast*);
    void shootball();
    void moveBall();
    void checkballcollisions();
    void checkballobstacle();

    void shootgun();
    void movebullets();
    void checkbullethitenemy();


public slots:
    // void spawn_enemy();
    //void endGame();
private slots:
    void update();
    void replaceArrowWithGun();
protected:
    //protected so levels can access them
    QList<obstacle*> obstacles;
    QList<diamonds*> diamond;
    QList<moving_enemy*> enemies;
    QList<arrow*> arrows;
    QList<spikes*> m_spikes;
    QList<ghast*> ghasts;
    QList<bullet*> bullets;
    QList<MovingObstacle*> m_obstacles;

    portal* nportal;
    int floorlevel=0;
    int graceperiod = 1000;
    health h;



private:
    steve *m_steve;
    QGraphicsScene *m_scene;
    Game *m_game;
    QTimer *timer;
    bool leftpressed, rightpressed, spacepressed;
    QGraphicsRectItem* Steve;
    bool ispaused;
    bool isopen;
    bool pausemenushown = false;
    int pausecount;
    QGraphicsPixmapItem * pause;
    QPushButton* back_button1;
    QGraphicsProxyWidget *proxyButton;
    bool portaltouched;
    int frameCounter;
    int rcount;
    int lcount;
    bool inair;
    int jumpcount;
    int maxjump;


    void enableGun();
    bool arrowRemoved = false;
    QGraphicsPixmapItem* arrowItem = nullptr;




    QElapsedTimer invincibilityTimer; // tracks grace period
    // int graceperiod = 1000; i made it protected
    int score;
    QGraphicsTextItem* scoreText;

    int fontId;
    QString fontFamily;
    QSoundEffect *portalsound = new QSoundEffect(this);
    QSoundEffect *explodesound = new QSoundEffect(this);
    //arrow/bow
    bool charging;
    QElapsedTimer chargetime;
    QSoundEffect *bowsound = new QSoundEffect(this);
    QSoundEffect *dingsound = new QSoundEffect(this);

    bow * bowitem;
    gun * gunitem;

    // ghast and fireball
    QSoundEffect *ghastsound = new QSoundEffect(this);
    QSoundEffect *fireballsound = new QSoundEffect(this);

};

#endif // BASELEVEL_H
