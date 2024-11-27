QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baselevel.cpp \
    diamonds.cpp \
    game.cpp \
    health.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    level4.cpp \
    level5.cpp \
    levelselect.cpp \
    main.cpp \
    mainmenu.cpp \
    mobs.cpp \
    moving_enemy.cpp \
    obstacle.cpp \
    portal.cpp \
    score.cpp \
    skinselect.cpp \
    steve.cpp

HEADERS += \
    baselevel.h \
    diamonds.h \
    game.h \
    health.h \
    level1.h \
    level2.h \
    level3.h \
    level4.h \
    level5.h \
    levelselect.h \
    mainmenu.h \
    mobs.h \
    moving_enemy.h \
    obstacle.h \
    portal.h \
    score.h \
    skinselect.h \
    steve.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
