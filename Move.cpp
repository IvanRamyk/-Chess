//
// Created by hryhorchuk117 on 10/12/2019.
//

#include "Move.h"

Move::Move(std::pair<int, int> begin, std::pair<int, int> end, Figure* fig) {
    this->_begin = begin;
    this->_end = end;
    this->_fig = fig;
}

std::string Move::getMove() {

}

std::pair<int, int> Move::getBegin() {
    return this->_begin;
}

std::pair<int, int> Move::getEnd() {
    return this->_end;
}

// x-y coordinates to chess-coordinates
std::string chessCoordinates(std::pair<int, int> coordinates) {

}

std::string Move::getStockFishMove() {

}