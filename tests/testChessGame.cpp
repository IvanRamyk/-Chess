//
// Created by ivan on 10.12.19.
//
#include <gtest/gtest.h>

#include "../src/Chess/ChessGame/ChessGame.h"

TEST(TestChessGame, TestNotaion){
    ChessGame game((ChessBoard()));
    EXPECT_TRUE(game.makeMove({4, 1}, {4, 3}));//a2-a4
    EXPECT_TRUE(game.makeMove({1, 6}, {1, 4}));//c7-c5

    EXPECT_TRUE(game.makeMove({4, 3}, {4, 4}));//Kg1-f3
    EXPECT_TRUE(game.makeMove({1, 4}, {1, 3}));//d7-d6

    EXPECT_TRUE(game.makeMove({1, 1}, {1, 2}));//Сf1-c4
    EXPECT_TRUE(game.makeMove({5, 6}, {5, 4}));//Сf1-c4

    EXPECT_TRUE(game.makeMove({4, 4}, {5, 5}));//Сf1-c4
    std::cout << game.getMoves();
}
