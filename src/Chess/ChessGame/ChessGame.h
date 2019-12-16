//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_CHESSGAME_H
#define CH_CHESSGAME_H

#include <string>
#include <vector>

#include "../ChessBoard/ChessBoard.h"
#include "../Move/Move.h"
#include "../MoveNotation/MoveNotation.h"

class ChessGame {
public:
    explicit ChessGame() = default;
    explicit ChessGame(ChessBoard);

    bool makeMove(std::pair<int,int>, std::pair<int, int>);

    [[nodiscard]] Figure * getFigure(std::pair<int, int> pos) const;

    [[nodiscard]] std::string getMoves() const;

    [[nodiscard]] std::string getStockfishMoves() const;

    [[nodiscard]] std::vector<std::string> getField() const;

    [[nodiscard]] bool isCheckmate(Color color);

private:
    ChessBoard _board;
    std::vector<MoveNotation> _moves;
};


#endif //CH_CHESSGAME_H
