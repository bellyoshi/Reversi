#pragma once
#include "Disc.h"
#include <vector>
#include <array>
#include "ColorStorage.h"
#include "Cube.h"
#include "Grid.h"



class Board
{
public:
	static const int SIZE = 8;
private:

	static const int RAW_SIZE = 1 + SIZE + 1;
	Grid<Color,RAW_SIZE,RAW_SIZE> RawBoard {
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

	inline static const int index(int x, int y) {
		return y * RAW_SIZE + x;
	}
	static std::vector<int> MakeDirection();

	static const int MAX_TURNS = 60;
	std::vector<Point> movablePos[MAX_TURNS + 1];
	std::vector<std::vector<Disc>> updateLog;
	
	int turns;
	Cube<int, RAW_SIZE,RAW_SIZE, MAX_TURNS> movableDir;
	Color currentColor = BLACK;
	void initMovable(); 
	void flipDiscs(const Point& point);
	ColorStorage<int> discs;
	void doCountDiscs() {
		discs.Clear();
		for (int i = 0; i < RAW_SIZE * RAW_SIZE;i++) {
			if (RawBoard[i] == GUARD)continue;
			discs[RawBoard[i]]++;
		}
	}
	static std::vector<int> directions;

public:

	int static Directions(int i) {
		return directions[i];
	}

	int DiscCount(Color color) {
		return discs[color];
	}


	Board() {
		doCountDiscs();
		turns = 0;
		initMovable();
	}
	int CheckMobirity(Disc disc);

	int Turns()
	{
		return turns;
	}
	Color CurrentColor() {
		return currentColor;
	}


	Color Cell(int x, int y) {
		return RawBoard[index(x, y)];
	}
	bool Move(Point point) {
		if (point.x <= 0 || point.x > SIZE) return false;
		if (point.y <= 0 || point.y > SIZE) return false;
		flipDiscs(point);
		currentColor = -currentColor;
		return true;
	}
};


