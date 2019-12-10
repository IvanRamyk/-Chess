//
// Created by hryhorchuk117 on 10/12/2019.
//

#include "ChessBoard.h"

ChessBoard::ChessBoard() {
    //empty cells
    for(auto& i : this->_board) {
        for (auto& j : i) {
            j = nullptr;
        }
    }


    //pows adding
    int x = 1;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 8; ++i) {
            Color curr = x == 1 ? Color::White : Color::Black;
            auto* newPow = new Pow(curr);
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

bool ChessBoard::checkMove(Move move) const {
}

matrix* ChessBoard::getBoard() {
    return reinterpret_cast<matrix *>(this->_board);
}