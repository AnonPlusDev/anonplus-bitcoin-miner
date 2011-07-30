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
    global.cpp \
    jsonrpccall.cpp \
    connectionform.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    global.h \
    jsonrpccall.h \
    connectionform.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    connectionform.ui

LIBS += -lqjson
