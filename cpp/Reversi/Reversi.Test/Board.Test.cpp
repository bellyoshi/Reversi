#include "pch.h"
#include "CppUnitTest.h"
#include "../Reversi/Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReversiTest
{
	TEST_CLASS(BoardTest)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			Assert::AreEqual(8, Board::SIZE);
			Board b;
			for (int i = 0; i < Board::SIZE + 2; ++i)
			{
				Assert::AreEqual(GUARD, b.Cell(0, i));
				Assert::AreEqual(GUARD, b.Cell(Board::SIZE + 1, i));
				Assert::AreEqual(GUARD, b.Cell(i, 0));
				Assert::AreEqual(GUARD, b.Cell(i, Board::SIZE + 1));
			}
			for (int x = 1; x <= Board::SIZE; ++x) {
				for (int y = 1; y <= Board::SIZE; ++y) {
					if (x == 4 || x == 5 || y == 4 || y == 5) 
						continue;
					Assert::AreEqual(EMPTY, b.Cell(x, y));
				}
			}
			Assert::AreEqual(BLACK, b.Cell(4, 5));
			Assert::AreEqual(BLACK, b.Cell(5, 4));
			Assert::AreEqual(WHITE, b.Cell(4, 4));
			Assert::AreEqual(WHITE, b.Cell(5, 5));

			Assert::AreEqual(BLACK, b.CurrentColor());

		}
		TEST_METHOD(Directions) {
			Board b;
			Assert::AreEqual(-10, Board::directions[0]);
			Assert::AreEqual(-11, Board::directions[1]);
			Assert::AreEqual(-1, Board::directions[2]);
			Assert::AreEqual(9, Board::directions[3]);
			Assert::AreEqual(10, Board::directions[4]);
			Assert::AreEqual(11, Board::directions[5]);
			Assert::AreEqual(1, Board::directions[6]);
			Assert::AreEqual(-9, Board::directions[7]);

		}
		TEST_METHOD(Move) {
			Board b;
			Assert::AreEqual(true, b.Move(Point(1, 1)));
			Assert::AreEqual(true, b.Move(Point(8, 8)));
			Assert::AreEqual(false, b.Move(Point(0, 1)));
			Assert::AreEqual(false, b.Move(Point(1, 0)));
			Assert::AreEqual(false, b.Move(Point(9, 5)));
			Assert::AreEqual(false, b.Move(Point(5, 9)));
		}
		TEST_METHOD(CheckMobirity) {
			Board b;
			Assert::AreEqual(0B000000001, b.CheckMobirity(Disc(5, 6,BLACK)));
			Assert::AreEqual(0B000010000, b.CheckMobirity(Disc(4, 3, BLACK)));
			Assert::AreEqual(0B001000000, b.CheckMobirity(Disc(3, 4, BLACK)));
			Assert::AreEqual(0B000000100, b.CheckMobirity(Disc(6, 5, BLACK)));
			for (int x = 1; x <= 8; x++) {
				for (int y = 1; y <= 8; y++) {
					if (x == 5 && y == 6)continue;
					if (x == 4 && y == 3)continue;
					if (x == 3 && y == 4)continue;
					if (x == 6 && y == 5)continue;
					Assert::AreEqual(0B0000000, b.CheckMobirity(Disc(x, y, BLACK)));
				}
			}
		}
		TEST_METHOD(MoveDiscs) {
			Board b;
			b.Move(Point(5, 6));
			Assert::AreEqual(4, b.DiscCount(BLACK));
			Assert::AreEqual(1, b.DiscCount(WHITE));
		
		}
	};
}