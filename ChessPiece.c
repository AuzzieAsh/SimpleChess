#include "ChessPiece.h"

char* get_piece_type(ChessPiece chessPiece) {
    switch (chessPiece.type) {
        case KING:
        return "KING";
        case QUEEN:
        return "QUEEN";
        case ROOK:
        return "ROOK";
        case BISHOP:
        return "BISHOP";
        case KNIGHT:
        return "KNIGHT";
        case PAWN:
        return "PAWN";
        default:
        return "Not a Type";
    }
}

char* get_piece_colour(ChessPiece chessPiece) {
    switch (chessPiece.colour) {
        case true:
        return "WHITE";
        case false:
        return "BLACK";
        default:
        return "Not a Colour";
    }
}

char* get_piece_status(ChessPiece chessPiece) {
    switch (chessPiece.status) {
        case true:
        return "ALIVE";
        case false:
        return "DEAD";
        default:
        return "Not a Status";
    }
}

bool create_chessPieces(ChessPiece chessPieces[16], bool isWhite) {
    int index = -1;
    
    ChessPiece newPiece = {
        .id = index,
        .type = index,
        .colour = isWhite,
        .status = true
    };
    
    for (index = 0; index < 16; index++) {
        chessPieces[index] = newPiece;
        chessPieces[index].id = index;
    }
    
    for (index = 0; index < 8; index++) {
        chessPieces[index].type = PAWN;
    }
    
    chessPieces[8].type = ROOK;
    chessPieces[15].type = ROOK;
    
    chessPieces[9].type = KNIGHT;
    chessPieces[14].type = KNIGHT;
    
    chessPieces[10].type = BISHOP;
    chessPieces[13].type = BISHOP;
    
    chessPieces[11].type = QUEEN;
    chessPieces[12].type = KING;

    return true;
}

void print_out_chessPieces(ChessPiece chessPieces[16]) {
    int index;
    
    for (index = 0; index < 16; index++) {
        printf("%2d: ", chessPieces[index].id);
        printf("%s ", get_piece_type(chessPieces[index]));
        printf("%s ", get_piece_colour(chessPieces[index]));
        printf("%s\n", get_piece_status(chessPieces[index]));
    }
}