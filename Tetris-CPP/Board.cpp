#include "Board.h"


void Board::initBoard()
{
	for (int i{}; i < BOARD_WIDTH;++i)
		for (int j{}; j < BOARD_HEIGHT; ++j)
			mBoard[i][j] = POS_FREE;
}

void Board::StorePiece(int pX, int pY, int pPiece, int pRot)
{
	//Store each block of the piece into the board
	for(int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; ++i1, ++i2)
		for (int j1 = pY, j2 = 0; j2 < pY + PIECE_BLOCKS; ++j1, ++j2)
		{
			if (mPieces->GetBlockType(pPiece, pRot, j2, i2) != 0)
				mBoard[i1][j1] = POS_FILLED;
		}
}

bool Board::isGameOver()
{
	for (int i{}; i < BOARD_WIDTH; ++i)
		if (mBoard[i][0] == POS_FILLED)
			return true;
	return false;
}

void Board::DeleteLine(int pY)
{
	for(int j= pY; j >0; --j)
		for (int i{}; i < BOARD_WIDTH; ++i)
		{
			mBoard[i][j] = mBoard[i][j - 1];
		}
}

void Board::DeletePossibleLines()
{
	for (int j{}; j < BOARD_HEIGHT; ++j)
	{
		int i = 0;
		while (i < BOARD_HEIGHT)
		{
			if (mBoard[i][j] != POS_FILLED)
				break;
			++i;
			if (i == BOARD_WIDTH)
				DeleteLine(j);
		}
	}
}

bool Board::IsFreeBlock(int pX, int pY)
{
	if (mBoard[pX][pY] == POS_FREE)
		return true;
	return false;
}

int Board::GetXPosInPixels(int pPos)
{
	return ((BOARD_POS - (BLOCK_SIZE * (BOARD_WIDTH / 2)))+ (pPos * BLOCK_SIZE));
}

int Board::GetYPosInPixels(int pPos)
{
	return ((BOARD_POS - (BLOCK_SIZE * (BOARD_HEIGHT / 2))) + (pPos * BLOCK_SIZE));
}

bool Board::IsPossibleMove(int pX, int pY, int pPiece, int pRot)
{
	//Check with piece already stored on the board or board limits
	for(int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; ++i1, ++i2)
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; ++j1, ++j2)
		{
			int isValid = mPieces->GetBlockType(pPiece, pRot, j2, i2);
			if (isValid != 0)
			{
				if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_WIDTH - 1)
					return false;
				else if ((j1 >= 0) && (!IsFreeBlock(i1, j1)))
					return false;
			}
		}
	return true;
}