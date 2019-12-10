//
// Created by ivan on 10.12.19.
//

#ifndef CH_MOVENOTATION_H
#define CH_MOVENOTATION_H

#include "../Move/Move.h"


class MoveNotation {
public:
    MoveNotation(Move move, bool check = false, bool checkmate = false, bool capture = false, int castle = 0);

    std::string getNotation() const;

    Move getMove(){
        return _move;
    }
private:
    Move _move;
    bool _check;
    bool _checkmate;
    bool _capture;
    int _castle;
};


#endif //CH_MOVENOTATION_H
