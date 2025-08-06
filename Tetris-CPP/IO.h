#pragma once
#ifndef _IO_
#define _IO_

#include "SDL3/SDL.h"

enum color{BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};

class IO
{
public:
	IO();
	void DrawRect(int pX1, int pY1, int pX2, int pY2, enum color pC);
	void ClearScreen();
	int GetScreenHeight();
	int InitGraph();
	int PollKey();
	int GetKey();
	int IsKeyDown(int pKey);
	void UpdateScreen();
};

#endif _IO_