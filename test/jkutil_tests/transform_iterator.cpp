#include <catch2/catch.hpp>
#include <jkutil/transform_iterator.h>

TEST_CASE("make_transform_range", "[transform_iterator][make_transform_range]")
{
	std::vector<int> g;

	jkutil::make_transform_range(g, [](int& i)
	{
		return i + 1;
	});
}