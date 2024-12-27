#include "gamePiece.h"
#include <iostream>
#define BOARD_SIZE 8
#define BLACK 0
#define WHITE 1

class Board
{
private:
	GamePiece _board[BOARD_SIZE][BOARD_SIZE];
	int _turn;
public:
	Board();
	~Board();
	int getTurn();
	void switchTurn();
	void load();
	void move();
	int isValid();
	bool checkMate();
	int* convert(std::string);
	int read(int startX, int startY, int endX, int endY);
	friend std::ostream& operator<<(std::ostream& os, const Board& board);
};
