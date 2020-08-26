#include "pch.h"
#include "CppUnitTest.h"
#include "../Reversi/Disc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReversiTest
{
	TEST_CLASS(ReversiTest)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			Disc d;
			Assert::AreEqual(0, d.x);
			Assert::AreEqual(0, d.y);
			Assert::AreEqual(EMPTY, d.color);

		}
	};
}
