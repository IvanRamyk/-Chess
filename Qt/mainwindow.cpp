#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move_color = new QTextBrowser(this);
    notation = new QTextBrowser(this);
    width = 1200;
    height = 0.7 * width;
    this->setFixedSize(width, height);
    left_board = height / 10;
    up_board = height / 10;
    height_board = height * 0.8;
    width_board = height * 0.8;
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

