#include "Board.h"

Board::Board()
{
	_turn = white;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_board[i][j] = new GamePiece(null, '#', i, j);
		}
	}
}

Board::~Board()
{

}

int Board::checkPieceMove(int posX, int posY, int tarX, int tarY)
{
	return _board[posY][posX]->checkMove(this->_board, tarX, tarY);
}



int Board::getTurn()
{
	return _turn;
}

void Board::switchTurn()
{
	if (_turn)
	{
		_turn = white;
	}
	else
	{
		_turn = black;
	}
}

void Board::load()
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 0 || i == 7)
			_board[0][i] = new rook(black, 'R', i, 0);
		if (i == 1 || i == 6)
			_board[0][i] = new knight(black, 'N', i, 0);
		if (i == 2 || i == 5)
			_board[0][i] = new bishop(black, 'B', i, 0);
		if (i == 3)
			_board[0][i] = new king(black, 'K', i, 0);
		if (i == 4)
			_board[0][i] = new queen(black, 'Q', i, 0);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		_board[1][i] = new pawn(black, 'p', i, 1);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		_board[6][i] = new pawn(white, 'p', i, 6);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 0 || i == 7)
			_board[7][i] = new rook(white, 'R', i, 7);
		if (i == 1 || i == 6)
			_board[7][i] = new knight(white, 'N', i, 7);
		if (i == 2 || i == 5)
			_board[7][i] = new bishop(white, 'B', i, 7);
		if (i == 3)
			_board[7][i] = new king(white, 'K', i, 7);
		if (i == 4)
			_board[7][i] = new queen(white, 'Q', i, 7);
	}
}

void Board::move()
{
	//INCOMPLETE
}

int Board::isValid(int startX, int startY, int endX, int endY)
{
	if (startX > 7 || startX < 0 || startY > 7 || startY < 0 || endX > 7 || endX < 0 || endY > 7 || endY < 0)
	{
		return 5;
	}
	if (startX == endX && startY == endY)
	{
		return 7;
	}
	if (_board[startY][startX]->getColor() != _turn)
	{
		return 2;
	}
	if (_board[startY][startX]->getColor() == _turn)
	{
		return 3;
	}
	return 0;
}

bool Board::checkMate(color colorOfKing)
{
	int posY;
	int posX;
	bool flag = true;
	int offsetX = 0;
	int offsetY = 0;
	//get the king's position
	for (int i = 0; i < BOARD_SIZE && flag; i++)
	{
		for (int j = 0; j < BOARD_SIZE && flag; j++)
		{
			if (_board[i][j]->getType() == 'K' && _board[i][j]->getColor() == colorOfKing)
			{
				posX = j;
				posY = i;
				flag = false;
			}
		}
	}
	//check vertical line (rooks and queen)
	for (int i = 0; i < 2; i++)
	{
		for (int j = posY; j < BOARD_SIZE && _board[j][posX]->getType() != '#'; j += i ? -1 : 1)
		{
			if ((_board[j][posX]->getType() == 'R' || _board[j][posX]->getType() == 'Q') && _board[posY][j]->getColor() != colorOfKing)
			{
				return true;
			}
		}
	}
	//check horizontal line (rooks and queen)
	for (int i = 0; i < 2; i++)
	{
		for (int j = posX; j < BOARD_SIZE && _board[posY][j]->getType() != '#'; j += i ? -1 : 1)
		{
			if ((_board[posY][j]->getType() == 'R' || _board[posY][j]->getType() == 'Q') && _board[posY][j]->getColor() != colorOfKing)
			{
				return true;
			}
		}
	}

	//check diagonals (bishops and queen)
	for (int i = -1; i < 3; i++)
	{
		offsetX = 0;
		offsetY = 0;
		while (posX + offsetX < BOARD_SIZE && posX + offsetX > 0 && posY + offsetY < BOARD_SIZE && posY + offsetY > 0 && _board[posY + offsetY][posX + offsetX]->getType() != '#')
		{
			if ((_board[posY + offsetY][posX + offsetX]->getType() == 'B' || _board[posY + offsetY][posX + offsetX]->getType() == 'Q') && _board[posY + offsetY][posX + offsetX]->getColor() != colorOfKing)
			{
				return true;
			}
			offsetX += i > 0 ? -1 : 1;
			offsetY += i > 0 ? 1 : -1;
			offsetX += i % 2 ? -1 : 1;
			offsetY += i % 2 ? -1 : 1;
		}
	}
	//check for pawns
	for (int i = -1; i < 2; i += 2)
	{
		offsetY = colorOfKing ? -1 : 1;
		if (posX + offsetX < BOARD_SIZE && posX + offsetX > 0 && posY + offsetY < BOARD_SIZE && posY + offsetY > 0)
		{
			if (_board[posY + offsetY][posX + i]->getType() == 'P' && _board[posY + offsetY][posX + i]->getColor() != colorOfKing)
			{
				return true;
			}
		}
	}
	//and finally, check for knights
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				offsetX = i ? -1 : 1;
				offsetY = j ? -1 : 1;
				offsetX *= k ? 2 : 1;
				offsetY *= k ? 1 : 2;
				if (posX + offsetX < BOARD_SIZE && posX + offsetX > 0 && posY + offsetY < BOARD_SIZE && posY + offsetY > 0)
				{
					if (_board[posY + offsetY][posX + offsetX]->getType() == 'N' && _board[posY + offsetY][posX + offsetX]->getColor() != colorOfKing)
					{
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

int* Board::convert(std::string infoStr)
{
	int infoArr[4];

	infoArr[0] = infoStr[0] - 'a';
	infoArr[1] = infoStr[1] - '0';
	infoArr[2] = infoStr[2] - 'a';
	infoArr[3] = infoStr[3] - '0';

	return infoArr;
	
}


std::ostream& operator<<(std::ostream& os, const Board& board)
{
	GamePiece cur;
	int i = 0, j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			cur = *board._board[i][j];
			if (cur.getType() == '#')
				os << "## ";
			else
				os << cur;
		}	
		os << '\n';
	}
	return os;
}
