#include "ChessBoard.h"

bool create_chessBoard(ChessBoard chessBoard[8][8], ChessPiece whitePieces[16], ChessPiece blackPieces[16]) {
    int row, col;
    ChessPiece emptyPiece = {.id = -1, .type = -1, .colour = -1, .status = false};
    
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            switch (row) {
                case 0:
                chessBoard[row][col].pieceInSlot = whitePieces[8+col];
                break;
                case 1:
                chessBoard[row][col].pieceInSlot = whitePieces[col];
                break;
                case 6:
                chessBoard[row][col].pieceInSlot = blackPieces[col];
                break;
                case 7:
                chessBoard[row][col].pieceInSlot = blackPieces[8+col];
                break;
                default:
                chessBoard[row][col].pieceInSlot = emptyPiece;
                break;
            }
        }
    }
    return true;
}

void print_chessBoard(ChessBoard chessBoard[8][8]) {
    int row, col;
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            printf("[");
            if (chessBoard[row][col].pieceInSlot.status) {
                switch (chessBoard[row][col].pieceInSlot.colour) {
                    case true:
                    printf("W");
                    break;
                    case false:
                    printf("B");
                    break;
                }
                switch (chessBoard[row][col].pieceInSlot.type) {
                    case KING:
                    printf("K");
                    break;
                    case QUEEN:
                    printf("Q");
                    break;
                    case ROOK:
                    printf("R");
                    break;
                    case BISHOP:
                    printf("B");
                    break;
                    case KNIGHT:
                    printf("K");
                    break;
                    case PAWN:
                    printf("P");
                    break;
                }
            }
            if (chessBoard[row][col].pieceInSlot.id == -1) {
                printf("  ");
            }
            printf("]");
        }
        printf("\n");
    }
}
