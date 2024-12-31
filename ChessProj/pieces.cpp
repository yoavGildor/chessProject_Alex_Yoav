#include "pieces.h"

pawn::pawn(color color, char type, int posX, int posY) : GamePiece(color, type, posX, posY)
{
	_hasMoved = false;
}

int pawn::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	int vertStep = 1;
	if (this->_color == black) //one step up or down depending on color
		vertStep *= -1;
	if (!this->_hasMoved) //allow double step on first move of pawn
		vertStep *= 2;
	if (tarX != _posX /*not the same file (a, b ,c...)*/ || abs(tarY - _posY) < 1 /*the target is behind*/ || abs(tarY - _posY) > abs(vertStep) /*the target is too far away*/)
	{
		return 6;
	}
	if (!_hasMoved /*if vertStep -2, 2*/ && board[tarX][_posY + vertStep / 2]->getType() != '#')
	{
		return 6;
	}
	if (board[tarX][tarY]->getType() != '#')
	{
		return 6;
	}
	_hasMoved = true;
	return 0;
	//if (!_hasMoved && vertStep == 2 && ) 
	//{
	//	_hasMoved = true;
	//	return 0;
	//}
	//else if(_posY + vertStep == tarY && board[tarX][tarY]->getType() == '#')
	////verticalStep = this->_color ? -1 : 1;
	////if (tarY != this->_posY + verticalStep)
	////{
	////	return 6;
	////}

	//if (tarX == this->_posX) //only walk forward when space in empty
	//{
	//	if (board[tarY][tarX]->getType() != '#')
	//	{
	//		return 6;
	//	}
	//	return 0;
	//}

	//if (tarX == this->_posX + 1 || tarX == this->_posX - 1) //only walk horizontal when there's an enemy piece
	//{
	//	if (board[tarY][tarX]->getType() == '#')
	//	{
	//		return 6;
	//	}
	//	return 0;
	//}
	//return 6;
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
	
	/*if (abs(tarY - _posY) == 1)
	{
		if (board[_posX][tarY]->getType() != '#')
			return 6;
	}
	if (abs(tarX - _posX) == 1)
	{
		if (board[tarX][_posY]->getType() != '#')
			return 6;
	}*/
	
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

king::king(color color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int king::checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY)
{
	return 0;
}