#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../Lab 8.1.2.1/Lab 8.1.2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(StringManipulationTest)
    {
    public:
        TEST_METHOD(TestCount)
        {
            char str1[] = "while abc while def while";
            Assert::AreEqual(Count(str1, 0), 3);

            char str2[] = "abc while def while ghi";
            Assert::AreEqual(Count(str2, 0), 2);

            char str3[] = "no occurrences";
            Assert::AreEqual(Count(str3, 0), 0);
        }

        TEST_METHOD(TestChange)
        {
            char str1[100] = "while dsf while jte while";
            char* dest = new char[151];
            dest = Change(str1);
            Assert::AreEqual(dest, "*** dsf *** jte ***");
            char str2[100] = "feg while bnm while u";
            dest = new char[151];
            dest = Change(str2);
            Assert::AreEqual(dest, "feg *** bnm *** u");
            char str3[100] = "no one whil e";
            dest = new char[151];
            dest = Change(str3);
            Assert::AreEqual(dest, str3);
        }
    };
}
