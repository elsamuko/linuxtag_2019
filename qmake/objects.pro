QT += core

MAIN_DIR=..
SRC_DIR=../src
include(setup.pri)

SOURCES += $${SRC_DIR}/objects/objects.cpp

HEADERS += $${SRC_DIR}/objects/doessth.hpp
SOURCES += $${SRC_DIR}/objects/doessth.cpp

INCLUDEPATH += $${SRC_DIR}/common/
HEADERS += $${SRC_DIR}/common/log.hpp
SOURCES += $${SRC_DIR}/common/log.cpp

DEFINES += 'LOG_FILENAME=\\\"linuxtag.log\\\"'
