#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "C_defs.h"
#include "ChessPiece.h"

typedef struct {
    ChessPiece pieceInSlot;
} ChessBoard;

bool create_chessBoard(ChessBoard chessBoard[8][8], ChessPiece whitePieces[16], ChessPiece blackPieces[16]);
void print_chessBoard(ChessBoard chessBoard[8][8]);

#endif
