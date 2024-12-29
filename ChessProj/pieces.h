#pragma once
#include "gamePiece.h"

class pawn : public GamePiece
{
private:
	bool _hasMoved;
public:
	pawn(color color, char type, int posX, int posY);
	int checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY) override;
};

class knight : public GamePiece
{
public:
	knight(color color, char type, int posX, int posY);
	int checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY) override;
};

class bishop : public GamePiece
{
public:
	bishop(color color, char type, int posX, int posY);
	int checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY) override;
};

class rook : public GamePiece
{
public:
	rook(color color, char type, int posX, int posY);
	int checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY) override;
};

class queen : public GamePiece
{
public:
	queen(color color, char type, int posX, int posY);
	int checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY) override;
};

class king : public GamePiece
{
public:
	king(color color, char type, int posX, int posY);
	int checkMove(GamePiece* board[BOARD_SIZE][BOARD_SIZE], int tarX, int tarY) override;
};