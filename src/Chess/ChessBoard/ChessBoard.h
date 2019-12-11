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

    void makeMove(Move move);

    [[nodiscard]] bool checkMove(Move move) const;

    matrix* getBoard();

    bool isCheck(Move move){
        return false;
    }

    bool isCheckmate(Move move){
        return false;
    }

    bool isCapture(Move move){
        return _board[move.getEnd().first][move.getEnd().second] != nullptr;
    }

    int isCastle(Move move){
        return 0;
    }

    Figure* getFigure(std::pair<int, int> position);

private:
    matrix _board;

    Move _prev;

    [[nodiscard]] bool checkBetween(Move move) const;

    static std::vector<std::pair<int, int>> getBetween(std::pair<int, int> begin, std::pair<int, int> end);

    void pawnTransform(std::pair<int, int> pos, FigureType to);

    //TODO
    FigureType getTypeToTransform() const;
};


#endif //CH_CHESSBOARD_H
