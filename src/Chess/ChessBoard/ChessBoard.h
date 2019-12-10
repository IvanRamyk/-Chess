//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_CHESSBOARD_H
#define CH_CHESSBOARD_H

#include "../Figure/Figure.h"
#include "../Move/Move.h"

using matrix = Figure*[8][8];

class ChessBoard {
public:
    ChessBoard();

    [[nodiscard]] bool checkMove(Move move) const;

    matrix* getBoard();

private:
    matrix _board;
};


#endif //CH_CHESSBOARD_H
