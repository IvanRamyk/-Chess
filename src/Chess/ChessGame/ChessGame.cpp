//
// Created by hryhorchuk117 on 10/12/2019.
//

#include "ChessGame.h"

ChessGame::ChessGame(ChessBoard board): _board(board) {}

bool ChessGame::makeMove(Move move) {
    if (!_board.checkMove(move)) {
        return false;
    }

    _board.makeMove(move);

    _moves.push_back(move);
    return true;
}

std::string ChessGame::getMoves() const {

}

std::string ChessGame::getStockfishMoves() const {
    std::string res;
    for (const auto& move : this->_moves) {
        res += move.getStockfishMove();
    }
    return res;
}

