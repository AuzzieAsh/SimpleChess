#include <stdio.h>
#include "ChessPiece.h"

/* 
Get the piece type, either the full name or a single character it is based on.
Given the ChessPiece type and whether true or false for verbose.
 */
char* get_piece_type(ChessPiece chessPiece, bool verbose) {
    switch (chessPiece.type) {
    case KING:
        return (verbose ? "King" : "K");
    case QUEEN:
        return (verbose ? "Queen" : "Q");
    case ROOK:
        return (verbose ? "Rook" : "R");
    case BISHOP:
        return (verbose ? "Bishop" : "B");
    case KNIGHT:
    // Knights single character is "N" so not to get confused with the Kings single character
        return (verbose ? "Knight" : "N");
    case PAWN:
        return (verbose ? "Prawn" : "P");
    default:
        return "Error: Not a Type";
    }
}

char* get_piece_colour(ChessPiece chessPiece, bool verbose) {
    switch (chessPiece.isWhite) {
    case true:
        return (verbose ? "White" : "W");
    case false:
        return (verbose ? "Black" : "B");
    default:
        return "Error: Not a Colour";
    }
}

char* get_piece_status(ChessPiece chessPiece, bool verbose) {
    switch (chessPiece.isAlive) {
    case true:
        return (verbose ? "Alive" : "A");
    case false:
        return (verbose ? "Dead" : "D");
    default:
        return "Error: Not a State";
    }
}

void create_chessPieces(ChessPiece chessPieces[32]) {
    int index;
    
    // Set up the White pieces
    ChessPiece whitePiece = {
        .id = -1,
        .type = PAWN,
        .isWhite = true,
        .isAlive = true
    };
    
    for (index = 0; index < 16; index++) {
        chessPieces[index] = whitePiece;
        chessPieces[index].id = index;
    }
    
    chessPieces[8].type = ROOK;
    chessPieces[15].type = ROOK;
    
    chessPieces[9].type = KNIGHT;
    chessPieces[14].type = KNIGHT;
    
    chessPieces[10].type = BISHOP;
    chessPieces[13].type = BISHOP;
    
    chessPieces[11].type = QUEEN;
    chessPieces[12].type = KING;
    
    // Set up the Black pieces
    ChessPiece blackPiece = {
        .id = -1,
        .type = PAWN,
        .isWhite = false,
        .isAlive = true
    };
    
    for (index = 16; index < 32; index++) {
        chessPieces[index] = blackPiece;
        chessPieces[index].id = index;
    }
    
    chessPieces[24].type = ROOK;
    chessPieces[31].type = ROOK;
    
    chessPieces[25].type = KNIGHT;
    chessPieces[30].type = KNIGHT;
    
    chessPieces[26].type = BISHOP;
    chessPieces[29].type = BISHOP;
    
    chessPieces[27].type = QUEEN;
    chessPieces[28].type = KING;
}

void print_out_chessPieces(ChessPiece chessPieces[32]) {
    int index;
    
    for (index = 0; index < 32; index++) {
        printf("%2d: ", chessPieces[index].id);
        printf("%s ", get_piece_type(chessPieces[index], true));
        printf("%s ", get_piece_colour(chessPieces[index], true));
        printf("%s\n", get_piece_status(chessPieces[index], true));
        //if (index == 15) puts("");
    }
}
