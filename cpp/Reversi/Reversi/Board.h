#pragma once
#include "Disc.h"
#include <vector>

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
	static const int MAX_TURNS = 60;
	std::vector<Point> movablePos[MAX_TURNS + 1];
	int turns;
	int movableDir[MAX_TURNS][8][8];
Color currentColor = BLACK;
void initMovable() {
	Disc disc(1,1,currentColor);
	movablePos[turns].clear();
	for (int x = 1; x <= SIZE; x++) {
		disc.x = x;
		for (int y = 1; y <= SIZE; y++) {
			disc.y = y;
			int dir = CheckMobirity(disc);
			if (dir != 0) {
				movablePos[turns].push_back(disc);
			}
			movableDir[turns][x][y] = dir;
		}
	}
}
public:
	static int* directions;

	int CheckMobirity(Disc disc);

	int Turns()
	{
		return turns;
	}
	Color CurrentColor() {
		return currentColor;
	}
	static void Initialize() {
		directionInit();
	}

	Color Cell(int x, int y) {
		return RawBoard[index(x, y)];
	}
	bool Move(Point point) {
		if (point.x <= 0 || point.x > SIZE) return false;
		if (point.y <= 0 || point.y > SIZE) return false;
		//todo:‚Ð‚Á‚­‚è•Ô‚·

		currentColor = -currentColor;
		return true;
	}
};

