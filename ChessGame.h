//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_CHESSGAME_H
#define CH_CHESSGAME_H

#include <string>

#include "ChessBoard.h"
#include "Move.h"

class ChessGame {
public:
    ChessGame(ChessBoard);

    void MakeMove(Move);

private:
    ChessBoard board;
    std::string moveOrder;
};


#endif //CH_CHESSGAME_H
