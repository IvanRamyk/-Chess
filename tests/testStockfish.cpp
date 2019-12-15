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
                st.getMove().getBegin() == std::make_pair(4, 3));

    std::cout <<st.getMove().getBegin().first << " " << st.getMove().getBegin().second;
}