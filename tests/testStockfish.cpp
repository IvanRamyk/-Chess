//
// Created by hryhorchuk117 on 15/12/2019.
//

#include <gtest/gtest.h>
#include <utility>

#include "../src/Stockfish/Stockfish.h"

TEST(TestStockfish, TestBestMove) {
    //ChessGame game;
    //Stockfish st(game);
    //EXPECT_TRUE(st.getMove().getBegin() == std::make_pair(4, 1) &&
    //            st.getMove().getEnd() == std::make_pair(4, 3));

    /*game.makeMove({4, 1}, {4, 3});
    //game.makeMove({2, 6}, {2, 4});
    //game.makeMove({6, 0}, {5, 2});
    //game.makeMove({3, 6}, {3, 5});
    //game.makeMove({5, 0}, {2, 3});
    Stockfish st2(game, 15);

    EXPECT_TRUE(st2.getMove().getBegin() == std::make_pair(6, 7) &&
                st2.getMove().getEnd() == std::make_pair(5, 5));
*/}


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