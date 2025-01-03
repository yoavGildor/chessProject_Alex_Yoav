#include "pieces.h"

pawn::pawn(color color, char type, int posX, int posY) : GamePiece(color, type, posX, posY)
{
	_hasMoved = false;
}

int pawn::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	int flag = 0;
	int vertStep = 1;
	if (this->_color == black) //one step up or down depending on color
		vertStep *= -1;
	if (!_hasMoved) //allow double step on first move of pawn
		vertStep *= 2;
	if (abs(tarX - _posX) == 1 && abs(tarY - _posY) == 1 && (_hasMoved && tarY - _posY == vertStep) && board[tarX][tarY]->getType() != '#')
	{
		_hasMoved = true;
		return 0;
	}
	if (tarX != _posX /*not the same file (a, b ,c...)*/ || abs(tarY - _posY) > abs(vertStep) /*the target is too far away*/ || (_hasMoved && tarY - _posY != vertStep) /*cant move backwards*/ || (!_hasMoved && board[tarX][_posY + vertStep / 2]->getType() != '#') /*if theres a piece in the way*/ || board[tarX][tarY]->getType() != '#' /*cant move to a busy space*/)
	{
		return 6;
	}
	_hasMoved = true;
	return 0;
}

knight::knight(color color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int knight::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	if ((abs(tarX - this->_posX) + abs(tarY - this->_posY)) == 3 && board[tarY][tarX]->getColor() != this->_color)
	{
		return 0;
	}
	return 6;
}
bishop::bishop(color color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int bishop::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	int x = 0, y = 0, i = 0;
	if (abs(tarX - _posX) != abs(tarY - _posY))
	{
		return 6;
	}
	for (i = 1; i < abs(_posX - tarX); i++)
	{
		x = i * cmpnum(tarX, _posX);
		y = i * cmpnum(tarY, _posY);
		if (board[_posX + x][_posY + y]->getType() != '#')
		{
			return 6;
		}
	}
	return 0;
}

rook::rook(color color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int rook::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	int x = 0, y = 0, i = 0;
	if (tarX != _posX && tarY != _posY)
	{
		return 6;
	}
	for (i = 1; i < (abs(tarX - _posX + tarY - _posY)); i++)
	{
		x = i * cmpnum(tarX, _posX);
		y = i * cmpnum(tarY, _posY);
		if (board[_posX + x][_posY + y]->getType() != '#')
		{
			return 6;
		}
	}
	return 0;
}

queen::queen(color color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int queen::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	int x = 0, y = 0, i = 0;
	if (tarX != _posX && tarY != _posY && abs(tarX - _posX) != abs(tarY - _posY))
	{
		return 6;
	}
	if (abs(tarX - _posX) == abs(tarY - _posY))
	{
		for (i = 1; i < abs(_posX - tarX); i++)
		{
			x = i * cmpnum(tarX, _posX);
			y = i * cmpnum(tarY, _posY);
			if (board[_posX + x][_posY + y]->getType() != '#')
			{
				return 6;
			}
		}
		return 0;
	}
	else if (tarX == _posX || tarY == _posY)
	{
		for (i = 1; i < (abs(tarX - _posX + tarY - _posY)); i++)
		{
			x = i * cmpnum(tarX, _posX);
			y = i * cmpnum(tarY, _posY);
			if (board[_posX + x][_posY + y]->getType() != '#')
			{
				return 6;
			}
		}
		return 0;
	}
	return 6;
}

king::king(color color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int king::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	int distanceX = 0, distanceY = 0, totalDistance = 0;
	distanceX = tarX - this->_posX;
	distanceY = tarY - this->_posY;
	totalDistance = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
	if (totalDistance >- 2)
	{
		return 6;
	}
	
	return 0;
}