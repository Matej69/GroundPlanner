#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T04:49:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Code
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    User/room.cpp \
    User/floor.cpp \
    User/jsonparser.cpp \
    WindowForms/auserwindow.cpp \
    WindowForms/editorwindow.cpp \
    User/global.cpp

HEADERS += \
    User/room.h \
    User/floor.h \
    User/jsonparser.h \
    WindowForms/auserwindow.h \
    WindowForms/editorwindow.h \
    User/global.h

FORMS += \
    WindowForms/auserwindow.ui \
    WindowForms/editorwindow.ui

RESOURCES += \
    Resources/res.qrc
