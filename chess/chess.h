#pragma once

#include <iostream>
#include <string>

enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

class square
{
	
	Piece piece;
	Color color;
	int x, y;
public:
	void setSpace(square*);
	void setEmpty();
	void setPC(Piece, Color);
	Piece getPiece();
	Color getColor();
	void setX(int new_x) { x = new_x; }
	void setY(int new_y) { y = new_y; }
	int getX() { return x; }
	int getY() { return y; }
	square();
};

class chess
{
	square board[8][8];
	Color turn=WHITE;
	bool moveKing(square* king, square* space);
	bool moveQueen(square* queen, square* space);
	bool moveBishop(square* bishop, square* space);
	bool moveKnight(square* knight, square* space);
	bool moveRook(square* rook, square* space);
	bool movePawn(square* pawn, square* space);
	bool makeMove(square* att, square* vic);
	bool checkMove(int x1, int y1, int x2, int y2);
	void printBoard();
	square* getSquare(int x, int y) {
		return &board[x][y];
	}
	void setSquare(square& s, int x, int y) {
		board[x][y] = s;
	}
	bool doMove();
public:

	void setBoard();
	bool play();
};

