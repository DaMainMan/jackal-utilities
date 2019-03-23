#include <jkutil/array_proxy.h>
#include <jkutil/zip.h>
#include <vector>
#include <catch2/catch.hpp>

TEST_CASE("array_proxy - Default constructed is empty.","[array_proxy]")
{
	jkutil::array_proxy<int> a;

	REQUIRE(a.empty());
	REQUIRE(a.begin() == a.end());
	REQUIRE(a.size() == 0);
	REQUIRE(a.cbegin() == a.cend());
	REQUIRE(const_cast<const jkutil::array_proxy<int>&>(a).begin() == const_cast<const jkutil::array_proxy<int>&>(a).end());
	REQUIRE(a.data() == nullptr);

}

TEST_CASE("array_proxy - Nullptr constructed is empty.", "[array_proxy]")
{
	jkutil::array_proxy<int> a = jkutil::array_proxy<int>(nullptr);

	REQUIRE(a.empty());
	REQUIRE(a.begin() == a.end());
	REQUIRE(a.size() == 0);
	REQUIRE(a.cbegin() == a.cend());
	REQUIRE(const_cast<const jkutil::array_proxy<int>&>(a).begin() == const_cast<const jkutil::array_proxy<int>&>(a).end());
	REQUIRE(a.data() == nullptr);

}

TEST_CASE("array_proxy - Manually empty constructed is empty.", "[array_proxy]")
{
	SECTION("Manually empty constructed")
	{
		jkutil::array_proxy<int> a = jkutil::array_proxy<int>(0, nullptr);

		REQUIRE(a.empty());
		REQUIRE(a.begin() == a.end());
		REQUIRE(a.size() == 0);
		REQUIRE(a.cbegin() == a.cend());
		REQUIRE(const_cast<const jkutil::array_proxy<int>&>(a).begin() == const_cast<const jkutil::array_proxy<int>&>(a).end());
		REQUIRE(a.data() == nullptr);
	}
	SECTION("Manually empty constructed - None nullptr data pointer.")
	{
		jkutil::array_proxy<int> a = jkutil::array_proxy<int>(0, reinterpret_cast<int*>(64));

		REQUIRE(a.empty());
		REQUIRE(a.begin() == a.end());
		REQUIRE(a.size() == 0);
		REQUIRE(a.cbegin() == a.cend());
		REQUIRE(const_cast<const jkutil::array_proxy<int>&>(a).begin() == const_cast<const jkutil::array_proxy<int>&>(a).end());
		REQUIRE(a.data() == nullptr);
	}
}

TEST_CASE("array_proxy - Copy assignment.", "[array_proxy]")
{
	jkutil::array_proxy<int> a;

	SECTION("Empty copy assignment.")
	{
		jkutil::array_proxy<int> b;

		//----//
		a = b;
		//----//

		REQUIRE(a.empty());
		REQUIRE(b.empty());
	}
	SECTION("Non-empty to empty copy assignment.")
	{
		std::vector<int> vec;
		vec.assign({1, 2, 3, 4});

		jkutil::array_proxy<int> b = jkutil::make_array_proxy(vec.size(),vec.data());

		//----//
		a = b;
		//----//

		REQUIRE(!a.empty());
		REQUIRE(!b.empty());
		REQUIRE(a.size() == b.size());
		REQUIRE(a.data() == b.data());
		REQUIRE(a.size() == vec.size());
		REQUIRE(a.data() == vec.data());
	}
	SECTION("Non-empty to Non-empty copy assignment.")
	{
		std::vector<int> vec1;
		vec1.assign({ 1, 2, 3, 4 });

		jkutil::array_proxy<int> b = jkutil::make_array_proxy(vec1.size(), vec1.data());

		for (auto i : jkutil::make_zip_range(b, vec1))
		{
			REQUIRE(std::get<0>(i) == std::get<1>(i));
		}

		std::vector<int> vec2;
		vec2.assign({ 8, 9, 10, 11 });

		a = jkutil::make_array_proxy(vec2.size(), vec2.data());

		for (auto i : jkutil::make_zip_range(a,vec2))
		{
			REQUIRE(std::get<0>(i) == std::get<1>(i));
		}

		REQUIRE(a.data() == vec2.data());
		REQUIRE(!a.empty());

		//----//
		a = b;
		//----//

		for (auto i : jkutil::make_zip_range(a, vec1))
		{
			REQUIRE(std::get<0>(i) == std::get<1>(i));
		}

		REQUIRE(a.data() == vec1.data());
		REQUIRE(!a.empty());
		REQUIRE(!b.empty());
		REQUIRE(a.size() == b.size());
		REQUIRE(a.data() == b.data());
		REQUIRE(a.size() == vec1.size());
		REQUIRE(a.data() == vec1.data());

	}
}

TEST_CASE("array_proxy - Move assignment.", "[array_proxy]")
{
	jkutil::array_proxy<int> a;

	SECTION("Empty move assignment.")
	{
		jkutil::array_proxy<int> b;

		//----//
		a = std::move(b);
		//----//

		REQUIRE(a.empty());
		REQUIRE(b.empty());
	}
	SECTION("Non-empty to empty move assignment.")
	{
		std::vector<int> vec;
		vec.assign({ 1, 2, 3, 4 });

		jkutil::array_proxy<int> b = jkutil::make_array_proxy(vec.size(), vec.data());

		for (auto i : jkutil::make_zip_range(b, vec))
		{
			REQUIRE(std::get<0>(i) == std::get<1>(i));
		}

		//----//
		a = std::move(b);
		//----//

		REQUIRE(!a.empty());
		REQUIRE(b.empty());
		REQUIRE(b.size() == 0);
		REQUIRE(b.data() == nullptr);
		REQUIRE(a.size() == vec.size());
		REQUIRE(a.data() == vec.data());
	}
	SECTION("Non-empty to Non-empty move assignment.")
	{
		std::vector<int> vec1;
		vec1.assign({ 1, 2, 3, 4 });

		jkutil::array_proxy<int> b = jkutil::make_array_proxy(vec1.size(), vec1.data());

		for (auto i : jkutil::make_zip_range(b, vec1))
		{
			REQUIRE(std::get<0>(i) == std::get<1>(i));
		}

		std::vector<int> vec2;
		vec2.assign({ 8, 9, 10, 11 });

		a = jkutil::make_array_proxy(vec2.size(), vec2.data());

		for (auto i : jkutil::make_zip_range(a, vec2))
		{
			REQUIRE(std::get<0>(i) == std::get<1>(i));
		}

		REQUIRE(a.data() == vec2.data());
		REQUIRE(!a.empty());

		//----//
		a = std::move(b);
		//----//

		for (auto i : jkutil::make_zip_range(a, vec1))
		{
			REQUIRE(std::get<0>(i) == std::get<1>(i));
		}

		for (auto i : b)
		{
			REQUIRE(false);
		}

		REQUIRE(a.data() == vec1.data());
		REQUIRE(!a.empty());
		REQUIRE(b.empty());
		REQUIRE(b.size() == 0);
		REQUIRE(b.data() == nullptr);
		REQUIRE(a.size() == vec1.size());
		REQUIRE(a.data() == vec1.data());

	}
}

TEST_CASE("array_proxy - Index access.", "[array_proxy]")
{
	std::vector<int> vec;
	vec.assign({ 56, 23, 67, 12 });

	jkutil::array_proxy<int> proxy = jkutil::make_array_proxy(vec.size(), vec.data());

	REQUIRE(proxy.at(0) == 56);
	REQUIRE(proxy.at(1) == 23);
	REQUIRE(proxy.at(2) == 67);
	REQUIRE(proxy.at(3) == 12);

	REQUIRE(proxy[0] == 56);
	REQUIRE(proxy[1] == 23);
	REQUIRE(proxy[2] == 67);
	REQUIRE(proxy[3] == 12);
}

TEST_CASE("array_proxy - Iterator access.", "[array_proxy]")
{
	std::vector<int> vec;
	vec.assign({ 56, 23, 67, 12 });

	jkutil::array_proxy<int> proxy = jkutil::make_array_proxy(vec.size(),vec.data());

	for (auto& i : proxy)
	{
		i = 9;
	}

	for (auto& i : proxy)
	{
		REQUIRE(i == 9);
	}
}

TEST_CASE("array_proxy - Equality and Inequality.", "[array_proxy]")
{
	std::vector<int> vec1;
	vec1.assign({ 56, 23, 67, 12 });

	jkutil::array_proxy<int> proxy1 = jkutil::make_array_proxy(vec1.size(), vec1.data());

	std::vector<int> vec2;
	vec2.assign({ 56, 23, 67, 12 });

	jkutil::array_proxy<int> proxy2 = jkutil::make_array_proxy(vec2.size(), vec2.data());

	REQUIRE(proxy1 != proxy2);

	proxy2 = jkutil::make_array_proxy(vec1.size(), vec1.data());

	REQUIRE(proxy1 == proxy2);
}