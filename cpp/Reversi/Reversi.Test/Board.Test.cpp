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

		}
	};
}