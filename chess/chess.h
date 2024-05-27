#pragma once

#include <iostream>
#include <string>

enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

class Square
{
private:
	Piece piece;
	Color color;
	int x, y;
public:
	void setSpace(Square*);
	void setEmpty();
	void setPC(Piece, Color);
	Piece getPiece();
	Color getColor();
	void setX(int new_x) { x = new_x; }
	void setY(int new_y) { y = new_y; }
	int getX() { return x; }
	int getY() { return y; }
	Square();
};

class Chess
{
private:
	Square board[8][8];
	Color turn=WHITE;
	bool moveKing(Square* king, Square* space);
	bool moveQueen(Square* queen, Square* space);
	bool moveBishop(Square* bishop, Square* space);
	bool moveKnight(Square* knight, Square* space);
	bool moveRook(Square* rook, Square* space);
	bool movePawn(Square* pawn, Square* space);
	bool makeMove(Square* att, Square* vic);
	bool checkMove(int x1, int y1, int x2, int y2);
	void printBoard();
	Square* getSquare(int x, int y) {
		return &board[x][y];
	}
	void setSquare(Square& s, int x, int y) {
		board[x][y] = s;
	}
	bool doMove();
public:

	void setBoard();
	bool play();
};

