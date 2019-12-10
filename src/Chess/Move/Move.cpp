//
// Created by hryhorchuk117 on 10/12/2019.
//

#include "Move.h"

Move::Move(std::pair<int, int> begin, std::pair<int, int> end, Figure* fig) {
    this->_begin = begin;
    this->_end = end;
    this->_fig = fig;
}

std::pair<int, int> Move::getBegin() const {
    return this->_begin;
}

std::pair<int, int> Move::getEnd() const {
    return this->_end;
}

Figure* Move::getFigure() const {
    return this->_fig;
}

// x-y coordinates to chess-coordinates
std::string chessCoordinates(std::pair<int, int> coordinates) {
    char letter = 'a';
    letter += coordinates.first;
    std::string chessStyle = char(letter) + std::to_string(coordinates.second + 1);
    return chessStyle;
}

std::string Move::getStockfishMove() const {
    return chessCoordinates(this->_begin) + chessCoordinates(this->_end);
}