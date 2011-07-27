#-------------------------------------------------
#
# Project created by QtCreator 2011-07-26T20:48:37
#
#-------------------------------------------------

QT       += core gui

TARGET = AnonPlus-BitCoinMiner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    minerclass.cpp \
    miningthread.cpp \
    pool.cpp \
    pools.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    minerclass.h \
    miningthread.h \
    pool.h \
    global.h \
    pools.h

FORMS    += mainwindow.ui \
    aboutdialog.ui
