//
// Created by hryhorchuk117 on 10/12/2019.
//

#include <vector>

#include "ChessBoard.h"

ChessBoard::ChessBoard() {
    //empty cells
    for(auto& i : this->_board) {
        for (auto& j : i) {
            j = nullptr;
        }
    }


    //pawns adding
    int x = 1;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 8; ++i) {
            Color curr = x == 1 ? Color::White : Color::Black;
            auto* newPow = new Pawn(curr);
            this->_board[x][1] = newPow;
        }
        x = 7;
    }

    //rooks adding
    this->_board[0][0] = new Rook(Color::White);
    this->_board[7][0] = new Rook(Color::White);

    this->_board[0][7] = new Rook(Color::Black);
    this->_board[7][7] = new Rook(Color::Black);

    //knights adding
    this->_board[1][0] = new Knight(Color::White);
    this->_board[6][0] = new Knight(Color::White);

    this->_board[1][7] = new Knight(Color::Black);
    this->_board[6][7] = new Knight(Color::Black);

    //bishops adding
    this->_board[2][0] = new Bishop(Color::White);
    this->_board[5][0] = new Bishop(Color::White);

    this->_board[2][7] = new Bishop(Color::Black);
    this->_board[5][7] = new Bishop(Color::Black);

    //queens adding
    this->_board[3][0] = new Queen(Color::White);

    this->_board[3][7] = new Queen(Color::Black);

    //kings adding
    this->_board[4][0] = new King(Color::White);

    this->_board[4][7] = new King(Color::Black);
}

void ChessBoard::makeMove(class Move move) {
    _board[move.getEnd().first][move.getEnd().second] =
            _board[move.getBegin().first][move.getBegin().second];
    _board[move.getBegin().first][move.getBegin().second] = nullptr;

    _board[move.getEnd().first][move.getEnd().second]->markMoved();

}

matrix* ChessBoard::getBoard() {
    return reinterpret_cast<matrix *>(this->_board);
}

std::vector<std::pair<int, int>> getBetween(std::pair<int, int> begin, std::pair<int, int> end) {
    std::vector<std::pair<int, int>> res;
    if (begin.first == end.first) {
        if (begin.second > end.second) {
            std::swap(begin.second, end.second);
        }
        for (int i = begin.second + 1; i < end.second; ++i) {
            res.emplace_back(begin.first, i);
        }
        return res;
    }

    if (begin.second == end.second) {
        if (begin.first > end.first) {
            std::swap(begin.first, end.first);
        }
        for (int i = begin.first + 1; i < end.first; ++i) {
            res.emplace_back(i, begin.second);
        }
        return res;
    }

    if (abs(begin.first - end.first) != abs(begin.second - end.second)) {
        if (begin.first > end.first && begin.second > end.second) {
            int j = 1;
            for (int i = end.first + 1; i < begin.first; ++i) {
                res.emplace_back(i, end.second + j);
                ++j;
            }
            return res;
        }

        if (begin.first > end.first && begin.second < end.second) {
            int j = 1;
            for (int i = end.first + 1; i < begin.first; ++i) {
                res.emplace_back(i, begin.second + j);
                ++j;
            }
            return res;
        }

        if (begin.first < end.first && begin.second > end.second) {
            int j = 1;
            for (int i = begin.first + 1; i < end.first; ++i) {
                res.emplace_back(i, end.second + j);
                ++j;
            }
            return res;
        }

        if (begin.first < end.first && begin.second < end.second) {
            int j = 1;
            for (int i = begin.first + 1; i < end.first; ++i) {
                res.emplace_back(i, begin.second + j);
                ++j;
            }
            return res;
        }
    }

    return res;
}


bool ChessBoard::checkMove(Move move) const {

    if (move.getEnd().first > 7 || move.getEnd().second > 7) {
        return false;
    }

    int begin_x = move.getBegin().first;
    int begin_y = move.getBegin().first;
    int end_x = move.getEnd().first;
    int end_y = move.getEnd().first;

    if (typeid(*move.getFigure()) == typeid(Pawn)) {

    }

    else if (typeid(*move.getFigure()) == typeid(Knight)) {
        return abs(begin_x - end_x) < 3 &&
               abs(begin_y - end_y) < 3 &&
               abs(begin_x - end_x) + abs(begin_y - end_y) == 3 &&

               (this->_board[end_x][end_y] == nullptr ||
               !this->_board[end_x][end_y]->isColor(move.getFigure()));
    }

    else if (typeid(*move.getFigure()) == typeid(Bishop)) {
        if (abs(begin_x - end_x) != abs(begin_y - end_y)) {
            return false;
        }



    }

    else if (typeid(*move.getFigure()) == typeid(Rook)) {

    }

    else if (typeid(*move.getFigure()) == typeid(Queen)) {

    }

    else if (typeid(*move.getFigure()) == typeid(King)) {

    }

    else return false;
}