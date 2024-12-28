#include <iostream>
#include <vector>
#define BLACK 0
#define WHITE 1
#define BOARD_SIZE 8
class GamePiece
{
protected:
	int _color;
	char _type;
	int _posX;
	int _posY;
public:
	GamePiece(int color, char type, int posX, int posY);
	GamePiece();
	int getColor();
	int getType();
	virtual int checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY);
	friend std::ostream& operator<<(std::ostream& os, const GamePiece& piece);
};