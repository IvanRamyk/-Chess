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
            auto* newPow = new Pawn(curr);
            this->_board[x][1] = newPow;
        }
        x = 7;
    }

    //rooks adding
    auto* newRook = new Rook(Color::White);
    this->_board[0][0] = newRook;
    newRook = new Rook(Color::White);
    this->_board[7][0] = newRook;

    newRook = new Rook(Color::Black);
    this->_board[0][7] = newRook;
    newRook = new Rook(Color::Black);
    this->_board[7][7] = newRook;

    //knights adding
    auto* newKnight = new Knight(Color::White);
    this->_board[1][0] = newKnight;
    newKnight = new Knight(Color::White);
    this->_board[6][0] = newKnight;

    newKnight = new Knight(Color::Black);
    this->_board[1][7] = newKnight;
    newKnight = new Knight(Color::Black);
    this->_board[6][7] = newKnight;

    //bishops adding
    auto* newBishop = new Bishop(Color::White);
    this->_board[2][0] = newBishop;
    newBishop = new Bishop(Color::White);
    this->_board[5][0] = newBishop;

    newBishop = new Bishop(Color::Black);
    this->_board[2][7] = newBishop;
    newBishop = new Bishop(Color::Black);
    this->_board[5][7] = newBishop;

    //queens adding
    auto* newQueen = new Queen(Color::White);
    this->_board[3][0] = newQueen;

    newQueen = new Queen(Color::Black);
    this->_board[3][7] = newQueen;

    //kings adding
    auto* newKing = new King(Color::White);
    this->_board[4][0] = newQueen;

    newKing = new King(Color::Black);
    this->_board[4][7] = newKing;
}

bool ChessBoard::checkMove(Move move) {
}

matrix* ChessBoard::getBoard() {
    return reinterpret_cast<matrix *>(this->_board);
}