#include "Board.h"

int main()
{
	Board board = Board();
	board.load();
	std::cout << board;
	
	return 0;
}