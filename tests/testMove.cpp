//
// Created by ivan on 10.12.19.
//
#include <gtest/gtest.h>
#include "../src/Chess/Move/Move.h"

TEST(TestMove, TestMoveKnight) {
    Move move({0, 0}, {1, 2}, new Knight(Color::White));
    EXPECT_TRUE(move.getBegin().first == 0 && move.getBegin().second == 0);
    EXPECT_TRUE(move.getEnd().first == 1 && move.getEnd().second == 2);
    EXPECT_TRUE(move.getStockfishMove() == "a1b3");
}

TEST(TestMove, TestMovePawn) {
    Move move({2, 2}, {3, 3}, new Pawn(Color::White));
    EXPECT_TRUE(move.getBegin().first == 2 && move.getBegin().second == 2);
    EXPECT_TRUE(move.getEnd().first == 3 && move.getEnd().second == 3);
    EXPECT_TRUE(move.getStockfishMove() == "c3d4");
}

TEST(TestMove, TestMoveBishop) {
    Move move({4, 4}, {5, 5}, new Bishop(Color::Black));
    EXPECT_TRUE(move.getBegin().first == 4 && move.getBegin().second == 4);
    EXPECT_TRUE(move.getEnd().first == 5 && move.getEnd().second == 5);
    EXPECT_TRUE(move.getStockfishMove() == "e5f6");
}

TEST(TestMove, TestMoveRook) {
    Move move({6, 6}, {7, 7}, new Rook(Color::Black));
    EXPECT_TRUE(move.getBegin().first == 6 && move.getBegin().second == 6);
    EXPECT_TRUE(move.getEnd().first == 7 && move.getEnd().second == 7);
    EXPECT_TRUE(move.getStockfishMove() == "g7h8");
}