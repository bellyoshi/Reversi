#include "Board.h"

class Initializer {
public:
	Initializer() {
		Board::Initialize();
	}
};

Initializer instance;

int* Board::directions;

int Board::CheckMobirity(Disc disc)
{
	int disc_p = index(disc.x, disc.y);
	if (RawBoard[disc_p] != EMPTY) return 0;

	Color revcolor = -disc.color;
	int allMobirity = 0;
	int dirMobirity = 1;
	for (int i = 0; i < 8; i++) {
		int dir = directions[i];

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