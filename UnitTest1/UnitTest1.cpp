#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.1_rec/7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 4;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 30; a[0][1] = 10; a[0][2] = 50; a[0][3] = 70;
			a[1][0] = 20; a[1][1] = 20; a[1][2] = 60; a[1][3] = 80;
			a[2][0] = 30; a[2][1] = 10; a[2][2] = 40; a[2][3] = 90;

			RecursiveSort(a, rowCount, colCount);

			Assert::IsTrue(a[0][0] == 20);
			Assert::IsTrue(a[1][0] == 30 && a[1][1] == 10 && a[1][3] == 90);
			Assert::IsTrue(a[2][0] == 30 && a[2][1] == 10 && a[2][3] == 70);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
