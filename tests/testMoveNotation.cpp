//
// Created by ivan on 10.12.19.
//

#include <gtest/gtest.h>
#include "../src/Chess/MoveNotation/MoveNotation.h"
#include <iostream>


TEST(TestMoveNotation, TestMoveKnight) {
    auto* knight = new Figure(Color::White, FigureType::Knight);
    Move knight_move({0, 0}, {1, 2}, knight);
    MoveNotation move_note(knight_move);
    EXPECT_TRUE(move_note.getNotation() == "Nb3");
}

TEST(TestMoveNotation, TestPawn){
    auto* pawn = new Figure(Color::White, FigureType::Pawn);
    Move pawn_move({3, 3}, {4, 4}, pawn);
    MoveNotation pawn_capture(pawn_move, false, true, true, 0);
    MoveNotation pawn_check(pawn_move, true, false, true, 0);
    EXPECT_TRUE("d-e#" == pawn_capture.getNotation());
    EXPECT_TRUE("d-e+" == pawn_check.getNotation());
}

TEST(TestMoveNotation, TestBishop){
    auto* bishop = new Figure(Color::White, FigureType::Bishop);
    Move pawn_move({3, 3}, {4, 4}, bishop);
    MoveNotation pawn_capture(pawn_move, false, true, true, 0);
    MoveNotation pawn_check(pawn_move, true, false, false, 0);
    EXPECT_TRUE("Bxe5#" == pawn_capture.getNotation());
    EXPECT_TRUE("Be5+" == pawn_check.getNotation());
}

TEST(TestMoveNotation, TestCastle){
    auto* king = new Figure(Color::White, FigureType::King);
    Move pawn_move({4, 0}, {6, 0}, king);
    MoveNotation pawn_capture(pawn_move, false, false, false, 1);
    MoveNotation pawn_check(pawn_move, false, false, false, 2);
    EXPECT_TRUE("0-0" == pawn_capture.getNotation());
    EXPECT_TRUE("0-0-0" == pawn_check.getNotation());
}

TEST(TestMoveNotation, TestKing){
    auto* king = new Figure(Color::White, FigureType::King);
    Move pawn_move({3, 3}, {4, 4}, king);
    MoveNotation pawn_capture(pawn_move, false, false, false, 0);
    EXPECT_TRUE("Ke5" == pawn_capture.getNotation());
}