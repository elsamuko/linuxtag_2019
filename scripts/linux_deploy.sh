#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
  echo "Usage: $(basename "$0") <dir>"
  exit 1
fi

DEPLOY_DIR="$1"

if [ ! -d "$DEPLOY_DIR" ]; then
  echo "\"$DEPLOY_DIR\" is not a dir"
  exit 1
fi

QTDIR=~/Qt5.12.4/5.12.4/gcc_64
QT_LIBS=( OpenGL Widgets Gui Core XcbQpa DBus Svg)

cd "$DEPLOY_DIR"
mkdir -p lib
mkdir -p plugins

for LIB in ${QT_LIBS[@]:0};
do
    QT_LIB="libQt5$LIB.so.5"
    cp "$QTDIR/lib/$QT_LIB" "lib/$QT_LIB"
done

ICU_LIBS=( i18n uc data )

for LIB in ${ICU_LIBS[@]:0};
do
    ICU_LIB="libicu$LIB.so.56"
    cp "$QTDIR/lib/$ICU_LIB" "lib/$ICU_LIB"
done

PLUGINS=( imageformats platforms xcbglintegrations )

for PLUGIN in ${PLUGINS[@]:0};
do
    cp -r "$QTDIR/plugins/$PLUGIN" "plugins"
done
