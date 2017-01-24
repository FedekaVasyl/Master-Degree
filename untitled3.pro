#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T16:06:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = untitled3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wirelesssensorsnetwork.cpp \
    coveragearea.cpp \
    sensor.cpp \
    environment.cpp \
    weather.cpp \
    cdo.cpp \
    processor.cpp \
    transferparameters.cpp \
    energyvalue.cpp \
    modelingwindow.cpp \
    imagewindow.cpp \
    graph.cpp \
    qcustomplot.cpp \
    chemicalstatus.cpp \
    randomvalue.cpp

HEADERS  += mainwindow.h \
    wirelesssensorsnetwork.h \
    coveragearea.h \
    sensor.h \
    environment.h \
    weather.h \
    cdo.h \
    processor.h \
    transferparameters.h \
    energyvalue.h \
    modelingwindow.h \
    imagewindow.h \
    graph.h \
    qcustomplot.h \
    chemicalstatus.h \
    randomvalue.h

FORMS    += mainwindow.ui \
    weather.ui \
    cdo.ui \
    processor.ui \
    transferparameters.ui \
    energyvalue.ui \
    modelingwindow.ui \
    imagewindow.ui \
    graph.ui \
    chemicalstatus.ui \
    randomvalue.ui
