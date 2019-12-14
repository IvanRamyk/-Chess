#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    width = 700;
    height = 700;
    this->setFixedSize(width, height);
    left_board = width / 10;
    up_board = width / 10;
    height_board = width * 0.8;
    width_board = width * 0.8;
    pictures = new Images;
    this->setWindowTitle("Chess");
    pictures->load();
    field = new Field(pictures, left_board, up_board, height_board, width_board);
    field->redraw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

