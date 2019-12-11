#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include "images.h"
#include <QVector>
#include <QPoint>
#include <QImage>
#include <QPainter>

class Field
{
public:
    Field(Images* images,int lft, int tp,int wdth,int hgh);
    ~Field(){
        delete images;
    }
    const QImage& getImage() const {
        return *image;
    }
    void redraw(){
        image->fill(0);
        QPainter painter(image);
        for (int i=0;i<8;i++)
                for (int j=0;j<8;j++){
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

private:
    Images *images;
    int left, top, width, height, cell_height, cell_width;
    QVector<QVector <Cell>> field;
    QImage *image;
};

#endif // FIELD_H
