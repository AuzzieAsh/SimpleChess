#include <stdio.h>
#include "ChessBoard.h"

void create_chessBoard(int chessBoard[8][8], ChessPiece chessPieces[32]) {
    int row, col;
    
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            switch (row) {
            case 0:
                chessBoard[row][col] = chessPieces[8+col].id;
                break;
            case 1:
                chessBoard[row][col] = chessPieces[col].id;
                break;
            case 6:
                chessBoard[row][col] = chessPieces[16+col].id;
                break;
            case 7:
                chessBoard[row][col] = chessPieces[24+col].id;
                break;
            default:
                chessBoard[row][col] = -1;
                break;
            }
        }
    }
}

void print_out_chessBoard(int chessBoard[8][8], ChessPiece chessPieces[32]) {
    int row, col, index;
    
    printf("  ");
    for (col = 0; col < 8; col++) {
        printf("%3d ", col);
    }
    printf("\n");

    for (row = 0; row < 8; row++) {
        printf(" %d ", row);
        for (col = 0; col < 8; col++) {
            printf("[");
            if (chessBoard[row][col] == -1) {
                printf("  ");
            }
            else {
                index = chessBoard[row][col];
                printf("%s", get_piece_colour(chessPieces[index], false));
                printf("%s", get_piece_type(chessPieces[index], false));
            }
            printf("]");
        }
        printf("\n");
    }
}
