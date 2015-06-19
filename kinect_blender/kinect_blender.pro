#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T11:51:53
#
#-------------------------------------------------

QT       += core gui
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kinect_blender
TEMPLATE = app

LIBS += -lfreenect -lusb-1.0 -lglut `pkg-config opencv --cflags --libs`# -lGL -lGLU -lglut

INCLUDEPATH += /usr/include/libusb-1.0

SOURCES += main.cpp\
        mainwindow.cpp \
    opkinect.cpp \
    render.cpp \
    render_window.cpp \
    save_load.cpp \
    vect.cpp \
    skeleton.cpp \
    win_param.cpp \
    progress.cpp \
    vect_f.cpp

HEADERS  += mainwindow.h \
    opkinect.h \
    render.h \
    render_window.h \
    save_load.h \
    vect.h \
    skeleton.h \
    win_param.h \
    progress.h \
    vect_f.h \
    win_size.h

FORMS    += mainwindow.ui
