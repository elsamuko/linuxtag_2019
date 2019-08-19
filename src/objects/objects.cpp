#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

#include "log.hpp"
#include "doessth.hpp"

void logQt( QtMsgType /*type*/, const QMessageLogContext& ctx, const QString& msg ) {
    const char* file = ctx.file ? ctx.file : "qt";
    const char* func = ctx.function ? ctx.function : "qt";
    Logger( file, ctx.line, func ) << msg.toStdString();
}

int main( int argc, char* argv[] ) {

    LOG( "Starting" );
    qInstallMessageHandler( logQt );

    int rv = 0;
    {
        QCoreApplication a( argc, argv );

        DoesSth doesSth;

        QObject::connect( &doesSth, &DoesSth::signalReady, qApp, &QCoreApplication::quit );

        QTimer::singleShot( 1000, [&doesSth] {
            doesSth.doSth();
        } );

        rv = a.exec();
    }

    return rv;
}
