#include "pch.h"
#include "CppUnitTest.h"
#include "../Reversi/ColorStorage.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReversiTest
{
	TEST_CLASS(ColorStorageTest)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			ColorStorage<int> s;
			Assert::AreEqual(0, s[EMPTY]);
			Assert::AreEqual(0, s[WHITE]);
			Assert::AreEqual(0, s[BLACK]);
			s[EMPTY] = 60;
			s[WHITE] = 2;
			s[BLACK] = 2;
			
			Assert::AreEqual(60, s[EMPTY]);
			Assert::AreEqual(2, s[WHITE]);
			Assert::AreEqual(2, s[BLACK]);
			s[BLACK]+=2;
			s[WHITE]--;
			Assert::AreEqual(60, s[EMPTY]);
			Assert::AreEqual(1, s[WHITE]);
			Assert::AreEqual(4, s[BLACK]);

		}
		TEST_METHOD(Clear)
		{
			ColorStorage<int> s;
			s[EMPTY] = 60;
			s.Clear();
			Assert::AreEqual(0, s[EMPTY]);
		}
	};
}