#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" {
	int getPerimeter(int* length, int* width);
	int getArea(int* length, int* width);
	void setLength(int input, int* length);
	void setWidth(int input, int* width);
}

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TESTgetPerimeter)	//First test
		{								//Test getPerimeter

			int length = 9, width = 8;

				int expected = 34;	// Perimeter = 2(length) + 2(width)
									// Perimeter = 2(9) + 2(8)
									// Perimeter = 18 + 16 = 34
					int actual = getPerimeter(&length, &width);	

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TESTgetArea)	//Second test
		{							//Test getArea
			int length = 6, width = 9;

				int expected = 54;	// Area = (length)*(width)
									// Area = (6)*(9) = 54
					int actual = getArea(&length, &width);

			Assert::AreEqual(expected, actual);
		}





		//QUESTION 2

		TEST_METHOD(TESTsetLength)	//Test for setLength
		{							//Length changes until maximum input allowed
									
			int length = 1;	//Initial
			
			int inputLength = 99;	//New input length

				setLength(inputLength, &length);
				Assert::AreEqual(inputLength, length);	//Expected new input to be "99"
		}


		TEST_METHOD(TESTsetLength_INVALID_INPUT)	//Test for setLength
													//Test invalid input
													//Length must remain the same
		{
			int length = 15;	//Initial

			int inputLength = -20;	//New input length

				setLength(inputLength, &length);
				Assert::AreEqual(15, length);	//Expect length to remain "15"
		}

		TEST_METHOD(TESTsetLength_ABOVE_MINIMUM)	//Test for setLength
									//Test input just above maximum range
		{							//Lenth must remain the same
			int length = 34;	//Initial

			int inputLength = 100;	//New input length

				setLength(inputLength, &length);
				Assert::AreEqual(34, length);	//Expect length to remain "34"
		}



			TEST_METHOD(TESTsetWidth)//Test for setWidth
		{							//Width changes until maximum input allowed

			int width = 4;	//Initial

			int inputWidth = 99;	//New input Width

			setWidth(inputWidth, &width);
			Assert::AreEqual(inputWidth, width);	//Expected new input to be "99"
		}


		TEST_METHOD(TESTsetWidth_INVALID_INPUT)	//Test for setWidth
									//Test invalid input
									//Width must remain the same
		{
			int width = 30;	//Initial

			int inputWidth = -20;	//New input width

			setWidth(inputWidth, &width);
			Assert::AreEqual(30, width);	//Expect width to remain "30"
		}

		TEST_METHOD(TESTsetWidth_MINIMUM_MAXIMUM)	//Test for setWidth
									//Test input minimum range and maximum range
		{							//width must change to new input Width
			int width = 1;	//Initial

			int inputWidth = 99;	//New input width

			setWidth(inputWidth, &width);
			Assert::AreEqual(inputWidth, width);	//Expect width to change to "99"
		}









	};
}
