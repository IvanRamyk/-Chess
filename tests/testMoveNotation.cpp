//
// Created by ivan on 10.12.19.
//

#include <gtest/gtest.h>
#include "../src/Chess/MoveNotation/MoveNotation.h"
#include <iostream>


TEST(TestMoveNotation, TestMoveKnight) {
    Figure* f = new Knight(Color::Black);
    std::cout << typeid(*f).name() << "  " << typeid(Knight).name() << "\n";
    EXPECT_TRUE(typeid(*f).name() == typeid(Knight).name());
    Move move({0, 0}, {1, 2}, new Knight(Color::White));
    MoveNotation move_note(move);
    std::cout << move_note.getNotation();
    EXPECT_TRUE(move_note.getNotation() == "Nb3");
}