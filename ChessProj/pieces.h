#pragma once
#include "gamePiece.h"

class pawn : public GamePiece
{
private:
	bool _hasMoved;
public:
	pawn(int color, char type, int posX, int posY);
	int checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY) override;
};

class knight : public GamePiece
{
public:
	knight(int color, char type, int posX, int posY);
	int checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY) override;
};

class bishop : public GamePiece
{
public:
	bishop(int color, char type, int posX, int posY);
	int checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY) override;
};

class rook : public GamePiece
{
public:
	rook(int color, char type, int posX, int posY);
	int checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY) override;
};

class queen : public GamePiece
{
public:
	queen(int color, char type, int posX, int posY);
	int checkMove(std::vector<std::vector<GamePiece*>> board, int tarX, int tarY) override;
};

class king : public GamePiece
{
public:
	king(int color, char type, int posX, int posY);
	int checkMove(std::vector<std::vector<GamePiece*>> _board, int tarX, int tarY) override;
};