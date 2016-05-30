TEMPLATE = app
CONFIG += console
CONFIG -= c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=gnu++11 -Wall -Wpedantic -Wextra
QMAKE_CXXFLAGS_DEBUG -= -O2
QMAKE_CXXFLAGS_DEBUG += -O0
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
    consumable.cpp \
    menuoption.cpp \
    weapon.cpp \
    fish.cpp \
    stategameover.cpp \
    crab.cpp

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
    consumable.h \
    menuoption.h \
    weapon.h \
    fish.h \
    stategameover.h \
    crab.h

