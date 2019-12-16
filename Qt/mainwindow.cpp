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
    stockfish_evaluation = new QCheckBox("Stockfish 10", this);
    stockfish_evaluation->setGeometry(width*0.7, height*0.007, width*0.2, width*0.05);
    stockfish_evaluation->setStyleSheet(""
                              "font-size:18pt;\n"
                              "text-align: center;");
    evaluation = new QTextBrowser(this);
    evaluation->clear();
    evaluation->setGeometry(width*0.85, height*0.018, width*0.2, width*0.05);
    evaluation->setStyleSheet("background-color: transparent;\n"
                              "font-size:18pt;\n"
                              "text-align: center;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

