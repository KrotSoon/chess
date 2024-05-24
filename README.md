# CHESS C++
___
## ������� ����:
+ ��� ������� � ������� ����� ���������� ��������� ����� � ��������� ���������� ����� � ���������� � ����� �������� ������, ������� ������ ������� ���. (���.1)
+ ��� ����, ����� ������� ���, ���������� ������ ������� ���������� ������, ������� �� ������ �����������, ����� ���������� ������, �� ������� �� ������ �����������. (������: "a1b3") (���.2;���.3)
+ ���� ��� ��������, ������ ������������ �� ����� ������ � ���������� �������� � ������� ������. ���� ��� ����������, ����������� ��������� �� ������ � ��� ����� ����� ������� ���������. (���.4)
+ ��� ������ ����������, ����� ������ ���������� ������ ��� ��������������� ��������, � �� ��������� ��� ������� �����. (���.5;���.6)
+ ����� ���������� ������, ����� ������ ������.(���.6)

[�����](https://youtu.be/72MuK8vSeno) �� youtube � ������������� ������ ���������.

![ris1](https://github.com/KrotSoon/chess/assets/122313221/224c188c-d51b-4664-bf66-d6bb9d0e3bc7)
���.1

![ris2](https://github.com/KrotSoon/chess/assets/122313221/28c68bf6-34d1-4629-9b59-f5aaac1fc0f7)
���.2

![ris3](https://github.com/KrotSoon/chess/assets/122313221/56bcf9fd-6b31-4977-bf4f-b33014a99a0b)
���.3

![ris4](https://github.com/KrotSoon/chess/assets/122313221/c8e6f711-3230-4985-82a2-adcb1c456c00)
���.4

![ris5](https://github.com/KrotSoon/chess/assets/122313221/7cc45464-6ee8-474c-9bee-6ea88c1915c8)
���.5

![ris6](https://github.com/KrotSoon/chess/assets/122313221/1b8aaf34-c260-47d0-9aba-06f229f0d258)
���.6
___
## ���������� 
��������� ��������� � ������� �������. ���������� ������� ��������� � `chess.cpp`. 

### SQUARE
�������� ������ `square`:
+ `Piece piece` - ��������� �������������� ���� Piece, �������������� � ���� �������;
+ `Color color` - ��������� �������������� ���� Color, �������������� � ���� ������ ������;
+ `int x, y` - ������������� ��� ��� ������������� ��������� ������.

�������� ������� ������ `square`:
+ `setSpace()` - ������ ��� piece � color;
+ `setEmpty()` - ������, ���������� piece � color (EMPTY � NONE �������������);
+ `getPiece()` - ������ ��� piece;
+ `getColor()` - ������ ��� color;
+ `setPC()` - ������ ��� piece � color;
+ `setX()\setY()` - ������� ��� ���������;
+ `setX()\setY()` - ������� ��� ���������;

### CHESS
�������� ������ `chess`:
+ `square board` - ������ ������ square, �������������� � ���� ��������� ������;
+ `Color turn` - ��������� �������������� ���� Color, �������������� � ���� ������ �������� ������;

�������� ������� ������ `chess`:
+ `play()` - �������, ���������� ��������� ������ ����, ��������� ���������� ������� � �������� ����� ���;
+ `printBoard()` - ������� ��� ������ ��������� ����� � �������;
+ `setBoard()` - ������� ��� ������������� �����;
+ `doMove()` - �������, ������� ������������� ���������� ����. ��� �� ���������� ��������� ����� ����������� ���������� � ���������� ������ �� �����;
+ `move***()` - �������, ��������������� ����������� �������� ���������� ������ (*** - �������� ������ (pawn, king, queen and etc.).
+ `getSquare()` - ������ ��� ���������� ������;
+ `setSquare()` - ������ ��� ���������� ������;
+ `makeMove()` - �������, ���������� ��������������� ��� `doMove()`, ���������� ��������� ������ � �������� ��������������� ������� `move***`;
+ `checkMove()` -  �������, ���������� ��������������� ��� `doMove()`, ��������� ��������� ������� ����������� ����.
___
## ���������
��� ����, ����� ��������� ����, �������� zip � ����������. ���� �� ����������� Visual Studio, �������� `chess.sln` ��� ������ (����->�������->������� ��� ������). ��������� `main.cpp`. 