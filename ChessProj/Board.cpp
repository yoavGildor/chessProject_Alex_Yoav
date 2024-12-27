#include "Board.h"

Board::Board()
{
	_turn = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_board[i][j] = GamePiece(0, '#');
		}
	}
}

Board::~Board()
{

}

int Board::getTurn()
{
	return _turn;
}

void Board::switchTurn()
{
	_turn = !_turn;
}

void Board::load()
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 0 || i == 7)
			_board[0][i] = GamePiece(BLACK, 'R');
		if (i == 1 || i == 6)
			_board[0][i] = GamePiece(BLACK, 'N');
		if (i == 2 || i == 5)
			_board[0][i] = GamePiece(BLACK, 'B');
		if (i == 3)
			_board[0][i] = GamePiece(BLACK, 'K');
		if (i == 4)
			_board[0][i] = GamePiece(BLACK, 'Q');
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		_board[1][i] = GamePiece(BLACK, 'p');
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		_board[6][i] = GamePiece(WHITE, 'p');
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 0 || i == 7)
			_board[7][i] = GamePiece(WHITE, 'R');
		if (i == 1 || i == 6)
			_board[7][i] = GamePiece(WHITE, 'N');
		if (i == 2 || i == 5)
			_board[7][i] = GamePiece(WHITE, 'B');
		if (i == 3)
			_board[7][i] = GamePiece(WHITE, 'K');
		if (i == 4)
			_board[7][i] = GamePiece(WHITE, 'Q');
	}
}

void Board::move()
{
	//INCOMPLETE
}

int Board::isValid()
{
	//INCOMPLETE
	return 0;
}

bool Board::checkMate()
{
	//INCOMPLETE
	return true;
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

int Board::read(int startX, int startY, int endX, int endY)
{
	//INCOMPLETE
	return 0;
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
	GamePiece cur;
	int i = 0, j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			cur = board._board[i][j];
			if (cur.getType() == '#')
				os << "## ";
			else
				os << cur;
		}	
		os << '\n';
	}
	return os;
}
