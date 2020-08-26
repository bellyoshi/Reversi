#include "Board.h"

class Initializer {
public:
	Initializer() {
		Board::Initialize();
	}
};

Initializer instance;

int* Board::directions;