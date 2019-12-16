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


TEST(TestPawnTransform, Pawn) {
    ChessGame game;
    EXPECT_TRUE(game.makeMove({0,1}, {0,3}));
    EXPECT_TRUE(game.makeMove({7,6}, {7,4}));

    EXPECT_TRUE(game.makeMove({0,3}, {0,4}));
    EXPECT_TRUE(game.makeMove({7,4}, {7,3}));

    EXPECT_TRUE(game.makeMove({0,4}, {0,5}));
    EXPECT_TRUE(game.makeMove({7,3}, {7,2}));

    EXPECT_TRUE(game.makeMove({0,5}, {1,6}));
    EXPECT_TRUE(game.makeMove({7,2}, {6,1}));

    EXPECT_TRUE(game.makeMove({1,6}, {0,7}));
    EXPECT_TRUE(game.makeMove({6,1}, {7,0}));
}

TEST(TestPawn, a7pawnTest) {
    ChessGame game;
    EXPECT_TRUE(game.makeMove({1,1}, {1,3}));
    EXPECT_TRUE(game.makeMove({1,6}, {1,4}));

    EXPECT_TRUE(game.makeMove({0,1}, {0,3}));
    EXPECT_TRUE(game.makeMove({0,6}, {0,4}));
}



TEST(Testmate, mate) {
    ChessGame game;
    EXPECT_TRUE(game.makeMove({4,1}, {4,3}));
    EXPECT_TRUE(game.makeMove({1,6}, {1,4}));

    EXPECT_TRUE(game.makeMove({5,0}, {2,3}));
    EXPECT_TRUE(game.makeMove({2,6}, {2,4}));

    EXPECT_TRUE(game.makeMove({3,0}, {5,2}));
    EXPECT_TRUE(game.makeMove({0,6}, {0,4}));

    EXPECT_TRUE(game.makeMove({5,2}, {5,6}));

    EXPECT_TRUE(game.isCheckmate(Color::Black));
}
