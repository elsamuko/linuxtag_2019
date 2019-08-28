#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow( QWidget* parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow ) {
    ui->setupUi( this );

    ui->pushButton->setIcon( QIcon( ":/icons/icons/circle.png" ) );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    qDebug() << "Button was clicked!";
    ui->statusBar->showMessage( "Button was clicked!", 2000 );
}
