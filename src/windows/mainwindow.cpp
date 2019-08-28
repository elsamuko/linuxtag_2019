#include "mainwindow.hpp"
#include "ui_mainwindow.h"

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
    ui->statusBar->showMessage( "Button was clicked!", 2000 );
}
