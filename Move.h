//
// Created by hryhorchuk117 on 10/12/2019.
//

#ifndef CH_MOVE_H
#define CH_MOVE_H

#include <utility>

#include "Figure.h"

class Move {
public:
    Move(std::pair<int, int> _begin, std::pair<int, int> _end, Figure* _fig);

    void GetMove();
private:
    std::pair<int, int> begin;
    std::pair<int, int> end;
    Figure* fig;

    void GetStockFishMove();
};


#endif //CH_MOVE_H
