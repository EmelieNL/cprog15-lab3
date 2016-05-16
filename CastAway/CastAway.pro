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
    stateplay.cpp \
    statepausemenu.cpp \
    inventory.cpp \
    item.cpp \
    terrain.cpp \
    tile.cpp \
    creature.cpp \
    player.cpp \
    stateinventory.cpp \
    consumable.cpp

HEADERS += \
    map.h \
    conmanip.h \
    abstractentity.h \
    engine.h \
    blocked.h \
    render.h \
    gamestate.h \
    stateintro.h \
    stateplay.h \
    statepausemenu.h \
    inventory.h \
    item.h \
    terrain.h \
    tile.h \
    creature.h \
    player.h \
    stateinventory.h \
    consumable.h

