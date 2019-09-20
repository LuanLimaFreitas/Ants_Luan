TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    network.cpp \
    ant.cpp \
    parameters.cpp \
    auxiliary_functions.cpp \
    droplet.cpp

HEADERS += \
    auxiliary_functions.h \
    parameters.h \
    resources/parameters.h \
    network.h \
    droplet.h \
    ant.h
