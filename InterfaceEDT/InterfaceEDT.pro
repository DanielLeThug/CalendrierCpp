#-------------------------------------------------
#
# Project created by QtCreator 2017-01-08T16:43:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterfaceEDT
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
        mainwindow.cpp \
    dialogaffichercours.cpp \
    annee.cpp \
    cours.cpp \
    etudiant.cpp \
    filiere.cpp \
    individu.cpp \
    journee.cpp \
    professeur.cpp \
    salle.cpp \
    semaine.cpp

HEADERS  += mainwindow.h \
    dialogaffichercours.h \
    annee.h \
    cours.h \
    etudiant.h \
    filiere.h \
    individu.h \
    journee.h \
    professeur.h \
    salle.h \
    semaine.h

FORMS    += mainwindow.ui \
    dialogaffichercours.ui