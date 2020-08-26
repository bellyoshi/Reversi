#pragma once
#include "Point.h"
typedef int Color;
const Color EMPTY = 0;
const Color WHITE = -1;
const Color BLACK = 1;
const Color GUARD = 2;

const Color E = EMPTY;
const Color B = BLACK;
const Color W = WHITE;
const Color G = GUARD;

struct Disc : public Point
{
	Color color;

	Disc() :Disc(0, 0, EMPTY) {}
	Disc(int x, int y, Color color); 
};

