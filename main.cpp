#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "mainmenu.h"
#include "steve.h"
#include <QIcon>
#include "shop.h"

int steve::skin_static = 1; // sets default skin to steve
int shop::totaldiamonds = 0; // start at 0
bool shop::arrowgravitybought = 0; // didnt buy yet
bool shop::gunbought = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //adding icon to app
    a.setWindowIcon(QIcon(":/images/icon.png"));

    //loading screen implementation
    QSplashScreen *loadscreen = new QSplashScreen;
    loadscreen->setPixmap(QPixmap(":/images/loadingscreen.png").scaled(1280, 720));
    loadscreen->show();

    Game game(1280, 720);

    QTimer::singleShot(100, [loadscreen, &game]()
    {
        loadscreen->finish(&game);
        game.show();
    });


    return a.exec();
}
