#include "Board.h"

class Initializer {
public:
	Initializer() {
		Board::Initialize();
	}
};

Initializer instance;

std::vector<int>* Board::directions;

int Board::CheckMobirity(Disc disc)
{
	int disc_p = index(disc.x, disc.y);
	if (RawBoard[disc_p] != EMPTY) return 0;

	Color revcolor = -disc.color;
	int allMobirity = 0;
	int dirMobirity = 1;
	for (int dir : *directions) {
		int p = disc_p + dir;
		if (RawBoard[p] == revcolor)
		{
			p += dir;
			while (RawBoard[p] == revcolor) p += dir;
			if (RawBoard[p] == disc.color) allMobirity |= dirMobirity;
		}
		dirMobirity <<= 1;
	}
	return allMobirity;
}

void Board::initMovable() {
	Disc disc(1, 1, currentColor);
	movablePos[turns].clear();
	for (int x = 1; x <= SIZE; x++) {
		disc.x = x;
		for (int y = 1; y <= SIZE; y++) {
			disc.y = y;
			int dir = CheckMobirity(disc);
			if (dir != 0) {
				movablePos[turns].push_back(disc);
			}
			movableDir.Cells(x,y,turns) = dir;
		}
	}
}

void Board::flipDiscs(const Point& point)
{
	Disc ope_disc(point.x, point.y, currentColor);
	int putdisc_p = index(point.x, point.y);
	int dir = movableDir.Cells(point.x,point.y,turns); 
	std::vector<Disc> update;
	RawBoard[putdisc_p] = currentColor;
	update.push_back(ope_disc);
	for (int mobirity = 1,i = 0; i < 8; mobirity <<= 1, ++i) {
		if (dir & mobirity) {
			int p = putdisc_p + ((*directions)[i]);
			while (RawBoard[p] == -currentColor) {
				RawBoard[p] = currentColor;
				ope_disc.x = p % RAW_SIZE;
				ope_disc.y = p / RAW_SIZE;
				update.push_back(ope_disc);

			}
		}
		
	}
	int discdiff = update.size();
	discs[currentColor] += discdiff;
	discs[-currentColor] -= discdiff - 1;
	discs[EMPTY]--;
	updateLog.push_back(update);

}
