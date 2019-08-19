QT += core gui widgets

MAIN_DIR=..
SRC_DIR=../src
include(setup.pri)

SOURCES += $${SRC_DIR}/widgets/widgets.cpp

SOURCES += $${SRC_DIR}/widgets/clickme.cpp
HEADERS += $${SRC_DIR}/widgets/clickme.hpp

INCLUDEPATH += $${SRC_DIR}/common/
HEADERS += $${SRC_DIR}/common/log.hpp
SOURCES += $${SRC_DIR}/common/log.cpp

DEFINES += 'LOG_FILENAME=\\\"linuxtag.log\\\"'
