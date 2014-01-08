#-------------------------------------------------
#
# Project created by QtCreator 2014-01-06T05:50:19
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 24Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myprofile.cpp \
    rosetta.cpp \
    counter.cpp \
    gamer.cpp \
    newGamerDialog[Abandon].cpp \
    answersDatabase.cpp \
    infix2postfix.cpp \
    gamerulewindow.cpp

HEADERS  += mainwindow.h \
    myprofile.h \
    rosetta.h \
    counter.h \
    gamer.h \
    newGamerDialog[Abandoned].h \
    answersDatabase.h \
    infix2postfix.h \
    gamerulewindow.h

FORMS    += mainwindow.ui \
    myprofile.ui \
    gamerulewindow.ui

OTHER_FILES += \
    allAnswers.dat
