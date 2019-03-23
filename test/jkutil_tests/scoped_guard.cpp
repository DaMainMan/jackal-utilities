#include <catch2\catch.hpp>
#include <jkutil\scoped_guard.h>

TEST_CASE("scoped_guard - enable", "[scoped_guard]")
{
	int value = 0;
	{
		auto guard = jkutil::make_scoped_guard([&value]()
		{
			++value;
		});
		guard.enable();
		REQUIRE(value == 0);
	}
	REQUIRE(value == 1);
}

TEST_CASE("scoped_guard - disable", "[scoped_guard]")
{
	int value = 0;
	{
		auto guard = jkutil::make_scoped_guard([&value]()
		{
			++value;
		});
		guard.disable();
		REQUIRE(value == 0);
	}
	REQUIRE(value == 0);
}

TEST_CASE("scoped_guard - move constructor", "[scoped_guard]")
{
	int value = 0;
	{
		auto guard = jkutil::make_scoped_guard([&value]()
		{
			++value;
		});
		REQUIRE(value == 0);
		{
			auto move_guard = std::move(guard);
			REQUIRE(value == 0);
		}
		REQUIRE(value == 1);
	}
	REQUIRE(value == 1);
}

TEST_CASE("scoped_guard - move and re-enable", "[scoped_guard]")
{
	int value = 0;
	{
		auto guard = jkutil::make_scoped_guard([&value]()
		{
			++value;
		});
		REQUIRE(value == 0);
		{
			auto move_guard = std::move(guard);
			guard.enable();
			REQUIRE(value == 0);
		}
		REQUIRE(value == 1);
	}
	REQUIRE(value == 1);
}