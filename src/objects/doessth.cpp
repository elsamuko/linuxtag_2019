#include "doessth.hpp"

#include <QDebug>

DoesSth::DoesSth( QObject* parent ) : QObject( parent ) {

}

void DoesSth::doSth() {
    qDebug() << "I'm doing sth";
    emit signalReady();
}
