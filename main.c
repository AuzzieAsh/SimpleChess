#include "C_defs.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

int main(int argc, char **argv) {
    ChessPiece whitePieces[16];
    ChessPiece blackPieces[16];
    ChessBoard chessBoard[8][8];
    
    create_chessPieces(whitePieces, true);
    create_chessPieces(blackPieces, false);
    
    //print_out_chessPieces(whitePieces);
    //print_out_chessPieces(blackPieces);
    
    create_chessBoard(chessBoard, whitePieces, blackPieces);
    print_chessBoard(chessBoard);
    
    return 0;
}
