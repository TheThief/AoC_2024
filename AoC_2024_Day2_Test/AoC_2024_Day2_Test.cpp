#include "CppUnitTest.h"

#include "AoC_2024_Day2/AoC_2024_Day2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;

namespace aoc2024::day2::test
{
	const std::string test_input_1 =
R"(7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9)"s;

	const std::string& test_input_2 = test_input_1;

	const int64_t expected_test_ouput_1 = 2;
	const int64_t expected_test_ouput_2 = 31;

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
