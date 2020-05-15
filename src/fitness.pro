#-------------------------------------------------
#
# Project created by QtCreator 2020-05-02T12:58:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fitness
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    neweventcreationform.cpp \
    event.cpp

HEADERS  += mainwindow.h \
    neweventcreationform.h \
    event.h

FORMS    += mainwindow.ui \
    neweventcreationform.ui
