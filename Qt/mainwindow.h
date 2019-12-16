#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMenuBar>
#include <QMouseEvent>
#include <QLabel>
#include <QTextBrowser>
#include <QPoint>
#include <QCheckBox>
#include <string>
#include <iostream>
#include <string>
#include "images.h"
#include "field.h"
#include "../src/Stockfish/Stockfish.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

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
        QString text = "";
        if (field->getColor() == Color::White)
            text = "Black ";
        else
            text = "White ";
        if (field->getState() == State::Checkmate)
            text += "win";
        else
            text += "move";
        if (field->getState() == State::Stalemate) {
            text = "Stalemate";
        }
        move_color->setText(text);
        move_color->show();
        notation->clear();
        notation->setGeometry(left_board + width_board + 0.075 * height, up_board + height * 0.075, height * 0.3, height * 0.7);
        notation->setStyleSheet("background-color: transparent;\n"
                                  "font-size:18pt;\n"
                                  "text-align: center;");
        notation->setText(QString::fromUtf8(field->getNotation().c_str()));
        notation->show();

        evaluation->clear();
        if (stockfish_evaluation->isChecked()){

            evaluation->setGeometry(width*0.85, height*0.018, width*0.2, width*0.05);
            evaluation->setStyleSheet("background-color: transparent;\n"
                                      "font-size:18pt;\n"
                                      "text-align: center;");

            evaluation->setText(QString::fromUtf8((std::to_string(field->getEvaluation())).c_str()));
            evaluation->show();
        }


    }
    void mousePressEvent (QMouseEvent *event) {
        QPoint position=event->pos();
        QPoint on_field = field->getCoordinate(position.x(), position.y());
        if (on_field.x() != -1)
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
    int height, width, left_board, up_board, height_board, width_board;
    QTextBrowser *move_color;
    QTextBrowser *notation;
    QTextBrowser *evaluation;
    QCheckBox *stockfish_evaluation;


};
#endif // MAINWINDOW_H
