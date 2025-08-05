#pragma once
#ifndef _BOARD_
#define _BOARD_

#include "Pieces.h"

#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POS 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERT_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5

class Board {
public:
	Board(Pieces* pPieces, int pScreenHeight);
	int GetXPosInPixels(int pPos);
	int GetYPosInPixels(int pPos);
	bool IsFreeBlock(int pX, int pY);
	bool IsPossibleMove(int pX, int pY, int pPiece, int pRot);
	void StorePiece(int pX, int pY, int pPiece, int pRot);
	void DeletePossibleLines();
	bool isGameOver();
private:
	enum {POS_FREE, POS_FILLED};
	int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
	Pieces* mPieces;
	int mScreenHeight;
	void initBoard();
	void DeleteLine(int pY);
};
#endif _BOARD_