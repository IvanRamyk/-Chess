//
// Created by hryhorchuk117 on 15/12/2019.
//

#include <fstream>
#include <sstream>

#include "Stockfish.h"

Stockfish::Stockfish(const ChessGame &game, int depth) {
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


