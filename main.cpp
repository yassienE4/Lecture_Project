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

    Game game(1920, 1080);

    //QTimer::singleShot(2000, [loadscreen, &game]() {
      //  loadscreen->close();
        //game.show();
    //});

    QTimer::singleShot(300,loadscreen,SLOT(close()));
    QTimer::singleShot(300,&game,SLOT(show()));


    return a.exec();
}
