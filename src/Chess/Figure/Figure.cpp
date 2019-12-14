//
// Created by hryhorchuk117 on 10/12/2019.
//

#include "Figure.h"

Figure::Figure(Color color, FigureType type) {
    this->_color = color;
    this->_type = type;
    this->_isMoved = false;
}

void Figure::markMoved() {
    this->_isMoved = true;
}

Color Figure::getColor() const {
    return this->_color;
}

bool Figure::isMoved() const {
    return this->_isMoved;
}

FigureType Figure::getType() const {
    return this->_type;
}