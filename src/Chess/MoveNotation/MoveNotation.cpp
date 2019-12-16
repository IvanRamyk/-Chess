//
// Created by ivan on 10.12.19.
//

#include "MoveNotation.h"

#include <iostream>

MoveNotation::MoveNotation(Move move, bool check, bool checkmate, bool capture, int castle) :_move(move), _check(check),
                                                            _checkmate(checkmate), _capture(capture), _castle(castle) {}

std::string chessVertical(int n){
    std::string answer;
    answer += char('a' + n);
    return answer;
}

char chessFigureNotation(Figure* fg){
    try {
        if (fg->getType() == FigureType::Knight)
            return 'N';
        if (fg->getType() == FigureType::Bishop)
            return 'B';
        if (fg->getType() == FigureType::Rook)
            return 'R';
        if (fg->getType() == FigureType::Queen)
            return 'Q';
        if (fg->getType() == FigureType::King)
            return 'K';
    } catch (std::exception& ex) {
        std::cout << "Wrong figure\n";
    }
}

std::string MoveNotation::getNotation() const{
    if (_castle == 1)
        return "0-0";
    if (_castle == 2)
        return "0-0-0";
    std::string begining{};
    if (_move.getFigure()->getType() == FigureType::Pawn){
        if (_capture)
            begining = chessVertical(_move.getBegin().first) + "-" + chessVertical(_move.getEnd().first);
        else
            begining = chessCoordinates(_move.getEnd());
    }
    else {
        begining = chessFigureNotation(_move.getFigure());
        if (_capture)
            begining += 'x';
        begining += chessCoordinates(_move.getEnd());
    }
    if (_checkmate)
        begining += '#';
    else if (_check){
        begining += '+';
    }
    return begining;
}

Move MoveNotation::getMove() const {
    return this->_move;
}
