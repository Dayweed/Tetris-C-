#pragma once
#ifndef _PIECES_
#define	_PIECES_

class Pieces
{
public:
	int GetBlockType(int pPiece, int pRot, int pX, int pY);
	int GetXInitPos(int pPiece, int pRot);
	int GetYInitPos(int pPiece, int pRot);
};

#endif _PIECES_