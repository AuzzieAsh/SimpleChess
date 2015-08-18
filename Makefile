CC = gcc
CFLAGS = -g -Wall
TARGET = Chess

OBJ = \
	main.o \
	ChessPiece.o \
	ChessBoard.o

default: $(TARGET)

$(TARGET): C_defs.h $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

ChessPiece.o: ChessPiece.c ChessPiece.h
	$(CC) $(CFLAGS) -c ChessPiece.c

ChessBoard.o: ChessBoard.c ChessBoard.h ChessPiece.h
	$(CC) $(CFLAGS) -c ChessBoard.c

clean:
	rm -f $(TARGET)
	rm -f $(TARGET).exe
	rm -f *~
	rm -f *.o
	rm -f .DS_Store
