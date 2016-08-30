#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "my_bool.h"
#include "ChessPiece.h"

// Populates the chessBoard array, given all 32 pieces from the chessPices array.
void create_chessBoard(int chessBoard[8][8], ChessPiece chessPieces[32]);
// Prints out the chess board to the console, so it is easier for a human to see the state of the game.
void print_out_chessBoard(int chessBoard[8][8], ChessPiece chessPieces[32]);

#endif
