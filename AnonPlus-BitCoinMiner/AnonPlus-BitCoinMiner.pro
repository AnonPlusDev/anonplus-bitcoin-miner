#-------------------------------------------------
#
# Project created by QtCreator 2011-07-26T20:48:37
#
#-------------------------------------------------

QT       += core gui network

TARGET = AnonPlus-BitCoinMiner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    minerclass.cpp \
    miningthread.cpp \
    global.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    minerclass.h \
    miningthread.h \
    global.h

FORMS    += mainwindow.ui \
    aboutdialog.ui

LIBS += -lqjson
