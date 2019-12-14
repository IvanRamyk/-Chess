#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include "images.h"
#include <QVector>
#include <QPoint>
#include <QImage>
#include <QPainter>
#include "../src/Chess/ChessGame/ChessGame.h"
#include "../src/Chess/ChessBoard/ChessBoard.h"


class Field
{
    enum State {
        Select,
        Move
    };
public:
    Field(Images* images,int lft, int tp,int wdth,int hgh);
    ~Field(){
        delete images;
    }
    const QImage& getImage() const {
        return *image;
    }
    void redraw(){
        updateField();
        image->fill(0);
        QPainter painter(image);
        for (int i=0;i<8;i++)
                for (int j=0;j<8;j++){
                    //painter.drawRect(QRect(i * cell_width, j * cell_height, cell_width, cell_height),Qt::lightGray);
                    Cell curr = getCell(i, j);
                    Cell::DrawFigure type = curr.getFigure();
                    Color color = curr.getColor();
                    switch(getCell(i,j).getFigure())
                    {
                        case Cell::DrawFigure::Pawn:
                            if (color == Color::Black)
                                painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("black pawn"));
                            else
                                painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("white pawn"));
                        break;
                    case Cell::DrawFigure::Knight:
                        if (color == Color::Black)
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("black knight"));
                        else
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("white knight"));
                    break;
                    case Cell::DrawFigure::Bishop:
                        if (color == Color::Black)
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("black bishop"));
                        else
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("white bishop"));
                    break;
                    case Cell::DrawFigure::Rook:
                        if (color == Color::Black)
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("black rook"));
                        else
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("white rook"));
                    break;
                    case Cell::DrawFigure::Queen:
                        if (color == Color::Black)
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("black queen"));
                        else
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("white queen"));
                    break;
                    case Cell::DrawFigure::King:
                        if (color == Color::Black){
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("black king"));
                        }
                        else {
                            painter.drawImage(QRect(i * cell_width, j * cell_height, cell_width, cell_height),images->get("white king"));
                        }
                    break;
                    default: break;
                    }
                }
    }
    Cell getCell(int x, int y){
        return field[x][y];
    }
    void setCell(int x, int y, Cell cell){
        field[x][y] = cell;
    }
    QPoint getCoordinate(int x, int y){
        if (x < left || x > left + width || y < top || y > top + height)
            return QPoint(-1, -1);
        QPoint res(1.0*(x - left) / cell_width, 1.0*(y - top)/ cell_height);
        return res;
    }
    int getX(){
        return left;
    }
    int getY(){
        return top;
    }
    void updateField(){
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                field[i][j].setFigure(Cell::DrawFigure::None);
        std::cout << "updating\n";
        std::vector<std::string> currentField = game.getField();
        for (auto s : currentField){
            Cell::DrawFigure figure = Cell::DrawFigure::None;
            if (s[0] == 'p') figure = Cell::DrawFigure::Pawn;
            if (s[0] == 'n') figure = Cell::DrawFigure::Knight;
            if (s[0] == 'b') figure = Cell::DrawFigure::Bishop;
            if (s[0] == 'r') figure = Cell::DrawFigure::Rook;
            if (s[0] == 'q') figure = Cell::DrawFigure::Queen;
            if (s[0] == 'k') figure = Cell::DrawFigure::King;
            int x, y;
            x = s[1] - '0';
            y = 7 - (s[2] - '0');
            Color color;
            if (s[3] == 'b') color = Color::Black;
            else color = Color::White;
            setCell(x, y, Cell(color, figure));
        }
    }
    void changeColor(){
        if (moveSide == White)
            moveSide = Black;
        else
            moveSide = White;
    }
    void handleClick(QPoint click){
        int x = click.x(), y = click.y();
        if (state == State::Select){
            if (field[x][y].getFigure() != Cell::DrawFigure::None && field[x][y].getColor() == moveSide){
                selectedCell = {x, y};
                state = Move;
            }
        }
        else if (state == State::Move){
            if (selectedCell.first == x && selectedCell.second == y){
                state = Select;
            }
            else if (game.makeMove({selectedCell.first, 7 - selectedCell.second}, {x, 7 - y})){
                changeColor();
                state = Select;
            }

        }

        redraw();
    }

private:
    Images *images;
    int left, top, width, height, cell_height, cell_width;
    QVector<QVector <Cell>> field;
    QImage *image;
    ChessGame game;
    State state;
    std::pair<int, int> selectedCell;
    Color moveSide;
};

#endif // FIELD_H
