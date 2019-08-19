#ifndef CLICKME_HPP
#define CLICKME_HPP

#include <QWidget>

class QPushButton;

class ClickMe : public QWidget {
        Q_OBJECT
    public:
        explicit ClickMe( QWidget* parent = nullptr );

    signals:
        void signalButtonPressed();

    public slots:
    private slots:
        void slotButtonPressed();
    private:
        QPushButton* button;
};

#endif // CLICKME_HPP
