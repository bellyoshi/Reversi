#pragma once
#include "Disc.h"


class Board
{
public:
	static const int SIZE = 8;
private:
	
	static const int RAW_SIZE = 1 + SIZE + 1;
	Color RawBoard[RAW_SIZE * RAW_SIZE] = {
		G,G,G,G,G,G,G,G,G,G,
		G,E,E,E,E,E,E,E,E,G,
		G,E,E,E,E,E,E,E,E,G,
		G,E,E,E,E,E,E,E,E,G,
		G,E,E,E,W,B,E,E,E,G,
		G,E,E,E,B,W,E,E,E,G,
		G,E,E,E,E,E,E,E,E,G,
		G,E,E,E,E,E,E,E,E,G,
		G,E,E,E,E,E,E,E,E,G,
		G,G,G,G,G,G,G,G,G,G
	};
	inline int index(int x, int y) {
		return y * RAW_SIZE + x;
	}
public:
	Board() {

	}
	Color Cell(int x, int y) {
		return RawBoard[index(x, y)];
	}

};

