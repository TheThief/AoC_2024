#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include <range/v3/all.hpp>

using namespace std::string_view_literals;

namespace aoc2024::day1
{
	struct puzzle_input
	{
		std::vector<std::array<int, 2>> lines;

		friend std::istream& operator>>(std::istream& is, puzzle_input& input)
		{
			input.lines = ranges::getlines(is) | ranges::views::transform(
				[](const std::string& line)
				{
					std::array<int, 2> values;
					std::stringstream(line) >> values[0] >> values[1];
					return values;
				}) | ranges::to<std::vector>();

			return is;
		}
	};

	int part1(const puzzle_input& input)
	{
		std::array<std::vector<int>, 2> values = {
			input.lines | ranges::views::transform(
				[](const auto& line)
				{
					return line[0];
				}) | ranges::to<std::vector>,
			input.lines | ranges::views::transform(
				[](const auto& line)
				{
					return line[1];
				}) | ranges::to<std::vector>,
		};
		ranges::sort(values[0]);
		ranges::sort(values[1]);
		return ranges::accumulate(
			ranges::views::zip_with(
				[](auto a, auto b)
				{
					return std::abs(a - b);
				},
				values[0], values[1]), 0);
	}

	int part2(const puzzle_input& input)
	{
		std::array<std::vector<int>, 2> values = {
			input.lines | ranges::views::transform(
				[](const auto& line)
				{
					return line[0];
				}) | ranges::to<std::vector>,
			input.lines | ranges::views::transform(
				[](const auto& line)
				{
					return line[1];
				}) | ranges::to<std::vector>,
		};
		ranges::sort(values[0]);
		ranges::sort(values[1]);

		std::vector<std::map<int, int>> counts =
			values | ranges::views::transform(
				[](const auto& set)
				{
					return set
						| ranges::views::group_by(std::equal_to())
						| ranges::views::transform(
							[](const auto& group)
							{
								return std::pair(group[0], (int)group.size());
							}) | ranges::to<std::map>;
				}) | ranges::to<std::vector>;

		return ranges::accumulate(
			counts[0] | ranges::views::transform(
				[&](const auto& countpair)
				{
					return countpair.first * counts[1][countpair.first] * countpair.second;
				}), (int64_t)0);
	}
}
