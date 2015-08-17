#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "C_defs.h"

typedef enum {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN} PieceType;

typedef struct {
    int id;
    PieceType type;
    bool colour;
    bool status;
} ChessPiece;

char* get_piece_type(ChessPiece chessPiece);
char* get_piece_colour(ChessPiece chessPiece);
char* get_piece_status(ChessPiece chessPiece);

bool create_chessPieces(ChessPiece chessPieces[16], bool isWhite);
void print_out_chessPieces(ChessPiece chessPieces[16]);

#endif
