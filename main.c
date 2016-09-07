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

    if (move_piece == -1) return false;
    if (place_piece != -1 && chessPieces[move_piece].isWhite == chessPieces[place_piece].isWhite) return false;
    
    if (chessPieces[move_piece].type == PAWN) {
        if (chessPieces[move_piece].isWhite) {
            if (x1 > x2) {
                printf ("Pawn cannot move backwards\n");
                return false;
            }
            if (((x2 - x1) > 1 && (x2 - x1) != 2) ||
                ((x2 - x1) == 2 && x1 != 1)) {
                printf("Pawn cannot move more than one place\n");
                return false;  
            }
            if ((y1 != y2 && (x2 - x1) != 1) ||
                (y1 < y2 && (y2 - y1) > 1) ||
                (y2 < y1 && (y1 - y2) > 1)) {
                printf("Pawn can only move one diagonaly\n");
                return false;
            }
            if ((place_piece != -1 && y1 == y2) ||
                ((x2 - x1) == 2 && chessBoard[2][y1] != -1)) {
                printf("Pawn cannot take/overtake a piece in front of it\n");
                return false;
            }
            if (place_piece == -1 && y1 != y2) {
                printf("Pawn can only take another piece on the diagonal\n");
                return false;
            }
            if (x2 == 7) {
                printf("Pawn just became a Queen!\n");
                chessPieces[move_piece].type = QUEEN;
            }
        }
        else { // is Black
            if (x2 > x1) {
                printf("Pawn cannot move backwards\n");
                return false;
            }
            if (((x1 - x2) > 1 && (x1 - x2) != 2) ||
                ((x1 - x2) == 2 && x1 != 6)) {
                printf("Pawn cannot move more than one place\n");
                return false;
            }
            if ((y1 != y2 && (x1 - x2) != 1) ||
                (y1 < y2 && (y2 - y1) > 1) ||
                (y2 < y1 && (y1 - y2) > 1)) {
                printf("Pawn can only move one diagonaly\n");
                return false;
            }
            if ((place_piece != -1 && y1 == y2) ||
                ((x1 - x2) == 2 && chessBoard[5][y1] != -1)) {
                printf("Pawn cannot take/overtake a piece in front of it\n");
                return false;
            }
            if (place_piece == -1 && y1 != y2) {
                printf("Pawn can only take another piece on the diagonal\n");
                return false;
            }
            if (x2 == 0) {
                printf("Pawn just became a Queen!\n");
                chessPieces[move_piece].type = QUEEN;
            }
        }
    }

    else if (chessPieces[move_piece].type == ROOK) {
        if (x1 != x2 && y1 != y2) {
            printf("Rook can only move in a straight line\n");
            return false;
        }
        if (x1 != x2) {
            if (x1 < x2) {
                for (int i = (x1 + 1); i <= (x2 - 1); i++) {
                    if (chessBoard[i][y1] != -1) {
                        printf("Rook cannot overtake another piece\n");
                        return false;
                    }
                }
            }
            else {// x2 > x1
                for (int i = (x1 - 1); i >= (x2 + 1); i--) {
                    if (chessBoard[i][y1] != -1) {
                        printf("Rook cannot overtake another piece\n");
                        return false;
                    }
                }
            }
        }
        else { // y1 != y2
            if (y1 < y2) {
                for (int i = (y1 + 1); i <= (y2 - 1); i++) {
                    if (chessBoard[x1][i] != -1) {
                        printf("Rook cannot overtake another piece\n");
                        return false;
                    }
                }
            }
            else { // y2 < y1
                for (int i = (y1 - 1); i >= (y2 + 1); i--) {
                    if (chessBoard[x1][i] != -1) {
                        printf("Rook cannot overtake another piece\n");
                        return false;
                    }
                }
            }
        }
    }
    

    chessBoard[x1][y1] = -1;
    chessBoard[x2][y2] = move_piece;
    if (place_piece != -1) chessPieces[place_piece].isAlive = false;
    //print_out_chessPieces(chessPieces);
    return true;
}
