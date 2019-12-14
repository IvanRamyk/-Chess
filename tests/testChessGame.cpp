//
// Created by ivan on 10.12.19.
//
#include <gtest/gtest.h>

#include "../src/Chess/ChessGame/ChessGame.h"

TEST(TestChessGame, TestNotaion){
    ChessGame game((ChessBoard()));
    EXPECT_TRUE(game.makeMove({4, 1}, {4, 3}));//a2-a4
    EXPECT_TRUE(game.makeMove({2, 6}, {2, 4}));//c7-c5
    EXPECT_TRUE(game.makeMove({6, 0}, {5, 2}));//Kg1-f3
    EXPECT_TRUE(game.makeMove({3, 6}, {3, 5}));//d7-d6
    EXPECT_TRUE(game.makeMove({5, 0}, {2, 3}));//Сf1-c4
    std::cout << game.getMoves();
}
