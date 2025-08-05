#pragma once
#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <ctime>

#define WAIT_TIME 700

class Game
{
public:
	Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight);
	void DrawScene();
	void CreateNewPiece();

	int mPosX, mPosY;
	int mPiece, mRot;
private:
	int mScreenHeight;
	int mNextPosX, mNextPosY;
	int mNextPiece, mNextRot;

	Board* mBoard;
	Pieces* mPieces;
	IO* mIO;

	int GetRand(int pA, int pB);
	void InitGame();
	void DrawPiece(int pX, int pY, int pPiece, int pRot);
	void DrawBoard();
};

#endif _GAME_