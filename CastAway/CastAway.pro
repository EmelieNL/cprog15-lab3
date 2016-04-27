TEMPLATE = app
CONFIG += console c++14 -Wall -pedantic
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    map.cpp \
    abstractentity.cpp \
    engine.cpp \
    blocked.cpp \
    stateintro.cpp \
    stateplay.cpp

HEADERS += \
    map.h \
    conmanip.h \
    abstractentity.h \
    engine.h \
    blocked.h \
    render.h \
    gamestate.h \
    stateintro.h \
    stateplay.h

