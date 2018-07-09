#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lift = new Lift(NULL);
}

MainWindow::~MainWindow()
{
    delete lift;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    lift->onPushButton(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    lift->onPushButton(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    lift->onPushButton(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    lift->onPushButton(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    lift->onPushButton(5);
}

