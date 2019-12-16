QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cell.cpp \
    field.cpp \
    images.cpp \
    main.cpp \
    mainwindow.cpp \
    ../src/Chess/ChessGame/ChessGame.cpp \
    ../src/Chess/ChessBoard/ChessBoard.cpp \
    ../src/Chess/Figure/Figure.cpp \
    ../src/Chess/Move/Move.cpp \
    ../src/Chess/MoveNotation/MoveNotation.cpp \
    ../src/Stockfish/Stockfish.cpp

HEADERS += \
    cell.h \
    field.h \
    images.h \
    mainwindow.h \
    ../src/Chess/ChessGame/ChessGame.h \
    ../src/Chess/ChessBoard/ChessBoard.h \
    ../src/Chess/Figure/Figure.h \
    ../src/Chess/Move/Move.h \
    ../src/Chess/MoveNotation/MoveNotaion.h \
    ../src/Stockfish/Stockfish.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    board.png \
    chessboard.png
