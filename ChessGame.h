#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "C_defs.h"
#include "ChessPiece.h"

#define MAX_INPUT 5

bool chess_game_loop(int chessBoard[8][8], ChessPiece chessPieces[32]);
bool handle_player_input(char playerInput[MAX_INPUT], int chessBoard[8][8], ChessPiece chessPieces[32]);
void print_game_usage();

#endif
