#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    left_board = 100;
    up_board = 100;
    height_board = 300;
    width_board = 300;
    ui->setupUi(this);
    pictures = new Images;
    pictures->load();
    field = new Field(pictures, left_board, up_board, height_board, width_board);
    field->redraw();
    state = State::Game;
}

MainWindow::~MainWindow()
{
    delete ui;
}

