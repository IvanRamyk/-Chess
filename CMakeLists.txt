cmake_minimum_required(VERSION 3.15)
project(ch)

set(CMAKE_CXX_STANDARD 17)

add_executable(ch main.cpp ChessGame.cpp ChessGame.h ChessBoard.cpp ChessBoard.h Figure.cpp Figure.h Move.cpp Move.h)