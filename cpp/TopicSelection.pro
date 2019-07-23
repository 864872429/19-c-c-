#-------------------------------------------------
#
# Project created by QtCreator 2019-05-11T09:35:04
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TopicSelection
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
        Fileoperation.cpp \
        Question.cpp \
        add_person.cpp \
        add_problem.cpp \
        admin.cpp \
        form.cpp \
        main.cpp \
        login.cpp \
        mainwindow.cpp \
        password.cpp \
        phone.cpp \
        report.cpp \
        selection.cpp \
        student.cpp \
        submitscore.cpp

HEADERS += \
        Fileoperation.h \
        Question.h \
        add_person.h \
        add_problem.h \
        admin.h \
        form.h \
        login.h \
        mainwindow.h \
        password.h \
        phone.h \
        report.h \
        selection.h \
        student.h \
        submitscore.h \
        tesk.h

FORMS += \
        Question.ui \
        Student.ui \
        add_person.ui \
        add_problem.ui \
        admin.ui \
        form.ui \
        login.ui \
        mainwindow.ui \
        password.ui \
        phone.ui \
        report.ui \
        selection.ui \
        submitscore.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
