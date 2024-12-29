#include <iostream>
#include <vector>
#define BLACK 0
#define WHITE 1
#define BOARD_SIZE 8

enum color {black, white, null};
class GamePiece
{
protected:
	enum color _color;
	char _type;
	int _posX;
	int _posY;
public:
	GamePiece(color color, char type, int posX, int posY);
	GamePiece();
	int getColor();
	int getType();
	virtual int checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY);
	friend std::ostream& operator<<(std::ostream& os, const GamePiece& piece);
};