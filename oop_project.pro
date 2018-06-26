#-------------------------------------------------
#
# Project created by QtCreator 2018-06-16T12:36:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = oop_project
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


SOURCES += main.cpp\
        select_form.cpp \
    dialog_interviewee.cpp \
    dialog_interviewer.cpp \
    interviewer_operations.cpp \
    dialog_manager.cpp \
    manager_operations.cpp \
    admin.cpp \
    interviewee.cpp \
    interviewer.cpp

HEADERS  += select_form.h \
    dialog_interviewee.h \
    dialog_interviewer.h \
    interviewer_operations.h \
    dialog_manager.h \
    manager_operations.h \
    admin.h \
    interviewee.h \
    interviewer.h \
    session.h

FORMS    += select_form.ui \
    dialog_interviewee.ui \
    dialog_interviewer.ui \
    interviewer_operations.ui \
    dialog_manager.ui \
    manager_operations.ui

RESOURCES += \
    resources.qrc
