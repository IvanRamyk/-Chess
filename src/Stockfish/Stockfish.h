//
// Created by hryhorchuk117 on 15/12/2019.
//

#ifndef QCHESS_STOCKFISH_H
#define QCHESS_STOCKFISH_H

#include <string>

#include "../Chess/ChessGame/ChessGame.h"

class Stockfish {
public:
    explicit Stockfish(ChessGame& game, int depth = 10);

    [[nodiscard]] Move getMove() const;

    [[nodiscard]] double getEvaluation() const;
private:
    const std::string _COMMANDS_PATH = "stockfish-script/commands.txt";
    const std::string _RES_PATH = "stockfish-script/res.txt";

    ChessGame _game;
    std::string _pos;
    double _eval;
    std::string _bestMove;

    std::string getBestMove(int depth);

    double getEval(int depth);
};


#endif //QCHESS_STOCKFISH_H
