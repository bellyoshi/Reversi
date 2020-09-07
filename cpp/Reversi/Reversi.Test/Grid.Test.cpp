#include "pch.h"
#include "CppUnitTest.h"
#include "../Reversi/Grid.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReversiTest
{
	TEST_CLASS(GridTest)
	{
	public:
		TEST_METHOD(Large)
		{
			Grid<int,1024,1024> d;
		}
		TEST_METHOD(Cells)
		{
			const int a = 2;
			const int b = a * a;

			Grid<int,a,b> g;
			g.Cells(1, 1) = 12345;
			Assert::AreEqual(12345, g.Cells(1, 1));
		}
	};
}
