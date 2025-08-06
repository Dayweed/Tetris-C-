#include "Game.h"
#include <windows.h>

int Game::GetRand(int pA, int pB)
{
	return rand () % (pB - pA + 1) + pA;
}

void Game::InitGame()
{
	srand((unsigned int) time(NULL));

	//1st Piece
	mPiece = GetRand(0, 6);
	mRot = GetRand(0, 3);
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitPos(mPiece, mRot);
	mPosY = mPieces->GetYInitPos(mPiece, mRot);

	//Next Piece
	mNextPiece = GetRand(0, 6);
	mNextRot = GetRand(0, 6);
	mNextPosX = BOARD_WIDTH + 5;
	mNextPosY = 5;
}

void Game::CreateNewPiece()
{
	mPiece = mNextPiece;
	mRot = mNextRot;
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitPos(mPiece, mRot);
	mPosY = mPieces->GetYInitPos(mPiece, mRot);

	mNextPiece = GetRand(0, 6);
	mNextRot = GetRand(0, 3);
}

void Game::DrawPiece(int pX, int pY, int pPiece, int pRot)
{
	color mCol;

	int mPixelsX = mBoard->GetXPosInPixels(pX);
	int mPixelsY = mBoard->GetYPosInPixels(pY);

	for (int i{}; i < PIECE_BLOCKS; ++i)
		for (int j{}; j < PIECE_BLOCKS; ++j)
		{
			switch (mPieces->GetBlockType(pPiece, pRot, j, i))
			{
			case 1: mCol = GREEN; break;
			case 2: mCol = BLUE; break;
			}
			if(mPieces->GetBlockType(pPiece,pRot,j,i) != 0)
				mIO->DrawRect(mPixelsX + i * BLOCK_SIZE, mPixelsY + j * BLOCK_SIZE, (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, mCol);
		}
}

void Game::DrawBoard()
{
	int mX1 = BOARD_POS - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	int mX2 = BOARD_POS + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

	mIO->DrawRect(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
	mIO->DrawRect(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

	mX1 += 1;
	for (int i{}; i < BOARD_WIDTH;++i)
		for (int j{}; j < BOARD_WIDTH; ++j)
		{
			if (!mBoard->IsFreeBlock(i, j))
				mIO->DrawRect(mX1 + i * BLOCK_SIZE, mY + j * BLOCK_SIZE, (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1, (mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, RED);
		}
}

void Game::DrawScene()
{
	DrawBoard();
	DrawPiece(mPosX, mPosY, mPiece, mRot);
	DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRot);
}