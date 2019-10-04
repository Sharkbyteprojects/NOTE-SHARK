#ifndef INIT_H
#define INIT_H/*
#include "mainwindow.h"
#include "ui_mainwindow.h"*/
#endif // INIT_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    numberq = 3;
    ui->spinBox->setValue(0);
    ui->spinBox->setMinimum(0);
    #include "sql-init.h"
    connect(ui->cmdeinfuegen, SIGNAL(clicked()),SLOT(cmdeinfuegenClicked()));
    this->setFixedSize(this->width(), this->height());
 }

MainWindow::~MainWindow()
{
    con.close();
    delete ui;
}
