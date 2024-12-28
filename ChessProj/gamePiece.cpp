#include "gamePiece.h"

GamePiece::GamePiece(int color, char type, int posX, int posY)
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
	_color = 1;
	_type = '#';
}

int GamePiece::checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY)
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