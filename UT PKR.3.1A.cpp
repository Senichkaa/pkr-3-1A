#include "pch.h"
#include "CppUnitTest.h"
#include "../pkr 3.1A/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTPKR31A
{
	TEST_CLASS(UTPKR31A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* arr = new Student[2];
			arr[0] = { "A", 1, Spec::IT, 5, 2, 4 };
			arr[1] = { "B", 1, Spec::IT, 4, 5, 3 };

			Assert::AreEqual(50., GoodStudent(arr, 2));
		}
	};
}
