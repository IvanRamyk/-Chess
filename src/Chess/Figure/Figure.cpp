//
// Created by hryhorchuk117 on 10/12/2019.
//

#include "Figure.h"

Figure::Figure(Color color) {
    this->_color = color;
    this->_isMoved = false;
}

void Figure::markMoved() {
    this->_isMoved = true;
}

bool Figure::isColor(Figure* figure) const {
    return this->_color == figure->_color;
}

bool Figure::isMoved() const {
    return this->_isMoved;
}