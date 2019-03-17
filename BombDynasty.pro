#-------------------------------------------------
#
# Project created by QtCreator 2019-02-10T17:31:53
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BombDynasty
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG+= static

SOURCES += \
        main.cpp \
        welcomepage.cpp \
    bomb.cpp \
    player.cpp \
    gameframe2.cpp \
    graph.cpp
    

HEADERS += \
        welcomepage.h \
    bomb.h \
    player.h \
    gameframe2.h \
    icon.h \
    graph.h
    

FORMS += \
        welcomepage.ui \
    gameframe2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/bomb+1.jpg \
    icons/freeze.jpg \
    icons/ghost.jpg \
    icons/powerup.jpg \
    icons/push.jpg \
    icons/reverse.jpg \
    icons/shield.jpg

RESOURCES += \
    res.qrc
