#include "Board.h"
#include <string>

using namespace std;
void debugGame();
int main()
{
	debugGame();
	return 0;
}
void debugGame() 
{
	std::string input = " ";
	Board board = Board();
	board.load();
	cout << "Demo of how this would look on the frontend, if board doesnt change the move is illegal\n\n";

	while (input[0] != 's')
	{
		cout << board << "\n\n";
		cout << "Enter the move string: ";
		cin >> input;
		board.playMove(input);
	}
}
