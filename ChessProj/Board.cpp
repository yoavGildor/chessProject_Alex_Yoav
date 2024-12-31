#include "Board.h"

Board::Board()
{
	_turn = white;
	for (int i = 0; i < BOARD_SIZE; i++) //changed x and y
	{
		for (int j = BOARD_SIZE-1; j > -1; j--)
		{
			_board[j][i] = new GamePiece(null, '#', i, j);
		}
	}
}

Board::~Board()
{
	int i = 0, j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			delete _board[j][i];
		}
	}
}

int Board::checkPieceMove(int posX, int posY, int tarX, int tarY) //changed x and y
{
	return _board[posX][posY]->checkMove(this->_board, tarX, tarY);
}

int Board::getTurn()
{
	return _turn;
}

void Board::switchTurn()
{
	if (_turn == white)
	{
		_turn = black;
	}
	else if(_turn == black)
	{
		_turn = white;
	}
}

void Board::load() //changed x and y
{
	int i = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 0 || i == 7)
			_board[i][0] = new rook(white, 'R', i, 0);
		if (i == 1 || i == 6)
			_board[i][0] = new knight(white, 'N', i, 0);
		if (i == 2 || i == 5)
			_board[i][0] = new bishop(white, 'B', i, 0);
		if (i == 3)
			_board[i][0] = new king(white, 'K', i, 0);
		if (i == 4)
			_board[i][0] = new queen(white, 'Q', i, 0);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		_board[i][1] = new pawn(white, 'p', i, 1);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		_board[i][6] = new pawn(black, 'p', i, 6);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		if (i == 0 || i == 7)
			_board[i][7] = new rook(black, 'R', i, 7);
		if (i == 1 || i == 6)
			_board[i][7] = new knight(black, 'N', i, 7);
		if (i == 2 || i == 5)
			_board[i][7] = new bishop(black, 'B', i, 7);
		if (i == 3)
			_board[i][7] = new king(black, 'K', i, 7);
		if (i == 4)
			_board[i][7] = new queen(black, 'Q', i, 7);
	}
}

void Board::move(int posX, int posY, int tarX, int tarY)
{
	char type = (char)_board[posX][posY]->getType();
	GamePiece* newPiece;
	pawn* newPawn;
	knight* newKnight;
	king* newKing;
	queen* newQueen;
	bishop* newBishop;
	rook* newRook;
	switch (type)
	{
	case 'R':
		newRook = new rook(_turn, type, tarX, tarY);
		delete _board[posX][posY];
		delete _board[tarX][tarY];
		_board[tarX][tarY] = newRook;
		break;
	case 'B':
		newBishop = new bishop(_turn, type, tarX, tarY);
		delete _board[posX][posY];
		delete _board[tarX][tarY];
		_board[tarX][tarY] = newBishop;
		break;
	case 'Q':
		newQueen = new queen(_turn, type, tarX, tarY);
		delete _board[posX][posY];
		delete _board[tarX][tarY];
		_board[tarX][tarY] = newQueen;
		break;
	case 'N':
		newKnight = new knight(_turn, type, tarX, tarY);
		delete _board[posX][posY];
		delete _board[tarX][tarY];
		_board[tarX][tarY] = newKnight;
		break;
	case 'K':
		newKing = new king(_turn, type, tarX, tarY);
		delete _board[posX][posY];
		delete _board[tarX][tarY];
		_board[tarX][tarY] = newKing;
		break;
	case 'p':
		newPawn = new pawn(_turn, type, tarX, tarY);
		delete _board[posX][posY];
		delete _board[tarX][tarY];
		_board[tarX][tarY] = newPawn;
		break;
	default:
		newPiece = new GamePiece();
		delete _board[posX][posY];
		delete _board[tarX][tarY];
		_board[tarX][tarY] = newPiece;
		break;
	}
	_board[posX][posY] = new GamePiece();
}

int Board::isValid(int startX, int startY, int endX, int endY) //changed x and y
{
	if (startX > 7 || startX < 0 || startY > 7 || startY < 0 || endX > 7 || endX < 0 || endY > 7 || endY < 0)
	{
		return 5;
	}
	if (startX == endX && startY == endY)
	{
		return 7;
	}
	if (_board[startX][startY]->getColor() != _turn)
	{
		return 2;
	}
	if (_board[endX][endY]->getColor() == (int)_turn)
	{
		return 3;
	}
	return 0;
}

bool Board::checkMate(color colorOfKing) //need to change x and y!!!!!!!
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
	int* fail = new int[4] {9, 9, 9, 9};
	if (infoStr.size() != 4)
		return fail;
	int i = 0;
	for (i = 0; i < infoStr.size(); i++)
	{
		if (i % 2 == 0 && !isalpha(infoStr[i]))
		{
			return fail;
		}
		if (i % 2 == 1 && !isalnum(infoStr[i]))
		{
			return fail;
		}
	}
	int* infoArr = new int[4] //next 4 lines are initialization
	{infoStr[0] - 'a',
	infoStr[1] - '1',
	infoStr[2] - 'a',
	infoStr[3] - '1'};

	return infoArr;
}



std::ostream& operator<<(std::ostream& os, const Board& board) //changed x and y
{
	GamePiece cur;
	int i = 0, j = 0;
	std::string turn = "";
	if (board._turn == white)
		turn = "White";
	else
		turn = "Black";
	os << "\n" << turn << " turn, Board:\nXX a  b  c  d  e  f  g  h  XX\n";
	for (i = BOARD_SIZE-1; i > -1; i--)
	{
		os << (i + 1) << "| ";
		for (j = 0; j < BOARD_SIZE; j++)
		{
			cur = *board._board[j][i];
			if (cur.getType() == '#')
				os << "-- ";
			else
				os << cur;
		}	
		os << "|" << (i + 1) << "\n";
	}
	os << "XX a  b  c  d  e  f  g  h  XX\n";
	return os;
}
void Board::playMove(std::string moveStr)
{

	int* arr = convert(moveStr); //arr contains the posx, posy, tarx, tary;
	if (isValid(arr[0], arr[1], arr[2], arr[3]) == 0)
	{
		if (checkPieceMove(arr[0], arr[1], arr[2], arr[3]) == 0)
		{
			move(arr[0], arr[1], arr[2], arr[3]);
			switchTurn();
		}
	}
	delete arr;
}
