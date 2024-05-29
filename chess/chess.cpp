#include "chess.h"


Square::Square()
{
	piece = EMPTY;
	color = NONE;
	x = 0;
	y = 0;
}

void Square::setSpace(Square* space)
{
	color = space->getColor();
	piece = space->getPiece();
}

void Square::setEmpty()
{
	color = NONE;
	piece = EMPTY;
}

Piece Square::getPiece()
{
	return piece;
}

Color Square::getColor()
{
	return color;
}

void Square::setPC(Piece p, Color c)
{
	piece = p;
	color = c;

}

void Chess::printBoard() {
	//Функция вывода текущего состояния шахматной доски в консоль
	using namespace std;
	cout << "   x: a  b  c  d  e  f  g  h " << endl << "y:" << endl;
	for (int i = 7; i >= 0; i--)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 8; j++)
		{
			Piece p = board[j][i].getPiece();
			Color c = board[j][i].getColor();

			switch (p)
			{
			//Конструкция swith-case для определения фигуры на клетке. Верхний регистр - белые фигуры, нижний регистр - черные фигуры.
			case KING: (c == WHITE) ? cout << " K " : cout << " k ";
				break;
			case QUEEN: (c == WHITE) ? cout << " Q " : cout << " q ";
				break;
			case BISHOP:(c == WHITE) ? cout << " B " : cout << " b ";
				break;
			case KNIGHT:(c == WHITE) ? cout << " H " : cout << " h ";
				break;
			case ROOK: (c == WHITE) ? cout << " R " : cout << " r ";
				break;
			case PAWN: (c == WHITE) ? cout << " P " : cout << " p ";
				break;
			case EMPTY: cout << " " << char(254) << " ";
				break;
			default: cout << "XXX";
				break;
			}

		}
		cout << endl;
	}

}

bool Chess::doMove() {
	//Функция, которая реализовывает совершения хода. При ее выполнении программа будет запрашивать координаты и перемещать фигуры на доске
	using namespace std;
	string move;
	int x1, x2, y1, y2;
	bool globstop = false;
	while (!globstop)
	{
		//Цикл, работающий до тех пор, пока не будет совершен ход
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		bool cinstop = false;
		while (!cinstop)
		{
			//Цикл, работающий до тех пор, пока не будут введены корректные координаты
			cout << "Type in your move as a single four character string. The input should be of the form x1y1x2y2." << endl;
			cin >> move;
			if (move.length() == 4)
				if (move[0] >= 97 and move[2] >= 97 and move[0] <= 104 and move[2] <= 104 and move[1] >= 48 and move[3] >= 48 and move[1] <= 55 and move[3] <= 55 and not(move[0] == move[2] and move[1] == move[3]))
					cinstop = true;
				else
					cout << "Input contains invalid characters or an invalid sequence" << endl;
			else
				cout << "Too few/Too many characters" << endl;
		}
		x1 = move[0] - 97;
		y1 = move[1] - 48;
		x2 = move[2] - 97;
		y2 = move[3] - 48;
		Square* att = getSquare(x1, y1); //Перемещаемая/атакующая фигура
		Square* vic = getSquare(x2, y2); //Простанство/атакуемая фигура
		if (att->getColor() == turn)
		{
			//Проверка на соответствие цвета атакующей фигуры цвету текущего игрока
			if (!(att->getColor() == vic->getColor() and vic->getColor() != NONE))
			{
				//Проверка на атаку дружественной фигуры
				
				switch (vic->getPiece())
				{
				case KING:
					//Если атакуют короля
					if (att->getColor() == WHITE)
						//Если атакуют короля белых
					{
						if (makeMove(att, vic))
						{
							//Если ход возможен и был совершен
							cout << "WHITE WINS" << endl; //Победа белых и завершение партии
							return false;
						}
						else
							cout << "Invalid move, this piece doesn't walk like that." << endl;
					}
					else
					{
						//Если атакуют короля черных
						if (makeMove(att, vic))
						{
							//Если ход возможен и был совершен
							cout << "BLACK WINS" << endl; //Победа черных и завершение партии
							return false;
						}
						else
							cout << "Invalid move, this piece doesn't walk like that." << endl;
					}
					break;
				default:
					if (makeMove(att, vic))
					{
						//Если ход возможен и был совершен
						globstop = true;
					}
					else
						cout << "Invalid move, this piece doesn't walk like that." << endl;
					break;
				}
			}
			else
				cout << "Invalid move: cannot land on your own piece" << endl;
		}
		else
			cout << "That's not your piece. Try again." << endl;
	}
	//Переход хода следующему игроку
	if (turn == BLACK)
		turn = WHITE;
	else
		turn = BLACK;

	return true;
}

void Chess::setBoard()
{
	board[0][0].setPC(ROOK, WHITE);
	board[1][0].setPC(KNIGHT, WHITE);
	board[2][0].setPC(BISHOP, WHITE);
	board[3][0].setPC(QUEEN, WHITE);
	board[4][0].setPC(KING, WHITE);
	board[5][0].setPC(BISHOP, WHITE);
	board[6][0].setPC(KNIGHT, WHITE);
	board[7][0].setPC(ROOK, WHITE);

	board[0][7].setPC(ROOK, BLACK);
	board[1][7].setPC(KNIGHT, BLACK);
	board[2][7].setPC(BISHOP, BLACK);
	board[3][7].setPC(QUEEN, BLACK);
	board[4][7].setPC(KING, BLACK);
	board[5][7].setPC(BISHOP, BLACK);
	board[6][7].setPC(KNIGHT, BLACK);
	board[7][7].setPC(ROOK, BLACK);

	for (int i = 0; i < 8; i++)
	{
		board[i][1].setPC(PAWN, WHITE);
		board[i][6].setPC(PAWN, BLACK);

	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			board[j][i].setPC(EMPTY, NONE);

	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			board[i][j].setX(i);
			board[i][j].setY(j);
		}

}

bool Chess::play()
{
	system("cls");		//Очищение консоли
	printBoard();		//Вывод шахматной доски в консоль
	return doMove();	//Возвращение необходимости продолжать игру, вернется false при завершении партии
}

bool Chess::moveKing(Square* king, Square* space)
{
	int kingX = king->getX();
	int kingY = king->getY();
	int spaceX = space->getX();
	int spaceY = space->getY();
	if (( (abs(spaceX - kingX == 1) and (abs(spaceY - kingY) == 0)) or ((abs(spaceX - kingX) == 0) and (abs(spaceY - kingY) == 1)) or ((abs(spaceX - kingX) == 1) and (abs(spaceY - kingY) == 1))))
		{//Условия законности хода короля
			space->setSpace(king); //Перемещение фигуры на клетку space
			king->setEmpty();	   //Клетка перемещающейся фигуры становится свободной
			return true;
		}
		else return false;
}
bool Chess::moveQueen(Square* queen, Square* space) {
	int queenX = queen->getX();
	int queenY = queen->getY();
	int spaceX = space->getX();
	int spaceY = space->getY();
	int yIncrement;
	int xIncrement;

	if (queenX != spaceX or queenY != spaceY)
	{

		if (queenX == spaceX)
		{//Движение по оси OY
			yIncrement = (spaceY - queenY) / (abs(spaceY - queenY)); //Вычисление инкремента, для проверки наличия препятствий при движении вдоль оси OY
			for (int i = queenY + yIncrement; i != spaceY; i += yIncrement)
			{

				if (board[spaceX][i].getColor() != NONE) //Если на пути движения фигуры присутствует препятствие
					return false;

			}
		}
		else
			if (queenY == spaceY)
			{//Движение по оси OX

				xIncrement = (spaceX - queenX) / (abs(spaceX - queenX)); //Вычисление инкремента, для проверки наличия препятствий при движении вдоль оси OX
				for (int i = queenX + xIncrement; i != spaceX; i += xIncrement)
				{
					if (board[i][spaceY].getColor() != NONE) //Если на пути движения фигуры присутствует препятствие
						return false;
				}
			}
			else
				if (abs(queenX - spaceX) == abs(queenY - spaceY))
				{//Движение по диагонали
					xIncrement = (spaceX - queenX) / (abs(spaceX - queenX)); //Вычисление инкремента, для проверки наличия препятствий при движении по диагонали
					yIncrement = (spaceY - queenY) / (abs(spaceY - queenY)); //Вычисление инкремента, для проверки наличия препятствий при движении по диагонали

					for (int i = 1; i < abs(queenX - spaceX); i++)
					{
						if (board[queenX + xIncrement*i][queenY + yIncrement*i].getColor() != NONE) //Если на пути движения фигуры присутствует препятствие
							return false;

					}
				}
				else
					return false;
	}

	space->setSpace(queen); //Перемещение фигуры на клетку space
	queen->setEmpty();      //Клетка перемещающейся фигуры становится свободной
	return true;
}

bool Chess::moveBishop(Square* bishop, Square* space) {
	int bishopX = bishop->getX();
	int bishopY = bishop->getY();
	int spaceX = space->getX();
	int spaceY = space->getY();

	if (abs(bishopX - spaceX) == abs(bishopY - spaceY))
	{//Движение по диагонали
		int xIncrement = (spaceX - bishopX) / (abs(spaceX - bishopX)); //Вычисление инкремента, для проверки наличия препятствий при движении по диагонали
		int yIncrement = (spaceY - bishopY) / (abs(spaceY - bishopY)); //Вычисление инкремента, для проверки наличия препятствий при движении по диагонали

		for (int i = 1; i < abs(bishopX - spaceX); i++)
		{
			if (board[bishopX + xIncrement*i][bishopY + yIncrement*i].getColor() != NONE) //Если на пути движения фигуры присутствует препятствие
				return false;

		}
	}
	else
		return false;

	space->setSpace(bishop); //Перемещение фигуры на клетку space
	bishop->setEmpty();      //Клетка перемещающейся фигуры становится свободной
	return true;
}
bool Chess::moveKnight(Square* knight, Square* space)
{
	int knightX = knight->getX();
	int knightY = knight->getY();
	int spaceX = space->getX();
	int spaceY = space->getY();

	if ((abs(knightX - spaceX) == 2 and abs(knightY - spaceY) == 1) or (abs(knightX - spaceX) == 1 and abs(knightY - spaceY) == 2))
	{//Условия законности хода для коня
		space->setSpace(knight); //Перемещение фигуры на клетку space
		knight->setEmpty();      //Клетка перемещающейся фигуры становится свободной
		return true;
	}
	else
	{
		return false;
	}
}

bool Chess::moveRook(Square* rook, Square* space)
{
	int rookX = rook->getX();
	int rookY = rook->getY();
	int spaceX = space->getX();
	int spaceY = space->getY();
	if (rookX != spaceX or rookY != spaceY)
	{

		if (rookX == spaceX)
		{//Движение по оси OY
			int yIncrement = (spaceY - rookY) / (abs(spaceY - rookY)); //Вычисление инкремента, для проверки наличия препятствий при движении вдоль оси OY
			for (int i = rookY + yIncrement; i != spaceY; i += yIncrement)
			{

				if (board[spaceX][i].getColor() != NONE) //Если на пути движения фигуры присутствует препятствие
					return false;

			}
		}
		else
			if (rookY == spaceY)
			{//Движение по оси OX

				int xIncrement = (spaceX - rookX) / (abs(spaceX - rookX)); //Вычисление инкремента, для проверки наличия препятствий при движении вдоль оси OX
				for (int i = rookX + xIncrement; i != spaceX; i += xIncrement)
				{
					if (board[i][spaceY].getColor() != NONE) //Если на пути движения фигуры присутствует препятствие
						return false;
				}
			}
			else
				return false;
	}
	space->setSpace(rook); //Перемещение фигуры на клетку space
	rook->setEmpty();      //Клетка перемещающейся фигуры становится свободной
	return true;
}

bool Chess::movePawn(Square* pawn, Square* space) {
	using namespace std;
	int pawnX = pawn->getX();
	int pawnY = pawn->getY();
	Color pawnC = pawn->getColor();
	int spaceX = space->getX();
	int spaceY = space->getY();
	Color spaceC = space->getColor();

	if (pawnC == WHITE)
	{//Если цвет пешки белый

		if (pawnX == spaceX and spaceY == pawnY + 1 and spaceC == NONE)
		{//Движение по оси OY
			space->setSpace(pawn); //Перемещение фигуры на клетку space
			pawn->setEmpty();      //Клетка перемещающейся фигуры становится свободной
			return true;
		}
		else
			if ((pawnX + 1 == spaceX or pawnX - 1 == spaceX) and pawnY + 1 == spaceY and spaceC == BLACK)
			{//Если ход совершается на вражескую фигуру по диагонали
				space->setSpace(pawn); //Перемещение фигуры на клетку space
				pawn->setEmpty();      //Клетка перемещающейся фигуры становится свободной
				return true;
			}
			else
				return false;
	}
	else
		if (pawnC == BLACK)
		{//Если цвет пешки черный
			if (pawnX == spaceX and spaceY == pawnY - 1 and spaceC == NONE)
			{//Движение по оси OY
				space->setSpace(pawn); //Перемещение фигуры на клетку space
				pawn->setEmpty();      //Клетка перемещающейся фигуры становится свободной
				return true;
			}
			else
				if ((pawnX + 1 == spaceX or pawnX - 1 == spaceX) and pawnY - 1 == spaceY and spaceC == WHITE)
				{//Если ход совершается на вражескую фигуру по диагонали
					space->setSpace(pawn); //Перемещение фигуры на клетку space
					pawn->setEmpty();      //Клетка перемещающейся фигуры становится свободной
					return true;
				}
				else
					return false;
		}
		else
			return false;
}
bool Chess::makeMove(Square* att, Square* vic) {
	switch (att->getPiece())
	{//Конструкция switch-case для определения перемещающейся фигуры и вызова соответствующей функции совершения хода
	case KING: return moveKing(att, vic);
		break;
	case QUEEN: return moveQueen(att, vic);
		break;
	case BISHOP: return moveBishop(att, vic);
		break;
	case KNIGHT: return moveKnight(att, vic);
		break;
	case ROOK: return moveRook(att, vic);
		break;
	case PAWN: return movePawn(att, vic);
		break;
	case EMPTY: std::cout << "You do not have a piece there" << std::endl;  return false; //Если на клетке нет фигуры
		break;
	}
	return false;
}

