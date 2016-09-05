#include <stdio.h>
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "ChessGame.h"

int main(int argc, char **argv) {
    ChessPiece chessPieces[32];
    int chessBoard[8][8];
    
    create_chessPieces(chessPieces);
    print_out_chessPieces(chessPieces);
    
    create_chessBoard(chessBoard, chessPieces);
    
    // ----------------------------------------------

    int moves = 0;
    bool isWhitePlayerTurn = true;
    char playerInput[MAX_INPUT];
    bool success;

    for (;;) {
        print_out_chessBoard(chessBoard, chessPieces);
        printf("Player %s turn. Moves made %d\n", (isWhitePlayerTurn ? "1 (White)" : "2 (Black)"), moves);
        printf("Your move: ");
        gets(playerInput);
        success = handle_player_input(playerInput, chessBoard, chessPieces);
        if (success) {
            moves++;
            isWhitePlayerTurn = !isWhitePlayerTurn;
        }
        else
            printf("Error in player input!\n");
    }

    return 0;
}

bool handle_player_input(char playerInput[MAX_INPUT], int chessBoard[8][8], ChessPiece chessPieces[32]) {
    int x1 = playerInput[0] - '0';
    int y1 = playerInput[1] - '0';
    char sp = playerInput[2];
    int x2 = playerInput[3] - '0';
    int y2 = playerInput[4] - '0';
    
    if (sp != ' ') return false;
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return false;
    if (x1 > 7 || y1 > 7 || x2 > 7 || y2 > 7) return false;
    if (x1 == x2 && y1 == y2) return false;

    int move_piece = chessBoard[x1][y1];
    int place_piece = chessBoard[x2][y2];

    if (chessPieces[move_piece].isWhite == chessPieces[place_piece].isWhite) return false;
    
    if (chessPieces[move_piece].isWhite) {
        if (chessPieces[move_piece].type == PAWN) {
            if (x1 > x2) {
                printf ("Pawn cannot move backwards\n");
                return false;
            }
            if (((x2 - x1) > 1) && (x1 != 1)) {
                printf("Pawn cannot move more than one place\n");
                return false;
            }
        }
    }
    else { // is Black
        if (chessPieces[move_piece].type == PAWN) {
            if (x2 > x1) {
                printf("Pawn cannot move backwards\n");
                return false;
            }
            if (((x1 - x2) > 1) && (x1 != 6)) {
                printf("Pawn cannot move more than one place\n");
                return false;
            }
        }
    }

    chessBoard[x1][y1] = -1;
    chessBoard[x2][y2] = move_piece;
    return true;
}
