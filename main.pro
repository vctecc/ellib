#-------------------------------------------------
#
# Project created by QtCreator 2018-01-14T20:54:46
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app


SOURCES += main.cpp \
    loginmenu.cpp \
    libraryclient.cpp \
    editdocwindow.cpp \
    filterwindow.cpp \
    database.cpp \
    setting.cpp \
    newdocwindow.cpp

HEADERS  += \
    loginmenu.h \
    libraryclient.h \
    editdocwindow.h \
    filterwindow.h \
    database.h \
    setting.h \
    newdocwindow.h

FORMS    +=
