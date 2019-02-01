#-------------------------------------------------
#
# Project created by QtCreator 2019-01-30T18:47:15
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SK2Projectv2
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

SOURCES += \
        main.cpp \
        loginwindow.cpp \
    mainwindow.cpp \
    quizchoice.cpp \
    quizdetail.cpp \
    newquestion.cpp \
    gameslist.cpp \
    newgame.cpp \
    gamelobby.cpp

HEADERS += \
        loginwindow.h \
    mainwindow.h \
    quizchoice.h \
    quizdetail.h \
    newquestion.h \
    gameslist.h \
    newgame.h \
    gamelobby.h

FORMS += \
        loginwindow.ui \
    mainwindow.ui \
    quizchoice.ui \
    quizdetail.ui \
    newquestion.ui \
    gameslist.ui \
    newgame.ui \
    gamelobby.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
