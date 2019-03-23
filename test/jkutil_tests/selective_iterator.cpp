#include <catch2/catch.hpp>
#include <jkutil/selective_iterator.h>

TEST_CASE("make_selective_range", "[selective_iterator][make_selective_range]")
{
	std::vector<int> g;

	jkutil::make_selective_range(g, [](int& i)
	{
		return true;
	});
}