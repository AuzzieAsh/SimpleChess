#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "my_bool.h"

// Create parameters for all the piece types in a chess game.
typedef enum {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN} PieceType;

// The struct of a chess piece, unique ID, its type, whether it is white or not, and whether it has been taken or not.
typedef struct {
    int id;
    PieceType type;
    bool isWhite;
    bool isAlive;
} ChessPiece;

char* get_piece_type(ChessPiece chessPiece, bool verbose);
char* get_piece_colour(ChessPiece chessPiece, bool verbose);
char* get_piece_status(ChessPiece chessPiece, bool verbose);

void create_chessPieces(ChessPiece chessPieces[32]);
void print_out_chessPieces(ChessPiece chessPieces[32]);

#endif
