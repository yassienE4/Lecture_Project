#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "mainmenu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //loading screen implementation
    QSplashScreen *loadscreen = new QSplashScreen;
    loadscreen->setPixmap(QPixmap("/Users/yassien/Desktop/lecture_project/Lecture_Project/loadingscreen.png"));
    loadscreen->show();

    QTimer::singleShot(300,loadscreen,SLOT(close()));


    return a.exec();
}
