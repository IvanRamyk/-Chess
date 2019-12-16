//
// Created by hryhorchuk117 on 10/12/2019.
//

#include "ChessGame.h"

#include <string>
#include <iostream>
#include <utility>

ChessGame::ChessGame(ChessBoard board): _board(std::move(board)) {}

bool ChessGame::makeMove(std::pair <int, int> from, std::pair<int, int> to) {
    Move move(from, to, _board.getFigure(from));
    if (move.getFigure() == nullptr) {
        return false;
    }
    if (!_board.checkMove(move)) {
        std::cout << "check move returns false\n";
        return false;
    }
    bool check = _board.isCheck(move.getFigure()->getColor() == White ? Black : White);
    bool checkmate = _board.isCheckmate(move.getFigure()->getColor() == White ? Black : White);
    bool capture = _board.isCapture(move);
    int castle = _board.isCastle(move);
    if (!_board.makeMove(move)) {
        return false;
    }
    _moves.emplace_back(move, check, checkmate, capture, castle);
    return true;
}


Figure * ChessGame::getFigure(std::pair<int, int> pos) const {
    return _board.getFigure(pos);
}

std::string ChessGame::getMoves() const {
    std::string result;
    for (int i = 0; i < _moves.size(); ++i) {
        if (i % 2 == 0)
            result += (std::to_string(i / 2 + 1) + ". ");
        result += (_moves[i].getNotation() + " ");
        if (i % 2 == 1)
            result += "\n";
    }
    return result;
}

std::string ChessGame::getStockfishMoves() const {
    std::string res;
    for (auto move_notation : this->_moves)
        res += (move_notation.getMove().getStockfishMove() + " ");
    //res.erase(res.end() - 1);
    return res;
}

std::vector<std::string> ChessGame::getField() const {
    return _board.getField();
}

