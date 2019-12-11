#include "field.h"
#include <iostream>

Field::Field(Images* _images,int lft, int tp,int wdth,int hgh):
    images(_images), left(lft), top(tp), width(wdth), height(hgh)
{
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

    field[1][1].setColor(Color::White);
    field[1][1].setFigure(Cell::DrawFigure::King);
    field[0][2].setColor(Color::Black);
    field[0][2].setFigure(Cell::DrawFigure::Queen);
    field[3][2].setColor(Color::Black);
    field[3][2].setFigure(Cell::DrawFigure::Queen);
}
