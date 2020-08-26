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
	inline static int index(int x, int y) {
		return y * RAW_SIZE + x;
	}



	static void directionInit()
	{
		int upper = index(0, -1);
		int left = index(-1, 0);
		int right = index(1, 0);
		int lower = index(0, 1);

		directions = new int[] {
			upper,
			upper + left,
			left,
			lower + left,
			lower,
			lower + right,
			right,
			upper + right
		};
	}
public:
	static int* directions;
	static void Initialize() {
		directionInit();
	}

	Color Cell(int x, int y) {
		return RawBoard[index(x, y)];
	}

};

