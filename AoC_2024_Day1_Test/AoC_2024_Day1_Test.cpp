#include "CppUnitTest.h"

#include <sstream>
#include <string_view>
#include "AoC_2024_Day1/AoC_2024_Day1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;

namespace aoc2024::day1::test
{
	const std::string test_input_1 =
R"(3   4
4   3
2   5
1   3
3   9
3   3)"s;

	const std::string& test_input_2 = test_input_1;

	const int expected_test_ouput_1 = 11;
	const int expected_test_ouput_2 = 31;

	TEST_CLASS(Test)
	{
	public:
		Test()
		{
		}

		TEST_METHOD(Part1)
		{
			puzzle_input input;
			std::istringstream(test_input_1) >> input;
			Assert::AreEqual(expected_test_ouput_1, part1(input));
		}

		TEST_METHOD(Part2)
		{
			puzzle_input input;
			std::istringstream(test_input_2) >> input;
			Assert::AreEqual(expected_test_ouput_2, part2(input));
		}
	};
}
