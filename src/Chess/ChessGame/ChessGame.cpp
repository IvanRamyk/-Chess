//
// Created by hryhorchuk117 on 10/12/2019.
//

#include "ChessGame.h"

ChessGame::ChessGame(ChessBoard board): _board(board) {}

bool ChessGame::makeMove(Move move) {
    if (_board.checkMove(move)) {
        _moves.push_back(move);
        return true;
    }
    return false;
}

std::string ChessGame::getMoves() {

}

std::string ChessGame::getStockfishMoves() {

}

