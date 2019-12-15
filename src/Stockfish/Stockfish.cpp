//
// Created by hryhorchuk117 on 15/12/2019.
//

#include <fstream>
#include <sstream>

#include "Stockfish.h"

Stockfish::Stockfish(ChessGame &game, int depth) {
    this->_game = game;
    this->_pos = game.getStockfishMoves();
    this->_eval = 0;
    this->_bestMove = getBestMove(depth);
}

std::string Stockfish::getBestMove(int depth) {
    std::ifstream res(_RES_PATH);
    std::ofstream commands(_COMMANDS_PATH);

    commands << "position startpos moves " << _pos << "\n";
    commands << "go depth " << depth << "\n";
    commands << "quit\n";


    system("cd stockfish-script && ./script.sh");

    std::string line{};
    while (res) {
        res >> line;
    }
    std::string bestMove{};
    std::stringstream ss{line};

    ss >> bestMove >> bestMove;
    return bestMove;
}

Move Stockfish::getMove() const {
    int x1, x2, y1, y2;
    x1 = _bestMove[0] - 'a';
    x2 = _bestMove[2] - 'a';
    y1 = (int)_bestMove[1] - '0';
    y2 = (int)_bestMove[3] - '0';

    return Move({x1, y1}, {x2, y2}, _game.getFigure({x1, x2}));
}
