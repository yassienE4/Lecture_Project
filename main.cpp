#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "mainmenu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //loading screen implementation
    QSplashScreen *loadscreen = new QSplashScreen;
    loadscreen->setPixmap(QPixmap(":/images/loadingscreen.png"));
    loadscreen->show();

    Game game(1280, 720);

    QTimer::singleShot(5000, [loadscreen, &game]()
    {
        loadscreen->finish(&game);
        game.show();
    });


    return a.exec();
}
