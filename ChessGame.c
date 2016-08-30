#include <stdio.h>
#include "ChessGame.h"

bool chess_game_loop(int chessBoard[8][8], ChessPiece chessPieces[32]) {
    int moves = 0;
    bool isWhitePlayerTurn = true;
    bool success;
    char playerInput[MAX_INPUT];
    
    for (;;) {
        printf("Player %s turn. Moves made %d\n", (isWhitePlayerTurn ? "1 (White)" : "2 (Black)"), moves);
        gets(playerInput);
        success = handle_player_input(playerInput, chessBoard, chessPieces);
        if (success) {
            moves++;
            isWhitePlayerTurn = !isWhitePlayerTurn;
        }
        else
            printf("Some Error !success\n");
    }
    return true;
}
/*
bool handle_player_input(char playerInput[MAX_INPUT], int chessBoard[8][8], ChessPiece chessPieces[32]) {
    int x1 = playerInput[0] - '0';
    int y1 = playerInput[1] - '0';
    char sp = playerInput[2];
    int x2 = playerInput[3] - '0';
    int y2 = playerInput[4] - '0';
    printf("handle_player_input: %d%d%c%d%d\n", x1,y1,sp,x2,y2);
    
    //if (x1 == 'q' || x1 == 'Q') exit(0);
    
    if (sp != ' ') return false;
    int move_piece = chessBoard[x1][y1];
    chessBoard[x1][y1] = -1;
    chessBoard[x2][y2] = move_piece;
    return true;
}
*/