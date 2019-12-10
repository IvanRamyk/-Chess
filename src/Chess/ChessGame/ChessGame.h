//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_CHESSGAME_H
#define CH_CHESSGAME_H

#include <string>
#include <vector>

#include "../ChessBoard/ChessBoard.h"
#include "../Move/Move.h"

class ChessGame {
public:
    explicit ChessGame() = default;
    explicit ChessGame(ChessBoard);

    bool makeMove(Move);

    std::string getMoves();

    std::string getStockfishMoves();

private:
    ChessBoard _board;
    std::vector <Move> _moves;
};


#endif //CH_CHESSGAME_H
