#include <iostream>

class GamePiece
{
private:
	int _color;
	char _type;
public:
	GamePiece(int color, char type);
	GamePiece();
	int getColor();
	int getType();
	virtual int checkMove(GamePiece[8][8]);
	friend std::ostream& operator<<(std::ostream& os, const GamePiece& piece);
};