#include "Board.h"



void Board::MakeDirection()
{
	int upper = RawBoard.index(0, -1);
	int left = RawBoard.index(-1, 0);
	int right = RawBoard.index(1, 0);
	int lower = RawBoard.index(0, 1);
	directions.push_back(upper);
	directions.push_back(upper + left);
	directions.push_back(left);
	directions.push_back(lower + left);
	directions.push_back(lower);
	directions.push_back(lower + right);
	directions.push_back(right);
	directions.push_back(upper + right);
}

int Board::CheckMobirity(Disc disc)
{
	int disc_p = RawBoard.index(disc.x, disc.y);
	if (RawBoard[disc_p] != EMPTY) return 0;

	Color revcolor = -disc.color;
	int allMobirity = 0;
	int dirMobirity = 1;
	for (int dir : directions) {
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
	int putdisc_p = RawBoard.index(point.x, point.y);
	int dir = movableDir.Cells(point.x,point.y,turns); 
	std::vector<Disc> update;
	RawBoard[putdisc_p] = currentColor;
	update.push_back(ope_disc);
	int mobirity = 1;
	for (int direction : directions) {
		if (dir & mobirity) {
			int p = putdisc_p + direction;
			while (RawBoard[p] == -currentColor) {
				RawBoard[p] = currentColor;
				ope_disc.x = p % RAW_SIZE;
				ope_disc.y = p / RAW_SIZE;
				update.push_back(ope_disc);
			}
		}
		mobirity <<= 1;
	}
	int discdiff = update.size();
	discs[currentColor] += discdiff;
	discs[-currentColor] -= discdiff - 1;
	discs[EMPTY]--;
	updateLog.push_back(update);

}
