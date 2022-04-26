#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_oop_3.3F\LongLong.cpp"
#include "..\Lab_12_oop_3.3F\PrivateCursor.cpp"
#include "..\Lab_12_oop_3.3F\PubicCursor.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			PrivateCursor p;
			p.move(10, 10);
			Assert::IsTrue(p.getPosition().getHigh() == 10 && p.getPosition().getLow() == 10);
		}
	};
}
