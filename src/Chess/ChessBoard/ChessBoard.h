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

    [[nodiscard]] std::vector<std::string> getField() const;

    [[nodiscard]] bool isCheck(Move move) const;

    [[nodiscard]] bool isCheckmate(Move move) const;

    [[nodiscard]] bool isCapture(Move move) const;

    //0-0 == 1
    //0-0-0 == 2
    [[nodiscard]] static int isCastle(Move move) ;

    Figure* getFigure(std::pair<int, int> position);

private:
    matrix _board;

    Move _prev;

    [[nodiscard]] bool checkBetween(Move move) const;

    static std::vector<std::pair<int, int>> getBetween(std::pair<int, int> begin, std::pair<int, int> end);

    void pawnTransform(std::pair<int, int> pos, FigureType to);

    static std::string figureToString(std::pair<int, int> pos, Figure* fig);

    //TODO
    FigureType getTypeToTransform() const;
};


#endif //CH_CHESSBOARD_H
