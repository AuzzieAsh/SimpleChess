#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "C_defs.h"

typedef enum {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN} PieceType;

typedef struct {
    int id;
    PieceType type;
    bool isWhite;
    bool isAlive;
} ChessPiece;

char* get_piece_type(ChessPiece chessPiece);
char* get_piece_colour(ChessPiece chessPiece);
char* get_piece_status(ChessPiece chessPiece);

void create_chessPieces(ChessPiece chessPieces[32]);
void print_out_chessPieces(ChessPiece chessPieces[32]);

#endif
