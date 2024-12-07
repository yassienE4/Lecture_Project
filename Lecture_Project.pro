QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

ICON = icon.icns
QMAKE_INFO_PLIST = Contents/Resources/Info.plist

SOURCES += \
    arrow.cpp \
    baselevel.cpp \
    bow.cpp \
    bullet.cpp \
    diamonds.cpp \
    fireball.cpp \
    game.cpp \
    ghast.cpp \
    gun.cpp \
    health.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    level4.cpp \
    level5.cpp \
    levelselect.cpp \
    main.cpp \
    mainmenu.cpp \
    moving_enemy.cpp \
    moving_obstacle.cpp \
    obstacle.cpp \
    portal.cpp \
    score.cpp \
    shop.cpp \
    skinselect.cpp \
    spikes.cpp \
    steve.cpp

HEADERS += \
    arrow.h \
    baselevel.h \
    bow.h \
    bullet.h \
    diamonds.h \
    fireball.h \
    game.h \
    ghast.h \
    gun.h \
    health.h \
    level1.h \
    level2.h \
    level3.h \
    level4.h \
    level5.h \
    levelselect.h \
    mainmenu.h \
    moving_enemy.h \
    moving_obstacle.h \
    obstacle.h \
    portal.h \
    score.h \
    shop.h \
    skinselect.h \
    spikes.h \
    steve.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
