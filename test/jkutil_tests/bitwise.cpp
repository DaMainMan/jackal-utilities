#include <catch2/catch.hpp>
#include <jkutil/bitwise.h>

TEST_CASE("all_highest_bits", "[bitwise][all_highest_bits]")
{
	REQUIRE(jkutil::all_highest_bits(0xffff'ffffU) == 0xffff'ffffU);
	REQUIRE(jkutil::all_highest_bits(0x0000'0000U) == 0x0000'0000U);
	REQUIRE(jkutil::all_highest_bits(0x0000'0001U) == 0xffff'ffffU);
	REQUIRE(jkutil::all_highest_bits(0x8000'0000U) == 0x8000'0000U);
	REQUIRE(jkutil::all_highest_bits(0x0000'1000U) == 0xffff'f000U);

	REQUIRE(jkutil::all_highest_bits(0xffff'ffff'ffff'ffffULL) == 0xffff'ffff'ffff'ffffULL);
	REQUIRE(jkutil::all_highest_bits(0x0000'0000'0000'0000ULL) == 0x0000'0000'0000'0000ULL);
	REQUIRE(jkutil::all_highest_bits(0x0000'0000'0000'0001ULL) == 0xffff'ffff'ffff'ffffULL);
	REQUIRE(jkutil::all_highest_bits(0x8000'0000'0000'0000ULL) == 0x8000'0000'0000'0000ULL);
	REQUIRE(jkutil::all_highest_bits(0x0000'0000'1000'0000ULL) == 0xffff'ffff'f000'0000ULL);
}

TEST_CASE("all_lowest_bits", "[bitwise][all_lowest_bits]")
{
	REQUIRE(jkutil::all_lowest_bits(0xffff'ffffU) == 0xffff'ffffU);
	REQUIRE(jkutil::all_lowest_bits(0x0000'0000U) == 0x0000'0000U);
	REQUIRE(jkutil::all_lowest_bits(0x0000'0001U) == 0x0000'0001U);
	REQUIRE(jkutil::all_lowest_bits(0x8000'0000U) == 0xffff'ffffU);
	REQUIRE(jkutil::all_lowest_bits(0x0000'1000U) == 0x0000'1fffU);

	REQUIRE(jkutil::all_lowest_bits(0xffff'ffff'ffff'ffffULL) == 0xffff'ffff'ffff'ffffULL);
	REQUIRE(jkutil::all_lowest_bits(0x0000'0000'0000'0000ULL) == 0x0000'0000'0000'0000ULL);
	REQUIRE(jkutil::all_lowest_bits(0x0000'0000'0000'0001ULL) == 0x0000'0000'0000'0001ULL);
	REQUIRE(jkutil::all_lowest_bits(0x8000'0000'0000'0000ULL) == 0xffff'ffff'ffff'ffffULL);
	REQUIRE(jkutil::all_lowest_bits(0x0000'0000'1000'0000ULL) == 0x0000'0000'1fff'ffffULL);
}

TEST_CASE("floor_pow2", "[bitwise][floor_pow2]")
{
	REQUIRE(jkutil::floor_pow2(0xffff'ffffU) == 0x8000'0000U);
	REQUIRE(jkutil::floor_pow2(0x0000'0000U) == 0x0000'0000U);
	REQUIRE(jkutil::floor_pow2(0x0000'0001U) == 0x0000'0001U);
	REQUIRE(jkutil::floor_pow2(0x8000'0000U) == 0x8000'0000U);
	REQUIRE(jkutil::floor_pow2(0x0000'1110U) == 0x0000'1000U);

	REQUIRE(jkutil::floor_pow2(0xffff'ffff'ffff'ffffULL) == 0x8000'0000'0000'0000ULL);
	REQUIRE(jkutil::floor_pow2(0x0000'0000'0000'0000ULL) == 0x0000'0000'0000'0000ULL);
	REQUIRE(jkutil::floor_pow2(0x0000'0000'0000'0001ULL) == 0x0000'0000'0000'0001ULL);
	REQUIRE(jkutil::floor_pow2(0x8000'0000'0000'0000ULL) == 0x8000'0000'0000'0000ULL);
	REQUIRE(jkutil::floor_pow2(0x0000'0000'1010'0010ULL) == 0x0000'0000'1000'0000ULL);
}

TEST_CASE("ceil_pow2", "[bitwise][ceil_pow2]")
{
	REQUIRE(jkutil::ceil_pow2(0xffff'ffffU) == 0x0000'0000U);
	REQUIRE(jkutil::ceil_pow2(0x0000'0000U) == 0x0000'0001U);
	REQUIRE(jkutil::ceil_pow2(0x0000'0001U) == 0x0000'0001U);
	REQUIRE(jkutil::ceil_pow2(0x8000'0000U) == 0x8000'0000U);
	REQUIRE(jkutil::ceil_pow2(0x0000'1110U) == 0x0000'2000U);

	REQUIRE(jkutil::ceil_pow2(0xffff'ffff'ffff'ffffULL) == 0x0000'0000'0000'0000ULL);
	REQUIRE(jkutil::ceil_pow2(0x0000'0000'0000'0000ULL) == 0x0000'0000'0000'0001ULL);
	REQUIRE(jkutil::ceil_pow2(0x0000'0000'0000'0001ULL) == 0x0000'0000'0000'0001ULL);
	REQUIRE(jkutil::ceil_pow2(0x8000'0000'0000'0000ULL) == 0x8000'0000'0000'0000ULL);
	REQUIRE(jkutil::ceil_pow2(0x0000'0000'1010'0010ULL) == 0x0000'0000'2000'0000ULL);
}

TEST_CASE("downto_pow2", "[bitwise][downto_pow2]")
{
	REQUIRE(jkutil::downto_pow2(0xffff'ffffU) == 0x8000'0000U);
	REQUIRE(jkutil::downto_pow2(0x0000'0000U) == 0x0000'0001U);
	REQUIRE(jkutil::downto_pow2(0x0000'0001U) == 0x0000'0001U);
	REQUIRE(jkutil::downto_pow2(0x8000'0000U) == 0x8000'0000U);
	REQUIRE(jkutil::downto_pow2(0x0000'1110U) == 0x0000'1000U);

	REQUIRE(jkutil::downto_pow2(0xffff'ffff'ffff'ffffULL) == 0x8000'0000'0000'0000ULL);
	REQUIRE(jkutil::downto_pow2(0x0000'0000'0000'0000ULL) == 0x0000'0000'0000'0001ULL);
	REQUIRE(jkutil::downto_pow2(0x0000'0000'0000'0001ULL) == 0x0000'0000'0000'0001ULL);
	REQUIRE(jkutil::downto_pow2(0x8000'0000'0000'0000ULL) == 0x8000'0000'0000'0000ULL);
	REQUIRE(jkutil::downto_pow2(0x0000'0000'1010'0010ULL) == 0x0000'0000'1000'0000ULL);
}

TEST_CASE("upto_pow2", "[bitwise][upto_pow2]")
{
	REQUIRE(jkutil::upto_pow2(0xffff'ffffU) == 0x8000'0000U);
	REQUIRE(jkutil::upto_pow2(0x0000'0000U) == 0x0000'0001U);
	REQUIRE(jkutil::upto_pow2(0x0000'0001U) == 0x0000'0001U);
	REQUIRE(jkutil::upto_pow2(0x8000'0000U) == 0x8000'0000U);
	REQUIRE(jkutil::upto_pow2(0x0000'1110U) == 0x0000'2000U);

	REQUIRE(jkutil::upto_pow2(0xffff'ffff'ffff'ffffULL) == 0x8000'0000'0000'0000ULL);
	REQUIRE(jkutil::upto_pow2(0x0000'0000'0000'0000ULL) == 0x0000'0000'0000'0001ULL);
	REQUIRE(jkutil::upto_pow2(0x0000'0000'0000'0001ULL) == 0x0000'0000'0000'0001ULL);
	REQUIRE(jkutil::upto_pow2(0x8000'0000'0000'0000ULL) == 0x8000'0000'0000'0000ULL);
	REQUIRE(jkutil::upto_pow2(0x0000'0000'1010'0010ULL) == 0x0000'0000'2000'0000ULL);
}

TEST_CASE("is_pow2", "[bitwise][is_pow2]")
{
	REQUIRE(!jkutil::is_pow2(0xffff'ffffU));
	REQUIRE(!jkutil::is_pow2(0x0000'0000U));
	REQUIRE(jkutil::is_pow2(0x0000'0001U));
	REQUIRE(jkutil::is_pow2(0x8000'0000U));
	REQUIRE(!jkutil::is_pow2(0x0000'1110U));

	REQUIRE(!jkutil::is_pow2(0xffff'ffff'ffff'ffffULL));
	REQUIRE(!jkutil::is_pow2(0x0000'0000'0000'0000ULL));
	REQUIRE(jkutil::is_pow2(0x0000'0000'0000'0001ULL));
	REQUIRE(jkutil::is_pow2(0x8000'0000'0000'0000ULL));
	REQUIRE(!jkutil::is_pow2(0x0000'0000'1010'0010ULL));
}

TEST_CASE("int_log2", "[bitwise][int_log2]")
{
	REQUIRE(jkutil::int_log2(0xffff'ffffU) == 31);
	REQUIRE(jkutil::int_log2(0x0000'0000U) == 0);
	REQUIRE(jkutil::int_log2(0x0000'0001U) == 0);
	REQUIRE(jkutil::int_log2(0x8000'0000U) == 31);
	REQUIRE(jkutil::int_log2(0x0000'1110U) == 12);

	REQUIRE(jkutil::int_log2(0xffff'ffff'ffff'ffffULL) == 63);
	REQUIRE(jkutil::int_log2(0x0000'0000'0000'0000ULL) == 0);
	REQUIRE(jkutil::int_log2(0x0000'0000'0000'0001ULL) == 0);
	REQUIRE(jkutil::int_log2(0x8000'0000'0000'0000ULL) == 63);
	REQUIRE(jkutil::int_log2(0x0000'0000'1010'0010ULL) == 28);
}

TEST_CASE("int_ceil_log2", "[bitwise][int_ceil_log2]")
{
	REQUIRE(jkutil::int_ceil_log2(0xffff'ffffU) == 32);
	REQUIRE(jkutil::int_ceil_log2(0x0000'0000U) == 0);
	REQUIRE(jkutil::int_ceil_log2(0x0000'0001U) == 0);
	REQUIRE(jkutil::int_ceil_log2(0x8000'0000U) == 31);
	REQUIRE(jkutil::int_ceil_log2(0x0000'1110U) == 13);

	REQUIRE(jkutil::int_ceil_log2(0xffff'ffff'ffff'ffffULL) == 64);
	REQUIRE(jkutil::int_ceil_log2(0x0000'0000'0000'0000ULL) == 0);
	REQUIRE(jkutil::int_ceil_log2(0x0000'0000'0000'0001ULL) == 0);
	REQUIRE(jkutil::int_ceil_log2(0x8000'0000'0000'0000ULL) == 63);
	REQUIRE(jkutil::int_ceil_log2(0x0000'0000'1010'0010ULL) == 29);
}