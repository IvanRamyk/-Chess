//
// Created by hryhorchuk117 on 10/12/2019.
//

#include <vector>
#include <stdexcept>
#include <iostream>

#include "ChessBoard.h"

ChessBoard::ChessBoard() {
    this->_prev = Move();

    //empty cells
    for(auto& i : this->_board) {
        for (auto& j : i) {
            j = nullptr;
        }
    }


    //pawns adding
    int x = 1;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 8; ++i) {
            Color curr = x == 1 ? Color::White : Color::Black;
            this->_board[i][x] = new Figure(curr, FigureType::Pawn);
        }
        x = 6;
    }

    //rooks adding
    this->_board[0][0] = new Figure(Color::White, FigureType::Rook);
    this->_board[7][0] = new Figure(Color::White, FigureType::Rook);

    this->_board[0][7] = new Figure(Color::Black, FigureType::Rook);
    this->_board[7][7] = new Figure(Color::Black, FigureType::Rook);

    //knights adding
    this->_board[1][0] = new Figure(Color::White, FigureType::Knight);
    this->_board[6][0] = new Figure(Color::White, FigureType::Knight);

    this->_board[1][7] = new Figure(Color::Black, FigureType::Knight);
    this->_board[6][7] = new Figure(Color::Black, FigureType::Knight);

    //bishops adding
    this->_board[2][0] = new Figure(Color::White, FigureType::Bishop);
    this->_board[5][0] = new Figure(Color::White, FigureType::Bishop);

    this->_board[2][7] = new Figure(Color::Black, FigureType::Bishop);
    this->_board[5][7] = new Figure(Color::Black, FigureType::Bishop);

    //queens adding
    this->_board[3][0] = new Figure(Color::White, FigureType::Queen);

    this->_board[3][7] = new Figure(Color::Black, FigureType::Queen);

    //kings adding
    this->_board[4][0] = new Figure(Color::White, FigureType::King);

    this->_board[4][7] = new Figure(Color::Black, FigureType::King);
}

void ChessBoard::makeMove(class Move move) {

    //pawn transform
    if (move.getFigure()->getType() == FigureType::Pawn) {
        if ((move.getFigure()->getColor() == Color::White && move.getEnd().second == 7) ||
            (move.getFigure()->getColor() == Color::Black && move.getEnd().second == 0)) {

            pawnTransform(move.getEnd(), move.getFigure()->getType());
        }
    }

    //En passant
    if (move.getFigure()->getType() == FigureType::Pawn && this->_prev.getFigure() &&
            this->_prev.getFigure()->getType() == FigureType::Pawn) {

        int moveDirection = move.getFigure()->getColor() == Color::White ? 1 : -1;
        if (move.getEnd().first == this->_prev.getEnd().first &&
                move.getEnd().second - moveDirection == this->_prev.getEnd().second) {

            this->_board[_prev.getEnd().first][_prev.getEnd().second] = nullptr;
        }
    }

    //castles
    //0-0 is 1
    //0-0-0 is 2
    int castle = isCastle(move);
    if (castle == 1) {
        std::swap(this->_board[move.getBegin().first + 1][move.getBegin().second],
                  this->_board[move.getBegin().first + 3][move.getBegin().second]);
    }

    else if (castle == 2) {
        std::swap(this->_board[move.getBegin().first - 1][move.getBegin().second],
                  this->_board[move.getBegin().first - 4][move.getBegin().second]);
    }

    //TODO check check :)

    _prev = move;
    _board[move.getEnd().first][move.getEnd().second] =
            _board[move.getBegin().first][move.getBegin().second];
    _board[move.getBegin().first][move.getBegin().second] = nullptr;

    _board[move.getEnd().first][move.getEnd().second]->markMoved();
}

//cells between begin and end
std::vector<std::pair<int, int>> ChessBoard::getBetween(std::pair<int, int> begin, std::pair<int, int> end) {
    std::vector<std::pair<int, int>> res;
    if (begin.first == end.first) {
        if (begin.second > end.second) {
            std::swap(begin.second, end.second);
        }
        for (int i = begin.second + 1; i < end.second; ++i) {
            res.emplace_back(begin.first, i);
        }
        return res;
    }

    if (begin.second == end.second) {
        if (begin.first > end.first) {
            std::swap(begin.first, end.first);
        }
        for (int i = begin.first + 1; i < end.first; ++i) {
            res.emplace_back(i, begin.second);
        }
        return res;
    }

    if (abs(begin.first - end.first) != abs(begin.second - end.second)) {
        if (begin.first > end.first && begin.second > end.second) {
            int j = 1;
            for (int i = end.first + 1; i < begin.first; ++i) {
                res.emplace_back(i, end.second + j);
                ++j;
            }
            return res;
        }

        if (begin.first > end.first && begin.second < end.second) {
            int j = 1;
            for (int i = end.first + 1; i < begin.first; ++i) {
                res.emplace_back(i, begin.second + j);
                ++j;
            }
            return res;
        }

        if (begin.first < end.first && begin.second > end.second) {
            int j = 1;
            for (int i = begin.first + 1; i < end.first; ++i) {
                res.emplace_back(i, end.second + j);
                ++j;
            }
            return res;
        }

        if (begin.first < end.first && begin.second < end.second) {
            int j = 1;
            for (int i = begin.first + 1; i < end.first; ++i) {
                res.emplace_back(i, begin.second + j);
                ++j;
            }
            return res;
        }
    }

    return res;
}

bool ChessBoard::checkBetween(Move move) const {
    int end_x = move.getEnd().first;
    int end_y = move.getEnd().second;
    if (this->_board[end_x][end_y] && this->_board[end_x][end_y]->getColor() == move.getFigure()->getColor()) {
        return false;
    }

    auto between = getBetween(move.getBegin(), move.getEnd());
    for (const auto& [x, y] : between) {
        if (this->_board[x][y] && this->_board[x][y]->getColor() == move.getFigure()->getColor()) {
            return false;
        }
    }

    return true;
}


bool ChessBoard::checkMove(Move move) const {

    if (move.getEnd().first > 7 || move.getEnd().second > 7) {
        return false;
    }

    int begin_x = move.getBegin().first;
    int begin_y = move.getBegin().second;
    int end_x = move.getEnd().first;
    int end_y = move.getEnd().second;

    //pawn possible moves
    if (move.getFigure()->getType() == FigureType::Pawn) {
        int step = 1;
        if (move.getFigure()->getColor() == Color::Black) {
            step *= -1;
        }

        if (begin_x == end_x && begin_y + step == end_y) {
            return !this->_board[end_x][end_y];
        }

        if (begin_x == end_x && begin_y + 2 * step == end_y) {
            return !move.getFigure()->isMoved() &&
                   !this->_board[begin_x][begin_y + step] &&
                   !this->_board[begin_x][begin_y + 2 * step];
            }

        if (abs(begin_x - end_x) == 1 && begin_y + step == end_y) {
            if (this->_board[end_x][end_y] && !this->_board[end_x][end_y]->getColor() == move.getFigure()->getColor()) {
                return true;
            }

            else if (this->_prev.getFigure()->getType() == FigureType::Pawn) {
                if (this->_prev.getBegin().first == end_x && this->_prev.getBegin().second == end_y + step &&
                    this->_prev.getEnd().first == end_x && this->_prev.getEnd().second == end_y - step) {

                    return !this->_board[end_x][end_y];
                }
            }

            return false;
        }

        return false;
    }

    //knight possible moves
    else if (move.getFigure()->getType() == FigureType::Knight) {
        return abs(begin_x - end_x) < 3 &&
               abs(begin_y - end_y) < 3 &&
               abs(begin_x - end_x) + abs(begin_y - end_y) == 3 &&

               (this->_board[end_x][end_y] == nullptr ||
               !this->_board[end_x][end_y]->getColor() == move.getFigure()->getColor());
    }

    //bishop possible moves
    else if (move.getFigure()->getType() == FigureType::Bishop) {
        if (abs(begin_x - end_x) != abs(begin_y - end_y)) {
            return false;
        }

        return checkBetween(move);
    }

    //rook possible moves
    else if (move.getFigure()->getType() == FigureType::Rook) {
        if (begin_x != end_x && begin_y != end_y) {
            return false;
        }

        return checkBetween(move);
    }

    //queen possible moves
    else if (move.getFigure()->getType() == FigureType::Queen) {
        if ((begin_x != end_x && begin_y != end_y) &&
                (abs(begin_x - end_x) != abs(begin_y - end_y))) {
            return false;
        }

        return checkBetween(move);
    }

    //king possible moves
    else if (move.getFigure()->getType() == FigureType::King) {
        if (abs(begin_x - end_x) + abs(begin_y - end_y) == 1) {
            return !(this->_board[end_x][end_y] && this->_board[end_x][end_y]->getColor() == move.getFigure()->getColor());
        }

        if (!move.getFigure()->isMoved()) {
            if (begin_x == end_x - 2 && begin_y == end_y) {
                return !this->_board[begin_x + 3][begin_y]->isMoved() &&
                    checkBetween(Move({begin_x, begin_y}, {begin_x + 3, begin_y}, move.getFigure()));
            }
            else if (begin_x == end_x + 2 && begin_y == end_y) {
                return !this->_board[begin_x - 4][begin_y]->isMoved() &&
                        checkBetween(Move({begin_x, begin_y}, {begin_x - 4, begin_y}, move.getFigure()));
            }
        }

        return false;
    }

    else return false;
}

std::vector<std::string> ChessBoard::getField() const {
    std::vector<std::string> res;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            if (_board[i][j] != nullptr){
                res.push_back(figureToString({i, j}, _board[i][j]));
            }
    }

    return res;
}

void ChessBoard::pawnTransform(std::pair<int, int> pos, FigureType to) {
    try {
        if (to == FigureType::King || to == FigureType::Pawn) {

            throw std::invalid_argument("Wrong figure to transform");
        }
        auto *newFig = new Figure(this->_board[pos.first][pos.second]->getColor(), to);
        this->_board[pos.first][pos.second] = newFig;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << "\n";
    }
}

std::string ChessBoard::figureToString(std::pair<int, int> pos, Figure* fig) {
    std::string res{};
    switch (fig->getType()) {
        case Pawn: res += 'p'; break;

        case Rook: res += 'r'; break;

        case Knight: res += 'n'; break;

        case Bishop: res += 'b'; break;

        case Queen: res += 'q'; break;

        case King: res += 'k'; break;
    }

    res += std::to_string(pos.first);
    res += std::to_string(pos.second);

    switch (fig->getColor()) {
        case White: res += 'w'; break;

        case Black: res += 'b'; break;
    }

    return res;
}

Figure *ChessBoard::getFigure(std::pair<int, int> position) {
    return _board[position.first][position.second];
}

bool ChessBoard::isCheck(Color color, std::pair<int, int> kingPos) const {
    if (kingPos.first == -1) {
        kingPos = findKing(color);
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (_board[i][j] && _board[i][j]->getColor() != color) {
                if (checkMove(Move({i, j}, kingPos, _board[i][j]))) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool ChessBoard::isCheckmate(Color color, std::pair<int, int> kingPos) const {

    if (kingPos.first == -1) {
        kingPos = findKing(color);
    }

    if (!isCheck(color, kingPos)) {
        return false;
    }

    for (int x = kingPos.first - 1; x <= kingPos.first + 1; ++x) {
        for (int y = kingPos.second - 1; y <= kingPos.second + 1; ++y) {
            if (!(x == kingPos.first && y == kingPos.second) &&
                checkMove(Move(kingPos, {x, y}, _board[x][y]))) {

                return false;
            }
        }
    }

    return true;
}

bool ChessBoard::isCapture(Move move) const {
    return _board[move.getEnd().first][move.getEnd().second] != nullptr;
}

int ChessBoard::isCastle(Move move) {
    if (move.getFigure()->getType() == FigureType::King && move.getBegin().second == move.getEnd().second) {
        if (abs(move.getEnd().first - move.getBegin().first) == 2) {
            if (move.getEnd().first > move.getBegin().first) {
                for (int x = move.getBegin().first; x <= move.getEnd().first; ++x) {
                    if (isCheck(move.getFigure()->getColor(), {x, move.getBegin().second})) {
                        return 0;
                    }
                }

                return 1;
            }

            else if (move.getEnd().first < move.getBegin().first) {
                for (int x = move.getEnd().first; x <= move.getBegin().first; ++x) {
                    if (isCheck(move.getFigure()->getColor(), {x, move.getBegin().second})) {
                        return 0;
                    }
                }
                return 2;
            }
        }
    }

    return 0;
}

std::pair<int, int> ChessBoard::findKing(Color color) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (this->_board[i][j] && this->_board[i][j]->getType() == FigureType::King &&
                this->_board[i][j]->getColor() == color) {

                return {i, j};
            }
        }
    }

    return {-1 ,-1};
}