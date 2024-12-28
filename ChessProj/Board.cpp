#include "Board.h"

Board::Board()
{
	_board.resize(BOARD_SIZE);
	_turn = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		_board[i].resize(BOARD_SIZE);
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_board[i][j] = new GamePiece(-1, '#', i, j);
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
	_turn = ~_turn;
}

void Board::load()
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 0 || i == 7)
			_board[0][i] = new rook(BLACK, 'R', i, 0);
		if (i == 1 || i == 6)
			_board[0][i] = new knight(BLACK, 'N', i, 0);
		if (i == 2 || i == 5)
			_board[0][i] = new bishop(BLACK, 'B', i, 0);
		if (i == 3)
			_board[0][i] = new king(BLACK, 'K', i, 0);
		if (i == 4)
			_board[0][i] = new queen(BLACK, 'Q', i, 0);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		_board[1][i] = new pawn(BLACK, 'p', i, 1);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		_board[6][i] = new pawn(WHITE, 'p', i, 6);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 0 || i == 7)
			_board[7][i] = new rook(WHITE, 'R', i, 7);
		if (i == 1 || i == 6)
			_board[7][i] = new knight(WHITE, 'N', i, 7);
		if (i == 2 || i == 5)
			_board[7][i] = new bishop(WHITE, 'B', i, 7);
		if (i == 3)
			_board[7][i] = new king(WHITE, 'K', i, 7);
		if (i == 4)
			_board[7][i] = new queen(WHITE, 'Q', i, 7);
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
