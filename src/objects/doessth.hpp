#ifndef DOESSTH_HPP
#define DOESSTH_HPP

#include <QObject>

class DoesSth : public QObject {
        Q_OBJECT
    public:
        explicit DoesSth( QObject* parent = nullptr );

    signals:
        void signalReady();
    public slots:

    public:
        void doSth();
};

#endif // DOESSTH_HPP
