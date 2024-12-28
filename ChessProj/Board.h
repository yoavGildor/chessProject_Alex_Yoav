#include "pieces.h"
#include <iostream>
#include <array>

class Board
{
private:
	std::vector<std::vector<GamePiece*>> _board;
	int _turn;
public:
	Board();
	~Board();
	int checkPieceMove(int posX, int posY, int tarX, int tarY);
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
