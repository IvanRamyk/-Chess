//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_MOVE_H
#define CH_MOVE_H

#include <utility>
#include <string>

#include "../Figure/Figure.h"


class Move {
public:
    explicit Move() = default;

    explicit Move(std::pair<int, int> begin, std::pair<int, int> end, Figure* fig);

    [[nodiscard]] std::string getStockfishMove() const;

    [[nodiscard]] std::pair<int, int> getBegin() const;

    [[nodiscard]] std::pair<int, int> getEnd() const;

    [[nodiscard]] Figure* getFigure() const;
private:
    std::pair<int, int> _begin;
    std::pair<int, int> _end;
    Figure* _fig{};
};

std::string chessCoordinates(std::pair<int, int>);

#endif //CH_MOVE_H
