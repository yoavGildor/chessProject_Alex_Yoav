#include "gamePiece.h"

GamePiece::GamePiece(int color, char type)
{
	_color = color;
	_type = type;
}

GamePiece::GamePiece()
{
	_color = 1;
	_type = '#';
}

int GamePiece::checkMove(GamePiece board[8][8])
{
	return 0;
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