#include "ChessGame.h"

bool chess_game_loop(int chessBoard[8][8], ChessPiece chessPieces[32]) {
    int moves = 0;
    bool isWhitePlayerTurn = true;
    bool success;
    char playerInput[MAX_INPUT];
    
    print_game_usage();
    
    for (;;) {
        printf("Player %s turn. Moves made %d\n", (isWhitePlayerTurn ? "1 (White)" : "2 (Black)"), moves);
        gets(playerInput);
        success = handle_player_input(playerInput, chessBoard, chessPieces);
        if (success) {
            moves++;
            isWhitePlayerTurn = !isWhitePlayerTurn;
        }
        else
            print_game_usage();
    }
    return true;
}

bool handle_player_input(char playerInput[MAX_INPUT], int chessBoard[8][8], ChessPiece chessPieces[32]) {
    char x1 = playerInput[0] - '0';
    char y1 = playerInput[1];
    char sp = playerInput[2];
    char x2 = playerInput[3] - '0';
    char y2 = playerInput[4];
    printf("%d%c%c%d%c\n", x1,y1,sp,x2,y2);
    
    if (sp != ' ') return false;
    if (x1 <= 0 || x1 > 8) return false;
    return true;
}

void print_game_usage() {
    printf("Usage: x1y1 x2y2\n");
}
