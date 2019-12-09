//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_CHESSBOARD_H
#define CH_CHESSBOARD_H

#include "Figure.h"
#include "Move.h"

using matrix = Figure*[8][8];

class ChessBoard {
public:
    ChessBoard();

    bool checkMove(Move move);

private:
    matrix _board;
};


#endif //CH_CHESSBOARD_H
