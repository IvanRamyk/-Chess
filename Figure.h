//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_FIGURE_H
#define CH_FIGURE_H


class Figure {
public:
    Figure(int color);
private:
    int _color;
    bool _isMoved;
};

class Pow : public Figure {
    explicit Pow(int color) : Figure(color) {}
};

class Knight : public Figure {
    explicit Knight(int color) : Figure(color) {}
};

class Bishop : public Figure {
    explicit Bishop(int color) : Figure(color) {}
};

class Queen : public Figure {
    explicit Queen(int color) : Figure(color) {}
};

class King : public Figure {
    explicit King(int color) : Figure(color) {}
};
#endif //CH_FIGURE_H
