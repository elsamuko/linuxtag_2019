QT       += core gui widgets
TEMPLATE = app

MAIN_DIR=..
SRC_DIR=../src
include(setup.pri)

SOURCES += $${SRC_DIR}/windows/windows.cpp
HEADERS += $${SRC_DIR}/windows/mainwindow.hpp
SOURCES += $${SRC_DIR}/windows/mainwindow.cpp
FORMS   += $${SRC_DIR}/windows/mainwindow.ui

RESOURCES += $${MAIN_DIR}/resources/resources.qrc

linux {
    CONFIG(release, debug|release) {
        # search in lib first for missing shared libraries
        QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/lib

        # https://bugs.launchpad.net/ubuntu/+source/glibc/+bug/1737608/comments/4
        QMAKE_LFLAGS += --disable-new-dtags

        # defines, where Qt searches for plugins
        RESOURCES += $${MAIN_DIR}/resources/qtconf.qrc
    }
}
