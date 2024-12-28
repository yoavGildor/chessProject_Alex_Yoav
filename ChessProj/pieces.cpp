#include "pieces.h"

pawn::pawn(int color, char type, int posX, int posY) : GamePiece(color, type, posX, posY)
{
	_hasMoved = false;
}

int pawn::checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY)
{
	int verticalStep = this->_color ? -1 : 1; //one step up or down depending on color
	verticalStep *= this->_hasMoved ? 1 : 2; //allow double step on first move of pawn
	if (!this->_hasMoved && tarY == this->_posY + verticalStep && tarX == this->_posX && board[tarY][tarX]->getType() == '#') //special case
	{
		if(board[tarY - 1][tarX]->getType() == '#')
		return 0;
	}
	verticalStep = this->_color ? -1 : 1;
	if (tarY != this->_posY + verticalStep)
	{

		return 6;
	}
	
	if (tarX == this->_posX) //only walk forward when space in empty
	{
		if (board[tarY][tarX]->getType() != '#')
		{
			return 6;
		}
		return 0;
	}

	if (tarX == this->_posX + 1 || tarX == this->_posX - 1) //only walk horizontal when there's an enemy piece
	{
		if (board[tarY][tarX]->getType() == '#')
		{
			return 6;
		}
		return 0;
	}
	return 6;
}

knight::knight(int color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int knight::checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY)
{
	if ((abs(tarX - this->_posX) + abs(tarY - this->_posY)) == 3 && board[tarY][tarX]->getColor() != this->_color)
	{
		return 0;
	}
	return 6;
}

bishop::bishop(int color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int bishop::checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY)
{
	return 0;
}

rook::rook(int color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int rook::checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY)
{
	return 0;
}

queen::queen(int color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int queen::checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY)
{
	return 0;
}

king::king(int color, char type, int posX, int posY) : GamePiece(color, type, posX, posY) {}

int king::checkMove(std::vector<std::vector<GamePiece*>> _board, int tarX, int tarY)
{
	return 0;
}
