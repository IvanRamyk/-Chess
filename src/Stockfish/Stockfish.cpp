//
// Created by hryhorchuk117 on 15/12/2019.
//

#include <fstream>
#include <sstream>

#include "Stockfish.h"

Stockfish::Stockfish(ChessGame &game, int depth) {
    this->_game = game;
    this->_pos = game.getStockfishMoves();
    this->_bestMove = getBestMove(depth);
    this->_eval = getEval(depth);
}

std::string Stockfish::getBestMove(int depth) {
    std::ofstream r(_RES_PATH, std::ofstream::out | std::ofstream::trunc); r.close();
    std::ofstream commands(_COMMANDS_PATH);

    commands << "position startpos moves " << _pos << "\n";
    commands << "go depth " << depth << "\n";
    commands << "quit";
    commands.close();

    system("cd .. && cd src && cd Stockfish && cd stockfish-script && ./script.sh");

    std::ifstream res(_RES_PATH);
    std::string line{};
    while (res) {
        if (line[0] == 'b') {
            break;
        }
        getline(res, line);
    }
    std::string bestMove{};
    std::stringstream ss{line};

    ss >> bestMove >> bestMove;
    return bestMove;
}

double Stockfish::getEval(int depth) {
    std::ofstream r(_RES_PATH, std::ofstream::out | std::ofstream::trunc); r.close();
    std::ofstream commands(_COMMANDS_PATH);

    commands << "position startpos moves " << _pos << "\n";
    commands << "eval depth " << depth << "\n";
    commands << "quit\n";
    commands.close();

    system("cd .. && cd src && cd Stockfish && cd stockfish-script && ./script.sh");

    std::ifstream res(_RES_PATH);
    std::string line{};
    while (res) {
        if (line[0] == 'T') {
            break;
        }
        getline(res, line);
    }
    std::string eval{};
    std::stringstream ss{line};

    while(ss.peek() != ':') {
        ss.ignore();
    }
    ss.ignore();

    double evalRes;
    ss >> evalRes;

    return evalRes;
}

Move Stockfish::getMove() const {
    int x1, x2, y1, y2;
    x1 = _bestMove[0] - 'a';
    x2 = _bestMove[2] - 'a';
    y1 = (int)_bestMove[1] - '0' - 1;
    y2 = (int)_bestMove[3] - '0' - 1;

    return Move({x1, y1}, {x2, y2}, _game.getFigure({x1, x2}));
}

double Stockfish::getEvaluation() const {
    return _eval;
}
