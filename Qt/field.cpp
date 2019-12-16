#include "field.h"
#include <iostream>
#include "../src/Chess/ChessGame/ChessGame.h"
#include "../src/Chess/ChessBoard/ChessBoard.h"

Field::Field(Images* _images,int lft, int tp,int wdth,int hgh):
    images(_images), left(lft), top(tp), width(wdth), height(hgh)
{
    game = ChessGame();
    image = new QImage(width,height,QImage::Format_ARGB32);
    cell_width = width / 8;
    cell_height = height / 8;
    std::cout << cell_width << " " << cell_height << "\n";
    field.resize(8);
    for (auto &i : field)
        i.resize(8);
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
                field[i][j] = Cell(Color::Black, Cell::DrawFigure::None);
    state = State::Select;
    moveSide = Color::White;
    updateField();
}
