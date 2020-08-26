#include "pch.h"
#include "CppUnitTest.h"
#include "../Reversi/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReversiTest
{
	TEST_CLASS(PointTest)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			Assert::AreEqual(true, !false);
			Point p;
			Assert::AreEqual(0, p.x);
			Assert::AreEqual(0, p.y);


		}
		TEST_METHOD(Constructor)
		{
			Point p(2, 3);
			Assert::AreEqual(2, p.x);
			Assert::AreEqual(3, p.y);
		}

	};
}