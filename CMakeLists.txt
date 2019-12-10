cmake_minimum_required(VERSION 3.15)
project(ch)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(ch main.cpp src/Chess/ChessGame/ChessGame.cpp src/Chess/ChessGame/ChessGame.h src/Chess/ChessBoard/ChessBoard.cpp src/Chess/ChessBoard/ChessBoard.h src/Chess/Figure/Figure.cpp src/Chess/Figure/Figure.h src/Chess/Move/Move.cpp src/Chess/Move/Move.h)
target_link_libraries(ch gtest gtest_main)