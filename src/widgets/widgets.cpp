#include <QApplication>
#include <QDebug>
#include <QTimer>

#include "log.hpp"
#include "clickme.hpp"

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
        QApplication a( argc, argv );

        ClickMe clickMe;

        QObject::connect( &clickMe, &ClickMe::signalButtonPressed, qApp, &QCoreApplication::quit );

        clickMe.show();

        rv = a.exec();
    }

    return rv;
}
