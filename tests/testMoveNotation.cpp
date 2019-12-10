//
// Created by ivan on 10.12.19.
//

#include <gtest/gtest.h>
#include "../src/Chess/MoveNotation/MoveNotation.h"
#include <iostream>


TEST(TestMoveNotation, TestMoveKnight) {
    auto f = new Knight(Color::Black);
    EXPECT_TRUE(typeid(*f).name() == typeid(Knight).name());
    auto k = new Knight(Color::White);
    Move move({0, 0}, {1, 2}, k);
    MoveNotation move_note(move);
    std::cout << move_note.getNotation();
    EXPECT_TRUE(move_note.getNotation() == "Nb3");
}