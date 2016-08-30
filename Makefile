CC = gcc
CFLAGS = -g -Wall
TARGET = Chess

OBJ = \
	main.o \
	ChessPiece.o \
	ChessBoard.o \
	ChessGame.o

default: $(TARGET)

$(TARGET): my_bool.h $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

ChessPiece.o: ChessPiece.c ChessPiece.h
	$(CC) $(CFLAGS) -c ChessPiece.c

ChessBoard.o: ChessBoard.c ChessBoard.h ChessPiece.h
	$(CC) $(CFLAGS) -c ChessBoard.c

ChessGame.o: ChessGame.c ChessGame.h ChessPiece.h
	$(CC) $(CFLAGS) -c ChessGame.c

clean:
	rm -f $(TARGET)
	rm -f *~
	rm -f *.o
