#-------------------------------------------------
#
# Project created by QtCreator 2015-06-16T23:40:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candy
TEMPLATE = app


SOURCES += main.cpp\
    stone.cpp \
    normalstone.cpp \
    rowstone.cpp \
    columnstone.cpp \
    tntstone.cpp \
    colarcleanstone.cpp \
    gameing.cpp \
    score.cpp

HEADERS  += \
    normalstone.h \
    rowstone.h \
    columnstone.h \
    tntstone.h \
    colarcleanstone.h \
    gameing.h \
    stong.h \
    score.h

FORMS    += gameing.ui

RESOURCES += \
    pit.qrc
