#include <jkutil\derived.h>
#include <jkutil\test_allocator.h>
#include <catch2\catch.hpp>

TEST_CASE("derived - Emplacment", "[derived]")
{
	jkutil::derived<int, jkutil::test_allocator> d;

	d.emplace<int>(45);
	REQUIRE(*d.get() == 45);
	REQUIRE(d.size() == sizeof(int));

	d.emplace<int>(67);
	REQUIRE(*d.get() == 67);
	REQUIRE(d.size() == sizeof(int));

	d.reset();
	REQUIRE(d.get() == nullptr);
	REQUIRE(!d.has_value());
	REQUIRE(d.size() == 0);
}

class A
{
public:
	int A_value = 12;
};

class B : public A
{
public:
	int B_value = 34;
};

class C : public A
{
public:
	int C_value = 67;
};

TEST_CASE("derived - Derived object emplacement", "[derived]")
{
	jkutil::derived<A, jkutil::test_allocator> d;

	d.emplace<B>(B());
	REQUIRE(static_cast<B*>(d.get())->B_value == 34);
	REQUIRE(static_cast<B*>(d.get())->A_value == 12);

	d.get()->A_value = 8;
	REQUIRE(static_cast<B*>(d.get())->B_value == 34);
	REQUIRE(static_cast<B*>(d.get())->A_value == 8);

	d.emplace<C>(C());
	REQUIRE(static_cast<B*>(d.get())->B_value == 67);
	REQUIRE(static_cast<B*>(d.get())->A_value == 12);
}