//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_FIGURE_H
#define CH_FIGURE_H

enum Color {
    White,
    Black
};

enum FigureType {
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};


class Figure {
public:
    explicit Figure(Color color, FigureType type);

    [[nodiscard]] bool isColor(Figure* figure) const;

    [[nodiscard]] bool isMoved() const;

    [[nodiscard]] FigureType getType() const;

    void markMoved();
private:
    FigureType _type;
    Color _color;
    bool _isMoved;

};
/*
class Pawn : public Figure {
public:
    explicit Pawn(Color color) : Figure(color) {}
};

class Knight : public Figure {
public:
    explicit Knight(Color color) : Figure(color) {}
};

class Bishop : public Figure {
public:
    explicit Bishop(Color color) : Figure(color) {}
};

class Rook : public Figure {
public:
    explicit Rook(Color color) : Figure(color) {}
};

class Queen : public Figure {
public:
    explicit Queen(Color color) : Figure(color) {}
};

class King : public Figure {
public:
    explicit King(Color color) : Figure(color) {}
};*/
#endif //CH_FIGURE_H
