#include "C_defs.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

int main(int argc, char **argv) {
    ChessPiece chessPieces[32];
    int chessBoard[8][8];
    
    create_chessPieces(chessPieces);
    print_out_chessPieces(chessPieces);
    
    create_chessBoard(chessBoard, chessPieces);
    print_out_chessBoard(chessBoard, chessPieces);
    
    return 0;
}
