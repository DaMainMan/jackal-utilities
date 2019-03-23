#include <jkutil/aligned.h>
#include <catch2/catch.hpp>
#include <memory>

TEST_CASE("aligned - Element is not under-aligned, when requested alignment is low.", "[aligned]")
{
	jkutil::aligned<double, 2> A;
	void* ptr = &A.value;
	std::size_t space = sizeof(double);
	REQUIRE(std::align(alignof(double), sizeof(double), ptr, space) != nullptr);
}

TEST_CASE("aligned - Element is over-aligned as requested.", "[aligned]")
{
	jkutil::aligned<int, 64> A;
	void* ptr = &A.value;
	std::size_t space = sizeof(int);
	REQUIRE(std::align(64, sizeof(int), ptr, space) != nullptr);
}

TEST_CASE("aligned - Default alignment is correct.", "[aligned]")
{
	jkutil::aligned<double> A;
	void* ptr = &A.value;
	std::size_t space = sizeof(double);
	REQUIRE(std::align(alignof(double), sizeof(double), ptr, space) != nullptr);
}

TEST_CASE("aligned - Element is corectly aligned, when its exact alignment is requested.", "[aligned]")
{
	jkutil::aligned<double, alignof(double)> A;
	void* ptr = &A.value;
	std::size_t space = sizeof(double);
	REQUIRE(std::align(alignof(double), sizeof(double), ptr, space) != nullptr);
}