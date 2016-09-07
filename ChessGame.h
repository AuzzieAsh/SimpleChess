#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "my_bool.h"
#include "ChessPiece.h"

#define MAX_INPUT 5

bool handle_player_input(char playerInput[MAX_INPUT], int chessBoard[8][8], ChessPiece chessPieces[32]);

#endif
