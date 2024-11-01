#include "pch.h"
#include "CppUnitTest.h"
#include "../lab72it/lab72it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int testMatrix[4][5] = {
                {10, 20, 30, 40, 50},
                {5, 15, 25, 35, 45},
                {7, 14, 21, 28, 35},
                {1, 2, 3, 4, 5}
            };

            
            int expected = 35; 

            
            int result = findMinOfMaxInEvenRows(&testMatrix[0][0], 4, 5);

            
            Assert::AreEqual(expected, result);
        
		};
	};
}
