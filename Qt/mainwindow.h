#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMenuBar>
#include <QMouseEvent>
#include <QLabel>
#include <QTextBrowser>
#include <QPoint>
#include <string>
#include <iostream>
#include "images.h"
#include "field.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT
enum State {
    Select,
    Move
};

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event){
        QPainter painter(this);
        //painter.drawImage(Qt::AlignCenter,this->menuBar()->geometry().height(),
        painter.drawImage(QRect(left_board, up_board, width_board, height_board),
                              pictures->get("board"));
        painter.drawImage(field->getX(),this->menuBar()
                              ->geometry().height()+field->getY(), field->getImage());
        move_color->clear();
        move_color->setGeometry(left_board, up_board - height * 0.075, width_board, height * 0.05);
        move_color->setStyleSheet("background-color: transparent;\n"
                                  "font-size:18pt;\n"
                                  "text-align: center;");
        if (field->getColor() == Color::White)
            move_color->setText("White move");
        else
            move_color->setText("Black move");
        move_color->show();
        notation->clear();
        notation->setGeometry(left_board + width_board + 0.075 * height, up_board + height * 0.075, height * 0.3, height * 0.7);
        notation->setStyleSheet("background-color: transparent;\n"
                                  "font-size:18pt;\n"
                                  "text-align: center;");
        notation->setText(QString::fromUtf8(field->getNotation().c_str()));
        notation->show();

    }
    void mousePressEvent (QMouseEvent *event) {
        QPoint position=event->pos();
        QPoint on_field = field->getCoordinate(position.x(), position.y());
        field->handleClick(on_field);
        this->update();
    }
private slots:
    void actionStart(){

    }
private:
    Ui::MainWindow *ui;
    Images *pictures;
    Field *field;
    State state;
    int height, width, left_board, up_board, height_board, width_board;
    QTextBrowser *move_color;
    QTextBrowser *notation;

};
#endif // MAINWINDOW_H
