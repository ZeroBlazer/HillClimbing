#-------------------------------------------------
#
# Project created by QtCreator 2014-04-21T09:01:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HillClimbing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myqlabel.cpp \
    graph.cpp \
    headers/avl_tree.cpp \
    headers/nodo.cpp

HEADERS  += mainwindow.h \
    myqlabel.h \
    graph.h \
    headers/avl_tree.h \
    headers/nodo.h

FORMS    += mainwindow.ui
