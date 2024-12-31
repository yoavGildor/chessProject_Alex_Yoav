#include "pieces.h"
#include <iostream>
#include <array>
#include <cmath>

class Board
{
private:
	GamePiece* _board[BOARD_SIZE][BOARD_SIZE];
	color _turn;
	int temp[];
public:
	Board();
	~Board();
	int checkPieceMove(int posX, int posY, int tarX, int tarY);
	int getTurn();
	void switchTurn();
	void load();
	void playMove(std::string);
	void move(int posX, int posY, int tarX, int tarY);
	int isValid(int startX, int startY, int endX, int endY);
	bool checkMate(color colorOfKing);
	int* convert(std::string);
	friend std::ostream& operator<<(std::ostream& os, const Board& board);
};
