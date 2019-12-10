//
// Created by ivan on 10.12.19.
//
#include <gtest/gtest.h>
#include "../src/Chess/Move/Move.h"

TEST(TestMove, TestStockfishConvert) {
    Move move({0, 0}, {1, 2}, new Knight(Color::White));
    EXPECT_TRUE(move.getBegin().first == 0 && move.getBegin().second == 0);
    EXPECT_TRUE(move.getEnd().first == 1 && move.getEnd().second == 2);
    EXPECT_TRUE(move.getStockfishMove() == "a1b3");
}