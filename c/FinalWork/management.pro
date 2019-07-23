#-------------------------------------------------
#
# Project created by QtCreator 2019-05-11T09:35:04
#
#-------------------------------------------------

QT       += core gui
QT       += sql
NCLUDEPATH += "./mysqllib/include"
LIBS+= "./mysqllib/lib/libmysql.lib"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = management
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
        add_person.cpp \
        admin.cpp \
        change_person.cpp \
        form.cpp \
        main.cpp \
        login.cpp \
        mainwindow.cpp \
        managemen.cpp \
        password.cpp \
        phone.cpp \
        staff.cpp

HEADERS += \
        add_person.h \
        admin.h \
        change_person.h \
        form.h \
        login.h \
        mainwindow.h \
        managemen.h \
        password.h \
        phone.h \
        staff.h \
        tesk.h

FORMS += \
        add_person.ui \
        admin.ui \
        change_person.ui \
        form.ui \
        login.ui \
        mainwindow.ui \
        managemen.ui \
        password.ui \
        phone.ui \
        staff.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
