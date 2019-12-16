//
// Created by hryhorchuk117 on 15/12/2019.
//

#include <gtest/gtest.h>
#include <utility>

#include "../src/Stockfish/Stockfish.h"

TEST(TestStockfish, TestBestMove) {
    ChessGame game;
    Stockfish st(game);
    EXPECT_TRUE(st.getMove().getBegin() == std::make_pair(4, 1) &&
                st.getMove().getEnd() == std::make_pair(4, 3));

    game.makeMove({4, 1}, {4, 3});
    game.makeMove({2, 6}, {2, 4});
    game.makeMove({6, 0}, {5, 2});
    game.makeMove({3, 6}, {3, 5});
    game.makeMove({5, 0}, {2, 3});
    Stockfish st2(game, 15);

    EXPECT_TRUE(st2.getMove().getBegin() == std::make_pair(6, 7) &&
                st2.getMove().getEnd() == std::make_pair(5, 5));
}
