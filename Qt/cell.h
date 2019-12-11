#ifndef CELL_H
#define CELL_H

#include <../src/Chess/ChessGame/ChessGame.h>


class Cell
{
public:
    enum DrawFigure{
        None,
        Pawn,
        Knight,
        Bishop,
        Rook,
        Queen,
        King
    };
    Cell(Color cl = Color::White, DrawFigure fg = DrawFigure::None): color(cl), figure(fg) {}
    void setColor(Color cl){
        color = cl;
    }
    Color getColor(){
        return color;
    }
    void setFigure(DrawFigure fg){
        figure = fg;
    }
    DrawFigure getFigure(){
        return figure;
    }
private:
    Color color;
    DrawFigure figure;
};

#endif // CELL_H
