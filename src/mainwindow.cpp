#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "MainWindow constructor";

    ui->setupUi(this);

    // Create RosThread
    this->rost = new RosThread();
    connect(this, SIGNAL(message(QString)), this->rost, SLOT(addLine(QString)));
    connect(this, SIGNAL(message1(QString)), this->rost, SLOT(addLine(QString)));
     // start begins periodically executing the run() function
    this->rost->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{
    QString qstring = "1";
    emit message( qstring );

}

void MainWindow::on_pushButton_2_pressed()
{
    QString qstring = "2";
    emit message1( qstring );
}
