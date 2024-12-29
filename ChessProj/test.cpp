#include "Board.h"

int main()
{
	Board board = Board();
	board.load();
	std::cout << board << std::endl;
	std::cout << board.checkPieceMove(0, 1, 0, 2); //pawn move 1
	std::cout << board.checkPieceMove(0, 1, 0, 3); //pawn move 2
	std::cout << board.checkPieceMove(0, 1, 0, 4); //pawn move 3
	std::cout << board.checkPieceMove(1, 0, 2, 2); //valid knight move
	std::cout << board.checkPieceMove(1, 0, 2, 3) << std::endl; //invalid knight move
	std::cout << board.checkMate(white);
	return 0;
}