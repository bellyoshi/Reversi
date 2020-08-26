#pragma once
#include "Point.h"
typedef int Color;
const Color EMPTY = 0;
const Color WHITE = -1;
const Color BLACK = 1;
const Color WALL = 2;

struct Disc : public Point
{
	Color color;

	Disc() :Disc(0, 0, EMPTY) {}
	Disc(int x, int y, Color color); 
};

