#-------------------------------------------------
#
# Project created by QtCreator 2019-07-02T15:22:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = I_AM_GHOST
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        bomb.cpp \
        booming.cpp \
        brain.cpp \
        bucket_ghost.cpp \
        bullet.cpp \
        bullet_breaking.cpp \
        football_ghost.cpp \
        ghost.cpp \
        ghost_die.cpp \
        hat_ghost.cpp \
        ice_bullet.cpp \
        ice_bullet_breaking.cpp \
        ice_shooter.cpp \
        losedialog.cpp \
        main.cpp \
        mainwindow.cpp \
        middledialog.cpp \
        normal_ghost.cpp \
        nut.cpp \
        plant.cpp \
        shooter.cpp \
        startdialog.cpp \
        windialog.cpp

HEADERS += \
        bomb.h \
        booming.h \
        brain.h \
        bucket_ghost.h \
        bullet.h \
        bullet_breaking.h \
        football_ghost.h \
        ghost.h \
        ghost_die.h \
        hat_ghost.h \
        ice_bullet.h \
        ice_bullet_breaking.h \
        ice_shooter.h \
        losedialog.h \
        mainwindow.h \
        middledialog.h \
        normal_ghost.h \
        nut.h \
        plant.h \
        shooter.h \
        startdialog.h \
        windialog.h

FORMS += \
        losedialog.ui \
        mainwindow.ui \
        middledialog.ui \
        startdialog.ui \
        windialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
