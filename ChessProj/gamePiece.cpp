#include "gamePiece.h"

GamePiece::GamePiece(color color, char type, int posX, int posY)
{
	_posX = posX;
	_posY = posY;
	_color = color;
	_type = type;
}

GamePiece::GamePiece()
{
	_posX = 0;
	_posY = 0;
	_color = null;
	_type = '#';
}

int GamePiece::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	return 1; //if something unexpected happens the move wont play
}

int GamePiece::getColor()
{
	return _color;
}
int GamePiece::getType()
{
	return _type;
}

std::ostream& operator<<(std::ostream& os, const GamePiece& piece)
{
	os << piece._color << piece._type << " ";
	return os;
}