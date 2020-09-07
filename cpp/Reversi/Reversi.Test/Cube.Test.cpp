#include "pch.h"
#include "CppUnitTest.h"
#include "../Reversi/Cube.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReversiTest
{
	TEST_CLASS(CubeTest)
	{
	public:
		
		TEST_METHOD(Cells)
		{
			Cube<int,10,10,64> g;
			g.Cells(1, 1,1) = 12345;
			Assert::AreEqual(12345, g.Cells(1, 1,1));
		}
	};
}
