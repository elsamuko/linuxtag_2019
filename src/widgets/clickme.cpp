#include "clickme.hpp"

#include <QPushButton>
#include <QDebug>

ClickMe::ClickMe( QWidget* parent ) : QWidget( parent ) {

    resize( 100, 100 );
    move( 500, 500 );

    button = new QPushButton( this );
    button->setText( "Push me!" );

    connect( button, &QPushButton::pressed, this, &ClickMe::slotButtonPressed );
}

void ClickMe::slotButtonPressed() {
    qDebug() << "Button was pressed!";
    emit signalButtonPressed();
}
