#pragma once

//#include <range/v3/all.hpp>

#include "common/stream_line.h"

import std;

using namespace std::string_view_literals;

namespace aoc2024::day2
{
	struct puzzle_input
	{
		std::vector<std::vector<int>> lines;

		friend std::istream& operator>>(std::istream& is, puzzle_input& input)
		{
			input.lines = std::ranges::istream_view<line<std::vector<int>>>(is) | std::ranges::to<std::vector<std::vector<int>>>();

			return is;
		}
	};

	enum class change
	{
		inc,
		dec,
		err
	};

	std::int64_t part1(const puzzle_input& input)
	{
		return std::ranges::count_if(
			input.lines
			| std::ranges::views::transform(
				[](const std::vector<int>& line)
				{
					auto sliding = line | std::ranges::views::pairwise | std::ranges::to<std::vector>();
					auto to_change =
						[](auto& pair)
						{
							if (std::get<0>(pair) < std::get<1>(pair) && std::get<1>(pair) - std::get<0>(pair) <= 3)
							{
								return change::inc;
							}
							if (std::get<1>(pair) < std::get<0>(pair) && std::get<0>(pair) - std::get<1>(pair) <= 3)
							{
								return change::dec;
							}
							return change::err;
						};
					auto changes = sliding
						| std::ranges::views::transform(
							to_change) | std::ranges::to<std::vector>();
					return *std::ranges::fold_left_first(
						changes
						, [](change lhs, change rhs)
						{
							return lhs == rhs ? lhs : change::err;
						});
				})
			, [](change line_result)
			{
				return line_result != change::err;
			});
	}

	std::int64_t part2(const puzzle_input& input)
	{
		return 0;
	}
}
