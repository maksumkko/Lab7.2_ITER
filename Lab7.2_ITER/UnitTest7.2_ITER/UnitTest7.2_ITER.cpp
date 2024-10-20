#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2_ITER/Lab7.2_ITER.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72ITER
{
	TEST_CLASS(UnitTest72ITER)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 3;
			int n = 3;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 10; a[0][1] = 15; a[0][2] = 5;
			a[1][0] = 20; a[1][1] = 25; a[1][2] = 30;
			a[2][0] = 1;  a[2][1] = 3;  a[2][2] = 2;

			int expected_sum = 5 + 20 + 1;

			Assert::AreEqual(expected_sum, sum(a, k, n));
		}
	};
}
