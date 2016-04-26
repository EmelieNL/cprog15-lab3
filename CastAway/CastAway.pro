TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    map.cpp \
    abstractentity.cpp \
    engine.cpp \
    blocked.cpp \
    stateintro.cpp

HEADERS += \
    map.h \
    conmanip.h \
    abstractentity.h \
    engine.h \
    blocked.h \
    render.h \
    gamestate.h \
    stateintro.h

